import unittest
import btllib


class TestBiHash(unittest.TestCase):

    def test_real_sequencing_read(self):
        first34 = (
            "ATCACGCNTAAACTTTTTTTTTTTTTTTTTTTTTTTTTTTNTTCCCCACCAGATCGGAAGAGCAC"
            "ACGTCTTAAAANCAGTCAATGGAGTTTATCGCGTTTGCCGTCGTCGGCTTGNAAAGGNGGGGGGG"
            "GGGGGGGGGGGGGGGGGG"
        )
        seq = first34
        h = 3
        k = 34

        bihash = btllib.BiHash(seq, h, k, "CG")
        hashes = []
        while bihash.roll():
            hashes.append(list(bihash.hashes()))
        self.assertGreater(len(hashes), 0)

    def test_cg_kmer_rolling(self):
        first34 = "AAACAGATCACCCGCTGAGCGGGTTACTGTGTAA"
        seq = first34 + first34
        h = 3
        k = 34

        bihash = btllib.BiHash(seq, h, k, "CG")
        hashes = []
        while bihash.roll():
            hashes.append(list(bihash.hashes()))

        self.assertEqual(len(hashes), len(seq) - k + 1)
        self.assertEqual(hashes[0], hashes[-1])

        groups = [
            ["AA", "GA"],
            ["AC", "AT", "GC", "GT"],
            ["AG"],
            ["GG"],
            ["CA", "CG", "TG"],
            ["CC"],
            ["CT"],
            ["TA"],
            ["TC", "TT"],
        ]

        def mutate_by_shift(s, shift):
            out = []
            for i in range(0, len(s), 2):
                dimer = s[i:i + 2]
                done = False
                for g in groups:
                    if dimer in g:
                        idx = g.index(dimer)
                        out.append(g[(idx + shift) % len(g)])
                        done = True
                        break
                if not done:
                    out.append(dimer)
            return "".join(out)

        def compute_hashes(s):
            bh = btllib.BiHash(s, h, k, "CG")
            out = []
            while bh.roll():
                out.append(list(bh.hashes()))
            return out

        # Degeneracy shifts
        for shift in [1, 2, 3]:
            seq_shift = first34 + mutate_by_shift(first34, shift)
            h1 = compute_hashes(seq)
            h2 = compute_hashes(seq_shift)
            self.assertEqual(len(h1), len(h2))
            self.assertEqual(h1[0], h1[-1])
            self.assertEqual(h2[0], h2[-1])

        # C->T mutation check
        first34_ct = "ATGCGTAGGTCGATGACGTTGAGCGTACGAGTAA"
        seq_ct = first34_ct + first34_ct
        bihash_ct = btllib.BiHash(seq_ct, h, k, "CG")
        hashes_ct = []
        while bihash_ct.roll():
            hashes_ct.append(list(bihash_ct.hashes()))
        self.assertEqual(len(hashes_ct), len(seq_ct) - k + 1)
        self.assertEqual(hashes_ct[0], hashes_ct[-1])

        def mutate_CT(s):
            return s.replace('C', 'T').replace('c', 't')

        seq_shift_ct = first34_ct + mutate_CT(first34_ct)
        h1 = compute_hashes(seq_ct)
        h2 = compute_hashes(seq_shift_ct)
        self.assertEqual(len(h1), len(h2))
        self.assertEqual(h1[0], h1[-1])
        for i in range(0, len(h1), 2):
            self.assertEqual(h1[i], h2[i])

        # G->A mutation check
        first34_ga = "TACCGATACCTACGCCATACGTCATACCGTTAAA"
        seq_ga = first34_ga + first34_ga
        bihash_ga = btllib.BiHash(seq_ga, h, k, "CG")
        hashes_ga = []
        while bihash_ga.roll():
            hashes_ga.append(list(bihash_ga.hashes()))
        self.assertEqual(len(hashes_ga), len(seq_ga) - k + 1)
        self.assertEqual(hashes_ga[0], hashes_ga[-1])

        def mutate_GA(s):
            return s.replace('G', 'A').replace('g', 'a')

        seq_shift_ga = first34_ga + mutate_GA(first34_ga)
        h1 = compute_hashes(seq_ga)
        h2 = compute_hashes(seq_shift_ga)
        self.assertEqual(len(h1), len(h2))
        self.assertEqual(h1[0], h1[-1])
        for i in range(0, len(h1), 2):
            self.assertEqual(h1[i], h2[i])

    def test_cc_kmer_rolling(self):
        first34 = "AAACAGATCACCCGCTGAGCGGGTTACTGTGTAA"
        seq = first34 + first34
        h = 3
        k = 34

        bihash = btllib.BiHash(seq, h, k, "CC")
        hashes = []
        while bihash.roll():
            hashes.append(list(bihash.hashes()))

        self.assertEqual(len(hashes), len(seq) - k + 1)
        self.assertEqual(hashes[0], hashes[-1])

    def test_ct_kmer_rolling(self):
        first34 = "AAACAGATCACCCGCTGAGCGGGTTACTGTGTAA"
        seq = first34 + first34
        h = 3
        k = 34

        bihash = btllib.BiHash(seq, h, k, "CT")
        hashes = []
        while bihash.roll():
            hashes.append(list(bihash.hashes()))

        self.assertEqual(len(hashes), len(seq) - k + 1)
        self.assertEqual(hashes[0], hashes[-1])

    def test_ca_kmer_rolling(self):
        first34 = "AAACAGATCACCCGCTGAGCGGGTTACTGTGTAA"
        seq = first34 + first34
        h = 3
        k = 34

        bihash = btllib.BiHash(seq, h, k, "CA")
        hashes = []
        while bihash.roll():
            hashes.append(list(bihash.hashes()))

        self.assertEqual(len(hashes), len(seq) - k + 1)
        self.assertEqual(hashes[0], hashes[-1])

    def test_kmer_rolling_vs_base_hash_values(self):
        seq = "ACGTACACTGGACTGAGTCT"
        for mode in ["CG", "CC", "CT", "CA"]:
            bihash = btllib.BiHash(seq, 3, len(seq) - 2, mode)
            kmer1 = seq[0:18]
            kmer2 = seq[1:19]
            kmer3 = seq[2:20]

            bihash_vector = [
                btllib.BiHash(kmer1, bihash.get_hash_num(), len(kmer1), mode),
                btllib.BiHash(kmer2, bihash.get_hash_num(), len(kmer2), mode),
                btllib.BiHash(kmer3, bihash.get_hash_num(), len(kmer3), mode),
            ]

            i = 0
            while bihash.roll() and bihash_vector[i].roll():
                for j in range(bihash.get_hash_num()):
                    self.assertEqual(bihash.hashes()[j], bihash_vector[i].hashes()[j])
                i += 1
            self.assertEqual(i, 3)

    def test_canonical_hashing(self):
        cases = [
            ("CG", "ACGTACGCGGGACGGAGTCGAA", "TTCGACTCCGTCCCGCGTACGT"),
            ("CA", "ACATACACAGGACAGAGTCAAA", "TTTGACTCTGTCCTGTGTATGT"),
            ("CC", "ACCTACCCCGGACCGAGTCCAA", "TTGGACTCGGTCCGGGGTAGGT"),
            ("CT", "ACTTACTCTGGACTGAGTCTAA", "TTAGACTCAGTCCAGAGTAAGT"),
        ]
        h = 3
        for mode, seq_f, seq_r in cases:
            bihash_f = btllib.BiHash(seq_f, h, len(seq_f), mode)
            bihash_r = btllib.BiHash(seq_r, h, len(seq_r), mode)
            bihash_f.roll()
            bihash_r.roll()
            self.assertEqual(bihash_f.get_hash_num(), bihash_r.get_hash_num())
            self.assertEqual(list(bihash_f.hashes()), list(bihash_r.hashes()))

    def test_kmer_back_rolling(self):
        seq = "ACTGACTA"
        h = 3
        k = 6
        for mode in ["CG", "CC", "CT", "CA"]:
            bihash = btllib.BiHash(seq, h, k, mode)
            hashes = []
            while bihash.roll():
                hashes.append(list(bihash.hashes()))

            self.assertEqual(len(hashes), len(seq) - k + 1)

            while True:
                self.assertEqual(list(bihash.hashes()), hashes.pop())
                if not bihash.roll_back():
                    break

    def test_skipping_ns(self):
        seq = "ACGTACACTGGACTGAGTCTAAAA"
        seq_with_ns = list(seq)
        self.assertGreaterEqual(len(seq_with_ns), 10)

        mid = len(seq_with_ns) // 2
        seq_with_ns[mid] = 'N'
        seq_with_ns[mid + 1] = 'N'
        seq_with_ns = "".join(seq_with_ns)

        k = (len(seq) - 2) // 2 - 1

        for mode in ["CG", "CC", "CA", "CT"]:
            bihash = btllib.BiHash(seq_with_ns, 3, k, mode)
            positions = []
            for i in range(len(seq_with_ns) // 2 - k + 1):
                positions.append(i)
            for i in range(len(seq_with_ns) // 2 + 2, len(seq_with_ns) - k + 1):
                positions.append(i)

            i = 0
            while bihash.roll():
                self.assertEqual(bihash.get_pos(), positions[i])
                i += 1
            self.assertEqual(len(positions), i)

    def test_methylation_module(self):
        cases = [
            ("CG", "AACGAA", "AATGAA", "TTCGTT", "TTCATT"),
            ("CC", "AACCTA", "AATTTA", "TAGGTT", "TAAATT"),
            ("CA", "AACAAA", "AATAAA", "TTTGTT", "TTTATT"),
            ("CT", "AACTAA", "AATTAA", "TTAGTT", "TTAATT"),
        ]
        for mode, seq, seq_no_meth, rc_seq, rc_seq_no_meth in cases:
            bihash = btllib.BiHash(seq, 3, len(seq), mode)
            bihash_no_meth = btllib.BiHash(seq_no_meth, 3, len(seq_no_meth), mode)
            bihash_rc = btllib.BiHash(rc_seq, 3, len(rc_seq), mode)
            bihash_rc_no_meth = btllib.BiHash(rc_seq_no_meth, 3, len(rc_seq_no_meth), mode)

            bihash.roll()
            bihash_no_meth.roll()
            bihash_rc.roll()
            bihash_rc_no_meth.roll()

            self.assertEqual(bihash.get_hash_num(), bihash_no_meth.get_hash_num())
            self.assertEqual(bihash.get_hash_num(), bihash_rc.get_hash_num())
            self.assertEqual(bihash.get_hash_num(), bihash_rc_no_meth.get_hash_num())

            h = bihash.get_hash_num()
            self.assertEqual(h, 3)

            self.assertEqual(list(bihash.hashes()), list(bihash_no_meth.hashes()))
            self.assertEqual(list(bihash.hashes()), list(bihash_rc.hashes()))
            self.assertEqual(list(bihash.hashes()), list(bihash_rc_no_meth.hashes()))

            self.assertEqual(bihash.is_methylated(), bihash_rc.is_methylated())
            self.assertNotEqual(bihash.is_methylated(), bihash_no_meth.is_methylated())
            self.assertNotEqual(bihash_rc.is_methylated(), bihash_rc_no_meth.is_methylated())
            self.assertNotEqual(bihash.is_forward_higher(), bihash_rc.is_forward_higher())

    def test_center_dimer(self):
        seq = "AACGAA"
        bihash = btllib.BiHash(seq, 1, 6, "CG")
        bihash.roll()
        self.assertEqual(bihash.center_dimer(), "CG")


if __name__ == "__main__":
    unittest.main()

