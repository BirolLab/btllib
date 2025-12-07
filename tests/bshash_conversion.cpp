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

  /*{
    PRINT_TEST_NAME("k-mer hash values")

    std::string seq = "ACATGCATGCA";
    const unsigned k = 5;
    const unsigned h = 3;

    const std::vector<std::array<uint64_t, h>> hashes = {
      { 0x38cc00f940aebdae, 0xab7e1b110e086fc6, 0x11a1818bcfdd553 },
      { 0x603a48c5a11c794a, 0xe66016e61816b9c4, 0xc5b13cb146996ffe }
    };

    btllib::NtHash nthash(seq, h, k);
    nthash.roll();
    btllib::BlindNtHash blind(seq.data(), h, k);

    for (const auto& h_vals : hashes) {
      nthash.roll();
      TEST_ASSERT_ARRAY_EQ(h_vals, nthash.hashes(), h);
      blind.roll(seq[blind.get_pos() + k]);
      TEST_ASSERT_ARRAY_EQ(h_vals, blind.hashes(), h);
    }
  }*/

  {
    PRINT_TEST_NAME("k-mer rolling")

    std::string seq = "AGTCAGTCAGTCA";
    unsigned h = 3;
    unsigned k = 5;
    //AGTCA
    //TGACT

    btllib::BSHashConversion nthash(seq, h, k, "CT");
    /*nthash.roll();
    nthash.roll();
    std::cerr << "CT forrward: " << nthash.get_forward_hash() << std::endl;
    std::cerr << "CT reverse: " << nthash.get_reverse_hash() << std::endl;
    btllib::BSHashConversion nthash2("GTCAG", h, k, "CT");
    nthash2.roll();
    std::cerr << "CT forrward: " << nthash2.get_forward_hash() << std::endl;
    std::cerr << "CT reverse: " << nthash2.get_reverse_hash() << std::endl;*/
    std::vector<uint64_t*> hashes;
    uint64_t fwd_hash = 0;
    uint64_t final_fwd_hash = 0;
    uint64_t rev_hash = 0;
    uint64_t final_rev_hash = 0;

    while (nthash.roll()) {
      if (fwd_hash == 0) {
        fwd_hash = nthash.get_forward_hash();
        rev_hash = nthash.get_reverse_hash();
      }
      final_fwd_hash = nthash.get_forward_hash();
      final_rev_hash = nthash.get_reverse_hash();
      uint64_t* h_vals = new uint64_t[h];
      std::copy(nthash.hashes(), nthash.hashes() + h, h_vals);
      hashes.push_back(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1);

    // check same hash value for identical k-mers (first and last)
    TEST_ASSERT_EQ(fwd_hash, final_fwd_hash);
    TEST_ASSERT_EQ(rev_hash, final_rev_hash);
    TEST_ASSERT_ARRAY_EQ(hashes.front(), hashes.back(), h);
  }

  {
    PRINT_TEST_NAME("k-mer rolling - (CT Conversion)")

    std::string seq = "AGTCAGTCAGTTA";
    unsigned h = 3;
    unsigned k = 5;
    //AGTCA
    //TGACT

    btllib::BSHashConversion nthash(seq, h, k, "CT");
    /*nthash.roll();
    nthash.roll();
    std::cerr << "CT forrward: " << nthash.get_forward_hash() << std::endl;
    std::cerr << "CT reverse: " << nthash.get_reverse_hash() << std::endl;
    btllib::BSHashConversion nthash2("GTCAG", h, k, "CT");
    nthash2.roll();
    std::cerr << "CT forrward: " << nthash2.get_forward_hash() << std::endl;
    std::cerr << "CT reverse: " << nthash2.get_reverse_hash() << std::endl;*/
    std::vector<uint64_t*> hashes;
    uint64_t fwd_hash = 0;
    uint64_t final_fwd_hash = 0;
    uint64_t rev_hash = 0;
    uint64_t final_rev_hash = 0;

    while (nthash.roll()) {
      if (fwd_hash == 0) {
        fwd_hash = nthash.get_forward_hash();
        rev_hash = nthash.get_reverse_hash();
      }
      final_fwd_hash = nthash.get_forward_hash();
      final_rev_hash = nthash.get_reverse_hash();
      uint64_t* h_vals = new uint64_t[h];
      std::copy(nthash.hashes(), nthash.hashes() + h, h_vals);
      hashes.push_back(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1);

    // check same hash value for identical k-mers (first and last)
    TEST_ASSERT_EQ(fwd_hash, final_fwd_hash);
    TEST_ASSERT_EQ(rev_hash, final_rev_hash);
    TEST_ASSERT_ARRAY_EQ(hashes.front(), hashes.back(), h);
  }


    {
    PRINT_TEST_NAME("k-mer rolling - (GA Conversion)")

    std::string seq = "AGTCAGTCAATCA";
    unsigned h = 3;
    unsigned k = 5;
    //AGTCA
    //TGACT

    btllib::BSHashConversion nthash(seq, h, k, "GA");
    /*nthash.roll();
    nthash.roll();
    std::cerr << "CT forrward: " << nthash.get_forward_hash() << std::endl;
    std::cerr << "CT reverse: " << nthash.get_reverse_hash() << std::endl;
    btllib::BSHashConversion nthash2("GTCAG", h, k, "CT");
    nthash2.roll();
    std::cerr << "CT forrward: " << nthash2.get_forward_hash() << std::endl;
    std::cerr << "CT reverse: " << nthash2.get_reverse_hash() << std::endl;*/
    std::vector<uint64_t*> hashes;
    uint64_t fwd_hash = 0;
    uint64_t final_fwd_hash = 0;
    uint64_t rev_hash = 0;
    uint64_t final_rev_hash = 0;

    while (nthash.roll()) {
      if (fwd_hash == 0) {
        fwd_hash = nthash.get_forward_hash();
        rev_hash = nthash.get_reverse_hash();
      }
      final_fwd_hash = nthash.get_forward_hash();
      final_rev_hash = nthash.get_reverse_hash();
      uint64_t* h_vals = new uint64_t[h];
      std::copy(nthash.hashes(), nthash.hashes() + h, h_vals);
      hashes.push_back(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1);

    // check same hash value for identical k-mers (first and last)
    TEST_ASSERT_EQ(fwd_hash, final_fwd_hash);
    TEST_ASSERT_EQ(rev_hash, final_rev_hash);
    TEST_ASSERT_ARRAY_EQ(hashes.front(), hashes.back(), h);
  }

  {
    PRINT_TEST_NAME("k-mer rolling vs. base hash values")

    std::string seq = "ACGTACACTGGACTGAGTCTA";

    btllib::BSHashConversion nthash(seq, 3, seq.size() - 2, "CT");
    /* 19-mers of kmer*/
    std::string kmer1 = seq.substr(0, 19);
    std::string kmer2 = seq.substr(1, 19);
    std::string kmer3 = seq.substr(2, 19);

    btllib::BSHashConversion nthash_vector[] = {
      btllib::BSHashConversion(kmer1, nthash.get_hash_num(), kmer1.size(), "CT"),
      btllib::BSHashConversion(kmer2, nthash.get_hash_num(), kmer2.size(), "CT"),
      btllib::BSHashConversion(kmer3, nthash.get_hash_num(), kmer3.size(), "CT")
    };

    size_t i;
    for (i = 0; nthash.roll() && nthash_vector[i].roll(); ++i) {
      for (size_t j = 0; j < nthash.get_hash_num(); ++j) {
        TEST_ASSERT_EQ(nthash.hashes()[j], nthash_vector[i].hashes()[j]);
      }
    }
    TEST_ASSERT_EQ(i, 3);
  }

  {
    PRINT_TEST_NAME("canonical hashing")

    std::string seq_f = "ACGTACACTGGACTGAGTCTA";
    std::string seq_r = "TAGACTCAGTCCAGTGTACGT";
    unsigned h = 3;

    btllib::BSHashConversion nthash_f(seq_f, h, seq_f.size(), "CT");
    btllib::BSHashConversion nthash_r(seq_r, h, seq_r.size(), "GA");

    nthash_f.roll();
    nthash_r.roll();
    TEST_ASSERT_EQ(nthash_f.get_hash_num(), nthash_r.get_hash_num())
    TEST_ASSERT_ARRAY_EQ(nthash_f.hashes(), nthash_r.hashes(), h)
  }

  {
    PRINT_TEST_NAME("k-mer back rolling")

    std::string seq = "ACTAGCTG";
    unsigned h = 3;
    unsigned k = 5;

    btllib::BSHashConversion nthash(seq, h, k, "CT");
    std::stack<uint64_t*> hashes;

    while (nthash.roll()) {
      uint64_t* h_vals = new uint64_t[h];
      std::copy(nthash.hashes(), nthash.hashes() + h, h_vals);
      hashes.push(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1)

    do {
      TEST_ASSERT_ARRAY_EQ(nthash.hashes(), hashes.top(), h)
      hashes.pop();
    } while (nthash.roll_back());
  }

  {
    PRINT_TEST_NAME("k-mer peeking")

    std::string seq = "ACTGATCAG";
    unsigned h = 3;
    unsigned k = 5;

    btllib::BSHashConversion nthash(seq, h, k, "CT");
    nthash.roll();

    size_t steps = 3;
    while (steps--) {
      nthash.peek();
      uint64_t* h_peek = new uint64_t[h];
      std::copy(nthash.hashes(), nthash.hashes() + h, h_peek);
      nthash.peek(seq[nthash.get_pos() + k]);
      TEST_ASSERT_ARRAY_EQ(nthash.hashes(), h_peek, h);
      nthash.roll();
      TEST_ASSERT_ARRAY_EQ(nthash.hashes(), h_peek, h);
    }
  }

  {
    PRINT_TEST_NAME("skipping Ns")

    std::string seq = "ACGTACACTGGACTGAGTCTAA";
    std::string seq_with_ns = seq;

    TEST_ASSERT_GE(seq_with_ns.size(), 10)
    seq_with_ns[seq_with_ns.size() / 2] = 'N';
    seq_with_ns[seq_with_ns.size() / 2 + 1] = 'N';
    unsigned k = (seq.size() - 2) / 2 - 1;
    btllib::BSHashConversion nthash(seq_with_ns, 3, k, "CT");

    std::vector<uint64_t> positions;
    for (size_t i = 0; i < seq_with_ns.size() / 2 - k + 1; i++) {
      positions.push_back(i);
    }
    for (size_t i = seq_with_ns.size() / 2 + 2; i < seq_with_ns.size() - k + 1;
         i++) {
      positions.push_back(i);
    }

    size_t i = 0;
    while (nthash.roll()) {
      TEST_ASSERT_EQ(nthash.get_pos(), positions[i])
      i++;
    }
    TEST_ASSERT_EQ(positions.size(), i)
  }

  {
    PRINT_TEST_NAME("base substitution")

    std::string seq = "ACGTACACTGGACTGAGTCTA";
    std::string sub = "ACGCGCACTGGACTGAGTCTA";

    btllib::BSHashConversion nthash(seq, 3, seq.size(), "CT");
    btllib::BSHashConversion nthash_subbed(sub, 3, sub.size(), "CT");

    nthash.roll();
    nthash.sub({ 3, 4 }, { 'C', 'G' });
    nthash_subbed.roll();
    TEST_ASSERT_EQ(nthash.get_hash_num(), nthash_subbed.get_hash_num());
    size_t i;
    for (i = 0; i < nthash.get_hash_num(); ++i) {
      TEST_ASSERT_EQ(nthash.hashes()[i], nthash_subbed.hashes()[i]);
    }
    TEST_ASSERT_EQ(i, 3);
  }

  

  return 0;
}
