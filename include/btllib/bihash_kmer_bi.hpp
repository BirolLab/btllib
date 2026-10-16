#pragma once

#include <cstdint>
#include <string>

#include <btllib/bihash_hashing_internals.hpp>
#include <btllib/bihash_kmer_base.hpp>
#include <btllib/hashing_internals.hpp>

namespace btllib {

/**
 * Bi BI-seq k-mer hashing.
 */
class BiHashBi : public BiHashSingleBase
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
  BiHashBi(const char* seq,
           size_t seq_len,
           hashing_internals::NUM_HASHES_TYPE num_hashes,
           hashing_internals::K_TYPE k,
           size_t pos = 0)
    : BiHashSingleBase(seq, seq_len, num_hashes, k, pos)
  {
    primitive_tab = hashing_internals::BI_BI_SEED_TAB;

    right_table = hashing_internals::BI_BI_MS_TAB_33R;
    left_table = hashing_internals::BI_BI_MS_TAB_31L;

    convert_tab = hashing_internals::BI_BI_CONVERT_TAB;
    rc_convert_tab = hashing_internals::BI_BI_RC_CONVERT_TAB;

    dimer_tab = hashing_internals::BI_BI_DIMER_TAB;
    rc_dimer_tab = hashing_internals::BI_BI_DIMER_TAB;
    trimer_tab = hashing_internals::BI_BI_TRIMER_TAB;
    rc_trimer_tab = hashing_internals::BI_BI_TRIMER_TAB;
    tetramer_tab = hashing_internals::BI_BI_TETRAMER_TAB;
    rc_tetramer_tab = hashing_internals::BI_BI_TETRAMER_TAB;
  }

  /**
   * Construct an BiHash object for k-mers.
   * @param seq Sequence string
   * @param num_hashes Number of hashes to produce per k-mer
   * @param k K-mer size
   * @param pos Position in sequence to start hashing from
   */
  BiHashBi(const std::string& seq,
           hashing_internals::NUM_HASHES_TYPE num_hashes,
           hashing_internals::K_TYPE k,
           size_t pos = 0)
    : BiHashBi(seq.data(), seq.size(), num_hashes, k, pos)
  {
  }

  BiHashBi(const BiHashBi& obj) = default;
  BiHashBi(BiHashBi&&) = default;

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
};

} // namespace btllib
