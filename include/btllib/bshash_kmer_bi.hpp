#pragma once

#include <array>
#include <cstdint>
#include <cstring>
#include <deque>
#include <memory>
#include <string>
#include <vector>

#include <btllib/bshash_hashing_internals.hpp>
#include <btllib/hashing_internals.hpp>
#include <btllib/nthash_kmer.hpp>
#include <btllib/status.hpp>

namespace btllib {

using hashing_internals::base_forward_hash;
using hashing_internals::base_reverse_hash;
using hashing_internals::extend_hashes;
using hashing_internals::next_forward_hash;
using hashing_internals::next_reverse_hash;
using hashing_internals::prev_forward_hash;
using hashing_internals::prev_reverse_hash;
using hashing_internals::SEED_N;
using hashing_internals::SEED_TAB;
using hashing_internals::sub_hash;

using hashing_internals::BS_BI_SEED_TAB;

using hashing_internals::BS_BI_MS_TAB_33R;

using hashing_internals::BS_BI_MS_TAB_31L;

using hashing_internals::BS_BI_CONVERT_TAB;

using hashing_internals::BS_BI_RC_CONVERT_TAB;

using hashing_internals::BS_BI_DIMER_TAB;
using hashing_internals::BS_BI_TETRAMER_TAB;
using hashing_internals::BS_BI_TRIMER_TAB;

namespace dev {
inline uint64_t
base_forward_hash_BI(const char* seq, unsigned k)
{
  return hashing_internals::base_forward_hash(
    seq,
    k,
    hashing_internals::SEED_TAB,
    hashing_internals::BS_BI_DIMER_TAB,
    hashing_internals::BS_BI_TRIMER_TAB,
    hashing_internals::BS_BI_TETRAMER_TAB,
    hashing_internals::BS_BI_CONVERT_TAB);
}

inline uint64_t
base_reverse_hash_BI(const char* seq, unsigned k)
{
  return hashing_internals::base_reverse_hash(
    seq,
    k,
    hashing_internals::SEED_TAB,
    hashing_internals::BS_BI_DIMER_TAB, // Bisulfite RC logic usually shares the
                                        // dimer tab
    hashing_internals::BS_BI_TRIMER_TAB,
    hashing_internals::BS_BI_TETRAMER_TAB,
    hashing_internals::BS_BI_RC_CONVERT_TAB);
}

// --- BI (C-to-T) Specialized Rolling Updates ---

inline uint64_t
next_forward_hash_BI(uint64_t h, unsigned k, char out, char in)
{
  return hashing_internals::next_forward_hash(
    h,
    k,
    (unsigned char)out,
    (unsigned char)in,
    hashing_internals::SEED_TAB,
    hashing_internals::BS_BI_MS_TAB_33R,
    hashing_internals::BS_BI_MS_TAB_31L);
}

inline uint64_t
next_reverse_hash_BI(uint64_t h, unsigned k, char out, char in)
{
  return hashing_internals::next_reverse_hash(
    h,
    k,
    (unsigned char)out,
    (unsigned char)in,
    hashing_internals::SEED_TAB,
    hashing_internals::BS_BI_MS_TAB_33R,
    hashing_internals::BS_BI_MS_TAB_31L);
}

}

/**
 * Bi BS-seq k-mer hashing.
 */
class BsHashBi
{

public:
  /**
   * Construct an ntHash object for k-mers.
   * @param seq C-string containing sequence data
   * @param seq_len Length of the sequence
   * @param num_hashes Number of hashes to generate per k-mer
   * @param k K-mer size
   * @param pos Position in the sequence to start hashing from
   */
  BsHashBi(const char* seq,
           size_t seq_len,
           hashing_internals::NUM_HASHES_TYPE num_hashes,
           hashing_internals::K_TYPE k,
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

    size_t num_dimers = k / 2;
    size_t center_dimer_start = (num_dimers / 2) * 2;
    meth_base_idx = center_dimer_start;

    primitive_tab = BS_BI_SEED_TAB;

    right_table = BS_BI_MS_TAB_33R;
    left_table = BS_BI_MS_TAB_31L;

    convert_tab = BS_BI_CONVERT_TAB;
    rc_convert_tab = BS_BI_RC_CONVERT_TAB;

    dimer_tab = BS_BI_DIMER_TAB;
    trimer_tab = BS_BI_TRIMER_TAB;
    tetramer_tab = BS_BI_TETRAMER_TAB;
  }

  /**
   * Construct an BsHash object for k-mers.
   * @param seq Sequence string
   * @param num_hashes Number of hashes to produce per k-mer
   * @param k K-mer size
   * @param pos Position in sequence to start hashing from
   */
  BsHashBi(const std::string& seq,
           hashing_internals::NUM_HASHES_TYPE num_hashes,
           hashing_internals::K_TYPE k,
           size_t pos = 0)
    : BsHashBi(seq.data(), seq.size(), num_hashes, k, pos)
  {
  }

  BsHashBi(const BsHashBi& obj)
    : seq(obj.seq)
    , seq_len(obj.seq_len)
    , num_hashes(obj.num_hashes)
    , k(obj.k)
    , pos(obj.pos)
    , initialized(obj.initialized)
    , fwd_hash(obj.fwd_hash)
    , rev_hash(obj.rev_hash)
    , hash_arr(new uint64_t[obj.num_hashes])
    , primitive_tab(obj.primitive_tab)
    , right_table(obj.right_table)
    , left_table(obj.left_table)
    , convert_tab(obj.convert_tab)
    , rc_convert_tab(obj.rc_convert_tab)
    , dimer_tab(obj.dimer_tab)
    , trimer_tab(obj.trimer_tab)
    , tetramer_tab(obj.tetramer_tab)
  {
    std::memcpy(
      hash_arr.get(), obj.hash_arr.get(), num_hashes * sizeof(uint64_t));
  }

  BsHashBi(BsHashBi&&) = default;
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
    if (pos >= seq_len - k) {
      return false;
    }
    if (hashing_internals::SEED_TAB[(unsigned char)seq[pos + k]] ==
        hashing_internals::SEED_N) {
      pos += k;
      return init();
    }
    fwd_hash = next_forward_hash(fwd_hash,
                                 k,
                                 seq[pos],
                                 seq[pos + k],
                                 primitive_tab,
                                 right_table,
                                 left_table);
    rev_hash = next_reverse_hash(rev_hash,
                                 k,
                                 seq[pos],
                                 seq[pos + k],
                                 primitive_tab,
                                 right_table,
                                 left_table);
    extend_hashes(fwd_hash, rev_hash, k, num_hashes, hash_arr.get());
    ++pos;
    return true;
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
    if (SEED_TAB[(unsigned char)seq[pos - 1]] == SEED_N && pos >= k) {
      pos -= k;
      return init();
    }
    if (SEED_TAB[(unsigned char)seq[pos - 1]] == SEED_N) {
      return false;
    }
    fwd_hash = prev_forward_hash(fwd_hash,
                                 k,
                                 seq[pos + k - 1],
                                 seq[pos - 1],
                                 primitive_tab,
                                 right_table,
                                 left_table);
    rev_hash = prev_reverse_hash(rev_hash,
                                 k,
                                 seq[pos + k - 1],
                                 seq[pos - 1],
                                 primitive_tab,
                                 right_table,
                                 left_table);
    extend_hashes(fwd_hash, rev_hash, k, num_hashes, hash_arr.get());
    --pos;
    return true;
  }

  /**
   * Peeks the hash values as if roll() was called (without advancing the
   * BsHash object. The peeked hash values can be obtained through the
   * hashes() method.
   * @return \p true on success and \p false otherwise
   */
  bool peek()
  {
    if (pos >= seq_len - k) {
      return false;
    }
    return peek(seq[pos + k]);
  }

  /**
   * Like peek(), but as if roll_back() was called.
   * @return \p true on success and \p false otherwise
   */
  bool peek_back()
  {
    if (pos == 0) {
      return false;
    }
    return peek_back(seq[pos - 1]);
  }

  /**
   * Peeks the hash values as if roll() was called for char_in (without
   * advancing the BsHash object. The peeked hash values can be obtained through
   * the hashes() method.
   * @return \p true on success and \p false otherwise
   */
  bool peek(char char_in)
  {
    if (!initialized) {
      return init();
    }
    if (SEED_TAB[(unsigned char)char_in] == SEED_N) {
      return false;
    }
    const uint64_t fwd = next_forward_hash(
      fwd_hash, k, seq[pos], char_in, primitive_tab, right_table, left_table);
    const uint64_t rev = next_reverse_hash(
      rev_hash, k, seq[pos], char_in, primitive_tab, right_table, left_table);
    extend_hashes(fwd, rev, k, num_hashes, hash_arr.get());
    return true;
  }

  /**
   * Like peek(), but as if roll_back on char_in was called.
   * @return \p true on success and \p false otherwise
   */
  bool peek_back(char char_in)
  {
    if (!initialized) {
      return init();
    }
    if (SEED_TAB[(unsigned char)char_in] == SEED_N) {
      return false;
    }
    const unsigned char char_out = seq[pos + k - 1];
    const uint64_t fwd = prev_forward_hash(
      fwd_hash, k, char_out, char_in, primitive_tab, right_table, left_table);
    const uint64_t rev = prev_reverse_hash(
      rev_hash, k, char_out, char_in, primitive_tab, right_table, left_table);
    extend_hashes(fwd, rev, k, num_hashes, hash_arr.get());
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

  bool is_methylated(int offset)
  {
    char base = seq[pos + meth_base_idx + offset];
    if (offset == 0) {
      return base == 'C' || base == 'c';
    } else {
      return base == 'G' || base == 'g';
    }
  }

  /**
   * Check if the forward hash is higher than the reverse hash.
   * @return true if forward hash > reverse hash, false otherwise
   */
  bool is_forward_higher() const { return fwd_hash > rev_hash; }

  void sub(const std::vector<unsigned>& positions,
           const std::vector<unsigned char>& new_bases)
  {
    sub_hash(fwd_hash,
             rev_hash,
             seq + pos,
             positions,
             new_bases,
             get_k(),
             get_hash_num(),
             hash_arr.get(),
             right_table,
             left_table);
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
  uint64_t get_forward_hash() const { return fwd_hash; }

  /**
   * Get the hash value of the reverse strand.
   * @return Reverse-complement hash value
   */
  uint64_t get_reverse_hash() const { return rev_hash; }

private:
  const char* seq;
  const size_t seq_len;
  hashing_internals::NUM_HASHES_TYPE num_hashes;
  hashing_internals::K_TYPE k;
  size_t pos;
  size_t meth_base_idx;
  bool initialized;
  uint64_t fwd_hash = 0;
  uint64_t rev_hash = 0;
  std::unique_ptr<uint64_t[]> hash_arr;

  const uint64_t* primitive_tab;

  const uint64_t* const* right_table;
  const uint64_t* const* left_table;

  const uint8_t* convert_tab;
  const uint8_t* rc_convert_tab;

  const uint64_t* dimer_tab;
  const uint64_t* trimer_tab;
  const uint64_t* tetramer_tab;

  /**
   * Initialize the internal state of the iterator
   * @return \p true if successful, \p false otherwise
   */
  bool init()
  {
    bool has_n = true;
    while (pos <= seq_len - k + 1 && has_n) {
      has_n = false;
      for (unsigned i = 0; i < k && pos <= seq_len - k + 1; i++) {
        if (SEED_TAB[(unsigned char)seq[pos + k - i - 1]] == SEED_N) {
          pos += k - i;
          has_n = true;
        }
      }
    }
    if (pos > seq_len - k) {
      return false;
    }
    fwd_hash = base_forward_hash(seq + pos,
                                 k,
                                 primitive_tab,
                                 dimer_tab,
                                 trimer_tab,
                                 tetramer_tab,
                                 convert_tab);
    rev_hash = base_reverse_hash(seq + pos,
                                 k,
                                 primitive_tab,
                                 dimer_tab,
                                 trimer_tab,
                                 tetramer_tab,
                                 rc_convert_tab);
    extend_hashes(fwd_hash, rev_hash, k, num_hashes, hash_arr.get());
    initialized = true;
    return true;
  }
};

} // namespace btllib
