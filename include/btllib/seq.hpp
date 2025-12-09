/**
 * Functions for sequence manipulation.
 */
#ifndef BTLLIB_SEQ_HPP
#define BTLLIB_SEQ_HPP

#include "btllib/status.hpp"

#include <string>

namespace btllib {

extern const char COMPLEMENTS[256];
extern const char AMINO_ACIDS[256];
extern const char CAPITALS[256];
extern const char CT_CONVERSION[256];
extern const char GA_CONVERSION[256];

/**
 * Reverse complement a sequence in-place.
 *
 * @param seq Sequence to reverse complement.
 */
void
reverse_complement(std::string& seq);

/**
 * Obtain a reverse complement of the provided sequence. The argument sequence
 * is left untouched.
 *
 * @param seq Sequence to reverse complement.
 *
 * @return Reverse complemented sequence.
 */
std::string
get_reverse_complement(const std::string& seq);

/**
 * Perform bisulfite conversion on a sequence in-place.
 *
 * Depending on the specified conversion type ("CT" or "GA"), each character in
 * the sequence is replaced with its bisulfite-converted form using the
 * corresponding conversion table. The argument sequence is modified directly.
 *
 * @param seq  Sequence to convert.
 * @param type Conversion type ("CT" or "GA").
 */
void
bs_conversion(std::string& seq, std::string& type);

/**
 * Obtain a bisulfite-converted copy of the provided sequence. The argument
 * sequence is left untouched.
 *
 * @param seq  Sequence to convert.
 * @param type Conversion type ("CT" or "GA").
 *
 * @return Bisulfite-converted sequence.
 */
std::string
get_bs_conversion(const std::string& seq, std::string& type);

}

// namespace btllib

#endif
