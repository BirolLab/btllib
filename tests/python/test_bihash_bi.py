import unittest
import btllib


class TestBiHashBi(unittest.TestCase):

    def test_kmer_rolling(self):
        seq = "AGTCAGTCAGTCAG"
        h = 3
        k = 6

        bihash = btllib.BiHashBi(seq, h, k)
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

    def test_kmer_rolling_vs_base_hash_values(self):
        seq = "ACGTACACTGGACTGAGTCTATCG"
        k = 22
        bihash = btllib.BiHashBi(seq, 3, len(seq) - 2)

        kmer1 = seq[0:22]
        kmer2 = seq[1:23]
        kmer3 = seq[2:24]

        bihash_vector = [
            btllib.BiHashBi(kmer1, bihash.get_hash_num(), len(kmer1)),
            btllib.BiHashBi(kmer2, bihash.get_hash_num(), len(kmer2)),
            btllib.BiHashBi(kmer3, bihash.get_hash_num(), len(kmer3)),
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

        bihash_f = btllib.BiHashBi(seq_f, h, len(seq_f))
        bihash_r = btllib.BiHashBi(seq_r, h, len(seq_r))

        bihash_f.roll()
        bihash_r.roll()
        self.assertEqual(bihash_f.get_hash_num(), bihash_r.get_hash_num())
        self.assertEqual(list(bihash_f.hashes()), list(bihash_r.hashes()))

    def test_canonical_hashing_reverse(self):
        seq_f = "ACGTACACTGGACTGAGTCTAA"
        seq_r = "TTAGACTCAGTCCAGTGTACGT"
        h = 3

        bihash_f = btllib.BiHashBi(seq_f, h, len(seq_f))
        bihash_r = btllib.BiHashBi(seq_r, h, len(seq_r))

        bihash_f.roll()
        bihash_r.roll()
        self.assertEqual(bihash_f.get_hash_num(), bihash_r.get_hash_num())
        self.assertEqual(list(bihash_f.hashes()), list(bihash_r.hashes()))

    def test_kmer_back_rolling(self):
        seq = "ACTAGACTG"
        h = 3
        k = 6

        bihash = btllib.BiHashBi(seq, h, k)
        hashes = []

        while bihash.roll():
            hashes.append(list(bihash.hashes()))

        self.assertEqual(len(hashes), len(seq) - k + 1)

        while True:
            self.assertEqual(list(bihash.hashes()), hashes.pop())
            if not bihash.roll_back():
                break

    def test_kmer_peeking(self):
        seq = "ACTGATCAG"
        h = 3
        k = 6

        bihash = btllib.BiHashBi(seq, h, k)
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

    def test_skipping_ns(self):
        seq = "ACGTACACTGGACTGAGTCTAAAA"
        seq_with_ns = list(seq)
        self.assertGreaterEqual(len(seq_with_ns), 10)

        mid = len(seq_with_ns) // 2
        seq_with_ns[mid] = 'N'
        seq_with_ns[mid + 1] = 'N'
        seq_with_ns = "".join(seq_with_ns)

        k = (len(seq) - 2) // 2 - 1
        bihash = btllib.BiHashBi(seq_with_ns, 3, k)

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

    def test_base_substitution(self):
        seq = "ACGTACACTGGACTGAGTCTAA"
        sub = "ACGCGCACTGGACTGAGTCTAA"

        bihash = btllib.BiHashBi(seq, 3, len(seq))
        bihash_subbed = btllib.BiHashBi(sub, 3, len(sub))

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

        bihash = btllib.BiHashBi(seq, 3, len(seq))
        bihash_no_meth = btllib.BiHashBi(seq_no_meth, 3, len(seq_no_meth))
        bihash_rc = btllib.BiHashBi(rc_seq, 3, len(rc_seq))
        bihash_rc_no_meth = btllib.BiHashBi(rc_seq_no_meth, 3, len(rc_seq_no_meth))

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

        self.assertEqual(bihash.is_methylated(0), bihash_rc.is_methylated(1))
        self.assertNotEqual(bihash.is_methylated(0), bihash_no_meth.is_methylated(0))
        self.assertNotEqual(bihash_rc.is_methylated(1), bihash_rc_no_meth.is_methylated(1))
        self.assertNotEqual(bihash.is_forward_higher(), bihash_rc.is_forward_higher())


if __name__ == "__main__":
    unittest.main()

