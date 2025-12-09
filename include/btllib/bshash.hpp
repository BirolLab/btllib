#pragma once

#include <array>
#include <cstdint>
#include <cstring>
#include <deque>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

#include <btllib/hashing_internals.hpp>
#include <btllib/bshash_kmer.hpp>
#include <btllib/bshash_kmer_directional.hpp>
#include <btllib/status.hpp>

namespace btllib {

/**
 * String representing the hash function's name. Only change if hash outputs
 * are different from the previous version. Useful for tracking differences in
 * saved hashes, e.g., in Bloom filters.
 */
static const char* const BSHASH_FN_NAME = "bsHash_v1";

} // namespace btllib