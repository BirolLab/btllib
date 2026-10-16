#pragma once

#include <cstdint>
#include <string>

#include <btllib/bihash_hashing_internals.hpp>
#include <btllib/bihash_kmer_base.hpp>
#include <btllib/hashing_internals.hpp>
#include <btllib/status.hpp>

namespace btllib {

/**
 * Directional BI-seq k-mer hashing.
 */
class BiHashDirectional : public BiHashSingleBase
{

public:
  /**
   * Construct an ntHash object for k-mers.
   * @param seq C-string containing sequence data
   * @param seq_len Length of the sequence
   * @param num_hashes Number of hashes to generate per k-mer
   * @param k K-mer size
   * @param conversion_type Bisulfite conversion mode ("CT" or "GA"),
   *        used to determine how bases are interpreted during hashing.
   * @param pos Position in the sequence to start hashing from
   */
  BiHashDirectional(const char* seq,
                    size_t seq_len,
                    hashing_internals::NUM_HASHES_TYPE num_hashes,
                    hashing_internals::K_TYPE k,
                    std::string conversion_type,
                    size_t pos = 0)
    : BiHashSingleBase(seq, seq_len, num_hashes, k, pos)
    , conversion_type(conversion_type)
  {
    if (conversion_type == "CT") {
      primitive_tab = hashing_internals::BI_CT_SEED_TAB;

      right_table = hashing_internals::BI_CT_MS_TAB_33R;
      left_table = hashing_internals::BI_CT_MS_TAB_31L;

      convert_tab = hashing_internals::BI_CT_CONVERT_TAB;
      rc_convert_tab = hashing_internals::BI_CT_RC_CONVERT_TAB;

      dimer_tab = hashing_internals::BI_CT_DIMER_TAB;
      rc_dimer_tab = hashing_internals::BI_GA_DIMER_TAB;
      trimer_tab = hashing_internals::BI_CT_TRIMER_TAB;
      rc_trimer_tab = hashing_internals::BI_GA_TRIMER_TAB;
      tetramer_tab = hashing_internals::BI_CT_TETRAMER_TAB;
      rc_tetramer_tab = hashing_internals::BI_GA_TETRAMER_TAB;
    } else if (conversion_type == "GA") {
      meth_base_idx += 1;

      primitive_tab = hashing_internals::BI_GA_SEED_TAB;

      right_table = hashing_internals::BI_GA_MS_TAB_33R;
      left_table = hashing_internals::BI_GA_MS_TAB_31L;

      convert_tab = hashing_internals::BI_GA_CONVERT_TAB;
      rc_convert_tab = hashing_internals::BI_GA_RC_CONVERT_TAB;

      dimer_tab = hashing_internals::BI_GA_DIMER_TAB;
      rc_dimer_tab = hashing_internals::BI_CT_DIMER_TAB;
      trimer_tab = hashing_internals::BI_GA_TRIMER_TAB;
      rc_trimer_tab = hashing_internals::BI_CT_TRIMER_TAB;
      tetramer_tab = hashing_internals::BI_GA_TETRAMER_TAB;
      rc_tetramer_tab = hashing_internals::BI_CT_TETRAMER_TAB;
    } else {
      check_error(
        true, "Unsupported conversion_type. Must be CT or GA, as capitalized.");
    }
  }

  /**
   * Construct an BiHash object for k-mers.
   * @param seq Sequence string
   * @param num_hashes Number of hashes to produce per k-mer
   * @param k K-mer size
   * @param conversion_type Bisulfite conversion mode ("CT" or "GA"),
   *        used to determine how bases are interpreted during hashing.
   * @param pos Position in sequence to start hashing from
   */
  BiHashDirectional(const std::string& seq,
                    hashing_internals::NUM_HASHES_TYPE num_hashes,
                    hashing_internals::K_TYPE k,
                    std::string conversion_type,
                    size_t pos = 0)
    : BiHashDirectional(seq.data(),
                        seq.size(),
                        num_hashes,
                        k,
                        conversion_type,
                        pos)
  {
  }

  BiHashDirectional(const BiHashDirectional& obj) = default;
  BiHashDirectional(BiHashDirectional&&) = default;

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
    char base = seq[pos + meth_base_idx];

    if (conversion_type == "CT")
      return base == 'C' || base == 'c';
    else
      return base == 'G' || base == 'g';
  }

private:
  std::string conversion_type;
};

} // namespace btllib
