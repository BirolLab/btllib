#pragma once

#include <algorithm>
#include <array>
#include <cstdint>
#include <cstring>
#include <deque>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

#include <btllib/bshash_hashing_internals.hpp>
#include <btllib/status.hpp>

namespace btllib {

using hashing_internals::extend_hashes;
using hashing_internals::srol;
using hashing_internals::sror;

using hashing_internals::base_forward_bs_hash;
using hashing_internals::next_forward_bs_hash;
using hashing_internals::prev_forward_bs_hash;

using hashing_internals::base_reverse_bs_hash;
using hashing_internals::next_reverse_bs_hash;
using hashing_internals::prev_reverse_bs_hash;

using hashing_internals::BS_CONVERT_TAB;
using hashing_internals::BS_RC_CONVERT_TAB;

using hashing_internals::CA_DIMER_TAB;
using hashing_internals::CC_DIMER_TAB;
using hashing_internals::CG_DIMER_TAB;
using hashing_internals::CT_DIMER_TAB;

using hashing_internals::MS_TAB_31L_CA;
using hashing_internals::MS_TAB_31L_CC;
using hashing_internals::MS_TAB_31L_CG;
using hashing_internals::MS_TAB_31L_CT;
using hashing_internals::MS_TAB_33R_CA;
using hashing_internals::MS_TAB_33R_CC;
using hashing_internals::MS_TAB_33R_CG;
using hashing_internals::MS_TAB_33R_CT;

class BsHash
{

public:
  /**
   * Construct an BsHash object for k-mers.
   * @param seq C-string containing sequence data
   * @param seq_len Length of the sequence
   * @param num_hashes Number of hashes to generate per k-mer
   * @param k K-mer size
   * @param mode  Hashing scheme targeting a specific methylation context.
   *              Supported values are "CG", "CC", "CT", and "CA". Each mode
   *              applies the corresponding bisulfite-oriented hashing behavior.
   *
   *              Note: BsHash can only handle one methylation context at a
   * time. For multi-context bisulfite processing, use BsHashDirectional, which
   * performs the additional required handling.
   * @param pos Position in the sequence to start hashing from
   */
  BsHash(const char* seq,
         size_t seq_len,
         hashing_internals::NUM_HASHES_TYPE num_hashes,
         hashing_internals::K_TYPE k,
         std::string mode,
         size_t pos = 0)
    : seq(seq)
    , seq_len(seq_len)
    , num_hashes(num_hashes)
    , k(k)
    , pos(pos)
    , initialized(false)
    , hash_arr(new uint64_t[num_hashes])
  {
    check_error(k == 0, "BsHash: k must be greater than 0");
    check_error(k % 2 == 1, "BsHash: k must be even");
    check_error((k / 2) % 2 == 0, "BsHash: k must have odd number of dimers");
    check_error(this->seq_len < k,
                "BsHash: sequence length (" + std::to_string(this->seq_len) +
                  ") is smaller than k (" + std::to_string(k) + ")");
    check_error(pos > this->seq_len - k,
                "BsHash: passed position (" + std::to_string(pos) +
                  ") is larger than sequence length (" +
                  std::to_string(this->seq_len) + ")");
    static const std::unordered_set<std::string> valid_modes = {
      "CG", "CC", "CT", "CA"
    };
    check_error(valid_modes.find(mode) == valid_modes.end(),
                "BsHash: mode must be one of [CG, CC, CT, CA], but got '" +
                  mode + "'");

    if (mode == "CC") {
      DIMER_TAB = CC_DIMER_TAB;
      TAB_33R = MS_TAB_33R_CC;
      TAB_31L = MS_TAB_31L_CC;
      meth_signal = { "CC", "GG" };
    } else if (mode == "CG") {
      DIMER_TAB = CG_DIMER_TAB;
      TAB_33R = MS_TAB_33R_CG;
      TAB_31L = MS_TAB_31L_CG;
      meth_signal = { "CG" };
    } else if (mode == "CT") {
      DIMER_TAB = CT_DIMER_TAB;
      TAB_33R = MS_TAB_33R_CT;
      TAB_31L = MS_TAB_31L_CT;
      meth_signal = { "CT", "AG" };
    } else if (mode == "CA") {
      DIMER_TAB = CA_DIMER_TAB;
      TAB_33R = MS_TAB_33R_CA;
      TAB_31L = MS_TAB_31L_CA;
      meth_signal = { "CA", "TG" };
    }
  }

  /**
   * Construct an BsHash object for k-mers.
   * @param seq Sequence string
   * @param num_hashes Number of hashes to produce per k-mer
   * @param k K-mer size
   * @param mode  Hashing scheme targeting a specific methylation context.
   *              Supported values are "CG", "CC", "CT", and "CA". Each mode
   *              applies the corresponding bisulfite-oriented hashing behavior.
   *
   *              Note: BsHash can only handle one methylation context at a
   * time. For multi-context bisulfite processing, use BsHashDirectional, which
   * performs the additional required handling.
   * @param pos Position in sequence to start hashing from
   */
  BsHash(const std::string& seq,
         hashing_internals::NUM_HASHES_TYPE num_hashes,
         hashing_internals::K_TYPE k,
         std::string mode = "CG",
         size_t pos = 0)
    : BsHash(seq.data(), seq.size(), num_hashes, k, mode, pos)
  {
  }

  BsHash(const BsHash& obj)
    : seq(obj.seq)
    , seq_len(obj.seq_len)
    , num_hashes(obj.num_hashes)
    , k(obj.k)
    , pos(obj.pos)
    , initialized(obj.initialized)
    , fwd_hashes(obj.fwd_hashes)
    , rev_hashes(obj.rev_hashes)
    , hash_arr(new uint64_t[obj.num_hashes])
  {
    DIMER_TAB = obj.DIMER_TAB;
    TAB_33R = obj.TAB_33R;
    TAB_31L = obj.TAB_31L;
    std::memcpy(
      hash_arr.get(), obj.hash_arr.get(), num_hashes * sizeof(uint64_t));
  }

  BsHash(BsHash&&) = default;

  /**
   * Calculate the hash values of current k-mer and advance to the next k-mer.
   * BsHash advances one nucleotide at a time until it finds a k-mer with valid
   * characters (ACGTU) and skips over those with invalid characters (non-ACGTU,
   * including N). This method must be called before hashes() is accessed, for
   * the first and every subsequent hashed kmer. get_pos() may be called at any
   * time to obtain the position of last hashed k-mer or the k-mer to be hashed
   * if roll() has never been called on this BsHash object. It is important to
   * note that the number of roll() calls is NOT necessarily equal to get_pos(),
   * if there are N's or invalid characters in the hashed sequence.
   * @return \p true on success and \p false otherwise
   */
  bool roll()
  {
    if (!initialized) {
      return init();
    }

    auto dimer_valid = [&](size_t p) -> bool {
      if (p + 1 >= seq_len)
        return false;
      char c1 = seq[p];
      char c2 = seq[p + 1];
      uint8_t a = BS_CONVERT_TAB[(unsigned char)c1];
      uint8_t b = BS_CONVERT_TAB[(unsigned char)c2];
      uint8_t loc = 10 * a + b;
      return DIMER_TAB[loc] != 0;
    };

    if (even) {
      if (pos >= seq_len - k)
        return false;

      if (!dimer_valid(pos + k - 1)) {
        pos += k;
        return init();
      }

      even = false;
      ++pos;

      extend_hashes(
        fwd_hashes[1], rev_hashes[1], k, num_hashes, hash_arr.get());
      return true;
    }

    if (pos >= seq_len - k)
      return false;

    if (!dimer_valid(pos + k - 1)) {
      pos += k;
      return init();
    }

    bool can_roll_second = dimer_valid(pos + k);

    for (int i = 0; i < 2; i++) {
      if (i == 0 || can_roll_second) {

        char out1 = seq[pos + i - 1];
        char out2 = seq[pos + i + 1 - 1];

        char in1 = seq[pos + k + i - 1];
        char in2 = seq[pos + k + i + 1 - 1];

        fwd_hashes[i] = next_forward_bs_hash(
          fwd_hashes[i], k, out1, out2, in1, in2, DIMER_TAB, TAB_33R, TAB_31L);

        rev_hashes[i] = next_reverse_bs_hash(
          rev_hashes[i], k, out1, out2, in1, in2, DIMER_TAB, TAB_33R, TAB_31L);
      }
    }

    extend_hashes(fwd_hashes[0], rev_hashes[0], k, num_hashes, hash_arr.get());

    ++pos;
    even = true;

    if (!can_roll_second) {
      fwd_hashes[1] = 0;
      rev_hashes[1] = 0;
    }

    return true;
  }

  /**
   * Extract the central dimer (two-base substring) of the current k-mer window.
   * Since the number of dimers in a k-mer is always odd, the center dimer is
   * unambiguously defined as the (num_dimers / 2)-th dimer from the start.
   *
   * If the computed index extends beyond the sequence boundary, an empty string
   * is returned.
   *
   * @return The center dimer of the current k-mer.
   */
  std::string_view center_dimer() const
  {
    constexpr size_t DIMER_LEN = 2;
    const size_t center_idx = pos + (k / 4) * DIMER_LEN;
    return std::string_view(seq + center_idx, DIMER_LEN);
  }

  /**
   * Check if the k-mer center position is methylated based on conversion type.
   * For CT conversion, methylation corresponds to a cytosine ('C'/'c').
   * For GA conversion, methylation corresponds to a guanine ('G'/'g').
   *
   * @return true if the base at the methylation index indicates methylation,
   * false otherwise.
   */
  bool is_methylated()
  {

    size_t num_dimers = k / 2;
    size_t center_idx = pos + (num_dimers / 2) * 2;

    std::string dimer;
    dimer += seq[center_idx];
    dimer += seq[center_idx + 1];

    std::transform(dimer.begin(), dimer.end(), dimer.begin(), ::toupper);
    return std::find(meth_signal.begin(), meth_signal.end(), dimer) !=
           meth_signal.end();
  }

  /**
   * Check if the forward hash is higher than the reverse hash.
   * @return true if forward hash > reverse hash, false otherwise
   */
  bool is_forward_higher()
  {
    size_t idx = even ? 0 : 1;
    return fwd_hashes[idx] > rev_hashes[idx];
  }

  /**
   * Like the roll() function, but advance backwards.
   * @return \p true on success and \p false otherwise
   */
  bool roll_back()
  {
    if (!initialized) {
      return init();
    }

    if (pos == 0) {
      return false;
    }

    auto dimer_valid = [&](size_t p) -> bool {
      if (p + 1 >= seq_len)
        return false;
      uint8_t a = BS_CONVERT_TAB[(unsigned char)seq[p]];
      uint8_t b = BS_CONVERT_TAB[(unsigned char)seq[p + 1]];
      uint8_t loc = 10 * a + b;
      return DIMER_TAB[loc] != 0;
    };

    // ---- ODD STATE: only roll back the primary hash ---- //
    if (!even) {
      extend_hashes(
        fwd_hashes[0], rev_hashes[0], k, num_hashes, hash_arr.get());
      --pos;
      even = true;
      return true;
    }

    // ---- EVEN STATE ---- //
    // First dimer (the one at pos-1, pos)
    if (!dimer_valid(pos - 1)) {
      if (pos <= k)
        return false;
      pos -= k;
      return init();
    }

    // Check if the second rollback is possible
    bool can_roll_second = true;
    if (pos <= 1 || !dimer_valid(pos - 2)) {
      can_roll_second = false;
    }

    // If the second hash is missing, restore it by reinitializing around pos-2
    if (fwd_hashes[1] == 0) {
      pos -= 2;
      init();
      pos++;
      extend_hashes(
        fwd_hashes[1], rev_hashes[1], k, num_hashes, hash_arr.get());
      even = false;
      return true;
    }

    // ---- Perform 1 or 2 backward hash updates ---- //
    for (int i = 0; i < 2; i++) {
      if (i == 1 || can_roll_second) {

        char out1 = seq[pos + k - 2 + i];
        char out2 = seq[pos + k - 1 + i];
        char in1 = seq[pos - 2 + i];
        char in2 = seq[pos - 1 + i];

        fwd_hashes[i] = prev_forward_bs_hash(
          fwd_hashes[i], k, out1, out2, in1, in2, DIMER_TAB, TAB_33R, TAB_31L);

        rev_hashes[i] = prev_reverse_bs_hash(
          rev_hashes[i], k, out1, out2, in1, in2, DIMER_TAB, TAB_33R, TAB_31L);
      }
    }

    extend_hashes(fwd_hashes[1], rev_hashes[1], k, num_hashes, hash_arr.get());

    --pos;
    even = false;
    return true;
  }

  /**
   * Get the array of current canonical hash values (length = \p get_hash_num())
   * @return Pointer to the hash array
   */
  const uint64_t* hashes() const { return hash_arr.get(); }

  /**
   * Get the position of last hashed k-mer or the k-mer to be hashed if roll()
   * has never been called on this BsHash object.
   * @return Position of the most recently hashed k-mer's first base-pair
   */
  size_t get_pos() const { return pos; }

  /**
   * Get the number of hashes generated per k-mer.
   * @return Number of hashes per k-mer
   */
  hashing_internals::NUM_HASHES_TYPE get_hash_num() const { return num_hashes; }

  /**
   * Get the length of the k-mers.
   * @return \p k
   */
  hashing_internals::K_TYPE get_k() const { return k; }

  /**
   * Get the hash value of the forward strand.
   * @return Forward hash value
   */
  uint64_t get_forward_hash() const
  {
    if (even) {
      return fwd_hashes[0];
    } else {
      return fwd_hashes[1];
    }
  }

  /**
   * Get the hash value of the reverse strand.
   * @return Reverse-complement hash value
   */
  uint64_t get_reverse_hash() const
  {
    if (even) {
      return rev_hashes[0];
    } else {
      return rev_hashes[1];
    }
  }

private:
  const char* seq;
  const size_t seq_len;
  hashing_internals::NUM_HASHES_TYPE num_hashes;
  hashing_internals::K_TYPE k;
  size_t pos;
  bool initialized;
  std::vector<uint64_t> fwd_hashes = { 0, 0 };
  std::vector<uint64_t> rev_hashes = { 0, 0 };
  std::vector<std::string> meth_signal;
  bool even = true;
  std::unique_ptr<uint64_t[]> hash_arr;
  const uint64_t* DIMER_TAB = nullptr;
  const uint64_t* const* TAB_33R = nullptr;
  const uint64_t* const* TAB_31L = nullptr;

  /**
   * Initialize the internal state of the iterator
   * @return \p true if successful, \p false otherwise
   */

  bool init()
  {
    bool has_n = true;
    while (pos <= seq_len - k + 1 && has_n) {
      has_n = false;
      for (unsigned i = 0; i < k && pos <= seq_len - k + 1; i += 2) {
        const char c1 = seq[pos + k - i - 2];
        const char c2 = seq[pos + k - i - 1];
        const uint8_t a = BS_CONVERT_TAB[(unsigned char)c1];
        const uint8_t b = BS_CONVERT_TAB[(unsigned char)c2];
        const uint8_t loc = 10 * a + b;

        if (DIMER_TAB[loc] == 0) {
          if (b == 0) {
            pos += k - i;
          } else {
            pos += k - i - 1;
          }

          has_n = true;
        }
      }
    }

    if (pos > seq_len - k) {
      return false;
    }

    bool has_second = true;
    if (pos == seq_len - k) {
      has_second = false;
    }

    fwd_hashes = base_forward_bs_hash(seq + pos, has_second, k, DIMER_TAB);
    rev_hashes = base_reverse_bs_hash(seq + pos, has_second, k, DIMER_TAB);

    extend_hashes(fwd_hashes[0], rev_hashes[0], k, num_hashes, hash_arr.get());

    initialized = true;
    return true;
  }
};
}