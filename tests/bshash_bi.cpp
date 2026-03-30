#include "btllib/bshash.hpp"
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
    PRINT_TEST_NAME("k-mer rolling - CT Mode - No Mutation")

    std::string seq = "AGTCAGTCAGTCAG";
    unsigned h = 3;
    unsigned k = 6;

    btllib::BsHashBi bshash(seq, h, k);
    std::vector<uint64_t*> hashes;
    uint64_t fwd_hash = 0;
    uint64_t final_fwd_hash = 0;
    uint64_t rev_hash = 0;
    uint64_t final_rev_hash = 0;

    while (bshash.roll()) {
      if (fwd_hash == 0) {
        fwd_hash = bshash.get_forward_hash();
        rev_hash = bshash.get_reverse_hash();
      }
      final_fwd_hash = bshash.get_forward_hash();
      final_rev_hash = bshash.get_reverse_hash();
      uint64_t* h_vals = new uint64_t[h];
      std::copy(bshash.hashes(), bshash.hashes() + h, h_vals);
      hashes.push_back(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1);
    TEST_ASSERT_EQ(fwd_hash, final_fwd_hash);
    TEST_ASSERT_EQ(rev_hash, final_rev_hash);
    TEST_ASSERT_ARRAY_EQ(hashes.front(), hashes.back(), h);
  }

  {
    PRINT_TEST_NAME("k-mer rolling - GA Mode - No Mutation")

    std::string seq = "AGTCAGTCAGTCAG";
    unsigned h = 3;
    unsigned k = 6;

    btllib::BsHashBi bshash(seq, h, k);
    std::vector<uint64_t*> hashes;
    uint64_t fwd_hash = 0;
    uint64_t final_fwd_hash = 0;
    uint64_t rev_hash = 0;
    uint64_t final_rev_hash = 0;

    while (bshash.roll()) {
      if (fwd_hash == 0) {
        fwd_hash = bshash.get_forward_hash();
        rev_hash = bshash.get_reverse_hash();
      }
      final_fwd_hash = bshash.get_forward_hash();
      final_rev_hash = bshash.get_reverse_hash();
      uint64_t* h_vals = new uint64_t[h];
      std::copy(bshash.hashes(), bshash.hashes() + h, h_vals);
      hashes.push_back(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1);
    TEST_ASSERT_EQ(fwd_hash, final_fwd_hash);
    TEST_ASSERT_EQ(rev_hash, final_rev_hash);
    TEST_ASSERT_ARRAY_EQ(hashes.front(), hashes.back(), h);
  }

  {
    PRINT_TEST_NAME("k-mer rolling - (CT Bi)")

    std::string seq = "AGTCAGTCAGTTAG";
    unsigned h = 3;
    unsigned k = 6;

    btllib::BsHashBi bshash(seq, h, k);
    std::vector<uint64_t*> hashes;
    uint64_t fwd_hash = 0;
    uint64_t final_fwd_hash = 0;
    uint64_t rev_hash = 0;
    uint64_t final_rev_hash = 0;

    while (bshash.roll()) {
      if (fwd_hash == 0) {
        fwd_hash = bshash.get_forward_hash();
        rev_hash = bshash.get_reverse_hash();
      }
      final_fwd_hash = bshash.get_forward_hash();
      final_rev_hash = bshash.get_reverse_hash();
      uint64_t* h_vals = new uint64_t[h];
      std::copy(bshash.hashes(), bshash.hashes() + h, h_vals);
      hashes.push_back(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1);
    TEST_ASSERT_EQ(fwd_hash, final_fwd_hash);
    TEST_ASSERT_EQ(rev_hash, final_rev_hash);
    TEST_ASSERT_ARRAY_EQ(hashes.front(), hashes.back(), h);
  }

  {
    PRINT_TEST_NAME("k-mer rolling - (GA Bi)")

    std::string seq = "AGTCAGTCAATCAA";
    unsigned h = 3;
    unsigned k = 6;

    btllib::BsHashBi bshash(seq, h, k);
    std::vector<uint64_t*> hashes;
    uint64_t fwd_hash = 0;
    uint64_t final_fwd_hash = 0;
    uint64_t rev_hash = 0;
    uint64_t final_rev_hash = 0;

    while (bshash.roll()) {
      if (fwd_hash == 0) {
        fwd_hash = bshash.get_forward_hash();
        rev_hash = bshash.get_reverse_hash();
      }
      final_fwd_hash = bshash.get_forward_hash();
      final_rev_hash = bshash.get_reverse_hash();
      uint64_t* h_vals = new uint64_t[h];
      std::copy(bshash.hashes(), bshash.hashes() + h, h_vals);
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

    btllib::BsHashBi bshash(seq, 3, seq.size() - 2);
    /* 19-mers of kmer*/
    std::string kmer1 = seq.substr(0, 22);
    std::string kmer2 = seq.substr(1, 22);
    std::string kmer3 = seq.substr(2, 22);

    btllib::BsHashBi bshash_vector[] = {
      btllib::BsHashBi(
        kmer1, bshash.get_hash_num(), kmer1.size()),
      btllib::BsHashBi(
        kmer2, bshash.get_hash_num(), kmer2.size()),
      btllib::BsHashBi(
        kmer3, bshash.get_hash_num(), kmer3.size())
    };

    size_t i;
    for (i = 0; bshash.roll() && bshash_vector[i].roll(); ++i) {
      for (size_t j = 0; j < bshash.get_hash_num(); ++j) {
        TEST_ASSERT_EQ(bshash.hashes()[j], bshash_vector[i].hashes()[j]);
      }
    }
    TEST_ASSERT_EQ(i, 3);
  }

  {
    PRINT_TEST_NAME("k-mer rolling vs. base hash values - GA Mode")

    std::string seq = "ACGTACACTGGACTGAGTCTATCG";

    btllib::BsHashBi bshash(seq, 3, seq.size() - 2);
    /* 19-mers of kmer*/
    std::string kmer1 = seq.substr(0, 22);
    std::string kmer2 = seq.substr(1, 22);
    std::string kmer3 = seq.substr(2, 22);

    btllib::BsHashBi bshash_vector[] = {
      btllib::BsHashBi(
        kmer1, bshash.get_hash_num(), kmer1.size()),
      btllib::BsHashBi(
        kmer2, bshash.get_hash_num(), kmer2.size()),
      btllib::BsHashBi(
        kmer3, bshash.get_hash_num(), kmer3.size())
    };

    size_t i;
    for (i = 0; bshash.roll() && bshash_vector[i].roll(); ++i) {
      for (size_t j = 0; j < bshash.get_hash_num(); ++j) {
        TEST_ASSERT_EQ(bshash.hashes()[j], bshash_vector[i].hashes()[j]);
      }
    }
    TEST_ASSERT_EQ(i, 3);
  }

  {
    PRINT_TEST_NAME("canonical hashing")

    std::string seq_f = "ACGTACACTGGACTGAGTCTAA";
    std::string seq_r = "TTAGACTCAGTCCAGTGTACGT";
    unsigned h = 3;

    btllib::BsHashBi bshash_f(seq_f, h, seq_f.size());
    btllib::BsHashBi bshash_r(seq_r, h, seq_r.size());

    bshash_f.roll();
    bshash_r.roll();
    TEST_ASSERT_EQ(bshash_f.get_hash_num(), bshash_r.get_hash_num())
    TEST_ASSERT_ARRAY_EQ(bshash_f.hashes(), bshash_r.hashes(), h)
  }

  {
    PRINT_TEST_NAME("canonical hashing - Reverse")

    std::string seq_f = "ACGTACACTGGACTGAGTCTAA";
    std::string seq_r = "TTAGACTCAGTCCAGTGTACGT";
    unsigned h = 3;

    btllib::BsHashBi bshash_f(seq_f, h, seq_f.size());
    btllib::BsHashBi bshash_r(seq_r, h, seq_r.size());

    bshash_f.roll();
    bshash_r.roll();
    TEST_ASSERT_EQ(bshash_f.get_hash_num(), bshash_r.get_hash_num())
    TEST_ASSERT_ARRAY_EQ(bshash_f.hashes(), bshash_r.hashes(), h)
  }

  {
    PRINT_TEST_NAME("k-mer back rolling - CT Mode")

    std::string seq = "ACTAGACTG";
    unsigned h = 3;
    unsigned k = 6;

    btllib::BsHashBi bshash(seq, h, k);
    std::stack<uint64_t*> hashes;

    while (bshash.roll()) {
      uint64_t* h_vals = new uint64_t[h];
      std::copy(bshash.hashes(), bshash.hashes() + h, h_vals);
      hashes.push(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1)

    do {
      TEST_ASSERT_ARRAY_EQ(bshash.hashes(), hashes.top(), h)
      hashes.pop();
    } while (bshash.roll_back());
  }

  {
    PRINT_TEST_NAME("k-mer back rolling - GA Mode")

    std::string seq = "ACTAGACTG";
    unsigned h = 3;
    unsigned k = 6;

    btllib::BsHashBi bshash(seq, h, k);
    std::stack<uint64_t*> hashes;

    while (bshash.roll()) {
      uint64_t* h_vals = new uint64_t[h];
      std::copy(bshash.hashes(), bshash.hashes() + h, h_vals);
      hashes.push(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1)

    do {
      TEST_ASSERT_ARRAY_EQ(bshash.hashes(), hashes.top(), h)
      hashes.pop();
    } while (bshash.roll_back());
  }

  {
    PRINT_TEST_NAME("k-mer peeking - CT Mode")

    std::string seq = "ACTGATCAG";
    unsigned h = 3;
    unsigned k = 6;

    btllib::BsHashBi bshash(seq, h, k);
    bshash.roll();

    size_t steps = 3;
    while (steps--) {
      bshash.peek();
      uint64_t* h_peek = new uint64_t[h];
      std::copy(bshash.hashes(), bshash.hashes() + h, h_peek);
      bshash.peek(seq[bshash.get_pos() + k]);
      TEST_ASSERT_ARRAY_EQ(bshash.hashes(), h_peek, h);
      bshash.roll();
      TEST_ASSERT_ARRAY_EQ(bshash.hashes(), h_peek, h);
    }
  }

  {
    PRINT_TEST_NAME("k-mer peeking - GA Mode")

    std::string seq = "ACTGATCAG";
    unsigned h = 3;
    unsigned k = 6;

    btllib::BsHashBi bshash(seq, h, k);
    bshash.roll();

    size_t steps = 3;
    while (steps--) {
      bshash.peek();
      uint64_t* h_peek = new uint64_t[h];
      std::copy(bshash.hashes(), bshash.hashes() + h, h_peek);
      bshash.peek(seq[bshash.get_pos() + k]);
      TEST_ASSERT_ARRAY_EQ(bshash.hashes(), h_peek, h);
      bshash.roll();
      TEST_ASSERT_ARRAY_EQ(bshash.hashes(), h_peek, h);
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
    btllib::BsHashBi bshash(seq_with_ns, 3, k);

    std::vector<uint64_t> positions;
    for (size_t i = 0; i < seq_with_ns.size() / 2 - k + 1; i++) {
      positions.push_back(i);
    }
    for (size_t i = seq_with_ns.size() / 2 + 2; i < seq_with_ns.size() - k + 1;
         i++) {
      positions.push_back(i);
    }

    size_t i = 0;
    while (bshash.roll()) {
      TEST_ASSERT_EQ(bshash.get_pos(), positions[i])
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
    btllib::BsHashBi bshash(seq_with_ns, 3, k);

    std::vector<uint64_t> positions;
    for (size_t i = 0; i < seq_with_ns.size() / 2 - k + 1; i++) {
      positions.push_back(i);
    }
    for (size_t i = seq_with_ns.size() / 2 + 2; i < seq_with_ns.size() - k + 1;
         i++) {
      positions.push_back(i);
    }

    size_t i = 0;
    while (bshash.roll()) {
      TEST_ASSERT_EQ(bshash.get_pos(), positions[i])
      i++;
    }
    TEST_ASSERT_EQ(positions.size(), i)
  }

  {
    PRINT_TEST_NAME("base substitution - CT Mode")

    std::string seq = "ACGTACACTGGACTGAGTCTAA";
    std::string sub = "ACGCGCACTGGACTGAGTCTAA";

    btllib::BsHashBi bshash(seq, 3, seq.size());
    btllib::BsHashBi bshash_subbed(sub, 3, sub.size());

    bshash.roll();
    bshash.sub({ 3, 4 }, { 'C', 'G' });
    bshash_subbed.roll();
    TEST_ASSERT_EQ(bshash.get_hash_num(), bshash_subbed.get_hash_num());
    size_t i;
    for (i = 0; i < bshash.get_hash_num(); ++i) {
      TEST_ASSERT_EQ(bshash.hashes()[i], bshash_subbed.hashes()[i]);
    }
    TEST_ASSERT_EQ(i, 3);
  }

  {
    PRINT_TEST_NAME("base substitution - GA Mode")

    std::string seq = "ACGTACACTGGACTGAGTCTAA";
    std::string sub = "ACGCGCACTGGACTGAGTCTAA";

    btllib::BsHashBi bshash(seq, 3, seq.size());
    btllib::BsHashBi bshash_subbed(sub, 3, sub.size());

    bshash.roll();
    bshash.sub({ 3, 4 }, { 'C', 'G' });
    bshash_subbed.roll();
    TEST_ASSERT_EQ(bshash.get_hash_num(), bshash_subbed.get_hash_num());
    size_t i;
    for (i = 0; i < bshash.get_hash_num(); ++i) {
      TEST_ASSERT_EQ(bshash.hashes()[i], bshash_subbed.hashes()[i]);
    }
    TEST_ASSERT_EQ(i, 3);
  }

  {
    PRINT_TEST_NAME("Methylation Module Tests")

    std::string seq = "ACCGAA";
    std::string seq_no_meth = "ACTGAA";
    std::string rc_seq = "TTCGGT";
    std::string rc_seq_no_meth = "TTCAAT";

    btllib::BsHashBi bshash(seq, 3, seq.size());
    btllib::BsHashBi bshash_no_meth(
      seq_no_meth, 3, seq_no_meth.size());
    btllib::BsHashBi bshash_rc(rc_seq, 3, rc_seq.size());
    btllib::BsHashBi bshash_rc_no_meth(
      rc_seq_no_meth, 3, rc_seq_no_meth.size());

    bshash.roll();
    bshash_no_meth.roll();
    bshash_rc.roll();
    bshash_rc_no_meth.roll();

    TEST_ASSERT_EQ(bshash.get_hash_num(), bshash_no_meth.get_hash_num());
    TEST_ASSERT_EQ(bshash.get_hash_num(), bshash_rc.get_hash_num());
    TEST_ASSERT_EQ(bshash.get_hash_num(), bshash_rc_no_meth.get_hash_num());

    size_t h = bshash.get_hash_num();
    TEST_ASSERT_EQ(h, 3);

    TEST_ASSERT_ARRAY_EQ(bshash.hashes(), bshash_no_meth.hashes(), h);
    TEST_ASSERT_ARRAY_EQ(bshash.hashes(), bshash_rc.hashes(), h);
    TEST_ASSERT_ARRAY_EQ(bshash.hashes(), bshash_rc_no_meth.hashes(), h);

    TEST_ASSERT_EQ(bshash.is_methylated(), bshash_rc.is_methylated());
    TEST_ASSERT_NE(bshash.is_methylated(), bshash_no_meth.is_methylated());
    TEST_ASSERT_NE(bshash_rc.is_methylated(),
                   bshash_rc_no_meth.is_methylated());
    TEST_ASSERT_NE(bshash.is_forward_higher(), bshash_rc.is_forward_higher());
  }

  return 0;
}
