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
    // ───────────────────────────────
    PRINT_TEST_NAME("CG k-mer rolling (64-mer base)")
    // ───────────────────────────────

    std::string first32 =
        "AAACAGAT"
        "CACCCGCT"
        "GAGCGGGT"
        "TACTGTGTAA";

    std::string seq = first32 + first32; // 64 bases total
    unsigned h = 3;
    unsigned k = 34;

    btllib::BsHash nthash(seq, h, k, "CG");
    std::vector<uint64_t*> hashes;

    while (nthash.roll()) {
        uint64_t* h_vals = new uint64_t[h];
        std::copy(nthash.hashes(), nthash.hashes() + h, h_vals);
        hashes.push_back(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1);
    TEST_ASSERT_ARRAY_EQ(hashes.front(), hashes.back(), h);

    // ───────────────────────────────
    //  Define degeneracy groups
    // ───────────────────────────────
    const std::vector<std::vector<std::string>> GROUPS = {
        {"AA", "GA"},
        {"AC", "AT", "GC", "GT"},
        {"AG", "GG"},
        {"CA", "CG", "TG"},
        {"CC", "CT"},
        {"TA"},
        {"TC", "TT"}
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
            if (!done) out += dimer;
        }
        return out;
    };
    

    auto compute_hashes = [&](const std::string& s) {
        btllib::BsHash nh(s, h, k, "CG");
        std::vector<uint64_t*> out;
        while (nh.roll()) {
            uint64_t* hv = new uint64_t[h];
            std::copy(nh.hashes(), nh.hashes() + h, hv);
            out.push_back(hv);
        }
        return out;
    };
// ───────────────────────────────
PRINT_TEST_NAME("CG k-mer rolling (degeneracy shift +1)")
// ───────────────────────────────
{
    std::string seq_shift = first32 + mutate_by_shift(first32, 1);
    auto h1 = compute_hashes(seq);
    auto h2 = compute_hashes(seq_shift);

    TEST_ASSERT_EQ(h1.size(), h2.size());
    TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
    for (unsigned i = 0;  i < h1.size(); i = i+2) {
      for (unsigned j = 0; j < h; ++j) {
          TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
      }
    }
}

    // ───────────────────────────────
    PRINT_TEST_NAME("CG k-mer rolling (degeneracy shift +2)")
    // ───────────────────────────────
    {
        std::string seq_shift = first32 + mutate_by_shift(first32, 2);
        auto h1 = compute_hashes(seq);
        auto h2 = compute_hashes(seq_shift);

        TEST_ASSERT_EQ(h1.size(), h2.size());
        TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
        for (unsigned i = 0;  i < h1.size(); i = i+2) {
          for (unsigned j = 0; j < h; ++j) {
              TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
          }
        }
    }

    // ───────────────────────────────
    PRINT_TEST_NAME("CG k-mer rolling (degeneracy shift +3)")
    // ───────────────────────────────
    {
        std::string seq_shift = first32 + mutate_by_shift(first32, 3);
      auto h1 = compute_hashes(seq);
      auto h2 = compute_hashes(seq_shift);

      TEST_ASSERT_EQ(h1.size(), h2.size());
      TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
      for (unsigned i = 0;  i < h1.size(); i = i+2) {
        for (unsigned j = 0; j < h; ++j) {
            TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
        }
      }
    }
  }

{
    // ───────────────────────────────
    PRINT_TEST_NAME("CG k-mer rolling (C→T mutation)")
    // ───────────────────────────────

    std::string first32 =
        "ATGCGTAGGTCGATGACGTTGAGCGTACGAGTAA";

    std::string seq = first32 + first32; // 64 bases total
    unsigned h = 3;
    unsigned k = 34;

    btllib::BsHash nthash(seq, h, k, "CG");
    std::vector<uint64_t*> hashes;

    while (nthash.roll()) {
        uint64_t* h_vals = new uint64_t[h];
        std::copy(nthash.hashes(), nthash.hashes() + h, h_vals);
        hashes.push_back(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1);
    TEST_ASSERT_ARRAY_EQ(hashes.front(), hashes.back(), h);

    // ───────────────────────────────
    //  Mutation function: C→T
    // ───────────────────────────────
    auto mutate_CT = [](const std::string& s) {
        std::string out = s;
        for (char& base : out) {
            if (base == 'C') base = 'T';
            else if (base == 'c') base = 't';
        }
        return out;
    };

    auto compute_hashes = [&](const std::string& s) {
        btllib::BsHash nh(s, h, k, "CG");
        std::vector<uint64_t*> out;
        while (nh.roll()) {
            uint64_t* hv = new uint64_t[h];
            std::copy(nh.hashes(), nh.hashes() + h, hv);
            out.push_back(hv);
        }
        return out;
    };

    // ───────────────────────────────
    PRINT_TEST_NAME("CG k-mer rolling (C→T forward check)")
    // ───────────────────────────────
    {
        std::string seq_shift = first32 + mutate_CT(first32);
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
    // ───────────────────────────────
    PRINT_TEST_NAME("CG k-mer rolling (G→A mutation)")
    // ───────────────────────────────

    std::string first32 =
        "TACCGATACCTACGCCATACGTCATACCGTTAAA";

    std::string seq = first32 + first32; // 64 bases total
    unsigned h = 3;
    unsigned k = 34;

    btllib::BsHash nthash(seq, h, k, "CG");
    std::vector<uint64_t*> hashes;

    while (nthash.roll()) {
        uint64_t* h_vals = new uint64_t[h];
        std::copy(nthash.hashes(), nthash.hashes() + h, h_vals);
        hashes.push_back(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1);
    TEST_ASSERT_ARRAY_EQ(hashes.front(), hashes.back(), h);

    // ───────────────────────────────
    //  Mutation function: G→A
    // ───────────────────────────────
    auto mutate_GA = [](const std::string& s) {
        std::string out = s;
        for (char& base : out) {
            if (base == 'G') base = 'A';
            else if (base == 'g') base = 'a';
        }
        return out;
    };

    auto compute_hashes = [&](const std::string& s) {
        btllib::BsHash nh(s, h, k, "CG");
        std::vector<uint64_t*> out;
        while (nh.roll()) {
            uint64_t* hv = new uint64_t[h];
            std::copy(nh.hashes(), nh.hashes() + h, hv);
            out.push_back(hv);
        }
        return out;
    };

    // ───────────────────────────────
    PRINT_TEST_NAME("CG k-mer rolling (G→A forward check)")
    // ───────────────────────────────
    {
        std::string seq_shift = first32 + mutate_GA(first32);
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


/*{
    // ───────────────────────────────
    PRINT_TEST_NAME("CC k-mer rolling (64-mer base)")
    // ───────────────────────────────

    std::string first32 =
        "AAACAGAT"
        "CACCCGCT"
        "GAGCGGGT"
        "TACTGTGT";

    std::string seq = first32 + first32; // 64 bases total
    unsigned h = 3;
    unsigned k = 32;

    btllib::BsHash nthash(seq, h, k, "CC"); // or "CC" if that parameter matters
    std::vector<uint64_t*> hashes;

    while (nthash.roll()) {
        uint64_t* h_vals = new uint64_t[h];
        std::copy(nthash.hashes(), nthash.hashes() + h, h_vals);
        hashes.push_back(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1);
    TEST_ASSERT_ARRAY_EQ(hashes.front(), hashes.back(), h);

    // ───────────────────────────────
    //  Define CC degeneracy groups
    // ───────────────────────────────
    const std::vector<std::vector<std::string>> CC_GROUPS = {
        {"AA", "AG", "GA", "GG"},      // 0x1bc5d5aba6ea6e02
        {"AC", "AT", "GC", "GT"},      // 0x8f15314b06b5ed9c
        {"CA", "CG", "TA", "TG"},      // 0x44fec7e4a74bce00
        {"CC", "CT", "TC", "TT"}       // 0x77c24a36c934fdc1
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
            if (!done) out += dimer;
        }
        return out;
    };

    auto compute_hashes = [&](const std::string& s) {
        btllib::BsHash nh(s, h, k, "CC"); // or "CC" if appropriate
        std::vector<uint64_t*> out;
        while (nh.roll()) {
            uint64_t* hv = new uint64_t[h];
            std::copy(nh.hashes(), nh.hashes() + h, hv);
            out.push_back(hv);
        }
        return out;
    };

    // ───────────────────────────────
    PRINT_TEST_NAME("CC k-mer rolling (degeneracy shift +1)")
    // ───────────────────────────────
    {
        std::string seq_shift = first32 + mutate_by_shift(first32, 1);
        auto h1 = compute_hashes(seq);
        auto h2 = compute_hashes(seq_shift);

        TEST_ASSERT_EQ(h1.size(), h2.size());
        TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
        for (unsigned i = 0;  i < h1.size(); i = i+2) {
          for (unsigned j = 0; j < h; ++j) {
              TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
          }
        }
    }

    // ───────────────────────────────
    PRINT_TEST_NAME("CC k-mer rolling (degeneracy shift +2)")
    // ───────────────────────────────
    {
        std::string seq_shift = first32 + mutate_by_shift(first32, 2);
        auto h1 = compute_hashes(seq);
        auto h2 = compute_hashes(seq_shift);

        TEST_ASSERT_EQ(h1.size(), h2.size());
        TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
        for (unsigned i = 0;  i < h1.size(); i = i+2) {
        for (unsigned j = 0; j < h; ++j) {
            TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
        }
        }
    }

    // ───────────────────────────────
    PRINT_TEST_NAME("CC k-mer rolling (degeneracy shift +3)")
    // ───────────────────────────────
    {
        std::string seq_shift = first32 + mutate_by_shift(first32, 3);
        auto h1 = compute_hashes(seq);
        auto h2 = compute_hashes(seq_shift);

        TEST_ASSERT_EQ(h1.size(), h2.size());
        TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
        for (unsigned i = 0;  i < h1.size(); i = i+2) {
          for (unsigned j = 0; j < h; ++j) {
              TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
          }
        }
    }
}*/

/*{
    // ───────────────────────────────
    PRINT_TEST_NAME("CT k-mer rolling (64-mer base)")
    // ───────────────────────────────

    std::string first32 =
        "AAACAGAT"
        "CACCCGCT"
        "GAGCGGGT"
        "TACTGTGT";

    std::string seq = first32 + first32; // 64 bases total
    unsigned h = 3;
    unsigned k = 32;

    btllib::BsHash nthash(seq, h, k, "CT"); // or "CT" if that parameter matters
    std::vector<uint64_t*> hashes;

    while (nthash.roll()) {
        uint64_t* h_vals = new uint64_t[h];
        std::copy(nthash.hashes(), nthash.hashes() + h, h_vals);
        hashes.push_back(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1);
    TEST_ASSERT_ARRAY_EQ(hashes.front(), hashes.back(), h);

    // ───────────────────────────────
    //  Define CT degeneracy groups based on CT_DIMER_TAB
    // ───────────────────────────────
    const std::vector<std::vector<std::string>> CT_GROUPS = {
        {"AA", "AC", "AG", "GG"},        // 0x9a533a6a5e7b14e2
        {"AT", "GT"},              // 0x897da34f6b464570
        {"CA"},
        {"CG"},               // 0xeeaf42d6e10d9ac0 and 0x68c7d4adebfb5001
        {"CC", "CT", "TC", "TT"},  // 0x049bab70128da11f
        {"GA", "GC", "GG", "AG"},        // 0x9a533a6a5e7b14e2
        {"TA"},                     // 0x0f1bfc76a0e3e700
        {"TG"}                      // 0x282450c57fae339f
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
            if (!done) out += dimer;
        }
        return out;
    };

    auto compute_hashes = [&](const std::string& s) {
        btllib::BsHash nh(s, h, k, "CT"); // or "CT" if needed
        std::vector<uint64_t*> out;
        while (nh.roll()) {
            uint64_t* hv = new uint64_t[h];
            std::copy(nh.hashes(), nh.hashes() + h, hv);
            out.push_back(hv);
        }
        return out;
    };

    // ───────────────────────────────
    PRINT_TEST_NAME("CT k-mer rolling (degeneracy shift +1)")
    // ───────────────────────────────
    {
        std::string seq_shift = first32 + mutate_by_shift(first32, 1);
        auto h1 = compute_hashes(seq);
        auto h2 = compute_hashes(seq_shift);
        std::cerr << seq << std::endl;
        std::cerr << seq_shift << std::endl;

        TEST_ASSERT_EQ(h1.size(), h2.size());
        TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
for (unsigned i = 0;  i < h1.size(); i = i+2) {
  std::cerr << i << std::endl;
        for (unsigned j = 0; j < h; ++j) {
            TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
        }
}
    }

    // ───────────────────────────────
    PRINT_TEST_NAME("CT k-mer rolling (degeneracy shift +2)")
    // ───────────────────────────────
    {
        std::string seq_shift = first32 + mutate_by_shift(first32, 2);
        auto h1 = compute_hashes(seq);
        auto h2 = compute_hashes(seq_shift);

        TEST_ASSERT_EQ(h1.size(), h2.size());
        TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
for (unsigned i = 0;  i < h1.size(); i = i+2) {
        for (unsigned j = 0; j < h; ++j) {
            TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
        }
}
    }

    // ───────────────────────────────
    PRINT_TEST_NAME("CT k-mer rolling (degeneracy shift +3)")
    // ───────────────────────────────
    {
        std::string seq_shift = first32 + mutate_by_shift(first32, 3);
        auto h1 = compute_hashes(seq);
        auto h2 = compute_hashes(seq_shift);

        TEST_ASSERT_EQ(h1.size(), h2.size());
        TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
for (unsigned i = 0;  i < h1.size(); i = i+2) {
        for (unsigned j = 0; j < h; ++j) {
            TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
        }
}
    }
}

{
    // ───────────────────────────────
    PRINT_TEST_NAME("CA k-mer rolling (64-mer base)")
    // ───────────────────────────────

    std::string first32 =
        "AAACAGAT"
        "CACCCGCT"
        "GAGCGGGT"
        "TACTGTGT";

    std::string seq = first32 + first32; // 64 bases total
    unsigned h = 3;
    unsigned k = 32;

    btllib::BsHash nthash(seq, h, k, "CA"); // or "CA" if that parameter matters
    std::vector<uint64_t*> hashes;

    while (nthash.roll()) {
        uint64_t* h_vals = new uint64_t[h];
        std::copy(nthash.hashes(), nthash.hashes() + h, h_vals);
        hashes.push_back(h_vals);
    }

    TEST_ASSERT_EQ(hashes.size(), seq.length() - k + 1);
    TEST_ASSERT_ARRAY_EQ(hashes.front(), hashes.back(), h);

    // ───────────────────────────────
    //  Define CA degeneracy groups based on CA_DIMER_TAB
    // ───────────────────────────────
    const std::vector<std::vector<std::string>> CA_GROUPS = {
        {"AA", "GA"},               // 0x7e4a36919c5032af
        {"AC", "AT", "GC", "GT"},   // 0x95b4b90696718a9f
        {"AG", "GG"},               // 0xf482881f5f3610bf
        {"CA", "TA", "TG"},          // 0xe12f0e8e678e5d30
        {"CC", "CT", "TT", "TC"},   // 0x9ff825331cf8a361 and 0x00e055ee083cfcff
        {"CG"}                       // 0xf248b960f9159cec
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
            if (!done) out += dimer;
        }
        return out;
    };

    auto compute_hashes = [&](const std::string& s) {
        btllib::BsHash nh(s, h, k, "CA"); // or "CA" if needed
        std::vector<uint64_t*> out;
        while (nh.roll()) {
            uint64_t* hv = new uint64_t[h];
            std::copy(nh.hashes(), nh.hashes() + h, hv);
            out.push_back(hv);
        }
        return out;
    };

    // ───────────────────────────────
    PRINT_TEST_NAME("CA k-mer rolling (degeneracy shift +1)")
    // ───────────────────────────────
    {
        std::string seq_shift = first32 + mutate_by_shift(first32, 1);
        auto h1 = compute_hashes(seq);
        auto h2 = compute_hashes(seq_shift);

        TEST_ASSERT_EQ(h1.size(), h2.size());
        TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
for (unsigned i = 0;  i < h1.size(); i = i+2) {
        for (unsigned j = 0; j < h; ++j) {
            TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
        }
}
    }

    // ───────────────────────────────
    PRINT_TEST_NAME("CA k-mer rolling (degeneracy shift +2)")
    // ───────────────────────────────
    {
        std::string seq_shift = first32 + mutate_by_shift(first32, 2);
        auto h1 = compute_hashes(seq);
        auto h2 = compute_hashes(seq_shift);

        TEST_ASSERT_EQ(h1.size(), h2.size());
        TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
for (unsigned i = 0;  i < h1.size(); i = i+2) {
        for (unsigned j = 0; j < h; ++j) {
            TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
        }
}
    }

    // ───────────────────────────────
    PRINT_TEST_NAME("CA k-mer rolling (degeneracy shift +3)")
    // ───────────────────────────────
    {
        std::string seq_shift = first32 + mutate_by_shift(first32, 3);
        auto h1 = compute_hashes(seq);
        auto h2 = compute_hashes(seq_shift);

        TEST_ASSERT_EQ(h1.size(), h2.size());
        TEST_ASSERT_ARRAY_EQ(h1.front(), h1.back(), h);
for (unsigned i = 0;  i < h1.size(); i = i+2) {
        for (unsigned j = 0; j < h; ++j) {
            TEST_ASSERT_EQ(h1[i][j], h2[i][j]);
        }
}
    }
}
*/


  {
    PRINT_TEST_NAME("k-mer rolling vs. base hash values")

    std::string seq = "ACGTACACTGGACTGAGTCT";

    btllib::BsHash nthash(seq, 3, seq.size() - 2, "CG");
    /* 18-mers of kmer*/
    std::string kmer1 = seq.substr(0, 18);
    std::string kmer2 = seq.substr(1, 18);
    std::string kmer3 = seq.substr(2, 18);

    btllib::BsHash nthash_vector[] = {
      btllib::BsHash(kmer1, nthash.get_hash_num(), kmer1.size(), "CG"),
      btllib::BsHash(kmer2, nthash.get_hash_num(), kmer2.size(), "CG"),
      btllib::BsHash(kmer3, nthash.get_hash_num(), kmer3.size(), "CG")
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
    PRINT_TEST_NAME("CG canonical hashing")

    std::string seq_f = "ACGTACACTGGACTGAGTCTAA";
    std::string seq_r = "TTAGACTCAGTCCAGTGTACGT";
    unsigned h = 3;

    btllib::BsHash nthash_f(seq_f, h, seq_f.size(), "CG");
    btllib::BsHash nthash_r(seq_r, h, seq_r.size(), "CG");

    nthash_f.roll();
    nthash_r.roll();
    TEST_ASSERT_EQ(nthash_f.get_hash_num(), nthash_r.get_hash_num())
    TEST_ASSERT_ARRAY_EQ(nthash_f.hashes(), nthash_r.hashes(), h)
  }
  
  /*{
    PRINT_TEST_NAME("CC canonical hashing")

    std::string seq_f = "ACGTACACTGGACTGAGTCT";
    std::string seq_r = "AGACTCAGTCCAGTGTACGT";
    unsigned h = 3;

    btllib::BsHash nthash_f(seq_f, h, seq_f.size(), "CC");
    btllib::BsHash nthash_r(seq_r, h, seq_r.size(), "CC");

    nthash_f.roll();
    nthash_r.roll();
    TEST_ASSERT_EQ(nthash_f.get_hash_num(), nthash_r.get_hash_num())
    TEST_ASSERT_ARRAY_EQ(nthash_f.hashes(), nthash_r.hashes(), h)
  }  

  {
    PRINT_TEST_NAME("CT canonical hashing")

    std::string seq_f = "ACGTACACTGGACTGAGTCT";
    std::string seq_r = "AGACTCAGTCCAGTGTACGT";
    unsigned h = 3;

    btllib::BsHash nthash_f(seq_f, h, seq_f.size(), "CT");
    btllib::BsHash nthash_r(seq_r, h, seq_r.size(), "CT");

    nthash_f.roll();
    nthash_r.roll();
    TEST_ASSERT_EQ(nthash_f.get_hash_num(), nthash_r.get_hash_num())
    TEST_ASSERT_ARRAY_EQ(nthash_f.hashes(), nthash_r.hashes(), h)
  }

  {
    PRINT_TEST_NAME("CA canonical hashing")

    std::string seq_f = "ACGTACACTGGACTGAGTCT";
    std::string seq_r = "AGACTCAGTCCAGTGTACGT";
    unsigned h = 3;

    btllib::BsHash nthash_f(seq_f, h, seq_f.size(), "CA");
    btllib::BsHash nthash_r(seq_r, h, seq_r.size(), "CA");

    nthash_f.roll();
    nthash_r.roll();
    TEST_ASSERT_EQ(nthash_f.get_hash_num(), nthash_r.get_hash_num())
    TEST_ASSERT_ARRAY_EQ(nthash_f.hashes(), nthash_r.hashes(), h)
  }
*/
  {
    PRINT_TEST_NAME("CG k-mer back rolling")

    std::string seq = "ACTGACTA";
    unsigned h = 3;
    unsigned k = 6;

    btllib::BsHash nthash(seq, h, k, "CG");
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

  /*{
    PRINT_TEST_NAME("CC k-mer back rolling")

    std::string seq = "ACTGACTG";
    unsigned h = 3;
    unsigned k = 4;

    btllib::BsHash nthash(seq, h, k, "CC");
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
    PRINT_TEST_NAME("CT k-mer back rolling")

    std::string seq = "ACTGACTG";
    unsigned h = 3;
    unsigned k = 4;

    btllib::BsHash nthash(seq, h, k, "CT");
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
    PRINT_TEST_NAME("CA k-mer back rolling")

    std::string seq = "ACTGACTG";
    unsigned h = 3;
    unsigned k = 4;

    btllib::BsHash nthash(seq, h, k, "CA");
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
  }   */   
/*
  {
    PRINT_TEST_NAME("k-mer peeking")

    std::string seq = "ACTGATCAG";
    unsigned h = 3;
    unsigned k = 6;

    btllib::BsHash nthash(seq, h, k);
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
  }*/

  {
    PRINT_TEST_NAME("skipping Ns")

    std::string seq = "ACGTACACTGGACTGAGTCTAAAA";
    std::string seq_with_ns = seq;

    TEST_ASSERT_GE(seq_with_ns.size(), 10)
    //10, 11 are Ns
    seq_with_ns[seq_with_ns.size() / 2] = 'N';
    seq_with_ns[seq_with_ns.size() / 2 + 1] = 'N';
    unsigned k = (seq.size() - 2) / 2 - 1;
    //k = 8
    btllib::BsHash nthash(seq_with_ns, 3, k);

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
    PRINT_TEST_NAME("check methylation")

    std::string seq_k6 = "ATCGGA";
    std::string seq_k4 = "GGCGTA";
    btllib::BsHash nthash1(seq_k6, 3, 6);
    nthash1.roll();
    TEST_ASSERT_EQ(nthash1.is_methylated(), true)
    btllib::BsHash nthash2(seq_k4, 3, 6);
    nthash2.roll();
    TEST_ASSERT_EQ(nthash2.is_methylated(), true)

    
  }


  return 0;
}
