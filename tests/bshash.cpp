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
    PRINT_TEST_NAME("CG k-mer rolling (64-mer base)")

    std::string first34 = "AAACAGAT"
                          "CACCCGCT"
                          "GAGCGGGT"
                          "TACTGTGTAA";

    std::string seq = first34 + first34;
    unsigned h = 3;
    unsigned k = 34;

    btllib::BsHash bshash(seq, h, k, "CG");
    std::vector<uint64_t*> hashes;

    while (bshash.roll()) {
      uint64_t* h_vals = new uint64_t[h];
      std::copy(bshash.hashes(), bshash.hashes() + h, h_vals);
      hashes.push_back(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1);
    TEST_ASSERT_ARRAY_EQ(hashes.front(), hashes.back(), h);

    const std::vector<std::vector<std::string>> GROUPS = {
      { "AA", "GA" },
      { "AC", "AT", "GC", "GT" },
      { "AG" },
      { "GG" },
      { "CA", "CG", "TG" },
      { "CC" },
      { "CT" },
      { "TA" },
      { "TC", "TT" }
    };

    auto mutate_by_shift = [&](const std::string& s, int shift) {
      std::string out;
      for (size_t i = 0; i < s.size(); i += 2) {
        std::string dimer = s.substr(i, 2);
        bool done = false;
        for (const auto& g : GROUPS) {
          auto it = std::find(g.begin(), g.end(), dimer);
          if (it != g.end()) {
            out += g[(std::distance(g.begin(), it) + shift) % g.size()];
            done = true;
            break;
          }
        }
        if (!done)
          out += dimer;
      }
      return out;
    };

    auto compute_hashes = [&](const std::string& s) {
      btllib::BsHash bh(s, h, k, "CG");
      std::vector<uint64_t*> out;
      while (bh.roll()) {
        uint64_t* hv = new uint64_t[h];
        std::copy(bh.hashes(), bh.hashes() + h, hv);
        out.push_back(hv);
      }
      return out;
    };

    PRINT_TEST_NAME("CG k-mer rolling (degeneracy shift +1)")

    {
      std::string seq_shift = first34 + mutate_by_shift(first34, 1);
      auto h1 = compute_hashes(seq);
      auto h2 = compute_hashes(seq_shift);

      TEST_ASSERT_EQ(h1.size(), h2.size());
      TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
      for (unsigned i = 0; i < h1.size(); i = i + 2) {
        for (unsigned j = 0; j < h; ++j) {
          TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
        }
      }
    }

    PRINT_TEST_NAME("CG k-mer rolling (degeneracy shift +2)")

    {
      std::string seq_shift = first34 + mutate_by_shift(first34, 2);
      auto h1 = compute_hashes(seq);
      auto h2 = compute_hashes(seq_shift);

      TEST_ASSERT_EQ(h1.size(), h2.size());
      TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
      for (unsigned i = 0; i < h1.size(); i = i + 2) {
        for (unsigned j = 0; j < h; ++j) {
          TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
        }
      }
    }

    PRINT_TEST_NAME("CG k-mer rolling (degeneracy shift +3)")

    {
      std::string seq_shift = first34 + mutate_by_shift(first34, 3);
      auto h1 = compute_hashes(seq);
      auto h2 = compute_hashes(seq_shift);

      TEST_ASSERT_EQ(h1.size(), h2.size());
      TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
      for (unsigned i = 0; i < h1.size(); i = i + 2) {
        for (unsigned j = 0; j < h; ++j) {
          TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
        }
      }
    }
  }

  {

    PRINT_TEST_NAME("CG k-mer rolling (C→T mutation)")

    std::string first34 = "ATGCGTAGGTCGATGACGTTGAGCGTACGAGTAA";

    std::string seq = first34 + first34;
    unsigned h = 3;
    unsigned k = 34;

    btllib::BsHash bshash(seq, h, k, "CG");
    std::vector<uint64_t*> hashes;

    while (bshash.roll()) {
      uint64_t* h_vals = new uint64_t[h];
      std::copy(bshash.hashes(), bshash.hashes() + h, h_vals);
      hashes.push_back(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1);
    TEST_ASSERT_ARRAY_EQ(hashes.front(), hashes.back(), h);

    auto mutate_CT = [](const std::string& s) {
      std::string out = s;
      for (char& base : out) {
        if (base == 'C')
          base = 'T';
        else if (base == 'c')
          base = 't';
      }
      return out;
    };

    auto compute_hashes = [&](const std::string& s) {
      btllib::BsHash bh(s, h, k, "CG");
      std::vector<uint64_t*> out;
      while (bh.roll()) {
        uint64_t* hv = new uint64_t[h];
        std::copy(bh.hashes(), bh.hashes() + h, hv);
        out.push_back(hv);
      }
      return out;
    };

    PRINT_TEST_NAME("CG k-mer rolling (C→T forward check)")

    {
      std::string seq_shift = first34 + mutate_CT(first34);
      auto h1 = compute_hashes(seq);
      auto h2 = compute_hashes(seq_shift);
      std::cerr << seq << std::endl;
      std::cerr << seq_shift << std::endl;

      TEST_ASSERT_EQ(h1.size(), h2.size());
      TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);

      for (unsigned i = 0; i < h1.size(); i += 2) {
        std::cerr << i << std::endl;

        for (unsigned j = 0; j < h; ++j) {
          TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
        }
      }
    }
  }

  {

    PRINT_TEST_NAME("CG k-mer rolling (G→A mutation)")

    std::string first34 = "TACCGATACCTACGCCATACGTCATACCGTTAAA";

    std::string seq = first34 + first34;
    unsigned h = 3;
    unsigned k = 34;

    btllib::BsHash bshash(seq, h, k, "CG");
    std::vector<uint64_t*> hashes;

    while (bshash.roll()) {
      uint64_t* h_vals = new uint64_t[h];
      std::copy(bshash.hashes(), bshash.hashes() + h, h_vals);
      hashes.push_back(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1);
    TEST_ASSERT_ARRAY_EQ(hashes.front(), hashes.back(), h);

    auto mutate_GA = [](const std::string& s) {
      std::string out = s;
      for (char& base : out) {
        if (base == 'G')
          base = 'A';
        else if (base == 'g')
          base = 'a';
      }
      return out;
    };

    auto compute_hashes = [&](const std::string& s) {
      btllib::BsHash bh(s, h, k, "CG");
      std::vector<uint64_t*> out;
      while (bh.roll()) {
        uint64_t* hv = new uint64_t[h];
        std::copy(bh.hashes(), bh.hashes() + h, hv);
        out.push_back(hv);
      }
      return out;
    };

    PRINT_TEST_NAME("CG k-mer rolling (G→A forward check)")

    {
      std::string seq_shift = first34 + mutate_GA(first34);
      auto h1 = compute_hashes(seq);
      auto h2 = compute_hashes(seq_shift);

      TEST_ASSERT_EQ(h1.size(), h2.size());
      TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);

      for (unsigned i = 0; i < h1.size(); i += 2) {
        for (unsigned j = 0; j < h; ++j) {
          TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
        }
      }
    }
  }

  {

    PRINT_TEST_NAME("CC k-mer rolling (64-mer base)")

    std::string first34 = "AAACAGAT"
                          "CACCCGCT"
                          "GAGCGGGT"
                          "TACTGTGTAA";

    std::string seq = first34 + first34;
    unsigned h = 3;
    unsigned k = 34;

    btllib::BsHash bshash(seq, h, k, "CC");
    std::vector<uint64_t*> hashes;

    while (bshash.roll()) {
      uint64_t* h_vals = new uint64_t[h];
      std::copy(bshash.hashes(), bshash.hashes() + h, h_vals);
      hashes.push_back(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1);
    TEST_ASSERT_ARRAY_EQ(hashes.front(), hashes.back(), h);

    const std::vector<std::vector<std::string>> CC_GROUPS = {
      { "AA", "AG", "GA", "GG" },
      { "AC", "AT", "GC", "GT" },
      { "CA", "TA", "TG" },
      { "CC", "CT", "TC", "TT" },
      { "CG" }
    };

    auto mutate_by_shift = [&](const std::string& s, int shift) {
      std::string out;
      for (size_t i = 0; i < s.size(); i += 2) {
        std::string dimer = s.substr(i, 2);
        bool done = false;
        for (const auto& g : CC_GROUPS) {
          auto it = std::find(g.begin(), g.end(), dimer);
          if (it != g.end()) {
            out += g[(std::distance(g.begin(), it) + shift) % g.size()];
            done = true;
            break;
          }
        }
        if (!done)
          out += dimer;
      }
      return out;
    };

    auto compute_hashes = [&](const std::string& s) {
      btllib::BsHash bh(s, h, k, "CC");
      std::vector<uint64_t*> out;
      while (bh.roll()) {
        uint64_t* hv = new uint64_t[h];
        std::copy(bh.hashes(), bh.hashes() + h, hv);
        out.push_back(hv);
      }
      return out;
    };

    PRINT_TEST_NAME("CC k-mer rolling (degeneracy shift +1)")

    {
      std::string seq_shift = first34 + mutate_by_shift(first34, 1);
      auto h1 = compute_hashes(seq);
      auto h2 = compute_hashes(seq_shift);

      TEST_ASSERT_EQ(h1.size(), h2.size());
      TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
      for (unsigned i = 0; i < h1.size(); i = i + 2) {
        for (unsigned j = 0; j < h; ++j) {
          TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
        }
      }
    }

    PRINT_TEST_NAME("CC k-mer rolling (degeneracy shift +2)")

    {
      std::string seq_shift = first34 + mutate_by_shift(first34, 2);
      auto h1 = compute_hashes(seq);
      auto h2 = compute_hashes(seq_shift);

      TEST_ASSERT_EQ(h1.size(), h2.size());
      TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
      for (unsigned i = 0; i < h1.size(); i = i + 2) {
        for (unsigned j = 0; j < h; ++j) {
          TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
        }
      }
    }

    PRINT_TEST_NAME("CC k-mer rolling (degeneracy shift +3)")

    {
      std::string seq_shift = first34 + mutate_by_shift(first34, 3);
      auto h1 = compute_hashes(seq);
      auto h2 = compute_hashes(seq_shift);

      TEST_ASSERT_EQ(h1.size(), h2.size());
      TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
      for (unsigned i = 0; i < h1.size(); i = i + 2) {
        for (unsigned j = 0; j < h; ++j) {
          TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
        }
      }
    }
  }

  {

    PRINT_TEST_NAME("CT k-mer rolling (64-mer base)")

    std::string first34 = "AAACAGAT"
                          "CACCCGCT"
                          "GAGCGGGT"
                          "TACTGTGTAA";

    std::string seq = first34 + first34;
    unsigned h = 3;
    unsigned k = 34;

    btllib::BsHash bshash(seq, h, k, "CT");
    std::vector<uint64_t*> hashes;

    while (bshash.roll()) {
      uint64_t* h_vals = new uint64_t[h];
      std::copy(bshash.hashes(), bshash.hashes() + h, h_vals);
      hashes.push_back(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1);
    TEST_ASSERT_ARRAY_EQ(hashes.front(), hashes.back(), h);

    const std::vector<std::vector<std::string>> CT_GROUPS = {
      { "AT", "AC", "GC", "GT" },
      { "CA" },
      { "CG" },
      { "CT", "TC", "TT" },
      { "GA", "AA", "AG" },
      { "TA" },
      { "CC" },
      { "GG" },
      { "TG" }
    };

    auto mutate_by_shift = [&](const std::string& s, int shift) {
      std::string out;
      for (size_t i = 0; i < s.size(); i += 2) {
        std::string dimer = s.substr(i, 2);
        bool done = false;
        for (const auto& g : CT_GROUPS) {
          auto it = std::find(g.begin(), g.end(), dimer);
          if (it != g.end()) {
            out += g[(std::distance(g.begin(), it) + shift) % g.size()];
            done = true;
            break;
          }
        }
        if (!done)
          out += dimer;
      }
      return out;
    };

    auto compute_hashes = [&](const std::string& s) {
      btllib::BsHash bh(s, h, k, "CT");
      std::vector<uint64_t*> out;
      while (bh.roll()) {
        uint64_t* hv = new uint64_t[h];
        std::copy(bh.hashes(), bh.hashes() + h, hv);
        out.push_back(hv);
      }
      return out;
    };

    PRINT_TEST_NAME("CT k-mer rolling (degeneracy shift +1)")

    {
      std::string seq_shift = first34 + mutate_by_shift(first34, 1);
      auto h1 = compute_hashes(seq);
      auto h2 = compute_hashes(seq_shift);
      std::cerr << seq << std::endl;
      std::cerr << seq_shift << std::endl;

      TEST_ASSERT_EQ(h1.size(), h2.size());
      TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
      for (unsigned i = 0; i < h1.size(); i = i + 2) {
        std::cerr << i << std::endl;
        for (unsigned j = 0; j < h; ++j) {
          TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
        }
      }
    }

    PRINT_TEST_NAME("CT k-mer rolling (degeneracy shift +2)")

    {
      std::string seq_shift = first34 + mutate_by_shift(first34, 2);
      auto h1 = compute_hashes(seq);
      auto h2 = compute_hashes(seq_shift);

      TEST_ASSERT_EQ(h1.size(), h2.size());
      TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
      for (unsigned i = 0; i < h1.size(); i = i + 2) {
        for (unsigned j = 0; j < h; ++j) {
          TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
        }
      }
    }

    PRINT_TEST_NAME("CT k-mer rolling (degeneracy shift +3)")

    {
      std::string seq_shift = first34 + mutate_by_shift(first34, 3);
      auto h1 = compute_hashes(seq);
      auto h2 = compute_hashes(seq_shift);

      TEST_ASSERT_EQ(h1.size(), h2.size());
      TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
      for (unsigned i = 0; i < h1.size(); i = i + 2) {
        for (unsigned j = 0; j < h; ++j) {
          TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
        }
      }
    }
  }

  {

    PRINT_TEST_NAME("CA k-mer rolling (64-mer base)")

    std::string first34 = "AAACAGAT"
                          "CACCCGCT"
                          "GAGCGGGT"
                          "TACTGTGTAA";

    std::string seq = first34 + first34;
    unsigned h = 3;
    unsigned k = 34;

    btllib::BsHash bshash(seq, h, k, "CA");
    std::vector<uint64_t*> hashes;

    while (bshash.roll()) {
      uint64_t* h_vals = new uint64_t[h];
      std::copy(bshash.hashes(), bshash.hashes() + h, h_vals);
      hashes.push_back(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1);
    TEST_ASSERT_ARRAY_EQ(hashes.front(), hashes.back(), h);

    const std::vector<std::vector<std::string>> CA_GROUPS = {
      { "AA", "GA" },
      { "AC", "AT", "GC", "GT" },
      { "AG" },
      { "GG" },
      { "CA", "TA", "TG" },
      { "CC" },
      { "CT" },
      { "TT", "TC" },
      { "CG" }
    };

    auto mutate_by_shift = [&](const std::string& s, int shift) {
      std::string out;
      for (size_t i = 0; i < s.size(); i += 2) {
        std::string dimer = s.substr(i, 2);
        bool done = false;
        for (const auto& g : CA_GROUPS) {
          auto it = std::find(g.begin(), g.end(), dimer);
          if (it != g.end()) {
            out += g[(std::distance(g.begin(), it) + shift) % g.size()];
            done = true;
            break;
          }
        }
        if (!done)
          out += dimer;
      }
      return out;
    };

    auto compute_hashes = [&](const std::string& s) {
      btllib::BsHash bh(s, h, k, "CA");
      std::vector<uint64_t*> out;
      while (bh.roll()) {
        uint64_t* hv = new uint64_t[h];
        std::copy(bh.hashes(), bh.hashes() + h, hv);
        out.push_back(hv);
      }
      return out;
    };

    PRINT_TEST_NAME("CA k-mer rolling (degeneracy shift +1)")

    {
      std::string seq_shift = first34 + mutate_by_shift(first34, 1);
      auto h1 = compute_hashes(seq);
      auto h2 = compute_hashes(seq_shift);

      TEST_ASSERT_EQ(h1.size(), h2.size());
      TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
      for (unsigned i = 0; i < h1.size(); i = i + 2) {
        for (unsigned j = 0; j < h; ++j) {
          TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
        }
      }
    }

    PRINT_TEST_NAME("CA k-mer rolling (degeneracy shift +2)")

    {
      std::string seq_shift = first34 + mutate_by_shift(first34, 2);
      auto h1 = compute_hashes(seq);
      auto h2 = compute_hashes(seq_shift);

      TEST_ASSERT_EQ(h1.size(), h2.size());
      TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
      for (unsigned i = 0; i < h1.size(); i = i + 2) {
        for (unsigned j = 0; j < h; ++j) {
          TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
        }
      }
    }

    PRINT_TEST_NAME("CA k-mer rolling (degeneracy shift +3)")

    {
      std::string seq_shift = first34 + mutate_by_shift(first34, 3);
      auto h1 = compute_hashes(seq);
      auto h2 = compute_hashes(seq_shift);

      TEST_ASSERT_EQ(h1.size(), h2.size());
      TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
      for (unsigned i = 0; i < h1.size(); i = i + 2) {
        for (unsigned j = 0; j < h; ++j) {
          TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
        }
      }
    }
  }

  {
    PRINT_TEST_NAME("k-mer rolling vs. base hash values - CG")

    std::string seq = "ACGTACACTGGACTGAGTCT";

    btllib::BsHash bshash(seq, 3, seq.size() - 2, "CG");

    std::string kmer1 = seq.substr(0, 18);
    std::string kmer2 = seq.substr(1, 18);
    std::string kmer3 = seq.substr(2, 18);

    btllib::BsHash bshash_vector[] = {
      btllib::BsHash(kmer1, bshash.get_hash_num(), kmer1.size(), "CG"),
      btllib::BsHash(kmer2, bshash.get_hash_num(), kmer2.size(), "CG"),
      btllib::BsHash(kmer3, bshash.get_hash_num(), kmer3.size(), "CG")
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
    PRINT_TEST_NAME("k-mer rolling vs. base hash values - CC")

    std::string seq = "ACGTACACTGGACTGAGTCT";

    btllib::BsHash bshash(seq, 3, seq.size() - 2, "CC");

    std::string kmer1 = seq.substr(0, 18);
    std::string kmer2 = seq.substr(1, 18);
    std::string kmer3 = seq.substr(2, 18);

    btllib::BsHash bshash_vector[] = {
      btllib::BsHash(kmer1, bshash.get_hash_num(), kmer1.size(), "CC"),
      btllib::BsHash(kmer2, bshash.get_hash_num(), kmer2.size(), "CC"),
      btllib::BsHash(kmer3, bshash.get_hash_num(), kmer3.size(), "CC")
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
    PRINT_TEST_NAME("k-mer rolling vs. base hash values - CT")

    std::string seq = "ACGTACACTGGACTGAGTCT";

    btllib::BsHash bshash(seq, 3, seq.size() - 2, "CT");

    std::string kmer1 = seq.substr(0, 18);
    std::string kmer2 = seq.substr(1, 18);
    std::string kmer3 = seq.substr(2, 18);

    btllib::BsHash bshash_vector[] = {
      btllib::BsHash(kmer1, bshash.get_hash_num(), kmer1.size(), "CT"),
      btllib::BsHash(kmer2, bshash.get_hash_num(), kmer2.size(), "CT"),
      btllib::BsHash(kmer3, bshash.get_hash_num(), kmer3.size(), "CT")
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
    PRINT_TEST_NAME("k-mer rolling vs. base hash values - CA")

    std::string seq = "ACGTACACTGGACTGAGTCT";

    btllib::BsHash bshash(seq, 3, seq.size() - 2, "CA");

    std::string kmer1 = seq.substr(0, 18);
    std::string kmer2 = seq.substr(1, 18);
    std::string kmer3 = seq.substr(2, 18);

    btllib::BsHash bshash_vector[] = {
      btllib::BsHash(kmer1, bshash.get_hash_num(), kmer1.size(), "CA"),
      btllib::BsHash(kmer2, bshash.get_hash_num(), kmer2.size(), "CA"),
      btllib::BsHash(kmer3, bshash.get_hash_num(), kmer3.size(), "CA")
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
    PRINT_TEST_NAME("CG canonical hashing")

    std::string seq_f = "ACGTACGCGGGACGGAGTCGAA";
    std::string seq_r = "TTCGACTCCGTCCCGCGTACGT";
    unsigned h = 3;

    btllib::BsHash bshash_f(seq_f, h, seq_f.size(), "CG");
    btllib::BsHash bshash_r(seq_r, h, seq_r.size(), "CG");

    bshash_f.roll();
    bshash_r.roll();

    TEST_ASSERT_EQ(bshash_f.get_hash_num(), bshash_r.get_hash_num());
    TEST_ASSERT_ARRAY_EQ(bshash_f.hashes(), bshash_r.hashes(), h);
  }

  {
    PRINT_TEST_NAME("CA canonical hashing")

    std::string seq_f = "ACATACACAGGACAGAGTCAAA";
    std::string seq_r = "TTTGACTCTGTCCTGTGTATGT";
    unsigned h = 3;

    btllib::BsHash bshash_f(seq_f, h, seq_f.size(), "CA");
    btllib::BsHash bshash_r(seq_r, h, seq_r.size(), "CA");

    bshash_f.roll();
    bshash_r.roll();

    TEST_ASSERT_EQ(bshash_f.get_hash_num(), bshash_r.get_hash_num());
    TEST_ASSERT_ARRAY_EQ(bshash_f.hashes(), bshash_r.hashes(), h);
  }
  {
    PRINT_TEST_NAME("CC canonical hashing")

    std::string seq_f = "ACCTACCCCGGACCGAGTCCAA";
    std::string seq_r = "TTGGACTCGGTCCGGGGTAGGT";
    unsigned h = 3;

    btllib::BsHash bshash_f(seq_f, h, seq_f.size(), "CC");
    btllib::BsHash bshash_r(seq_r, h, seq_r.size(), "CC");

    bshash_f.roll();
    bshash_r.roll();

    TEST_ASSERT_EQ(bshash_f.get_hash_num(), bshash_r.get_hash_num());
    TEST_ASSERT_ARRAY_EQ(bshash_f.hashes(), bshash_r.hashes(), h);
  }
  {
    PRINT_TEST_NAME("CT canonical hashing")

    std::string seq_f = "ACTTACTCTGGACTGAGTCTAA";
    std::string seq_r = "TTAGACTCAGTCCAGAGTAAGT";
    unsigned h = 3;

    btllib::BsHash bshash_f(seq_f, h, seq_f.size(), "CT");
    btllib::BsHash bshash_r(seq_r, h, seq_r.size(), "CT");

    bshash_f.roll();
    bshash_r.roll();

    TEST_ASSERT_EQ(bshash_f.get_hash_num(), bshash_r.get_hash_num());
    TEST_ASSERT_ARRAY_EQ(bshash_f.hashes(), bshash_r.hashes(), h);
  }

  {
    PRINT_TEST_NAME("CG k-mer back rolling")

    std::string seq = "ACTGACTA";
    unsigned h = 3;
    unsigned k = 6;

    btllib::BsHash bshash(seq, h, k, "CG");
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
    PRINT_TEST_NAME("CC k-mer back rolling")

    std::string seq = "ACTGACTG";
    unsigned h = 3;
    unsigned k = 6;

    btllib::BsHash bshash(seq, h, k, "CC");
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
    PRINT_TEST_NAME("CT k-mer back rolling")

    std::string seq = "ACTGACTG";
    unsigned h = 3;
    unsigned k = 6;

    btllib::BsHash bshash(seq, h, k, "CT");
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
    PRINT_TEST_NAME("CA k-mer back rolling")

    std::string seq = "ACTGACTG";
    unsigned h = 3;
    unsigned k = 6;

    btllib::BsHash bshash(seq, h, k, "CA");
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
    PRINT_TEST_NAME("CG skipping Ns")

    std::string seq = "ACGTACACTGGACTGAGTCTAAAA";
    std::string seq_with_ns = seq;

    TEST_ASSERT_GE(seq_with_ns.size(), 10)

    seq_with_ns[seq_with_ns.size() / 2] = 'N';
    seq_with_ns[seq_with_ns.size() / 2 + 1] = 'N';
    unsigned k = (seq.size() - 2) / 2 - 1;

    btllib::BsHash bshash(seq_with_ns, 3, k, "CG");

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
    PRINT_TEST_NAME("CC skipping Ns")

    std::string seq = "ACGTACACTGGACTGAGTCTAAAA";
    std::string seq_with_ns = seq;

    TEST_ASSERT_GE(seq_with_ns.size(), 10)

    seq_with_ns[seq_with_ns.size() / 2] = 'N';
    seq_with_ns[seq_with_ns.size() / 2 + 1] = 'N';
    unsigned k = (seq.size() - 2) / 2 - 1;

    btllib::BsHash bshash(seq_with_ns, 3, k, "CC");

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
    PRINT_TEST_NAME("CA skipping Ns")

    std::string seq = "ACGTACACTGGACTGAGTCTAAAA";
    std::string seq_with_ns = seq;

    TEST_ASSERT_GE(seq_with_ns.size(), 10)

    seq_with_ns[seq_with_ns.size() / 2] = 'N';
    seq_with_ns[seq_with_ns.size() / 2 + 1] = 'N';
    unsigned k = (seq.size() - 2) / 2 - 1;

    btllib::BsHash bshash(seq_with_ns, 3, k, "CA");

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
    PRINT_TEST_NAME("CT skipping Ns")

    std::string seq = "ACGTACACTGGACTGAGTCTAAAA";
    std::string seq_with_ns = seq;

    TEST_ASSERT_GE(seq_with_ns.size(), 10)

    seq_with_ns[seq_with_ns.size() / 2] = 'N';
    seq_with_ns[seq_with_ns.size() / 2 + 1] = 'N';
    unsigned k = (seq.size() - 2) / 2 - 1;

    btllib::BsHash bshash(seq_with_ns, 3, k, "CT");

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
    PRINT_TEST_NAME("CG Methylation Module Tests")

    std::string seq = "AACGAA";
    std::string seq_no_meth = "AATGAA";
    std::string rc_seq = "TTCGTT";
    std::string rc_seq_no_meth = "TTCATT";

    btllib::BsHash bshash(seq, 3, seq.size(), "CG");
    btllib::BsHash bshash_no_meth(seq_no_meth, 3, seq_no_meth.size(), "CG");
    btllib::BsHash bshash_rc(rc_seq, 3, rc_seq.size(), "CG");
    btllib::BsHash bshash_rc_no_meth(
      rc_seq_no_meth, 3, rc_seq_no_meth.size(), "CG");

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

  {
    PRINT_TEST_NAME("CC Methylation Module Tests")

    std::string seq = "AACCTA";
    std::string seq_no_meth = "AATTTA";
    std::string rc_seq = "TAGGTT";
    std::string rc_seq_no_meth = "TAAATT";

    btllib::BsHash bshash(seq, 3, seq.size(), "CC");
    btllib::BsHash bshash_no_meth(seq_no_meth, 3, seq_no_meth.size(), "CC");
    btllib::BsHash bshash_rc(rc_seq, 3, rc_seq.size(), "CC");
    btllib::BsHash bshash_rc_no_meth(
      rc_seq_no_meth, 3, rc_seq_no_meth.size(), "CC");

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

  {
    PRINT_TEST_NAME("CA Methylation Module Tests")

    std::string seq = "AACAAA";
    std::string seq_no_meth = "AATAAA";
    std::string rc_seq = "TTTGTT";
    std::string rc_seq_no_meth = "TTTATT";

    btllib::BsHash bshash(seq, 3, seq.size(), "CA");
    btllib::BsHash bshash_no_meth(seq_no_meth, 3, seq_no_meth.size(), "CA");
    btllib::BsHash bshash_rc(rc_seq, 3, rc_seq.size(), "CA");
    btllib::BsHash bshash_rc_no_meth(
      rc_seq_no_meth, 3, rc_seq_no_meth.size(), "CA");

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

  {
    PRINT_TEST_NAME("CT Methylation Module Tests")

    std::string seq = "AACTAA";
    std::string seq_no_meth = "AATTAA";
    std::string rc_seq = "TTAGTT";
    std::string rc_seq_no_meth = "TTAATT";

    btllib::BsHash bshash(seq, 3, seq.size(), "CT");
    btllib::BsHash bshash_no_meth(seq_no_meth, 3, seq_no_meth.size(), "CT");
    btllib::BsHash bshash_rc(rc_seq, 3, rc_seq.size(), "CT");
    btllib::BsHash bshash_rc_no_meth(
      rc_seq_no_meth, 3, rc_seq_no_meth.size(), "CT");

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
