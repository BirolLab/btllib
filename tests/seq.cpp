#include "btllib/seq.hpp"
#include "helpers.hpp"

#include <string>

int
main()
{
  std::string seq = "ACGTACACTGGACTGAGTCT";
  std::string rc = "AGACTCAGTCCAGTGTACGT";
  TEST_ASSERT_EQ(btllib::get_reverse_complement(seq), rc);
  std::string ct = "ATGTATATTGGATGTAGTTT";
  TEST_ASSERT_EQ(btllib::get_bs_conversion(seq, "CT"), ct);
  std::string ga = "ACATAAACTAAACTAAATCT";
  TEST_ASSERT_EQ(btllib::get_bs_conversion(seq, "GA"), ga);
  return 0;
}
