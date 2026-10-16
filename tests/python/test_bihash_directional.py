import unittest
import btllib


class TestBiHashDirectional(unittest.TestCase):

    def test_kmer_rolling_ct_mode(self):
        seq = "AGTCAGTCAGTCAG"
        h = 3
        k = 6

        bihash = btllib.BiHashDirectional(seq, h, k, "CT")
        hashes = []
        fwd_hash = 0
        final_fwd_hash = 0
        rev_hash = 0
        final_rev_hash = 0

        while bihash.roll():
            if fwd_hash == 0:
                fwd_hash = bihash.get_forward_hash()
                rev_hash = bihash.get_reverse_hash()
            final_fwd_hash = bihash.get_forward_hash()
            final_rev_hash = bihash.get_reverse_hash()
            hashes.append(list(bihash.hashes()))

        self.assertEqual(len(hashes), len(seq) - k + 1)
        self.assertEqual(fwd_hash, final_fwd_hash)
        self.assertEqual(rev_hash, final_rev_hash)
        self.assertEqual(hashes[0], hashes[-1])

    def test_kmer_rolling_ga_mode(self):
        seq = "AGTCAGTCAGTCAG"
        h = 3
        k = 6

        bihash = btllib.BiHashDirectional(seq, h, k, "GA")
        hashes = []
        fwd_hash = 0
        final_fwd_hash = 0
        rev_hash = 0
        final_rev_hash = 0

        while bihash.roll():
            if fwd_hash == 0:
                fwd_hash = bihash.get_forward_hash()
                rev_hash = bihash.get_reverse_hash()
            final_fwd_hash = bihash.get_forward_hash()
            final_rev_hash = bihash.get_reverse_hash()
            hashes.append(list(bihash.hashes()))

        self.assertEqual(len(hashes), len(seq) - k + 1)
        self.assertEqual(fwd_hash, final_fwd_hash)
        self.assertEqual(rev_hash, final_rev_hash)
        self.assertEqual(hashes[0], hashes[-1])

    def test_kmer_rolling_vs_base_hash_values_ct_mode(self):
        seq = "ACGTACACTGGACTGAGTCTATCG"
        bihash = btllib.BiHashDirectional(seq, 3, len(seq) - 2, "CT")

        kmer1 = seq[0:22]
        kmer2 = seq[1:23]
        kmer3 = seq[2:24]

        bihash_vector = [
            btllib.BiHashDirectional(kmer1, bihash.get_hash_num(), len(kmer1), "CT"),
            btllib.BiHashDirectional(kmer2, bihash.get_hash_num(), len(kmer2), "CT"),
            btllib.BiHashDirectional(kmer3, bihash.get_hash_num(), len(kmer3), "CT"),
        ]

        i = 0
        while bihash.roll() and bihash_vector[i].roll():
            for j in range(bihash.get_hash_num()):
                self.assertEqual(bihash.hashes()[j], bihash_vector[i].hashes()[j])
            i += 1
        self.assertEqual(i, 3)

    def test_kmer_rolling_vs_base_hash_values_ga_mode(self):
        seq = "ACGTACACTGGACTGAGTCTATCG"
        bihash = btllib.BiHashDirectional(seq, 3, len(seq) - 2, "GA")

        kmer1 = seq[0:22]
        kmer2 = seq[1:23]
        kmer3 = seq[2:24]

        bihash_vector = [
            btllib.BiHashDirectional(kmer1, bihash.get_hash_num(), len(kmer1), "GA"),
            btllib.BiHashDirectional(kmer2, bihash.get_hash_num(), len(kmer2), "GA"),
            btllib.BiHashDirectional(kmer3, bihash.get_hash_num(), len(kmer3), "GA"),
        ]

        i = 0
        while bihash.roll() and bihash_vector[i].roll():
            for j in range(bihash.get_hash_num()):
                self.assertEqual(bihash.hashes()[j], bihash_vector[i].hashes()[j])
            i += 1
        self.assertEqual(i, 3)

    def test_canonical_hashing(self):
        seq_f = "ACGTACACTGGACTGAGTCTAA"
        seq_r = "TTAGACTCAGTCCAGTGTACGT"
        h = 3

        bihash_f = btllib.BiHashDirectional(seq_f, h, len(seq_f), "CT")
        bihash_r = btllib.BiHashDirectional(seq_r, h, len(seq_r), "GA")

        bihash_f.roll()
        bihash_r.roll()
        self.assertEqual(bihash_f.get_hash_num(), bihash_r.get_hash_num())
        self.assertEqual(list(bihash_f.hashes()), list(bihash_r.hashes()))

    def test_canonical_hashing_reverse(self):
        seq_f = "ACGTACACTGGACTGAGTCTAA"
        seq_r = "TTAGACTCAGTCCAGTGTACGT"
        h = 3

        bihash_f = btllib.BiHashDirectional(seq_f, h, len(seq_f), "CT")
        bihash_r = btllib.BiHashDirectional(seq_r, h, len(seq_r), "GA")

        bihash_f.roll()
        bihash_r.roll()
        self.assertEqual(bihash_f.get_hash_num(), bihash_r.get_hash_num())
        self.assertEqual(list(bihash_f.hashes()), list(bihash_r.hashes()))

    def test_kmer_back_rolling_ct_mode(self):
        seq = "ACTAGACTG"
        h = 3
        k = 6

        bihash = btllib.BiHashDirectional(seq, h, k, "CT")
        hashes = []

        while bihash.roll():
            hashes.append(list(bihash.hashes()))

        self.assertEqual(len(hashes), len(seq) - k + 1)

        while True:
            self.assertEqual(list(bihash.hashes()), hashes.pop())
            if not bihash.roll_back():
                break

    def test_kmer_back_rolling_ga_mode(self):
        seq = "ACTAGACTG"
        h = 3
        k = 6

        bihash = btllib.BiHashDirectional(seq, h, k, "GA")
        hashes = []

        while bihash.roll():
            hashes.append(list(bihash.hashes()))

        self.assertEqual(len(hashes), len(seq) - k + 1)

        while True:
            self.assertEqual(list(bihash.hashes()), hashes.pop())
            if not bihash.roll_back():
                break

    def test_kmer_peeking_ct_mode(self):
        seq = "ACTGATCAG"
        h = 3
        k = 6

        bihash = btllib.BiHashDirectional(seq, h, k, "CT")
        bihash.roll()

        steps = 3
        while steps > 0:
            steps -= 1
            bihash.peek()
            h_peek = list(bihash.hashes())
            bihash.peek(ord(seq[bihash.get_pos() + k]))
            self.assertEqual(list(bihash.hashes()), h_peek)
            bihash.roll()
            self.assertEqual(list(bihash.hashes()), h_peek)

    def test_kmer_peeking_ga_mode(self):
        seq = "ACTGATCAG"
        h = 3
        k = 6

        bihash = btllib.BiHashDirectional(seq, h, k, "GA")
        bihash.roll()

        steps = 3
        while steps > 0:
            steps -= 1
            bihash.peek()
            h_peek = list(bihash.hashes())
            bihash.peek(ord(seq[bihash.get_pos() + k]))
            self.assertEqual(list(bihash.hashes()), h_peek)
            bihash.roll()
            self.assertEqual(list(bihash.hashes()), h_peek)

    def test_skipping_ns_ct_mode(self):
        seq = "ACGTACACTGGACTGAGTCTAAAA"
        seq_with_ns = list(seq)
        self.assertGreaterEqual(len(seq_with_ns), 10)

        mid = len(seq_with_ns) // 2
        seq_with_ns[mid] = 'N'
        seq_with_ns[mid + 1] = 'N'
        seq_with_ns = "".join(seq_with_ns)

        k = (len(seq) - 2) // 2 - 1
        bihash = btllib.BiHashDirectional(seq_with_ns, 3, k, "CT")

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

    def test_skipping_ns_ga_mode(self):
        seq = "ACGTACACTGGACTGAGTCTAAAA"
        seq_with_ns = list(seq)
        self.assertGreaterEqual(len(seq_with_ns), 10)

        mid = len(seq_with_ns) // 2
        seq_with_ns[mid] = 'N'
        seq_with_ns[mid + 1] = 'N'
        seq_with_ns = "".join(seq_with_ns)

        k = (len(seq) - 2) // 2 - 1
        bihash = btllib.BiHashDirectional(seq_with_ns, 3, k, "GA")

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

    def test_base_substitution_ct_mode(self):
        seq = "ACGTACACTGGACTGAGTCTAA"
        sub = "ACGCGCACTGGACTGAGTCTAA"

        bihash = btllib.BiHashDirectional(seq, 3, len(seq), "CT")
        bihash_subbed = btllib.BiHashDirectional(sub, 3, len(sub), "CT")

        bihash.roll()
        bihash.sub([3, 4], [ord('C'), ord('G')])
        bihash_subbed.roll()

        self.assertEqual(bihash.get_hash_num(), bihash_subbed.get_hash_num())
        for i in range(bihash.get_hash_num()):
            self.assertEqual(bihash.hashes()[i], bihash_subbed.hashes()[i])

    def test_base_substitution_ga_mode(self):
        seq = "ACGTACACTGGACTGAGTCTAA"
        sub = "ACGCGCACTGGACTGAGTCTAA"

        bihash = btllib.BiHashDirectional(seq, 3, len(seq), "GA")
        bihash_subbed = btllib.BiHashDirectional(sub, 3, len(sub), "GA")

        bihash.roll()
        bihash.sub([3, 4], [ord('C'), ord('G')])
        bihash_subbed.roll()

        self.assertEqual(bihash.get_hash_num(), bihash_subbed.get_hash_num())
        for i in range(bihash.get_hash_num()):
            self.assertEqual(bihash.hashes()[i], bihash_subbed.hashes()[i])

    def test_methylation_module(self):
        seq = "ACCGAA"
        seq_no_meth = "ACTGAA"
        rc_seq = "TTCGGT"
        rc_seq_no_meth = "TTCAAT"

        bihash = btllib.BiHashDirectional(seq, 3, len(seq), "CT")
        bihash_no_meth = btllib.BiHashDirectional(seq_no_meth, 3, len(seq_no_meth), "CT")
        bihash_rc = btllib.BiHashDirectional(rc_seq, 3, len(rc_seq), "GA")
        bihash_rc_no_meth = btllib.BiHashDirectional(rc_seq_no_meth, 3, len(rc_seq_no_meth), "GA")

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


if __name__ == "__main__":
    unittest.main()

