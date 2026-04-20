#include "btllib/bihash.hpp"
#include "btllib/seq.hpp"
#include "helpers.hpp"

#include <iostream>
#include <queue>
#include <stack>
#include <string>

int
main()
{
  {
    PRINT_TEST_NAME("k-mer rolling - CT Mode")

    std::string seq = "AGTCAGTCAGTCAG";
    unsigned h = 3;
    unsigned k = 6;

    btllib::BiHashDirectional bihash(seq, h, k, "CT");
    std::vector<uint64_t*> hashes;
    uint64_t fwd_hash = 0;
    uint64_t final_fwd_hash = 0;
    uint64_t rev_hash = 0;
    uint64_t final_rev_hash = 0;

    while (bihash.roll()) {
      if (fwd_hash == 0) {
        fwd_hash = bihash.get_forward_hash();
        rev_hash = bihash.get_reverse_hash();
      }
      final_fwd_hash = bihash.get_forward_hash();
      final_rev_hash = bihash.get_reverse_hash();
      uint64_t* h_vals = new uint64_t[h];
      std::copy(bihash.hashes(), bihash.hashes() + h, h_vals);
      hashes.push_back(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1);
    TEST_ASSERT_EQ(fwd_hash, final_fwd_hash);
    TEST_ASSERT_EQ(rev_hash, final_rev_hash);
    TEST_ASSERT_ARRAY_EQ(hashes.front(), hashes.back(), h);
  }

  {
    PRINT_TEST_NAME("k-mer rolling - GA Mode")

    std::string seq = "AGTCAGTCAGTCAG";
    unsigned h = 3;
    unsigned k = 6;

    btllib::BiHashDirectional bihash(seq, h, k, "GA");
    std::vector<uint64_t*> hashes;
    uint64_t fwd_hash = 0;
    uint64_t final_fwd_hash = 0;
    uint64_t rev_hash = 0;
    uint64_t final_rev_hash = 0;

    while (bihash.roll()) {
      if (fwd_hash == 0) {
        fwd_hash = bihash.get_forward_hash();
        rev_hash = bihash.get_reverse_hash();
      }
      final_fwd_hash = bihash.get_forward_hash();
      final_rev_hash = bihash.get_reverse_hash();
      uint64_t* h_vals = new uint64_t[h];
      std::copy(bihash.hashes(), bihash.hashes() + h, h_vals);
      hashes.push_back(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1);
    TEST_ASSERT_EQ(fwd_hash, final_fwd_hash);
    TEST_ASSERT_EQ(rev_hash, final_rev_hash);
    TEST_ASSERT_ARRAY_EQ(hashes.front(), hashes.back(), h);
  }

  {
    PRINT_TEST_NAME("k-mer rolling vs. base hash values - CT Mode")

    std::string seq = "ACGTACACTGGACTGAGTCTATCG";

    btllib::BiHashDirectional bihash(seq, 3, seq.size() - 2, "CT");
    /* 19-mers of kmer*/
    std::string kmer1 = seq.substr(0, 22);
    std::string kmer2 = seq.substr(1, 22);
    std::string kmer3 = seq.substr(2, 22);

    btllib::BiHashDirectional bihash_vector[] = {
      btllib::BiHashDirectional(
        kmer1, bihash.get_hash_num(), kmer1.size(), "CT"),
      btllib::BiHashDirectional(
        kmer2, bihash.get_hash_num(), kmer2.size(), "CT"),
      btllib::BiHashDirectional(
        kmer3, bihash.get_hash_num(), kmer3.size(), "CT")
    };

    size_t i;
    for (i = 0; bihash.roll() && bihash_vector[i].roll(); ++i) {
      for (size_t j = 0; j < bihash.get_hash_num(); ++j) {
        TEST_ASSERT_EQ(bihash.hashes()[j], bihash_vector[i].hashes()[j]);
      }
    }
    TEST_ASSERT_EQ(i, 3);
  }

  {
    PRINT_TEST_NAME("k-mer rolling vs. base hash values - GA Mode")

    std::string seq = "ACGTACACTGGACTGAGTCTATCG";

    btllib::BiHashDirectional bihash(seq, 3, seq.size() - 2, "GA");
    /* 19-mers of kmer*/
    std::string kmer1 = seq.substr(0, 22);
    std::string kmer2 = seq.substr(1, 22);
    std::string kmer3 = seq.substr(2, 22);

    btllib::BiHashDirectional bihash_vector[] = {
      btllib::BiHashDirectional(
        kmer1, bihash.get_hash_num(), kmer1.size(), "GA"),
      btllib::BiHashDirectional(
        kmer2, bihash.get_hash_num(), kmer2.size(), "GA"),
      btllib::BiHashDirectional(
        kmer3, bihash.get_hash_num(), kmer3.size(), "GA")
    };

    size_t i;
    for (i = 0; bihash.roll() && bihash_vector[i].roll(); ++i) {
      for (size_t j = 0; j < bihash.get_hash_num(); ++j) {
        TEST_ASSERT_EQ(bihash.hashes()[j], bihash_vector[i].hashes()[j]);
      }
    }
    TEST_ASSERT_EQ(i, 3);
  }

  {
    PRINT_TEST_NAME("canonical hashing")

    std::string seq_f = "ACGTACACTGGACTGAGTCTAA";
    std::string seq_r = "TTAGACTCAGTCCAGTGTACGT";
    unsigned h = 3;

    btllib::BiHashDirectional bihash_f(seq_f, h, seq_f.size(), "CT");
    btllib::BiHashDirectional bihash_r(seq_r, h, seq_r.size(), "GA");

    bihash_f.roll();
    bihash_r.roll();
    TEST_ASSERT_EQ(bihash_f.get_hash_num(), bihash_r.get_hash_num())
    TEST_ASSERT_ARRAY_EQ(bihash_f.hashes(), bihash_r.hashes(), h)
  }

  {
    PRINT_TEST_NAME("canonical hashing - Reverse")

    std::string seq_f = "ACGTACACTGGACTGAGTCTAA";
    std::string seq_r = "TTAGACTCAGTCCAGTGTACGT";
    unsigned h = 3;

    btllib::BiHashDirectional bihash_f(seq_f, h, seq_f.size(), "GA");
    btllib::BiHashDirectional bihash_r(seq_r, h, seq_r.size(), "CT");

    bihash_f.roll();
    bihash_r.roll();
    TEST_ASSERT_EQ(bihash_f.get_hash_num(), bihash_r.get_hash_num())
    TEST_ASSERT_ARRAY_EQ(bihash_f.hashes(), bihash_r.hashes(), h)
  }

  {
    PRINT_TEST_NAME("k-mer back rolling - CT Mode")

    std::string seq = "ACTAGACTG";
    unsigned h = 3;
    unsigned k = 6;

    btllib::BiHashDirectional bihash(seq, h, k, "CT");
    std::stack<uint64_t*> hashes;

    while (bihash.roll()) {
      uint64_t* h_vals = new uint64_t[h];
      std::copy(bihash.hashes(), bihash.hashes() + h, h_vals);
      hashes.push(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1)

    do {
      TEST_ASSERT_ARRAY_EQ(bihash.hashes(), hashes.top(), h)
      hashes.pop();
    } while (bihash.roll_back());
  }

  {
    PRINT_TEST_NAME("k-mer back rolling - GA Mode")

    std::string seq = "ACTAGACTG";
    unsigned h = 3;
    unsigned k = 6;

    btllib::BiHashDirectional bihash(seq, h, k, "GA");
    std::stack<uint64_t*> hashes;

    while (bihash.roll()) {
      uint64_t* h_vals = new uint64_t[h];
      std::copy(bihash.hashes(), bihash.hashes() + h, h_vals);
      hashes.push(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1)

    do {
      TEST_ASSERT_ARRAY_EQ(bihash.hashes(), hashes.top(), h)
      hashes.pop();
    } while (bihash.roll_back());
  }

  {
    PRINT_TEST_NAME("k-mer peeking - CT Mode")

    std::string seq = "ACTGATCAG";
    unsigned h = 3;
    unsigned k = 6;

    btllib::BiHashDirectional bihash(seq, h, k, "CT");
    bihash.roll();

    size_t steps = 3;
    while (steps--) {
      bihash.peek();
      uint64_t* h_peek = new uint64_t[h];
      std::copy(bihash.hashes(), bihash.hashes() + h, h_peek);
      bihash.peek(seq[bihash.get_pos() + k]);
      TEST_ASSERT_ARRAY_EQ(bihash.hashes(), h_peek, h);
      bihash.roll();
      TEST_ASSERT_ARRAY_EQ(bihash.hashes(), h_peek, h);
    }
  }

  {
    PRINT_TEST_NAME("k-mer peeking - GA Mode")

    std::string seq = "ACTGATCAG";
    unsigned h = 3;
    unsigned k = 6;

    btllib::BiHashDirectional bihash(seq, h, k, "GA");
    bihash.roll();

    size_t steps = 3;
    while (steps--) {
      bihash.peek();
      uint64_t* h_peek = new uint64_t[h];
      std::copy(bihash.hashes(), bihash.hashes() + h, h_peek);
      bihash.peek(seq[bihash.get_pos() + k]);
      TEST_ASSERT_ARRAY_EQ(bihash.hashes(), h_peek, h);
      bihash.roll();
      TEST_ASSERT_ARRAY_EQ(bihash.hashes(), h_peek, h);
    }
  }

  {
    PRINT_TEST_NAME("skipping Ns - CT Mode")

    std::string seq = "ACGTACACTGGACTGAGTCTAAAA";
    std::string seq_with_ns = seq;

    TEST_ASSERT_GE(seq_with_ns.size(), 10)
    seq_with_ns[seq_with_ns.size() / 2] = 'N';
    seq_with_ns[seq_with_ns.size() / 2 + 1] = 'N';
    unsigned k = (seq.size() - 2) / 2 - 1;
    btllib::BiHashDirectional bihash(seq_with_ns, 3, k, "CT");

    std::vector<uint64_t> positions;
    for (size_t i = 0; i < seq_with_ns.size() / 2 - k + 1; i++) {
      positions.push_back(i);
    }
    for (size_t i = seq_with_ns.size() / 2 + 2; i < seq_with_ns.size() - k + 1;
         i++) {
      positions.push_back(i);
    }

    size_t i = 0;
    while (bihash.roll()) {
      TEST_ASSERT_EQ(bihash.get_pos(), positions[i])
      i++;
    }
    TEST_ASSERT_EQ(positions.size(), i)
  }

  {
    PRINT_TEST_NAME("skipping Ns - GA Mode")

    std::string seq = "ACGTACACTGGACTGAGTCTAAAA";
    std::string seq_with_ns = seq;

    TEST_ASSERT_GE(seq_with_ns.size(), 10)
    seq_with_ns[seq_with_ns.size() / 2] = 'N';
    seq_with_ns[seq_with_ns.size() / 2 + 1] = 'N';
    unsigned k = (seq.size() - 2) / 2 - 1;
    btllib::BiHashDirectional bihash(seq_with_ns, 3, k, "CT");

    std::vector<uint64_t> positions;
    for (size_t i = 0; i < seq_with_ns.size() / 2 - k + 1; i++) {
      positions.push_back(i);
    }
    for (size_t i = seq_with_ns.size() / 2 + 2; i < seq_with_ns.size() - k + 1;
         i++) {
      positions.push_back(i);
    }

    size_t i = 0;
    while (bihash.roll()) {
      TEST_ASSERT_EQ(bihash.get_pos(), positions[i])
      i++;
    }
    TEST_ASSERT_EQ(positions.size(), i)
  }

  {
    PRINT_TEST_NAME("base subititution - CT Mode")

    std::string seq = "ACGTACACTGGACTGAGTCTAA";
    std::string sub = "ACGCGCACTGGACTGAGTCTAA";

    btllib::BiHashDirectional bihash(seq, 3, seq.size(), "CT");
    btllib::BiHashDirectional bihash_subbed(sub, 3, sub.size(), "CT");

    bihash.roll();
    bihash.sub({ 3, 4 }, { 'C', 'G' });
    bihash_subbed.roll();
    TEST_ASSERT_EQ(bihash.get_hash_num(), bihash_subbed.get_hash_num());
    size_t i;
    for (i = 0; i < bihash.get_hash_num(); ++i) {
      TEST_ASSERT_EQ(bihash.hashes()[i], bihash_subbed.hashes()[i]);
    }
    TEST_ASSERT_EQ(i, 3);
  }

  {
    PRINT_TEST_NAME("base subititution - GA Mode")

    std::string seq = "ACGTACACTGGACTGAGTCTAA";
    std::string sub = "ACGCGCACTGGACTGAGTCTAA";

    btllib::BiHashDirectional bihash(seq, 3, seq.size(), "GA");
    btllib::BiHashDirectional bihash_subbed(sub, 3, sub.size(), "GA");

    bihash.roll();
    bihash.sub({ 3, 4 }, { 'C', 'G' });
    bihash_subbed.roll();
    TEST_ASSERT_EQ(bihash.get_hash_num(), bihash_subbed.get_hash_num());
    size_t i;
    for (i = 0; i < bihash.get_hash_num(); ++i) {
      TEST_ASSERT_EQ(bihash.hashes()[i], bihash_subbed.hashes()[i]);
    }
    TEST_ASSERT_EQ(i, 3);
  }

  {
    PRINT_TEST_NAME("Methylation Module Tests")

    std::string seq = "ACCGAA";
    std::string seq_no_meth = "ACTGAA";
    std::string rc_seq = "TTCGGT";
    std::string rc_seq_no_meth = "TTCAAT";

    btllib::BiHashDirectional bihash(seq, 3, seq.size(), "CT");
    btllib::BiHashDirectional bihash_no_meth(
      seq_no_meth, 3, seq_no_meth.size(), "CT");
    btllib::BiHashDirectional bihash_rc(rc_seq, 3, rc_seq.size(), "GA");
    btllib::BiHashDirectional bihash_rc_no_meth(
      rc_seq_no_meth, 3, rc_seq_no_meth.size(), "GA");

    bihash.roll();
    bihash_no_meth.roll();
    bihash_rc.roll();
    bihash_rc_no_meth.roll();

    TEST_ASSERT_EQ(bihash.get_hash_num(), bihash_no_meth.get_hash_num());
    TEST_ASSERT_EQ(bihash.get_hash_num(), bihash_rc.get_hash_num());
    TEST_ASSERT_EQ(bihash.get_hash_num(), bihash_rc_no_meth.get_hash_num());

    size_t h = bihash.get_hash_num();
    TEST_ASSERT_EQ(h, 3);

    TEST_ASSERT_ARRAY_EQ(bihash.hashes(), bihash_no_meth.hashes(), h);
    TEST_ASSERT_ARRAY_EQ(bihash.hashes(), bihash_rc.hashes(), h);
    TEST_ASSERT_ARRAY_EQ(bihash.hashes(), bihash_rc_no_meth.hashes(), h);

    TEST_ASSERT_EQ(bihash.is_methylated(), bihash_rc.is_methylated());
    TEST_ASSERT_NE(bihash.is_methylated(), bihash_no_meth.is_methylated());
    TEST_ASSERT_NE(bihash_rc.is_methylated(),
                   bihash_rc_no_meth.is_methylated());
    TEST_ASSERT_NE(bihash.is_forward_higher(), bihash_rc.is_forward_higher());
  }

  return 0;
}
