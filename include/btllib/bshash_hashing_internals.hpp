#pragma once

#include <cstddef>
#include <iostream>
#include <limits>

#include <btllib/hashing_internals.hpp>

namespace btllib::hashing_internals {

static const uint64_t XX_SEED_N_ = SEED_N;

static const uint64_t BI_SEED_A_ = 0x6a8c7aa7db953866ULL;
static const uint64_t BI_SEED_T_ = 0x320d1bb2e76ae9f2ULL;

const uint64_t BS_BI_SEED_TAB[ASCII_SIZE] = {
  XX_SEED_N_, BI_SEED_T_, XX_SEED_N_, BI_SEED_A_,
  BI_SEED_A_, BI_SEED_A_, XX_SEED_N_, BI_SEED_T_, // 0..7
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 8..15
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 16..23
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 24..31
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 32..39
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 40..47
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 48..55
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 56..63
  XX_SEED_N_, BI_SEED_A_, XX_SEED_N_, BI_SEED_T_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, BI_SEED_A_, // 64..71
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 72..79
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  BI_SEED_T_, BI_SEED_T_, XX_SEED_N_, XX_SEED_N_, // 80..87
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 88..95
  XX_SEED_N_, BI_SEED_A_, XX_SEED_N_, BI_SEED_T_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, BI_SEED_A_, // 96..103
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 104..111
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  BI_SEED_T_, BI_SEED_T_, XX_SEED_N_, XX_SEED_N_, // 112..119
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 120..127
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 128..135
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 136..143
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 144..151
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 152..159
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 160..167
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 168..175
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 176..183
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 184..191
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 192..199
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 200..207
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 208..215
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 216..223
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 224..231
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 232..239
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 240..247
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_ // 248..255
};

static const uint64_t BI_A_33R[33] = {
    0x00000001db953866,     0x00000001b72a70cd,     0x000000016e54e19b,     0x00000000dca9c337,     0x00000001b953866e,     0x0000000172a70cdd,     0x00000000e54e19bb,     0x00000001ca9c3376,     0x00000001953866ed,     0x000000012a70cddb,
    0x0000000054e19bb7,     0x00000000a9c3376e,     0x0000000153866edc,     0x00000000a70cddb9,     0x000000014e19bb72,     0x000000009c3376e5,     0x000000013866edca,     0x0000000070cddb95,     0x00000000e19bb72a,     0x00000001c3376e54,
    0x00000001866edca9,     0x000000010cddb953,     0x0000000019bb72a7,     0x000000003376e54e,     0x0000000066edca9c,     0x00000000cddb9538,     0x000000019bb72a70,     0x00000001376e54e1,     0x000000006edca9c3,     0x00000000ddb95386,
    0x00000001bb72a70c,     0x0000000176e54e19,     0x00000000edca9c33 
};

static const uint64_t BI_A_31L[31] = {
    0x6a8c7aa600000000,     0xd518f54c00000000,     0xaa31ea9a00000000,     0x5463d53600000000,     0xa8c7aa6c00000000,     0x518f54da00000000,     0xa31ea9b400000000,     0x463d536a00000000,     0x8c7aa6d400000000,     0x18f54daa00000000,
    0x31ea9b5400000000,     0x63d536a800000000,     0xc7aa6d5000000000,     0x8f54daa200000000,     0x1ea9b54600000000,     0x3d536a8c00000000,     0x7aa6d51800000000,     0xf54daa3000000000,     0xea9b546200000000,     0xd536a8c600000000,
    0xaa6d518e00000000,     0x54daa31e00000000,     0xa9b5463c00000000,     0x536a8c7a00000000,     0xa6d518f400000000,     0x4daa31ea00000000,     0x9b5463d400000000,     0x36a8c7aa00000000,     0x6d518f5400000000,     0xdaa31ea800000000,
    0xb5463d5200000000 
};

// ===== BI_T =====
static const uint64_t BI_T_33R[33] = {
    0x00000000e76ae9f2,     0x00000001ced5d3e4,     0x000000019daba7c9,     0x000000013b574f93,     0x0000000076ae9f27,     0x00000000ed5d3e4e,     0x00000001daba7c9c,     0x00000001b574f939,     0x000000016ae9f273,     0x00000000d5d3e4e7,
    0x00000001aba7c9ce,     0x00000001574f939d,     0x00000000ae9f273b,     0x000000015d3e4e76,     0x00000000ba7c9ced,     0x0000000174f939da,     0x00000000e9f273b5,     0x00000001d3e4e76a,     0x00000001a7c9ced5,     0x000000014f939dab,
    0x000000009f273b57,     0x000000013e4e76ae,     0x000000007c9ced5d,     0x00000000f939daba,     0x00000001f273b574,     0x00000001e4e76ae9,     0x00000001c9ced5d3,     0x00000001939daba7,     0x00000001273b574f,     0x000000004e76ae9f,
    0x000000009ced5d3e,     0x0000000139daba7c,     0x0000000073b574f9 
};

static const uint64_t BI_T_31L[31] = {
    0x320d1bb200000000,     0x641a376400000000,     0xc8346ec800000000,     0x9068dd9200000000,     0x20d1bb2600000000,     0x41a3764c00000000,     0x8346ec9800000000,     0x68dd93200000000,     0xd1bb26400000000,     0x1a3764c800000000,
    0x346ec99000000000,     0x68dd932000000000,     0xd1bb264000000000,     0xa3764c8200000000,     0x46ec990600000000,     0x8dd9320c00000000,     0x1bb2641a00000000,     0x3764c83400000000,     0x6ec9906800000000,     0xdd9320d000000000,
    0xbb2641a200000000,     0x764c834600000000,     0xec99068c00000000,     0xd9320d1a00000000,     0xb2641a3600000000,     0x64c8346e00000000,     0xc99068dc00000000,     0x9320d1ba00000000,     0x2641a37600000000,     0x4c8346ec00000000,
    0x99068dd800000000 
};


const uint64_t XX_N_33R[33] = { SEED_N, SEED_N, SEED_N, SEED_N, SEED_N, SEED_N,
                                SEED_N, SEED_N, SEED_N, SEED_N, SEED_N, SEED_N,
                                SEED_N, SEED_N, SEED_N, SEED_N, SEED_N, SEED_N,
                                SEED_N, SEED_N, SEED_N, SEED_N, SEED_N, SEED_N,
                                SEED_N, SEED_N, SEED_N, SEED_N, SEED_N, SEED_N,
                                SEED_N, SEED_N, SEED_N };

const uint64_t XX_N_31L[31] = { SEED_N, SEED_N, SEED_N, SEED_N, SEED_N, SEED_N,
                                SEED_N, SEED_N, SEED_N, SEED_N, SEED_N, SEED_N,
                                SEED_N, SEED_N, SEED_N, SEED_N, SEED_N, SEED_N,
                                SEED_N, SEED_N, SEED_N, SEED_N, SEED_N, SEED_N,
                                SEED_N, SEED_N, SEED_N, SEED_N, SEED_N, SEED_N,
                                SEED_N };

const uint64_t BS_BI_DIMER_TAB[16] = {
    13804816994807007403ULL, 0ULL, 0ULL, 16651477977602758975ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    1051113059013159810ULL, 0ULL, 0ULL, 6203476314356136470ULL
    
};

const uint64_t BS_BI_TRIMER_TAB[64] = {
    1559764382008453424ULL, 0ULL, 0ULL, 5558572668666804388ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    11864635746089699865ULL, 0ULL, 0ULL, 18169427777599298445ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    8620137231271915362ULL, 0ULL, 0ULL, 3396136566885400310ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    14313041098185591883ULL, 0ULL, 0ULL, 11395024181815188959ULL
    
};

const uint64_t BS_BI_TETRAMER_TAB[256] = {
    4739669480572086791ULL, 0ULL, 0ULL, 1821654728216263571ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    17349117488419162414ULL, 0ULL, 0ULL, 12125118989076666554ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    2576960677352385621ULL, 0ULL, 0ULL, 8881754873906003393ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    10575004143309721468ULL, 0ULL, 0ULL, 14573814593982652136ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    9641565659040900771ULL, 0ULL, 0ULL, 15946360035580524343ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    3805395219231491466ULL, 0ULL, 0ULL, 7804205850964038686ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    16701665948108824817ULL, 0ULL, 0ULL, 13783651101934645605ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    0ULL, 0ULL, 0ULL, 0ULL, 
    6254090964361282520ULL, 0ULL, 0ULL, 1030092370127082060ULL
    
};

const uint64_t* const BS_BI_MS_TAB_33R[ASCII_SIZE] = {
  XX_N_33R, BI_T_33R, XX_N_33R, BI_A_33R,
  BI_A_33R, BI_A_33R, XX_N_33R, BI_T_33R, // 0..7
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 8..15
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 16..23
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 24..31
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 32..39
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 40..47
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 48..55
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 56..63
  XX_N_33R, BI_A_33R, XX_N_33R, BI_T_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, BI_A_33R, // 64..71
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 72..79
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  BI_T_33R, BI_T_33R, XX_N_33R, XX_N_33R, // 80..87
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 88..95
  XX_N_33R, BI_A_33R, XX_N_33R, BI_T_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, BI_A_33R, // 96..103
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 104..111
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  BI_T_33R, BI_T_33R, XX_N_33R, XX_N_33R, // 112..119
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 120..127
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 128..135
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 136..143
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 144..151
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 152..159
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 160..167
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 168..175
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 176..183
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 184..191
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 192..199
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 200..207
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 208..215
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 216..223
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 224..231
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 232..239
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 240..247
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R // 248..255
};

const uint64_t* const BS_BI_MS_TAB_31L[ASCII_SIZE] = {
  XX_N_31L, BI_T_31L, XX_N_31L, BI_A_31L,
  BI_A_31L, BI_A_31L, XX_N_31L, BI_T_31L, // 0..7
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 8..15
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 16..23
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 24..31
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 32..39
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 40..47
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 48..55
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 56..63
  XX_N_31L, BI_A_31L, XX_N_31L, BI_T_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, BI_A_31L, // 64..71
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 72..79
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  BI_T_31L, BI_T_31L, XX_N_31L, XX_N_31L, // 80..87
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 88..95
  XX_N_31L, BI_A_31L, XX_N_31L, BI_T_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, BI_A_31L, // 96..103
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 104..111
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  BI_T_31L, BI_T_31L, XX_N_31L, XX_N_31L, // 112..119
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 120..127
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 128..135
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 136..143
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 144..151
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 152..159
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 160..167
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 168..175
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 176..183
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 184..191
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 192..199
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 200..207
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 208..215
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 216..223
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 224..231
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 232..239
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 240..247
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L // 248..255
};

const uint8_t BS_BI_CONVERT_TAB[ASCII_SIZE] = {
  255, 255, 255, 255, 255, 255, 255, 255, // 0..7
  255, 255, 255, 255, 255, 255, 255, 255, // 8..15
  255, 255, 255, 255, 255, 255, 255, 255, // 16..23
  255, 255, 255, 255, 255, 255, 255, 255, // 24..31
  255, 255, 255, 255, 255, 255, 255, 255, // 32..39
  255, 255, 255, 255, 255, 255, 255, 255, // 40..47
  255, 255, 255, 255, 255, 255, 255, 255, // 48..55
  255, 255, 255, 255, 255, 255, 255, 255, // 56..63
  255, 0,   255, 3,   255, 255, 255, 0,   // 64..71
  255, 255, 255, 255, 255, 255, 255, 255, // 72..79
  255, 255, 255, 255, 3,   3,   255, 255, // 80..87
  255, 255, 255, 255, 255, 255, 255, 255, // 88..95
  255, 0,   255, 3,   255, 255, 255, 0,   // 96..103
  255, 255, 255, 255, 255, 255, 255, 255, // 104..111
  255, 255, 255, 255, 3,   3,   255, 255, // 112..119
  255, 255, 255, 255, 255, 255, 255, 255, // 120..127
  255, 255, 255, 255, 255, 255, 255, 255, // 128..135
  255, 255, 255, 255, 255, 255, 255, 255, // 136..143
  255, 255, 255, 255, 255, 255, 255, 255, // 144..151
  255, 255, 255, 255, 255, 255, 255, 255, // 152..159
  255, 255, 255, 255, 255, 255, 255, 255, // 160..167
  255, 255, 255, 255, 255, 255, 255, 255, // 168..175
  255, 255, 255, 255, 255, 255, 255, 255, // 176..183
  255, 255, 255, 255, 255, 255, 255, 255, // 184..191
  255, 255, 255, 255, 255, 255, 255, 255, // 192..199
  255, 255, 255, 255, 255, 255, 255, 255, // 200..207
  255, 255, 255, 255, 255, 255, 255, 255, // 208..215
  255, 255, 255, 255, 255, 255, 255, 255, // 216..223
  255, 255, 255, 255, 255, 255, 255, 255, // 224..231
  255, 255, 255, 255, 255, 255, 255, 255, // 232..239
  255, 255, 255, 255, 255, 255, 255, 255, // 240..247
  255, 255, 255, 255, 255, 255, 255, 255  // 248..255
};

const uint8_t BS_BI_RC_CONVERT_TAB[ASCII_SIZE] = {
  255, 255, 255, 255, 255, 255, 255, 255, // 0..7
  255, 255, 255, 255, 255, 255, 255, 255, // 8..15
  255, 255, 255, 255, 255, 255, 255, 255, // 16..23
  255, 255, 255, 255, 255, 255, 255, 255, // 24..31
  255, 255, 255, 255, 255, 255, 255, 255, // 32..39
  255, 255, 255, 255, 255, 255, 255, 255, // 40..47
  255, 255, 255, 255, 255, 255, 255, 255, // 48..55
  255, 255, 255, 255, 255, 255, 255, 255, // 56..63
  255, 3,   255, 0,   255, 255, 255, 3,   // 64..71
  255, 255, 255, 255, 255, 255, 255, 255, // 72..79
  255, 255, 255, 255, 0,   0,   255, 255, // 80..87
  255, 255, 255, 255, 255, 255, 255, 255, // 88..95
  255, 3,   255, 0,   255, 255, 255, 3,   // 96..103
  255, 255, 255, 255, 255, 255, 255, 255, // 104..111
  255, 255, 255, 255, 0,   0,   255, 255, // 112..119
  255, 255, 255, 255, 255, 255, 255, 255, // 120..127
  255, 255, 255, 255, 255, 255, 255, 255, // 128..135
  255, 255, 255, 255, 255, 255, 255, 255, // 136..143
  255, 255, 255, 255, 255, 255, 255, 255, // 144..151
  255, 255, 255, 255, 255, 255, 255, 255, // 152..159
  255, 255, 255, 255, 255, 255, 255, 255, // 160..167
  255, 255, 255, 255, 255, 255, 255, 255, // 168..175
  255, 255, 255, 255, 255, 255, 255, 255, // 176..183
  255, 255, 255, 255, 255, 255, 255, 255, // 184..191
  255, 255, 255, 255, 255, 255, 255, 255, // 192..199
  255, 255, 255, 255, 255, 255, 255, 255, // 200..207
  255, 255, 255, 255, 255, 255, 255, 255, // 208..215
  255, 255, 255, 255, 255, 255, 255, 255, // 216..223
  255, 255, 255, 255, 255, 255, 255, 255, // 224..231
  255, 255, 255, 255, 255, 255, 255, 255, // 232..239
  255, 255, 255, 255, 255, 255, 255, 255, // 240..247
  255, 255, 255, 255, 255, 255, 255, 255  // 248..255
};

// Group CTConversion XOR pairs (6 SEEDs → 3 pairs)
static const uint64_t CT_SEED_A_ = 0x38e1680db3188ddfULL; // 0
static const uint64_t CT_SEED_G_ = 0x07d6453133a367b1ULL; // 2
static const uint64_t CT_SEED_CT = 0x2c555d4ed6a221a1ULL; // 3
                                                          // 3

// Group GAConversion XOR pairs (6 SEEDs → 3 pairs)
static const uint64_t GA_SEED_GA = 0x4d9c9d29392bb7d6ULL; // 0
static const uint64_t GA_SEED_C_ = 0x0e06d727c6e35043ULL; // 1
static const uint64_t GA_SEED_T_ = 0x013a8fe8dea57b07ULL; // 3
inline const std::unordered_set<std::string> VALID_MODES = { "CG",
                                                             "CC",
                                                             "CT",
                                                             "CA" };

const uint64_t BS_CT_SEED_TAB[ASCII_SIZE] = {
  XX_SEED_N_, GA_SEED_T_, XX_SEED_N_, GA_SEED_GA,
  GA_SEED_GA, GA_SEED_GA, XX_SEED_N_, GA_SEED_C_, // 0..7
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 8..15
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 16..23
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 24..31
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 32..39
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 40..47
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 48..55
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 56..63
  XX_SEED_N_, CT_SEED_A_, XX_SEED_N_, CT_SEED_CT,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, CT_SEED_G_, // 64..71
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 72..79
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  CT_SEED_CT, CT_SEED_CT, XX_SEED_N_, XX_SEED_N_, // 80..87
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 88..95
  XX_SEED_N_, CT_SEED_A_, XX_SEED_N_, CT_SEED_CT,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, CT_SEED_G_, // 96..103
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 104..111
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  CT_SEED_CT, CT_SEED_CT, XX_SEED_N_, XX_SEED_N_, // 112..119
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 120..127
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 128..135
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 136..143
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 144..151
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 152..159
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 160..167
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 168..175
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 176..183
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 184..191
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 192..199
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 200..207
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 208..215
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 216..223
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 224..231
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 232..239
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 240..247
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_ // 248..255
};

const uint64_t BS_GA_SEED_TAB[ASCII_SIZE] = {
  XX_SEED_N_, CT_SEED_CT, XX_SEED_N_, CT_SEED_G_,
  CT_SEED_A_, CT_SEED_A_, XX_SEED_N_, CT_SEED_CT, // 0..7
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 8..15
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 16..23
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 24..31
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 32..39
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 40..47
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 48..55
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 56..63
  XX_SEED_N_, GA_SEED_GA, XX_SEED_N_, GA_SEED_C_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, GA_SEED_GA, // 64..71
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 72..79
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  GA_SEED_T_, GA_SEED_T_, XX_SEED_N_, XX_SEED_N_, // 80..87
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 88..95
  XX_SEED_N_, GA_SEED_GA, XX_SEED_N_, GA_SEED_C_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, GA_SEED_GA, // 96..103
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 104..111
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  GA_SEED_T_, GA_SEED_T_, XX_SEED_N_, XX_SEED_N_, // 112..119
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 120..127
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 128..135
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 136..143
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 144..151
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 152..159
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 160..167
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 168..175
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 176..183
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 184..191
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 192..199
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 200..207
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 208..215
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 216..223
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 224..231
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 232..239
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, // 240..247
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_,
  XX_SEED_N_, XX_SEED_N_, XX_SEED_N_, XX_SEED_N_ // 248..255
};

const uint64_t BS_CT_DIMER_TAB[16] = { 5270258388568741472ULL,
                                       0ULL,
                                       8508589596476603406ULL,
                                       6744014374774716958ULL,
                                       0ULL,
                                       0ULL,
                                       0ULL,
                                       0ULL,
                                       3985090206635016892ULL,
                                       0ULL,
                                       611028647685761234ULL,
                                       2592339656081469122ULL,
                                       6938871167320903325ULL,
                                       0ULL,
                                       6880655447580681459ULL,
                                       8430711922963669731ULL

};

const uint64_t BS_CT_TRIMER_TAB[64] = { 12296542375903994143ULL,
                                        0ULL,
                                        10777453763052456817ULL,
                                        13696059339288153441ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        15332577898988860867ULL,
                                        0ULL,
                                        17005433182935818157ULL,
                                        13870091925232998845ULL,
                                        9497654699218631138ULL,
                                        0ULL,
                                        13617020073335395212ULL,
                                        10915115690247869852ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        6231483061417281702ULL,
                                        0ULL,
                                        7587863783224107720ULL,
                                        4813953927640687832ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        2888204484391197818ULL,
                                        0ULL,
                                        1667417705464477204ULL,
                                        4368707067656630276ULL,
                                        9156599042800701531ULL,
                                        0ULL,
                                        4622359443003849269ULL,
                                        7757154674165939237ULL,
                                        17903722964224905445ULL,
                                        0ULL,
                                        14358003450906344075ULL,
                                        17060471493690637467ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        9662639389952885817ULL,
                                        0ULL,
                                        13344089177003470423ULL,
                                        10569000649149409351ULL,
                                        15068665748674332696ULL,
                                        0ULL,
                                        17161400230922396278ULL,
                                        14243358305793533030ULL

};

const uint64_t BS_CT_TETRAMER_TAB[256] = { 7903069985244696545ULL,
                                           0ULL,
                                           5952199028685153679ULL,
                                           8726125620783047583ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           1423984374654180157ULL,
                                           0ULL,
                                           3239265717627122003ULL,
                                           537959694350858051ULL,
                                           4955422779349047068ULL,
                                           0ULL,
                                           8931236194499526002ULL,
                                           5796422442532485986ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           10480418080795158104ULL,
                                           0ULL,
                                           12557937413778541622ULL,
                                           9639350223324760614ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           17230691697404916356ULL,
                                           0ULL,
                                           14999410022686677226ULL,
                                           18134732970037944058ULL,
                                           13265781732207312549ULL,
                                           0ULL,
                                           9740911128328721611ULL,
                                           12442798639878738651ULL,
                                           4574968163017784859ULL,
                                           0ULL,
                                           21005562311251061ULL,
                                           3155255381851099749ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           4689328268616313543ULL,
                                           0ULL,
                                           9089664875619762345ULL,
                                           6172150804119029433ULL,
                                           1591432901806794470ULL,
                                           0ULL,
                                           2964154664228736136ULL,
                                           189664148293585560ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           10670208004106787987ULL,
                                           0ULL,
                                           12331731648208664317ULL,
                                           9268413422807691501ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           16895935546904758351ULL,
                                           0ULL,
                                           15370019031266140705ULL,
                                           18360716771597345841ULL,
                                           13653888368900424814ULL,
                                           0ULL,
                                           9388727718593310208ULL,
                                           12234149755652892688ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           7550431377666028842ULL,
                                           0ULL,
                                           6340971969386962756ULL,
                                           8970238170159749460ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           1632237297318027766ULL,
                                           0ULL,
                                           2995441377836469144ULL,
                                           149439503918058888ULL,
                                           4729043290971336151ULL,
                                           0ULL,
                                           9121973896872036281ULL,
                                           6130765314036646313ULL,
                                           14322824142644718953ULL,
                                           0ULL,
                                           18010960957546809095ULL,
                                           15163850771780370711ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           13306657871389129141ULL,
                                           0ULL,
                                           9772129397874496475ULL,
                                           12402503902173812171ULL,
                                           17270334977163097492ULL,
                                           0ULL,
                                           15031787489074651130ULL,
                                           18093417574358702570ULL,
                                           14415162961378847764ULL,
                                           0ULL,
                                           17815078398106617466ULL,
                                           15904680980454047850ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           13142251585342896328ULL,
                                           0ULL,
                                           9895962073632248486ULL,
                                           11733738969707828406ULL,
                                           16241274185646601449ULL,
                                           0ULL,
                                           16020348337179074183ULL,
                                           17712848172773365911ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           3805619366837683629ULL,
                                           0ULL,
                                           857772563979235267ULL,
                                           2334117937676265939ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           5385773951433757041ULL,
                                           0ULL,
                                           8469355426070739743ULL,
                                           6776274342720863503ULL,
                                           2141510149062286672ULL,
                                           0ULL,
                                           2490210351169910590ULL,
                                           651923950472458542ULL,
                                           11158837266677243374ULL,
                                           0ULL,
                                           11955661059224500096ULL,
                                           10261471664026595728ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           16479371589667244338ULL,
                                           0ULL,
                                           15818137341953581916ULL,
                                           17295591019177141580ULL,
                                           12949060435646432531ULL,
                                           0ULL,
                                           10125042934416846717ULL,
                                           12033750801055738221ULL

};

const uint64_t BS_GA_DIMER_TAB[16] = { 15466952634673191035ULL,
                                       10754575533572636654ULL,
                                       0ULL,
                                       11097913711551190186ULL,
                                       5877535496320390993ULL,
                                       1300266414860792004ULL,
                                       0ULL,
                                       2105188344771369856ULL,
                                       0ULL,
                                       0ULL,
                                       0ULL,
                                       0ULL,
                                       5758277602454356440ULL,
                                       897281711739086413ULL,
                                       0ULL,
                                       238567881438104841ULL

};

const uint64_t BS_GA_TRIMER_TAB[64] = { 16201651124989724449ULL,
                                        11767230542839996596ULL,
                                        0ULL,
                                        12425925165519260656ULL,
                                        7485905922695612427ULL,
                                        2628147013137149854ULL,
                                        0ULL,
                                        3117991808660735194ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        8762868368011140738ULL,
                                        4179829000807872791ULL,
                                        0ULL,
                                        3836473814229799507ULL,
                                        17203464567451130228ULL,
                                        12476292506423230177ULL,
                                        0ULL,
                                        11680341964607149477ULL,
                                        7605014056128239198ULL,
                                        3030964276180857291ULL,
                                        0ULL,
                                        2678653576253708943ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        8643215145753641175ULL,
                                        3776431493625472834ULL,
                                        0ULL,
                                        4275266935868017670ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        15154499325442733158ULL,
                                        10508537125562078195ULL,
                                        0ULL,
                                        11450835371142150327ULL,
                                        6159530959071411020ULL,
                                        1648676777120242905ULL,
                                        0ULL,
                                        1863678824033957789ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        0ULL,
                                        5405372172001914309ULL,
                                        619798376795097680ULL,
                                        0ULL,
                                        551039597220094228ULL

};

const uint64_t BS_GA_TETRAMER_TAB[256] = { 10102482841122093461ULL,
                                           14963615003264376320ULL,
                                           0ULL,
                                           13877042217463412036ULL,
                                           794795739487041215ULL,
                                           5232589638041243946ULL,
                                           0ULL,
                                           5161613641720576622ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           1548991017688113206ULL,
                                           6261504389880137635ULL,
                                           0ULL,
                                           6474221187766217959ULL,
                                           9392840475291690944ULL,
                                           13961256338029068373ULL,
                                           0ULL,
                                           14914796497557187345ULL,
                                           391398344175249642ULL,
                                           5112936561611444095ULL,
                                           0ULL,
                                           5316662609698825275ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           1951808117724528227ULL,
                                           6380612394262551030ULL,
                                           0ULL,
                                           6318591945652269746ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           13739200011520215762ULL,
                                           18244429068126416199ULL,
                                           0ULL,
                                           17441706179187852803ULL,
                                           4152289719497344504ULL,
                                           8792626876107301485ULL,
                                           0ULL,
                                           8447054438424348969ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           2875359367268995953ULL,
                                           7240976841901733092ULL,
                                           0ULL,
                                           7728536354038472608ULL,
                                           10439742971334657342ULL,
                                           15238809933785883307ULL,
                                           0ULL,
                                           15872787535609874927ULL,
                                           1717559167161027092ULL,
                                           6075273402150661505ULL,
                                           0ULL,
                                           6589870402902132421ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           697300835471006877ULL,
                                           5347749012401158920ULL,
                                           0ULL,
                                           4975173205340442700ULL,
                                           11423453917689355115ULL,
                                           15929804584091122942ULL,
                                           0ULL,
                                           15145130632992380858ULL,
                                           1854593325084628033ULL,
                                           6496051875600806868ULL,
                                           0ULL,
                                           6132429400583706768ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           559685854125523656ULL,
                                           4926424929898751325ULL,
                                           0ULL,
                                           5432033363231264281ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           11707425986759079545ULL,
                                           16276972118015169004ULL,
                                           0ULL,
                                           17212532555803097768ULL,
                                           2688004620665649491ULL,
                                           7410673165475159750ULL,
                                           0ULL,
                                           7632377835808404866ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           4266321074409320410ULL,
                                           8696255610672826447ULL,
                                           0ULL,
                                           8616255423678309131ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           16790453619013574426ULL,
                                           12293110188280461455ULL,
                                           0ULL,
                                           11936155684350399435ULL,
                                           7941878618842992688ULL,
                                           3291412832639317925ULL,
                                           0ULL,
                                           2490818554466065633ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           8092837802684991161ULL,
                                           3735105958421766444ULL,
                                           0ULL,
                                           4389210678668986984ULL,
                                           16675286395804860751ULL,
                                           11885226664861542106ULL,
                                           0ULL,
                                           12379434820203482526ULL,
                                           6944006080901647973ULL,
                                           2577284614385265136ULL,
                                           0ULL,
                                           3240342666676093620ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           9090130062791399660ULL,
                                           4448689121532002169ULL,
                                           0ULL,
                                           3639106275939783741ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           15824496359018523741ULL,
                                           10953226629488970696ULL,
                                           0ULL,
                                           10898136436499554444ULL,
                                           6678683788476883831ULL,
                                           2248766861403210978ULL,
                                           0ULL,
                                           1155561727788445606ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           0ULL,
                                           4816531739325199870ULL,
                                           93880803705459307ULL,
                                           0ULL,
                                           1040842618995587375ULL

};

// ===== CTConversion_XOR_1_4 =====
static const uint64_t CT_A_33R[33] = {
  0x00000001b3188ddf, 0x0000000166311bbf, 0x00000000cc62377f,
  0x0000000198c46efe, 0x000000013188ddfd, 0x000000006311bbfb,
  0x00000000c62377f6, 0x000000018c46efec, 0x00000001188ddfd9,
  0x00000000311bbfb3, 0x0000000062377f66, 0x00000000c46efecc,
  0x0000000188ddfd98, 0x0000000111bbfb31, 0x000000002377f663,
  0x0000000046efecc6, 0x000000008ddfd98c, 0x000000011bbfb318,
  0x00000000377f6631, 0x000000006efecc62, 0x00000000ddfd98c4,
  0x00000001bbfb3188, 0x0000000177f66311, 0x00000000efecc623,
  0x00000001dfd98c46, 0x00000001bfb3188d, 0x000000017f66311b,
  0x00000000fecc6237, 0x00000001fd98c46e, 0x00000001fb3188dd,
  0x00000001f66311bb, 0x00000001ecc62377, 0x00000001d98c46ef
};

static const uint64_t CT_A_31L[31] = {
  0x38e1680c00000000, 0x71c2d01800000000, 0xe385a03000000000,
  0xc70b406200000000, 0x8e1680c600000000, 0x1c2d018e00000000,
  0x385a031c00000000, 0x70b4063800000000, 0xe1680c7000000000,
  0xc2d018e200000000, 0x85a031c600000000, 0xb40638e00000000,
  0x1680c71c00000000, 0x2d018e3800000000, 0x5a031c7000000000,
  0xb40638e000000000, 0x680c71c200000000, 0xd018e38400000000,
  0xa031c70a00000000, 0x40638e1600000000, 0x80c71c2c00000000,
  0x18e385a00000000,  0x31c70b400000000,  0x638e16800000000,
  0xc71c2d000000000,  0x18e385a000000000, 0x31c70b4000000000,
  0x638e168000000000, 0xc71c2d0000000000, 0x8e385a0200000000,
  0x1c70b40600000000
};

// ===== CTConversion_XOR_2_5 =====
static const uint64_t CT_G_33R[33] = {
  0x0000000133a367b1, 0x000000006746cf63, 0x00000000ce8d9ec6,
  0x000000019d1b3d8c, 0x000000013a367b19, 0x00000000746cf633,
  0x00000000e8d9ec66, 0x00000001d1b3d8cc, 0x00000001a367b199,
  0x0000000146cf6333, 0x000000008d9ec667, 0x000000011b3d8cce,
  0x00000000367b199d, 0x000000006cf6333a, 0x00000000d9ec6674,
  0x00000001b3d8cce8, 0x0000000167b199d1, 0x00000000cf6333a3,
  0x000000019ec66746, 0x000000013d8cce8d, 0x000000007b199d1b,
  0x00000000f6333a36, 0x00000001ec66746c, 0x00000001d8cce8d9,
  0x00000001b199d1b3, 0x000000016333a367, 0x00000000c66746cf,
  0x000000018cce8d9e, 0x00000001199d1b3d, 0x00000000333a367b,
  0x0000000066746cf6, 0x00000000cce8d9ec, 0x0000000199d1b3d8
};

static const uint64_t CT_G_31L[31] = {
  0x7d6453000000000,  0xfac8a6000000000,  0x1f5914c000000000,
  0x3eb2298000000000, 0x7d64530000000000, 0xfac8a60000000000,
  0xf5914c0200000000, 0xeb22980600000000, 0xd645300e00000000,
  0xac8a601e00000000, 0x5914c03e00000000, 0xb229807c00000000,
  0x645300fa00000000, 0xc8a601f400000000, 0x914c03ea00000000,
  0x229807d600000000, 0x45300fac00000000, 0x8a601f5800000000,
  0x14c03eb200000000, 0x29807d6400000000, 0x5300fac800000000,
  0xa601f59000000000, 0x4c03eb2200000000, 0x9807d64400000000,
  0x300fac8a00000000, 0x601f591400000000, 0xc03eb22800000000,
  0x807d645200000000, 0xfac8a600000000,   0x1f5914c00000000,
  0x3eb229800000000
};

// ===== CTConversion_XOR_3_6 =====
static const uint64_t CT_CT33R[33] = {
  0x00000000d6a221a1, 0x00000001ad444342, 0x000000015a888685,
  0x00000000b5110d0b, 0x000000016a221a16, 0x00000000d444342d,
  0x00000001a888685a, 0x000000015110d0b5, 0x00000000a221a16b,
  0x00000001444342d6, 0x00000000888685ad, 0x00000001110d0b5a,
  0x00000000221a16b5, 0x0000000044342d6a, 0x0000000088685ad4,
  0x0000000110d0b5a8, 0x0000000021a16b51, 0x000000004342d6a2,
  0x000000008685ad44, 0x000000010d0b5a88, 0x000000001a16b511,
  0x00000000342d6a22, 0x00000000685ad444, 0x00000000d0b5a888,
  0x00000001a16b5110, 0x0000000142d6a221, 0x0000000085ad4443,
  0x000000010b5a8886, 0x0000000016b5110d, 0x000000002d6a221a,
  0x000000005ad44434, 0x00000000b5a88868, 0x000000016b5110d0
};

static const uint64_t CT_CT31L[31] = {
  0x2c555d4e00000000, 0x58aaba9c00000000, 0xb155753800000000,
  0x62aaea7200000000, 0xc555d4e400000000, 0x8aaba9ca00000000,
  0x1557539600000000, 0x2aaea72c00000000, 0x555d4e5800000000,
  0xaaba9cb000000000, 0x5575396200000000, 0xaaea72c400000000,
  0x55d4e58a00000000, 0xaba9cb1400000000, 0x5753962a00000000,
  0xaea72c5400000000, 0x5d4e58aa00000000, 0xba9cb15400000000,
  0x753962aa00000000, 0xea72c55400000000, 0xd4e58aaa00000000,
  0xa9cb155600000000, 0x53962aae00000000, 0xa72c555c00000000,
  0x4e58aaba00000000, 0x9cb1557400000000, 0x3962aaea00000000,
  0x72c555d400000000, 0xe58aaba800000000, 0xcb15575200000000,
  0x962aaea600000000
};

// ===== GAConversion_XOR_1_4 =====
static const uint64_t GA_GA33R[33] = {
  0x00000001392bb7d6, 0x0000000072576fad, 0x00000000e4aedf5a,
  0x00000001c95dbeb4, 0x0000000192bb7d69, 0x000000012576fad3,
  0x000000004aedf5a7, 0x0000000095dbeb4e, 0x000000012bb7d69c,
  0x00000000576fad39, 0x00000000aedf5a72, 0x000000015dbeb4e4,
  0x00000000bb7d69c9, 0x0000000176fad392, 0x00000000edf5a725,
  0x00000001dbeb4e4a, 0x00000001b7d69c95, 0x000000016fad392b,
  0x00000000df5a7257, 0x00000001beb4e4ae, 0x000000017d69c95d,
  0x00000000fad392bb, 0x00000001f5a72576, 0x00000001eb4e4aed,
  0x00000001d69c95db, 0x00000001ad392bb7, 0x000000015a72576f,
  0x00000000b4e4aedf, 0x0000000169c95dbe, 0x00000000d392bb7d,
  0x00000001a72576fa, 0x000000014e4aedf5, 0x000000009c95dbeb
};

static const uint64_t GA_GA31L[31] = {
  0x4d9c9d2800000000, 0x9b393a5000000000, 0x367274a200000000,
  0x6ce4e94400000000, 0xd9c9d28800000000, 0xb393a51200000000,
  0x67274a2600000000, 0xce4e944c00000000, 0x9c9d289a00000000,
  0x393a513600000000, 0x7274a26c00000000, 0xe4e944d800000000,
  0xc9d289b200000000, 0x93a5136600000000, 0x274a26ce00000000,
  0x4e944d9c00000000, 0x9d289b3800000000, 0x3a51367200000000,
  0x74a26ce400000000, 0xe944d9c800000000, 0xd289b39200000000,
  0xa513672600000000, 0x4a26ce4e00000000, 0x944d9c9c00000000,
  0x289b393a00000000, 0x5136727400000000, 0xa26ce4e800000000,
  0x44d9c9d200000000, 0x89b393a400000000, 0x1367274a00000000,
  0x26ce4e9400000000
};

// ===== GAConversion_XOR_2_5 =====
static const uint64_t GA_C_33R[33] = {
  0x00000001c6e35043, 0x000000018dc6a087, 0x000000011b8d410f,
  0x00000000371a821f, 0x000000006e35043e, 0x00000000dc6a087c,
  0x00000001b8d410f8, 0x0000000171a821f1, 0x00000000e35043e3,
  0x00000001c6a087c6, 0x000000018d410f8d, 0x000000011a821f1b,
  0x0000000035043e37, 0x000000006a087c6e, 0x00000000d410f8dc,
  0x00000001a821f1b8, 0x000000015043e371, 0x00000000a087c6e3,
  0x00000001410f8dc6, 0x00000000821f1b8d, 0x00000001043e371a,
  0x00000000087c6e35, 0x0000000010f8dc6a, 0x0000000021f1b8d4,
  0x0000000043e371a8, 0x0000000087c6e350, 0x000000010f8dc6a0,
  0x000000001f1b8d41, 0x000000003e371a82, 0x000000007c6e3504,
  0x00000000f8dc6a08, 0x00000001f1b8d410, 0x00000001e371a821
};

static const uint64_t GA_C_31L[31] = {
  0xe06d72600000000,  0x1c0dae4c00000000, 0x381b5c9800000000,
  0x7036b93000000000, 0xe06d726000000000, 0xc0dae4c200000000,
  0x81b5c98600000000, 0x36b930e00000000,  0x6d7261c00000000,
  0xdae4c3800000000,  0x1b5c987000000000, 0x36b930e000000000,
  0x6d7261c000000000, 0xdae4c38000000000, 0xb5c9870200000000,
  0x6b930e0600000000, 0xd7261c0c00000000, 0xae4c381a00000000,
  0x5c98703600000000, 0xb930e06c00000000, 0x7261c0da00000000,
  0xe4c381b400000000, 0xc987036a00000000, 0x930e06d600000000,
  0x261c0dae00000000, 0x4c381b5c00000000, 0x987036b800000000,
  0x30e06d7200000000, 0x61c0dae400000000, 0xc381b5c800000000,
  0x87036b9200000000
};

// ===== GAConversion_XOR_3_6 =====
static const uint64_t GA_T_33R[33] = {
  0x00000000dea57b07, 0x00000001bd4af60e, 0x000000017a95ec1d,
  0x00000000f52bd83b, 0x00000001ea57b076, 0x00000001d4af60ed,
  0x00000001a95ec1db, 0x0000000152bd83b7, 0x00000000a57b076f,
  0x000000014af60ede, 0x0000000095ec1dbd, 0x000000012bd83b7a,
  0x0000000057b076f5, 0x00000000af60edea, 0x000000015ec1dbd4,
  0x00000000bd83b7a9, 0x000000017b076f52, 0x00000000f60edea5,
  0x00000001ec1dbd4a, 0x00000001d83b7a95, 0x00000001b076f52b,
  0x0000000160edea57, 0x00000000c1dbd4af, 0x0000000183b7a95e,
  0x00000001076f52bd, 0x000000000edea57b, 0x000000001dbd4af6,
  0x000000003b7a95ec, 0x0000000076f52bd8, 0x00000000edea57b0,
  0x00000001dbd4af60, 0x00000001b7a95ec1, 0x000000016f52bd83
};

static const uint64_t GA_T_31L[31] = {
  0x13a8fe800000000,  0x2751fd000000000,  0x4ea3fa000000000,
  0x9d47f4000000000,  0x13a8fe8000000000, 0x2751fd0000000000,
  0x4ea3fa0000000000, 0x9d47f40000000000, 0x3a8fe80200000000,
  0x751fd00400000000, 0xea3fa00800000000, 0xd47f401200000000,
  0xa8fe802600000000, 0x51fd004e00000000, 0xa3fa009c00000000,
  0x47f4013a00000000, 0x8fe8027400000000, 0x1fd004ea00000000,
  0x3fa009d400000000, 0x7f4013a800000000, 0xfe80275000000000,
  0xfd004ea200000000, 0xfa009d4600000000, 0xf4013a8e00000000,
  0xe802751e00000000, 0xd004ea3e00000000, 0xa009d47e00000000,
  0x4013a8fe00000000, 0x802751fc00000000, 0x4ea3fa00000000,
  0x9d47f400000000
};

const uint64_t* const BS_CT_MS_TAB_33R[ASCII_SIZE] = {
  XX_N_33R, GA_T_33R, XX_N_33R, GA_GA33R,
  GA_GA33R, GA_GA33R, XX_N_33R, GA_C_33R, // 0..7
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 8..15
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 16..23
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 24..31
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 32..39
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 40..47
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 48..55
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 56..63
  XX_N_33R, CT_A_33R, XX_N_33R, CT_CT33R,
  XX_N_33R, XX_N_33R, XX_N_33R, CT_G_33R, // 64..71
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 72..79
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  CT_CT33R, CT_CT33R, XX_N_33R, XX_N_33R, // 80..87
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 88..95
  XX_N_33R, CT_A_33R, XX_N_33R, CT_CT33R,
  XX_N_33R, XX_N_33R, XX_N_33R, CT_G_33R, // 96..103
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 104..111
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  CT_CT33R, CT_CT33R, XX_N_33R, XX_N_33R, // 112..119
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 120..127
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 128..135
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 136..143
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 144..151
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 152..159
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 160..167
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 168..175
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 176..183
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 184..191
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 192..199
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 200..207
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 208..215
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 216..223
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 224..231
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 232..239
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 240..247
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R // 248..255
};

const uint64_t* const BS_CT_MS_TAB_31L[ASCII_SIZE] = {
  XX_N_31L, GA_T_31L, XX_N_31L, GA_GA31L,
  GA_GA31L, GA_GA31L, XX_N_31L, GA_C_31L, // 0..7
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 8..15
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 16..23
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 24..31
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 32..39
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 40..47
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 48..55
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 56..63
  XX_N_31L, CT_A_31L, XX_N_31L, CT_CT31L,
  XX_N_31L, XX_N_31L, XX_N_31L, CT_G_31L, // 64..71
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 72..79
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  CT_CT31L, CT_CT31L, XX_N_31L, XX_N_31L, // 80..87
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 88..95
  XX_N_31L, CT_A_31L, XX_N_31L, CT_CT31L,
  XX_N_31L, XX_N_31L, XX_N_31L, CT_G_31L, // 96..103
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 104..111
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  CT_CT31L, CT_CT31L, XX_N_31L, XX_N_31L, // 112..119
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 120..127
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 128..135
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 136..143
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 144..151
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 152..159
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 160..167
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 168..175
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 176..183
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 184..191
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 192..199
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 200..207
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 208..215
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 216..223
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 224..231
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 232..239
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 240..247
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L // 248..255
};

const uint64_t* const BS_GA_MS_TAB_33R[ASCII_SIZE] = {
  XX_N_33R, CT_CT33R, XX_N_33R, CT_G_33R,
  CT_A_33R, CT_A_33R, XX_N_33R, CT_CT33R, // 0..7
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 8..15
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 16..23
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 24..31
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 32..39
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 40..47
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 48..55
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 56..63
  XX_N_33R, GA_GA33R, XX_N_33R, GA_C_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, GA_GA33R, // 64..71
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 72..79
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  GA_T_33R, GA_T_33R, XX_N_33R, XX_N_33R, // 80..87
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 88..95
  XX_N_33R, GA_GA33R, XX_N_33R, GA_C_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, GA_GA33R, // 96..103
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 104..111
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  GA_T_33R, GA_T_33R, XX_N_33R, XX_N_33R, // 112..119
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 120..127
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 128..135
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 136..143
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 144..151
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 152..159
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 160..167
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 168..175
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 176..183
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 184..191
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 192..199
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 200..207
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 208..215
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 216..223
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 224..231
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 232..239
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R, // 240..247
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R,
  XX_N_33R, XX_N_33R, XX_N_33R, XX_N_33R // 248..255
};

const uint64_t* const BS_GA_MS_TAB_31L[ASCII_SIZE] = {
  XX_N_31L, CT_CT31L, XX_N_31L, CT_G_31L,
  CT_A_31L, CT_A_31L, XX_N_31L, CT_CT31L, // 0..7
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 8..15
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 16..23
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 24..31
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 32..39
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 40..47
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 48..55
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 56..63
  XX_N_31L, GA_GA31L, XX_N_31L, GA_C_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, GA_GA31L, // 64..71
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 72..79
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  GA_T_31L, GA_T_31L, XX_N_31L, XX_N_31L, // 80..87
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 88..95
  XX_N_31L, GA_GA31L, XX_N_31L, GA_C_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, GA_GA31L, // 96..103
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 104..111
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  GA_T_31L, GA_T_31L, XX_N_31L, XX_N_31L, // 112..119
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 120..127
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 128..135
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 136..143
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 144..151
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 152..159
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 160..167
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 168..175
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 176..183
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 184..191
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 192..199
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 200..207
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 208..215
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 216..223
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 224..231
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 232..239
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L, // 240..247
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L,
  XX_N_31L, XX_N_31L, XX_N_31L, XX_N_31L // 248..255
};

const uint8_t BS_CT_CONVERT_TAB[ASCII_SIZE] = {
  255, 255, 255, 255, 255, 255, 255, 255, // 0..7
  255, 255, 255, 255, 255, 255, 255, 255, // 8..15
  255, 255, 255, 255, 255, 255, 255, 255, // 16..23
  255, 255, 255, 255, 255, 255, 255, 255, // 24..31
  255, 255, 255, 255, 255, 255, 255, 255, // 32..39
  255, 255, 255, 255, 255, 255, 255, 255, // 40..47
  255, 255, 255, 255, 255, 255, 255, 255, // 48..55
  255, 255, 255, 255, 255, 255, 255, 255, // 56..63
  255, 0,   255, 3,   255, 255, 255, 2,   // 64..71
  255, 255, 255, 255, 255, 255, 255, 255, // 72..79
  255, 255, 255, 255, 3,   3,   255, 255, // 80..87
  255, 255, 255, 255, 255, 255, 255, 255, // 88..95
  255, 0,   255, 3,   255, 255, 255, 2,   // 96..103
  255, 255, 255, 255, 255, 255, 255, 255, // 104..111
  255, 255, 255, 255, 3,   3,   255, 255, // 112..119
  255, 255, 255, 255, 255, 255, 255, 255, // 120..127
  255, 255, 255, 255, 255, 255, 255, 255, // 128..135
  255, 255, 255, 255, 255, 255, 255, 255, // 136..143
  255, 255, 255, 255, 255, 255, 255, 255, // 144..151
  255, 255, 255, 255, 255, 255, 255, 255, // 152..159
  255, 255, 255, 255, 255, 255, 255, 255, // 160..167
  255, 255, 255, 255, 255, 255, 255, 255, // 168..175
  255, 255, 255, 255, 255, 255, 255, 255, // 176..183
  255, 255, 255, 255, 255, 255, 255, 255, // 184..191
  255, 255, 255, 255, 255, 255, 255, 255, // 192..199
  255, 255, 255, 255, 255, 255, 255, 255, // 200..207
  255, 255, 255, 255, 255, 255, 255, 255, // 208..215
  255, 255, 255, 255, 255, 255, 255, 255, // 216..223
  255, 255, 255, 255, 255, 255, 255, 255, // 224..231
  255, 255, 255, 255, 255, 255, 255, 255, // 232..239
  255, 255, 255, 255, 255, 255, 255, 255, // 240..247
  255, 255, 255, 255, 255, 255, 255, 255  // 248..255
};

const uint8_t BS_CT_RC_CONVERT_TAB[ASCII_SIZE] = {
  255, 255, 255, 255, 255, 255, 255, 255, // 0..7
  255, 255, 255, 255, 255, 255, 255, 255, // 8..15
  255, 255, 255, 255, 255, 255, 255, 255, // 16..23
  255, 255, 255, 255, 255, 255, 255, 255, // 24..31
  255, 255, 255, 255, 255, 255, 255, 255, // 32..39
  255, 255, 255, 255, 255, 255, 255, 255, // 40..47
  255, 255, 255, 255, 255, 255, 255, 255, // 48..55
  255, 255, 255, 255, 255, 255, 255, 255, // 56..63
  255, 3,   255, 0,   255, 255, 255, 1,   // 64..71
  255, 255, 255, 255, 255, 255, 255, 255, // 72..79
  255, 255, 255, 255, 0,   0,   255, 255, // 80..87
  255, 255, 255, 255, 255, 255, 255, 255, // 88..95
  255, 3,   255, 0,   255, 255, 255, 1,   // 96..103
  255, 255, 255, 255, 255, 255, 255, 255, // 104..111
  255, 255, 255, 255, 0,   0,   255, 255, // 112..119
  255, 255, 255, 255, 255, 255, 255, 255, // 120..127
  255, 255, 255, 255, 255, 255, 255, 255, // 128..135
  255, 255, 255, 255, 255, 255, 255, 255, // 136..143
  255, 255, 255, 255, 255, 255, 255, 255, // 144..151
  255, 255, 255, 255, 255, 255, 255, 255, // 152..159
  255, 255, 255, 255, 255, 255, 255, 255, // 160..167
  255, 255, 255, 255, 255, 255, 255, 255, // 168..175
  255, 255, 255, 255, 255, 255, 255, 255, // 176..183
  255, 255, 255, 255, 255, 255, 255, 255, // 184..191
  255, 255, 255, 255, 255, 255, 255, 255, // 192..199
  255, 255, 255, 255, 255, 255, 255, 255, // 200..207
  255, 255, 255, 255, 255, 255, 255, 255, // 208..215
  255, 255, 255, 255, 255, 255, 255, 255, // 216..223
  255, 255, 255, 255, 255, 255, 255, 255, // 224..231
  255, 255, 255, 255, 255, 255, 255, 255, // 232..239
  255, 255, 255, 255, 255, 255, 255, 255, // 240..247
  255, 255, 255, 255, 255, 255, 255, 255  // 248..255
};

const uint8_t BS_GA_CONVERT_TAB[ASCII_SIZE] = {
  255, 255, 255, 255, 255, 255, 255, 255, // 0..7
  255, 255, 255, 255, 255, 255, 255, 255, // 8..15
  255, 255, 255, 255, 255, 255, 255, 255, // 16..23
  255, 255, 255, 255, 255, 255, 255, 255, // 24..31
  255, 255, 255, 255, 255, 255, 255, 255, // 32..39
  255, 255, 255, 255, 255, 255, 255, 255, // 40..47
  255, 255, 255, 255, 255, 255, 255, 255, // 48..55
  255, 255, 255, 255, 255, 255, 255, 255, // 56..63
  255, 0,   255, 1,   255, 255, 255, 0,   // 64..71
  255, 255, 255, 255, 255, 255, 255, 255, // 72..79
  255, 255, 255, 255, 3,   3,   255, 255, // 80..87
  255, 255, 255, 255, 255, 255, 255, 255, // 88..95
  255, 0,   255, 1,   255, 255, 255, 0,   // 96..103
  255, 255, 255, 255, 255, 255, 255, 255, // 104..111
  255, 255, 255, 255, 3,   3,   255, 255, // 112..119
  255, 255, 255, 255, 255, 255, 255, 255, // 120..127
  255, 255, 255, 255, 255, 255, 255, 255, // 128..135
  255, 255, 255, 255, 255, 255, 255, 255, // 136..143
  255, 255, 255, 255, 255, 255, 255, 255, // 144..151
  255, 255, 255, 255, 255, 255, 255, 255, // 152..159
  255, 255, 255, 255, 255, 255, 255, 255, // 160..167
  255, 255, 255, 255, 255, 255, 255, 255, // 168..175
  255, 255, 255, 255, 255, 255, 255, 255, // 176..183
  255, 255, 255, 255, 255, 255, 255, 255, // 184..191
  255, 255, 255, 255, 255, 255, 255, 255, // 192..199
  255, 255, 255, 255, 255, 255, 255, 255, // 200..207
  255, 255, 255, 255, 255, 255, 255, 255, // 208..215
  255, 255, 255, 255, 255, 255, 255, 255, // 216..223
  255, 255, 255, 255, 255, 255, 255, 255, // 224..231
  255, 255, 255, 255, 255, 255, 255, 255, // 232..239
  255, 255, 255, 255, 255, 255, 255, 255, // 240..247
  255, 255, 255, 255, 255, 255, 255, 255  // 248..255
};

const uint8_t BS_GA_RC_CONVERT_TAB[ASCII_SIZE] = {
  255, 255, 255, 255, 255, 255, 255, 255, // 0..7
  255, 255, 255, 255, 255, 255, 255, 255, // 8..15
  255, 255, 255, 255, 255, 255, 255, 255, // 16..23
  255, 255, 255, 255, 255, 255, 255, 255, // 24..31
  255, 255, 255, 255, 255, 255, 255, 255, // 32..39
  255, 255, 255, 255, 255, 255, 255, 255, // 40..47
  255, 255, 255, 255, 255, 255, 255, 255, // 48..55
  255, 255, 255, 255, 255, 255, 255, 255, // 56..63
  255, 3,   255, 2,   255, 255, 255, 3,   // 64..71
  255, 255, 255, 255, 255, 255, 255, 255, // 72..79
  255, 255, 255, 255, 0,   0,   255, 255, // 80..87
  255, 255, 255, 255, 255, 255, 255, 255, // 88..95
  255, 3,   255, 2,   255, 255, 255, 3,   // 96..103
  255, 255, 255, 255, 255, 255, 255, 255, // 104..111
  255, 255, 255, 255, 0,   0,   255, 255, // 112..119
  255, 255, 255, 255, 255, 255, 255, 255, // 120..127
  255, 255, 255, 255, 255, 255, 255, 255, // 128..135
  255, 255, 255, 255, 255, 255, 255, 255, // 136..143
  255, 255, 255, 255, 255, 255, 255, 255, // 144..151
  255, 255, 255, 255, 255, 255, 255, 255, // 152..159
  255, 255, 255, 255, 255, 255, 255, 255, // 160..167
  255, 255, 255, 255, 255, 255, 255, 255, // 168..175
  255, 255, 255, 255, 255, 255, 255, 255, // 176..183
  255, 255, 255, 255, 255, 255, 255, 255, // 184..191
  255, 255, 255, 255, 255, 255, 255, 255, // 192..199
  255, 255, 255, 255, 255, 255, 255, 255, // 200..207
  255, 255, 255, 255, 255, 255, 255, 255, // 208..215
  255, 255, 255, 255, 255, 255, 255, 255, // 216..223
  255, 255, 255, 255, 255, 255, 255, 255, // 224..231
  255, 255, 255, 255, 255, 255, 255, 255, // 232..239
  255, 255, 255, 255, 255, 255, 255, 255, // 240..247
  255, 255, 255, 255, 255, 255, 255, 255  // 248..255
};

constexpr uint8_t BS_CONVERT_TAB[128] = {
  // 0–64
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 3,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

constexpr uint8_t BS_RC_CONVERT_TAB[128] = {

  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 3, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 3, 0, 0, 0, 2,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

// Group CG XOR pairs (18 SEEDs → 9 pairs)
static const uint64_t CG_group1 = 0x85447b35f730b24eULL;
static const uint64_t CG_group2 = 0x1e7ec42ae67bf290ULL;
static const uint64_t CG_group3 = 0xe630f41524612363ULL;
static const uint64_t CG_group4 = 0x891759872e4a1a40ULL;
static const uint64_t CG_group5 = 0x10a9d125b4781d1bULL;
static const uint64_t CG_group6 = 0xe345fa6e0b3efe26ULL;
static const uint64_t CG_group7 = 0xed73b07d7795d703ULL;
static const uint64_t CG_group8 = 0xc05a70c787ddc030ULL;
static const uint64_t CG_group9 = 0xb3e7ea1d5f69e07dULL;

// Group CC XOR pairs (10 SEEDs → 5 pairs)
static const uint64_t CC_group1 = 0x35186b8fc962b995ULL;
static const uint64_t CC_group2 = 0xeeecbd3086db4364ULL;
static const uint64_t CC_group3 = 0x15dc1dfcf2d821d7ULL;
static const uint64_t CC_group4 = 0x501734bd0947b87dULL;
static const uint64_t CC_group5 = 0xda7b6ec0c3c8457aULL;

// Group CA XOR pairs (18 SEEDs → 9 pairs)
static const uint64_t CA_group1 = 0xd2e69a6245391840ULL;
static const uint64_t CA_group2 = 0xfcdf37536278deafULL;
static const uint64_t CA_group3 = 0x72e4656f024fd310ULL;
static const uint64_t CA_group4 = 0xdee651b2976fa1f8ULL;
static const uint64_t CA_group5 = 0xf3288907ec8cd8f0ULL;
static const uint64_t CA_group6 = 0x129d2554868dad85ULL;
static const uint64_t CA_group7 = 0x23f706d477652a44ULL;
static const uint64_t CA_group8 = 0x3fd2c4487b9f6d6cULL;
static const uint64_t CA_group9 = 0xa8a3d2ed1139ceeaULL;

// Group CT XOR pairs (18 SEEDs → 9 pairs)
static const uint64_t CT_group1 = 0x385ed2689c215294ULL;
static const uint64_t CT_group2 = 0x5997dfab383a421eULL;
static const uint64_t CT_group3 = 0x2c62c0516c643607ULL;
static const uint64_t CT_group4 = 0x5186a5a92af12d90ULL;
static const uint64_t CT_group5 = 0x34fd2f6305426fbeULL;
static const uint64_t CT_group6 = 0xfd1fccb21e12f0f6ULL;
static const uint64_t CT_group7 = 0xde1be1658d22c3a7ULL;
static const uint64_t CT_group8 = 0x669139b5a878cd6cULL;
static const uint64_t CT_group9 = 0x36f4413f12bacedcULL;

constexpr uint64_t CG_DIMER_TAB[45] = {
  0, 0,         0,         0,         0,         0, 0, 0, 0, 0,
  0, CG_group4, CG_group2, CG_group8, CG_group2, 0, 0, 0, 0, 0, // AA,AC,AG,AT
  0, CG_group1, CG_group7, CG_group1, CG_group9, 0, 0, 0, 0, 0, // CA,CC,CG,CT
  0, CG_group4, CG_group2, CG_group6, CG_group2, 0, 0, 0, 0, 0, // GA,GC,GG,GT
  0, CG_group5, CG_group3, CG_group1, CG_group3                 // TA,TC,TG,TT
};

constexpr uint64_t CC_DIMER_TAB[45] = {
  0, 0,         0,         0,         0,         0, 0, 0, 0, 0, // 0–9
  0, CC_group2, CC_group3, CC_group2, CC_group3, 0, 0, 0, 0, 0, // AA,AC,AG,AT
  0, CC_group4, CC_group1, CC_group5, CC_group1, 0, 0, 0, 0, 0, // CA,CC,CG,CT
  0, CC_group2, CC_group3, CC_group2, CC_group3, 0, 0, 0, 0, 0, // GA,GC,GG,GT
  0, CC_group4, CC_group1, CC_group4, CC_group1                 // TA,TC,TG,TT
};

constexpr uint64_t CA_DIMER_TAB[45] = {
  0, 0,         0,         0,         0,         0, 0, 0, 0, 0,
  0, CA_group3, CA_group2, CA_group7, CA_group2, 0, 0, 0, 0, 0, // AA,AC,AG,AT
  0, CA_group1, CA_group6, CA_group9, CA_group8, 0, 0, 0, 0, 0, // CA,CC,CG,CT
  0, CA_group3, CA_group2, CA_group5, CA_group2, 0, 0, 0, 0, 0, // GA,GC,GG,GT
  0, CA_group1, CA_group4, CA_group1, CA_group4                 // TA,TC,TG,TT
};

constexpr uint64_t CT_DIMER_TAB[45] = {
  0, 0,         0,         0,         0,         0, 0, 0, 0, 0,
  0, CT_group2, CT_group3, CT_group2, CT_group3, 0, 0, 0, 0, 0, // AA,AC,AG,AT
  0, CT_group8, CT_group5, CT_group9, CT_group1, 0, 0, 0, 0, 0, // CA,CC,CG,CT
  0, CT_group2, CT_group3, CT_group4, CT_group3, 0, 0, 0, 0, 0, // GA,GC,GG,GT
  0, CT_group6, CT_group1, CT_group7, CT_group1                 // TA,TC,TG,TT
};

// Generic dimer-based rolling hash
inline std::vector<uint64_t>
base_forward_bs_hash(const char* seq,
                     bool has_second,
                     unsigned k,
                     const uint64_t* DIMER_TAB)
{
  uint64_t h0 = 0;
  uint64_t h1 = 0;

  for (unsigned i = 0; i < k; i += 2) {
    h0 = srol(h0, 1);
    const char c1 = seq[i];
    const char c2 = seq[i + 1];
    const uint8_t a = BS_CONVERT_TAB[(unsigned char)c1];
    const uint8_t b = BS_CONVERT_TAB[(unsigned char)c2];
    const uint8_t loc = 10 * a + b; // yields 11, 12, ..., 44
    h0 ^= DIMER_TAB[loc];
  }

  if (!has_second)
    return { h0, 0 };

  for (unsigned i = 1; i < k + 1; i += 2) {
    h1 = srol(h1, 1);
    const char c1 = seq[i];
    const char c2 = seq[i + 1];
    const uint8_t a = BS_CONVERT_TAB[(unsigned char)c1];
    const uint8_t b = BS_CONVERT_TAB[(unsigned char)c2];
    const uint8_t loc = 10 * a + b;
    h1 ^= DIMER_TAB[loc];
  }

  return { h0, h1 };
}

// ===== CC_XOR_1_6 =====
static const uint64_t CC_group1_33R[33] = {
  0x00000001c962b995, 0x0000000192c5732b, 0x00000001258ae657,
  0x000000004b15ccaf, 0x00000000962b995e, 0x000000012c5732bc,
  0x0000000058ae6579, 0x00000000b15ccaf2, 0x0000000162b995e4,
  0x00000000c5732bc9, 0x000000018ae65792, 0x0000000115ccaf25,
  0x000000002b995e4b, 0x000000005732bc96, 0x00000000ae65792c,
  0x000000015ccaf258, 0x00000000b995e4b1, 0x00000001732bc962,
  0x00000000e65792c5, 0x00000001ccaf258a, 0x00000001995e4b15,
  0x0000000132bc962b, 0x0000000065792c57, 0x00000000caf258ae,
  0x0000000195e4b15c, 0x000000012bc962b9, 0x000000005792c573,
  0x00000000af258ae6, 0x000000015e4b15cc, 0x00000000bc962b99,
  0x00000001792c5732, 0x00000000f258ae65, 0x00000001e4b15cca
};

static const uint64_t CC_group1_31L[31] = {
  0x35186b8e00000000, 0x6a30d71c00000000, 0xd461ae3800000000,
  0xa8c35c7200000000, 0x5186b8e600000000, 0xa30d71cc00000000,
  0x461ae39a00000000, 0x8c35c73400000000, 0x186b8e6a00000000,
  0x30d71cd400000000, 0x61ae39a800000000, 0xc35c735000000000,
  0x86b8e6a200000000, 0xd71cd4600000000,  0x1ae39a8c00000000,
  0x35c7351800000000, 0x6b8e6a3000000000, 0xd71cd46000000000,
  0xae39a8c200000000, 0x5c73518600000000, 0xb8e6a30c00000000,
  0x71cd461a00000000, 0xe39a8c3400000000, 0xc735186a00000000,
  0x8e6a30d600000000, 0x1cd461ae00000000, 0x39a8c35c00000000,
  0x735186b800000000, 0xe6a30d7000000000, 0xcd461ae200000000,
  0x9a8c35c600000000
};

// ===== CC_XOR_2_7 =====
static const uint64_t CC_group2_33R[33] = {
  0x0000000086db4364, 0x000000010db686c8, 0x000000001b6d0d91,
  0x0000000036da1b22, 0x000000006db43644, 0x00000000db686c88,
  0x00000001b6d0d910, 0x000000016da1b221, 0x00000000db436443,
  0x00000001b686c886, 0x000000016d0d910d, 0x00000000da1b221b,
  0x00000001b4364436, 0x00000001686c886d, 0x00000000d0d910db,
  0x00000001a1b221b6, 0x000000014364436d, 0x0000000086c886db,
  0x000000010d910db6, 0x000000001b221b6d, 0x00000000364436da,
  0x000000006c886db4, 0x00000000d910db68, 0x00000001b221b6d0,
  0x0000000164436da1, 0x00000000c886db43, 0x00000001910db686,
  0x00000001221b6d0d, 0x000000004436da1b, 0x00000000886db436,
  0x0000000110db686c, 0x0000000021b6d0d9, 0x00000000436da1b2
};

static const uint64_t CC_group2_31L[31] = {
  0xeeecbd3000000000, 0xddd97a6200000000, 0xbbb2f4c600000000,
  0x7765e98e00000000, 0xeecbd31c00000000, 0xdd97a63a00000000,
  0xbb2f4c7600000000, 0x765e98ee00000000, 0xecbd31dc00000000,
  0xd97a63ba00000000, 0xb2f4c77600000000, 0x65e98eee00000000,
  0xcbd31ddc00000000, 0x97a63bba00000000, 0x2f4c777600000000,
  0x5e98eeec00000000, 0xbd31ddd800000000, 0x7a63bbb200000000,
  0xf4c7776400000000, 0xe98eeeca00000000, 0xd31ddd9600000000,
  0xa63bbb2e00000000, 0x4c77765e00000000, 0x98eeecbc00000000,
  0x31ddd97a00000000, 0x63bbb2f400000000, 0xc77765e800000000,
  0x8eeecbd200000000, 0x1ddd97a600000000, 0x3bbb2f4c00000000,
  0x77765e9800000000
};

// ===== CC_XOR_3_8 =====
static const uint64_t CC_group3_33R[33] = {
  0x00000000f2d821d7, 0x00000001e5b043ae, 0x00000001cb60875d,
  0x0000000196c10ebb, 0x000000012d821d77, 0x000000005b043aef,
  0x00000000b60875de, 0x000000016c10ebbc, 0x00000000d821d779,
  0x00000001b043aef2, 0x0000000160875de5, 0x00000000c10ebbcb,
  0x00000001821d7796, 0x00000001043aef2d, 0x000000000875de5b,
  0x0000000010ebbcb6, 0x0000000021d7796c, 0x0000000043aef2d8,
  0x00000000875de5b0, 0x000000010ebbcb60, 0x000000001d7796c1,
  0x000000003aef2d82, 0x0000000075de5b04, 0x00000000ebbcb608,
  0x00000001d7796c10, 0x00000001aef2d821, 0x000000015de5b043,
  0x00000000bbcb6087, 0x000000017796c10e, 0x00000000ef2d821d,
  0x00000001de5b043a, 0x00000001bcb60875, 0x00000001796c10eb
};

static const uint64_t CC_group3_31L[31] = {
  0x15dc1dfc00000000, 0x2bb83bf800000000, 0x577077f000000000,
  0xaee0efe000000000, 0x5dc1dfc200000000, 0xbb83bf8400000000,
  0x77077f0a00000000, 0xee0efe1400000000, 0xdc1dfc2a00000000,
  0xb83bf85600000000, 0x7077f0ae00000000, 0xe0efe15c00000000,
  0xc1dfc2ba00000000, 0x83bf857600000000, 0x77f0aee00000000,
  0xefe15dc00000000,  0x1dfc2bb800000000, 0x3bf8577000000000,
  0x77f0aee000000000, 0xefe15dc000000000, 0xdfc2bb8200000000,
  0xbf85770600000000, 0x7f0aee0e00000000, 0xfe15dc1c00000000,
  0xfc2bb83a00000000, 0xf857707600000000, 0xf0aee0ee00000000,
  0xe15dc1de00000000, 0xc2bb83be00000000, 0x8577077e00000000,
  0xaee0efe00000000
};

// ===== CC_XOR_4_9 =====
static const uint64_t CC_group4_33R[33] = {
  0x000000010947b87d, 0x00000000128f70fb, 0x00000000251ee1f6,
  0x000000004a3dc3ec, 0x00000000947b87d8, 0x0000000128f70fb0,
  0x0000000051ee1f61, 0x00000000a3dc3ec2, 0x0000000147b87d84,
  0x000000008f70fb09, 0x000000011ee1f612, 0x000000003dc3ec25,
  0x000000007b87d84a, 0x00000000f70fb094, 0x00000001ee1f6128,
  0x00000001dc3ec251, 0x00000001b87d84a3, 0x0000000170fb0947,
  0x00000000e1f6128f, 0x00000001c3ec251e, 0x0000000187d84a3d,
  0x000000010fb0947b, 0x000000001f6128f7, 0x000000003ec251ee,
  0x000000007d84a3dc, 0x00000000fb0947b8, 0x00000001f6128f70,
  0x00000001ec251ee1, 0x00000001d84a3dc3, 0x00000001b0947b87,
  0x000000016128f70f, 0x00000000c251ee1f, 0x0000000184a3dc3e
};

static const uint64_t CC_group4_31L[31] = {
  0x501734bc00000000, 0xa02e697800000000, 0x405cd2f200000000,
  0x80b9a5e400000000, 0x1734bca00000000,  0x2e6979400000000,
  0x5cd2f2800000000,  0xb9a5e5000000000,  0x1734bca000000000,
  0x2e69794000000000, 0x5cd2f28000000000, 0xb9a5e50000000000,
  0x734bca0200000000, 0xe697940400000000, 0xcd2f280a00000000,
  0x9a5e501600000000, 0x34bca02e00000000, 0x6979405c00000000,
  0xd2f280b800000000, 0xa5e5017200000000, 0x4bca02e600000000,
  0x979405cc00000000, 0x2f280b9a00000000, 0x5e50173400000000,
  0xbca02e6800000000, 0x79405cd200000000, 0xf280b9a400000000,
  0xe501734a00000000, 0xca02e69600000000, 0x9405cd2e00000000,
  0x280b9a5e00000000
};

// ===== CC_XOR_5_10 =====
static const uint64_t CC_group5_33R[33] = {
  0x00000000c3c8457a, 0x0000000187908af4, 0x000000010f2115e9,
  0x000000001e422bd3, 0x000000003c8457a6, 0x000000007908af4c,
  0x00000000f2115e98, 0x00000001e422bd30, 0x00000001c8457a61,
  0x00000001908af4c3, 0x000000012115e987, 0x00000000422bd30f,
  0x000000008457a61e, 0x0000000108af4c3c, 0x00000000115e9879,
  0x0000000022bd30f2, 0x00000000457a61e4, 0x000000008af4c3c8,
  0x0000000115e98790, 0x000000002bd30f21, 0x0000000057a61e42,
  0x00000000af4c3c84, 0x000000015e987908, 0x00000000bd30f211,
  0x000000017a61e422, 0x00000000f4c3c845, 0x00000001e987908a,
  0x00000001d30f2115, 0x00000001a61e422b, 0x000000014c3c8457,
  0x00000000987908af, 0x0000000130f2115e, 0x0000000061e422bd
};

static const uint64_t CC_group5_31L[31] = {
  0xda7b6ec000000000, 0xb4f6dd8200000000, 0x69edbb0600000000,
  0xd3db760c00000000, 0xa7b6ec1a00000000, 0x4f6dd83600000000,
  0x9edbb06c00000000, 0x3db760da00000000, 0x7b6ec1b400000000,
  0xf6dd836800000000, 0xedbb06d200000000, 0xdb760da600000000,
  0xb6ec1b4e00000000, 0x6dd8369e00000000, 0xdbb06d3c00000000,
  0xb760da7a00000000, 0x6ec1b4f600000000, 0xdd8369ec00000000,
  0xbb06d3da00000000, 0x760da7b600000000, 0xec1b4f6c00000000,
  0xd8369eda00000000, 0xb06d3db600000000, 0x60da7b6e00000000,
  0xc1b4f6dc00000000, 0x8369edba00000000, 0x6d3db7600000000,
  0xda7b6ec00000000,  0x1b4f6dd800000000, 0x369edbb000000000,
  0x6d3db76000000000
};

// ===== CG_XOR_1_10 =====
static const uint64_t CG_group1_33R[33] = {
  0x00000001f730b24e, 0x00000001ee61649d, 0x00000001dcc2c93b,
  0x00000001b9859277, 0x00000001730b24ef, 0x00000000e61649df,
  0x00000001cc2c93be, 0x000000019859277d, 0x0000000130b24efb,
  0x0000000061649df7, 0x00000000c2c93bee, 0x00000001859277dc,
  0x000000010b24efb9, 0x000000001649df73, 0x000000002c93bee6,
  0x0000000059277dcc, 0x00000000b24efb98, 0x00000001649df730,
  0x00000000c93bee61, 0x000000019277dcc2, 0x0000000124efb985,
  0x0000000049df730b, 0x0000000093bee616, 0x00000001277dcc2c,
  0x000000004efb9859, 0x000000009df730b2, 0x000000013bee6164,
  0x0000000077dcc2c9, 0x00000000efb98592, 0x00000001df730b24,
  0x00000001bee61649, 0x000000017dcc2c93, 0x00000000fb985927
};

static const uint64_t CG_group1_31L[31] = {
  0x85447b3400000000, 0xa88f66a00000000,  0x1511ecd400000000,
  0x2a23d9a800000000, 0x5447b35000000000, 0xa88f66a000000000,
  0x511ecd4200000000, 0xa23d9a8400000000, 0x447b350a00000000,
  0x88f66a1400000000, 0x11ecd42a00000000, 0x23d9a85400000000,
  0x47b350a800000000, 0x8f66a15000000000, 0x1ecd42a200000000,
  0x3d9a854400000000, 0x7b350a8800000000, 0xf66a151000000000,
  0xecd42a2200000000, 0xd9a8544600000000, 0xb350a88e00000000,
  0x66a1511e00000000, 0xcd42a23c00000000, 0x9a85447a00000000,
  0x350a88f600000000, 0x6a1511ec00000000, 0xd42a23d800000000,
  0xa85447b200000000, 0x50a88f6600000000, 0xa1511ecc00000000,
  0x42a23d9a00000000
};

// ===== CG_XOR_2_11 =====
static const uint64_t CG_group2_33R[33] = {
  0x00000000e67bf290, 0x00000001ccf7e520, 0x0000000199efca41,
  0x0000000133df9483, 0x0000000067bf2907, 0x00000000cf7e520e,
  0x000000019efca41c, 0x000000013df94839, 0x000000007bf29073,
  0x00000000f7e520e6, 0x00000001efca41cc, 0x00000001df948399,
  0x00000001bf290733, 0x000000017e520e67, 0x00000000fca41ccf,
  0x00000001f948399e, 0x00000001f290733d, 0x00000001e520e67b,
  0x00000001ca41ccf7, 0x00000001948399ef, 0x00000001290733df,
  0x00000000520e67bf, 0x00000000a41ccf7e, 0x0000000148399efc,
  0x0000000090733df9, 0x0000000120e67bf2, 0x0000000041ccf7e5,
  0x000000008399efca, 0x000000010733df94, 0x000000000e67bf29,
  0x000000001ccf7e52, 0x00000000399efca4, 0x00000000733df948
};

static const uint64_t CG_group2_31L[31] = {
  0x1e7ec42a00000000, 0x3cfd885400000000, 0x79fb10a800000000,
  0xf3f6215000000000, 0xe7ec42a200000000, 0xcfd8854600000000,
  0x9fb10a8e00000000, 0x3f62151e00000000, 0x7ec42a3c00000000,
  0xfd88547800000000, 0xfb10a8f200000000, 0xf62151e600000000,
  0xec42a3ce00000000, 0xd885479e00000000, 0xb10a8f3e00000000,
  0x62151e7e00000000, 0xc42a3cfc00000000, 0x885479fa00000000,
  0x10a8f3f600000000, 0x2151e7ec00000000, 0x42a3cfd800000000,
  0x85479fb000000000, 0xa8f3f6200000000,  0x151e7ec400000000,
  0x2a3cfd8800000000, 0x5479fb1000000000, 0xa8f3f62000000000,
  0x51e7ec4200000000, 0xa3cfd88400000000, 0x479fb10a00000000,
  0x8f3f621400000000
};

// ===== CG_XOR_3_12 =====
static const uint64_t CG_group3_33R[33] = {
  0x0000000124612363, 0x0000000048c246c7, 0x0000000091848d8e,
  0x0000000123091b1c, 0x0000000046123639, 0x000000008c246c72,
  0x000000011848d8e4, 0x000000003091b1c9, 0x0000000061236392,
  0x00000000c246c724, 0x00000001848d8e48, 0x00000001091b1c91,
  0x0000000012363923, 0x00000000246c7246, 0x0000000048d8e48c,
  0x0000000091b1c918, 0x0000000123639230, 0x0000000046c72461,
  0x000000008d8e48c2, 0x000000011b1c9184, 0x0000000036392309,
  0x000000006c724612, 0x00000000d8e48c24, 0x00000001b1c91848,
  0x0000000163923091, 0x00000000c7246123, 0x000000018e48c246,
  0x000000011c91848d, 0x000000003923091b, 0x0000000072461236,
  0x00000000e48c246c, 0x00000001c91848d8, 0x00000001923091b1
};

static const uint64_t CG_group3_31L[31] = {
  0xe630f41400000000, 0xcc61e82a00000000, 0x98c3d05600000000,
  0x3187a0ae00000000, 0x630f415c00000000, 0xc61e82b800000000,
  0x8c3d057200000000, 0x187a0ae600000000, 0x30f415cc00000000,
  0x61e82b9800000000, 0xc3d0573000000000, 0x87a0ae6200000000,
  0xf415cc600000000,  0x1e82b98c00000000, 0x3d05731800000000,
  0x7a0ae63000000000, 0xf415cc6000000000, 0xe82b98c200000000,
  0xd057318600000000, 0xa0ae630e00000000, 0x415cc61e00000000,
  0x82b98c3c00000000, 0x573187a00000000,  0xae630f400000000,
  0x15cc61e800000000, 0x2b98c3d000000000, 0x573187a000000000,
  0xae630f4000000000, 0x5cc61e8200000000, 0xb98c3d0400000000,
  0x73187a0a00000000
};

// ===== CG_XOR_4_13 =====
static const uint64_t CG_group4_33R[33] = {
  0x000000012e4a1a40, 0x000000005c943481, 0x00000000b9286902,
  0x000000017250d204, 0x00000000e4a1a409, 0x00000001c9434812,
  0x0000000192869025, 0x00000001250d204b, 0x000000004a1a4097,
  0x000000009434812e, 0x000000012869025c, 0x0000000050d204b9,
  0x00000000a1a40972, 0x00000001434812e4, 0x00000000869025c9,
  0x000000010d204b92, 0x000000001a409725, 0x0000000034812e4a,
  0x0000000069025c94, 0x00000000d204b928, 0x00000001a4097250,
  0x000000014812e4a1, 0x000000009025c943, 0x00000001204b9286,
  0x000000004097250d, 0x00000000812e4a1a, 0x00000001025c9434,
  0x0000000004b92869, 0x00000000097250d2, 0x0000000012e4a1a4,
  0x0000000025c94348, 0x000000004b928690, 0x0000000097250d20
};

static const uint64_t CG_group4_31L[31] = {
  0x8917598600000000, 0x122eb30e00000000, 0x245d661c00000000,
  0x48bacc3800000000, 0x9175987000000000, 0x22eb30e200000000,
  0x45d661c400000000, 0x8bacc38800000000, 0x1759871200000000,
  0x2eb30e2400000000, 0x5d661c4800000000, 0xbacc389000000000,
  0x7598712200000000, 0xeb30e24400000000, 0xd661c48a00000000,
  0xacc3891600000000, 0x5987122e00000000, 0xb30e245c00000000,
  0x661c48ba00000000, 0xcc38917400000000, 0x987122ea00000000,
  0x30e245d600000000, 0x61c48bac00000000, 0xc389175800000000,
  0x87122eb200000000, 0xe245d6600000000,  0x1c48bacc00000000,
  0x3891759800000000, 0x7122eb3000000000, 0xe245d66000000000,
  0xc48bacc200000000
};

// ===== CG_XOR_5_14 =====
static const uint64_t CG_group5_33R[33] = {
  0x00000001b4781d1b, 0x0000000168f03a37, 0x00000000d1e0746f,
  0x00000001a3c0e8de, 0x000000014781d1bd, 0x000000008f03a37b,
  0x000000011e0746f6, 0x000000003c0e8ded, 0x00000000781d1bda,
  0x00000000f03a37b4, 0x00000001e0746f68, 0x00000001c0e8ded1,
  0x0000000181d1bda3, 0x0000000103a37b47, 0x000000000746f68f,
  0x000000000e8ded1e, 0x000000001d1bda3c, 0x000000003a37b478,
  0x00000000746f68f0, 0x00000000e8ded1e0, 0x00000001d1bda3c0,
  0x00000001a37b4781, 0x0000000146f68f03, 0x000000008ded1e07,
  0x000000011bda3c0e, 0x0000000037b4781d, 0x000000006f68f03a,
  0x00000000ded1e074, 0x00000001bda3c0e8, 0x000000017b4781d1,
  0x00000000f68f03a3, 0x00000001ed1e0746, 0x00000001da3c0e8d
};

static const uint64_t CG_group5_31L[31] = {
  0x10a9d12400000000, 0x2153a24800000000, 0x42a7449000000000,
  0x854e892000000000, 0xa9d124200000000,  0x153a248400000000,
  0x2a74490800000000, 0x54e8921000000000, 0xa9d1242000000000,
  0x53a2484200000000, 0xa744908400000000, 0x4e89210a00000000,
  0x9d12421400000000, 0x3a24842a00000000, 0x7449085400000000,
  0xe89210a800000000, 0xd124215200000000, 0xa24842a600000000,
  0x4490854e00000000, 0x89210a9c00000000, 0x1242153a00000000,
  0x24842a7400000000, 0x490854e800000000, 0x9210a9d000000000,
  0x242153a200000000, 0x4842a74400000000, 0x90854e8800000000,
  0x210a9d1200000000, 0x42153a2400000000, 0x842a744800000000,
  0x854e89200000000
};

// ===== CG_XOR_6_15 =====
static const uint64_t CG_group6_33R[33] = {
  0x000000000b3efe26, 0x00000000167dfc4c, 0x000000002cfbf898,
  0x0000000059f7f130, 0x00000000b3efe260, 0x0000000167dfc4c0,
  0x00000000cfbf8981, 0x000000019f7f1302, 0x000000013efe2605,
  0x000000007dfc4c0b, 0x00000000fbf89816, 0x00000001f7f1302c,
  0x00000001efe26059, 0x00000001dfc4c0b3, 0x00000001bf898167,
  0x000000017f1302cf, 0x00000000fe26059f, 0x00000001fc4c0b3e,
  0x00000001f898167d, 0x00000001f1302cfb, 0x00000001e26059f7,
  0x00000001c4c0b3ef, 0x00000001898167df, 0x000000011302cfbf,
  0x0000000026059f7f, 0x000000004c0b3efe, 0x0000000098167dfc,
  0x00000001302cfbf8, 0x000000006059f7f1, 0x00000000c0b3efe2,
  0x000000018167dfc4, 0x0000000102cfbf89, 0x00000000059f7f13
};

static const uint64_t CG_group6_31L[31] = {
  0xe345fa6e00000000, 0xc68bf4de00000000, 0x8d17e9be00000000,
  0x1a2fd37e00000000, 0x345fa6fc00000000, 0x68bf4df800000000,
  0xd17e9bf000000000, 0xa2fd37e200000000, 0x45fa6fc600000000,
  0x8bf4df8c00000000, 0x17e9bf1a00000000, 0x2fd37e3400000000,
  0x5fa6fc6800000000, 0xbf4df8d000000000, 0x7e9bf1a200000000,
  0xfd37e34400000000, 0xfa6fc68a00000000, 0xf4df8d1600000000,
  0xe9bf1a2e00000000, 0xd37e345e00000000, 0xa6fc68be00000000,
  0x4df8d17e00000000, 0x9bf1a2fc00000000, 0x37e345fa00000000,
  0x6fc68bf400000000, 0xdf8d17e800000000, 0xbf1a2fd200000000,
  0x7e345fa600000000, 0xfc68bf4c00000000, 0xf8d17e9a00000000,
  0xf1a2fd3600000000
};

// ===== CG_XOR_7_16 =====
static const uint64_t CG_group7_33R[33] = {
  0x000000017795d703, 0x00000000ef2bae07, 0x00000001de575c0e,
  0x00000001bcaeb81d, 0x00000001795d703b, 0x00000000f2bae077,
  0x00000001e575c0ee, 0x00000001caeb81dd, 0x0000000195d703bb,
  0x000000012bae0777, 0x00000000575c0eef, 0x00000000aeb81dde,
  0x000000015d703bbc, 0x00000000bae07779, 0x0000000175c0eef2,
  0x00000000eb81dde5, 0x00000001d703bbca, 0x00000001ae077795,
  0x000000015c0eef2b, 0x00000000b81dde57, 0x00000001703bbcae,
  0x00000000e077795d, 0x00000001c0eef2ba, 0x0000000181dde575,
  0x0000000103bbcaeb, 0x00000000077795d7, 0x000000000eef2bae,
  0x000000001dde575c, 0x000000003bbcaeb8, 0x0000000077795d70,
  0x00000000eef2bae0, 0x00000001dde575c0, 0x00000001bbcaeb81
};

static const uint64_t CG_group7_31L[31] = {
  0xed73b07c00000000, 0xdae760fa00000000, 0xb5cec1f600000000,
  0x6b9d83ee00000000, 0xd73b07dc00000000, 0xae760fba00000000,
  0x5cec1f7600000000, 0xb9d83eec00000000, 0x73b07dda00000000,
  0xe760fbb400000000, 0xcec1f76a00000000, 0x9d83eed600000000,
  0x3b07ddae00000000, 0x760fbb5c00000000, 0xec1f76b800000000,
  0xd83eed7200000000, 0xb07ddae600000000, 0x60fbb5ce00000000,
  0xc1f76b9c00000000, 0x83eed73a00000000, 0x7ddae7600000000,
  0xfbb5cec00000000,  0x1f76b9d800000000, 0x3eed73b000000000,
  0x7ddae76000000000, 0xfbb5cec000000000, 0xf76b9d8200000000,
  0xeed73b0600000000, 0xddae760e00000000, 0xbb5cec1e00000000,
  0x76b9d83e00000000
};

// ===== CG_XOR_8_17 =====
static const uint64_t CG_group8_33R[33] = {
  0x0000000187ddc030, 0x000000010fbb8061, 0x000000001f7700c3,
  0x000000003eee0186, 0x000000007ddc030c, 0x00000000fbb80618,
  0x00000001f7700c30, 0x00000001eee01861, 0x00000001ddc030c3,
  0x00000001bb806187, 0x000000017700c30f, 0x00000000ee01861f,
  0x00000001dc030c3e, 0x00000001b806187d, 0x00000001700c30fb,
  0x00000000e01861f7, 0x00000001c030c3ee, 0x00000001806187dd,
  0x0000000100c30fbb, 0x0000000001861f77, 0x00000000030c3eee,
  0x0000000006187ddc, 0x000000000c30fbb8, 0x000000001861f770,
  0x0000000030c3eee0, 0x000000006187ddc0, 0x00000000c30fbb80,
  0x00000001861f7700, 0x000000010c3eee01, 0x00000000187ddc03,
  0x0000000030fbb806, 0x0000000061f7700c, 0x00000000c3eee018
};

static const uint64_t CG_group8_31L[31] = {
  0xc05a70c600000000, 0x80b4e18e00000000, 0x169c31e00000000,
  0x2d3863c00000000,  0x5a70c7800000000,  0xb4e18f000000000,
  0x169c31e000000000, 0x2d3863c000000000, 0x5a70c78000000000,
  0xb4e18f0000000000, 0x69c31e0200000000, 0xd3863c0400000000,
  0xa70c780a00000000, 0x4e18f01600000000, 0x9c31e02c00000000,
  0x3863c05a00000000, 0x70c780b400000000, 0xe18f016800000000,
  0xc31e02d200000000, 0x863c05a600000000, 0xc780b4e00000000,
  0x18f0169c00000000, 0x31e02d3800000000, 0x63c05a7000000000,
  0xc780b4e000000000, 0x8f0169c200000000, 0x1e02d38600000000,
  0x3c05a70c00000000, 0x780b4e1800000000, 0xf0169c3000000000,
  0xe02d386200000000
};

// ===== CG_XOR_9_18 =====
static const uint64_t CG_group9_33R[33] = {
  0x000000015f69e07d, 0x00000000bed3c0fb, 0x000000017da781f6,
  0x00000000fb4f03ed, 0x00000001f69e07da, 0x00000001ed3c0fb5,
  0x00000001da781f6b, 0x00000001b4f03ed7, 0x0000000169e07daf,
  0x00000000d3c0fb5f, 0x00000001a781f6be, 0x000000014f03ed7d,
  0x000000009e07dafb, 0x000000013c0fb5f6, 0x00000000781f6bed,
  0x00000000f03ed7da, 0x00000001e07dafb4, 0x00000001c0fb5f69,
  0x0000000181f6bed3, 0x0000000103ed7da7, 0x0000000007dafb4f,
  0x000000000fb5f69e, 0x000000001f6bed3c, 0x000000003ed7da78,
  0x000000007dafb4f0, 0x00000000fb5f69e0, 0x00000001f6bed3c0,
  0x00000001ed7da781, 0x00000001dafb4f03, 0x00000001b5f69e07,
  0x000000016bed3c0f, 0x00000000d7da781f, 0x00000001afb4f03e
};

static const uint64_t CG_group9_31L[31] = {
  0xb3e7ea1c00000000, 0x67cfd43a00000000, 0xcf9fa87400000000,
  0x9f3f50ea00000000, 0x3e7ea1d600000000, 0x7cfd43ac00000000,
  0xf9fa875800000000, 0xf3f50eb200000000, 0xe7ea1d6600000000,
  0xcfd43ace00000000, 0x9fa8759e00000000, 0x3f50eb3e00000000,
  0x7ea1d67c00000000, 0xfd43acf800000000, 0xfa8759f200000000,
  0xf50eb3e600000000, 0xea1d67ce00000000, 0xd43acf9e00000000,
  0xa8759f3e00000000, 0x50eb3e7e00000000, 0xa1d67cfc00000000,
  0x43acf9fa00000000, 0x8759f3f400000000, 0xeb3e7ea00000000,
  0x1d67cfd400000000, 0x3acf9fa800000000, 0x759f3f5000000000,
  0xeb3e7ea000000000, 0xd67cfd4200000000, 0xacf9fa8600000000,
  0x59f3f50e00000000
};

// ===== CT_XOR_1_10 =====
static const uint64_t CT_group1_33R[33] = {
  0x000000009c215294, 0x000000013842a528, 0x0000000070854a51,
  0x00000000e10a94a2, 0x00000001c2152944, 0x00000001842a5289,
  0x000000010854a513, 0x0000000010a94a27, 0x000000002152944e,
  0x0000000042a5289c, 0x00000000854a5138, 0x000000010a94a270,
  0x00000000152944e1, 0x000000002a5289c2, 0x0000000054a51384,
  0x00000000a94a2708, 0x0000000152944e10, 0x00000000a5289c21,
  0x000000014a513842, 0x0000000094a27085, 0x000000012944e10a,
  0x000000005289c215, 0x00000000a513842a, 0x000000014a270854,
  0x00000000944e10a9, 0x00000001289c2152, 0x00000000513842a5,
  0x00000000a270854a, 0x0000000144e10a94, 0x0000000089c21529,
  0x0000000113842a52, 0x00000000270854a5, 0x000000004e10a94a
};

static const uint64_t CT_group1_31L[31] = {
  0x385ed26800000000, 0x70bda4d000000000, 0xe17b49a000000000,
  0xc2f6934200000000, 0x85ed268600000000, 0xbda4d0e00000000,
  0x17b49a1c00000000, 0x2f69343800000000, 0x5ed2687000000000,
  0xbda4d0e000000000, 0x7b49a1c200000000, 0xf693438400000000,
  0xed26870a00000000, 0xda4d0e1600000000, 0xb49a1c2e00000000,
  0x6934385e00000000, 0xd26870bc00000000, 0xa4d0e17a00000000,
  0x49a1c2f600000000, 0x934385ec00000000, 0x26870bda00000000,
  0x4d0e17b400000000, 0x9a1c2f6800000000, 0x34385ed200000000,
  0x6870bda400000000, 0xd0e17b4800000000, 0xa1c2f69200000000,
  0x4385ed2600000000, 0x870bda4c00000000, 0xe17b49a00000000,
  0x1c2f693400000000
};

// ===== CT_XOR_2_11 =====
static const uint64_t CT_group2_33R[33] = {
  0x00000001383a421e, 0x000000007074843d, 0x00000000e0e9087a,
  0x00000001c1d210f4, 0x0000000183a421e9, 0x00000001074843d3,
  0x000000000e9087a7, 0x000000001d210f4e, 0x000000003a421e9c,
  0x0000000074843d38, 0x00000000e9087a70, 0x00000001d210f4e0,
  0x00000001a421e9c1, 0x000000014843d383, 0x000000009087a707,
  0x00000001210f4e0e, 0x00000000421e9c1d, 0x00000000843d383a,
  0x00000001087a7074, 0x0000000010f4e0e9, 0x0000000021e9c1d2,
  0x0000000043d383a4, 0x0000000087a70748, 0x000000010f4e0e90,
  0x000000001e9c1d21, 0x000000003d383a42, 0x000000007a707484,
  0x00000000f4e0e908, 0x00000001e9c1d210, 0x00000001d383a421,
  0x00000001a7074843, 0x000000014e0e9087, 0x000000009c1d210f
};

static const uint64_t CT_group2_31L[31] = {
  0x5997dfaa00000000, 0xb32fbf5400000000, 0x665f7eaa00000000,
  0xccbefd5400000000, 0x997dfaaa00000000, 0x32fbf55600000000,
  0x65f7eaac00000000, 0xcbefd55800000000, 0x97dfaab200000000,
  0x2fbf556600000000, 0x5f7eaacc00000000, 0xbefd559800000000,
  0x7dfaab3200000000, 0xfbf5566400000000, 0xf7eaacca00000000,
  0xefd5599600000000, 0xdfaab32e00000000, 0xbf55665e00000000,
  0x7eaaccbe00000000, 0xfd55997c00000000, 0xfaab32fa00000000,
  0xf55665f600000000, 0xeaaccbee00000000, 0xd55997de00000000,
  0xaab32fbe00000000, 0x55665f7e00000000, 0xaaccbefc00000000,
  0x55997dfa00000000, 0xab32fbf400000000, 0x5665f7ea00000000,
  0xaccbefd400000000
};

// ===== CT_XOR_3_12 =====
static const uint64_t CT_group3_33R[33] = {
  0x000000016c643607, 0x00000000d8c86c0f, 0x00000001b190d81e,
  0x000000016321b03d, 0x00000000c643607b, 0x000000018c86c0f6,
  0x00000001190d81ed, 0x00000000321b03db, 0x00000000643607b6,
  0x00000000c86c0f6c, 0x0000000190d81ed8, 0x0000000121b03db1,
  0x0000000043607b63, 0x0000000086c0f6c6, 0x000000010d81ed8c,
  0x000000001b03db19, 0x000000003607b632, 0x000000006c0f6c64,
  0x00000000d81ed8c8, 0x00000001b03db190, 0x00000001607b6321,
  0x00000000c0f6c643, 0x0000000181ed8c86, 0x0000000103db190d,
  0x0000000007b6321b, 0x000000000f6c6436, 0x000000001ed8c86c,
  0x000000003db190d8, 0x000000007b6321b0, 0x00000000f6c64360,
  0x00000001ed8c86c0, 0x00000001db190d81, 0x00000001b6321b03
};

static const uint64_t CT_group3_31L[31] = {
  0x2c62c05000000000, 0x58c580a000000000, 0xb18b014000000000,
  0x6316028200000000, 0xc62c050400000000, 0x8c580a0a00000000,
  0x18b0141600000000, 0x3160282c00000000, 0x62c0505800000000,
  0xc580a0b000000000, 0x8b01416200000000, 0x160282c600000000,
  0x2c05058c00000000, 0x580a0b1800000000, 0xb014163000000000,
  0x60282c6200000000, 0xc05058c400000000, 0x80a0b18a00000000,
  0x141631600000000,  0x282c62c00000000,  0x5058c5800000000,
  0xa0b18b000000000,  0x1416316000000000, 0x282c62c000000000,
  0x5058c58000000000, 0xa0b18b0000000000, 0x4163160200000000,
  0x82c62c0400000000, 0x58c580a00000000,  0xb18b01400000000,
  0x1631602800000000
};

// ===== CT_XOR_4_13 =====
static const uint64_t CT_group4_33R[33] = {
  0x000000012af12d90, 0x0000000055e25b21, 0x00000000abc4b642,
  0x0000000157896c84, 0x00000000af12d909, 0x000000015e25b212,
  0x00000000bc4b6425, 0x000000017896c84a, 0x00000000f12d9095,
  0x00000001e25b212a, 0x00000001c4b64255, 0x00000001896c84ab,
  0x0000000112d90957, 0x0000000025b212af, 0x000000004b64255e,
  0x0000000096c84abc, 0x000000012d909578, 0x000000005b212af1,
  0x00000000b64255e2, 0x000000016c84abc4, 0x00000000d9095789,
  0x00000001b212af12, 0x0000000164255e25, 0x00000000c84abc4b,
  0x0000000190957896, 0x00000001212af12d, 0x000000004255e25b,
  0x0000000084abc4b6, 0x000000010957896c, 0x0000000012af12d9,
  0x00000000255e25b2, 0x000000004abc4b64, 0x00000000957896c8
};

static const uint64_t CT_group4_31L[31] = {
  0x5186a5a800000000, 0xa30d4b5000000000, 0x461a96a200000000,
  0x8c352d4400000000, 0x186a5a8a00000000, 0x30d4b51400000000,
  0x61a96a2800000000, 0xc352d45000000000, 0x86a5a8a200000000,
  0xd4b514600000000,  0x1a96a28c00000000, 0x352d451800000000,
  0x6a5a8a3000000000, 0xd4b5146000000000, 0xa96a28c200000000,
  0x52d4518600000000, 0xa5a8a30c00000000, 0x4b51461a00000000,
  0x96a28c3400000000, 0x2d45186a00000000, 0x5a8a30d400000000,
  0xb51461a800000000, 0x6a28c35200000000, 0xd45186a400000000,
  0xa8a30d4a00000000, 0x51461a9600000000, 0xa28c352c00000000,
  0x45186a5a00000000, 0x8a30d4b400000000, 0x1461a96a00000000,
  0x28c352d400000000
};

// ===== CT_XOR_5_14 =====
static const uint64_t CT_group5_33R[33] = {
  0x0000000105426fbe, 0x000000000a84df7d, 0x000000001509befa,
  0x000000002a137df4, 0x000000005426fbe8, 0x00000000a84df7d0,
  0x00000001509befa0, 0x00000000a137df41, 0x00000001426fbe82,
  0x0000000084df7d05, 0x0000000109befa0a, 0x00000000137df415,
  0x0000000026fbe82a, 0x000000004df7d054, 0x000000009befa0a8,
  0x0000000137df4150, 0x000000006fbe82a1, 0x00000000df7d0542,
  0x00000001befa0a84, 0x000000017df41509, 0x00000000fbe82a13,
  0x00000001f7d05426, 0x00000001efa0a84d, 0x00000001df41509b,
  0x00000001be82a137, 0x000000017d05426f, 0x00000000fa0a84df,
  0x00000001f41509be, 0x00000001e82a137d, 0x00000001d05426fb,
  0x00000001a0a84df7, 0x0000000141509bef, 0x0000000082a137df
};

static const uint64_t CT_group5_31L[31] = {
  0x34fd2f6200000000, 0x69fa5ec400000000, 0xd3f4bd8800000000,
  0xa7e97b1200000000, 0x4fd2f62600000000, 0x9fa5ec4c00000000,
  0x3f4bd89a00000000, 0x7e97b13400000000, 0xfd2f626800000000,
  0xfa5ec4d200000000, 0xf4bd89a600000000, 0xe97b134e00000000,
  0xd2f6269e00000000, 0xa5ec4d3e00000000, 0x4bd89a7e00000000,
  0x97b134fc00000000, 0x2f6269fa00000000, 0x5ec4d3f400000000,
  0xbd89a7e800000000, 0x7b134fd200000000, 0xf6269fa400000000,
  0xec4d3f4a00000000, 0xd89a7e9600000000, 0xb134fd2e00000000,
  0x6269fa5e00000000, 0xc4d3f4bc00000000, 0x89a7e97a00000000,
  0x134fd2f600000000, 0x269fa5ec00000000, 0x4d3f4bd800000000,
  0x9a7e97b000000000
};

// ===== CT_XOR_6_15 =====
static const uint64_t CT_group6_33R[33] = {
  0x000000001e12f0f6, 0x000000003c25e1ec, 0x00000000784bc3d8,
  0x00000000f09787b0, 0x00000001e12f0f60, 0x00000001c25e1ec1,
  0x0000000184bc3d83, 0x0000000109787b07, 0x0000000012f0f60f,
  0x0000000025e1ec1e, 0x000000004bc3d83c, 0x000000009787b078,
  0x000000012f0f60f0, 0x000000005e1ec1e1, 0x00000000bc3d83c2,
  0x00000001787b0784, 0x00000000f0f60f09, 0x00000001e1ec1e12,
  0x00000001c3d83c25, 0x0000000187b0784b, 0x000000010f60f097,
  0x000000001ec1e12f, 0x000000003d83c25e, 0x000000007b0784bc,
  0x00000000f60f0978, 0x00000001ec1e12f0, 0x00000001d83c25e1,
  0x00000001b0784bc3, 0x0000000160f09787, 0x00000000c1e12f0f,
  0x0000000183c25e1e, 0x000000010784bc3d, 0x000000000f09787b
};

static const uint64_t CT_group6_31L[31] = {
  0xfd1fccb200000000, 0xfa3f996600000000, 0xf47f32ce00000000,
  0xe8fe659e00000000, 0xd1fccb3e00000000, 0xa3f9967e00000000,
  0x47f32cfe00000000, 0x8fe659fc00000000, 0x1fccb3fa00000000,
  0x3f9967f400000000, 0x7f32cfe800000000, 0xfe659fd000000000,
  0xfccb3fa200000000, 0xf9967f4600000000, 0xf32cfe8e00000000,
  0xe659fd1e00000000, 0xccb3fa3e00000000, 0x9967f47e00000000,
  0x32cfe8fe00000000, 0x659fd1fc00000000, 0xcb3fa3f800000000,
  0x967f47f200000000, 0x2cfe8fe600000000, 0x59fd1fcc00000000,
  0xb3fa3f9800000000, 0x67f47f3200000000, 0xcfe8fe6400000000,
  0x9fd1fcca00000000, 0x3fa3f99600000000, 0x7f47f32c00000000,
  0xfe8fe65800000000
};

// ===== CT_XOR_7_16 =====
static const uint64_t CT_group7_33R[33] = {
  0x000000018d22c3a7, 0x000000011a45874f, 0x00000000348b0e9f,
  0x0000000069161d3e, 0x00000000d22c3a7c, 0x00000001a45874f8,
  0x0000000148b0e9f1, 0x000000009161d3e3, 0x0000000122c3a7c6,
  0x0000000045874f8d, 0x000000008b0e9f1a, 0x00000001161d3e34,
  0x000000002c3a7c69, 0x000000005874f8d2, 0x00000000b0e9f1a4,
  0x0000000161d3e348, 0x00000000c3a7c691, 0x00000001874f8d22,
  0x000000010e9f1a45, 0x000000001d3e348b, 0x000000003a7c6916,
  0x0000000074f8d22c, 0x00000000e9f1a458, 0x00000001d3e348b0,
  0x00000001a7c69161, 0x000000014f8d22c3, 0x000000009f1a4587,
  0x000000013e348b0e, 0x000000007c69161d, 0x00000000f8d22c3a,
  0x00000001f1a45874, 0x00000001e348b0e9, 0x00000001c69161d3
};

static const uint64_t CT_group7_31L[31] = {
  0xde1be16400000000, 0xbc37c2ca00000000, 0x786f859600000000,
  0xf0df0b2c00000000, 0xe1be165a00000000, 0xc37c2cb600000000,
  0x86f8596e00000000, 0xdf0b2de00000000,  0x1be165bc00000000,
  0x37c2cb7800000000, 0x6f8596f000000000, 0xdf0b2de000000000,
  0xbe165bc200000000, 0x7c2cb78600000000, 0xf8596f0c00000000,
  0xf0b2de1a00000000, 0xe165bc3600000000, 0xc2cb786e00000000,
  0x8596f0de00000000, 0xb2de1be00000000,  0x165bc37c00000000,
  0x2cb786f800000000, 0x596f0df000000000, 0xb2de1be000000000,
  0x65bc37c200000000, 0xcb786f8400000000, 0x96f0df0a00000000,
  0x2de1be1600000000, 0x5bc37c2c00000000, 0xb786f85800000000,
  0x6f0df0b200000000
};

// ===== CT_XOR_8_17 =====
static const uint64_t CT_group8_33R[33] = {
  0x00000001a878cd6c, 0x0000000150f19ad9, 0x00000000a1e335b3,
  0x0000000143c66b66, 0x00000000878cd6cd, 0x000000010f19ad9a,
  0x000000001e335b35, 0x000000003c66b66a, 0x0000000078cd6cd4,
  0x00000000f19ad9a8, 0x00000001e335b350, 0x00000001c66b66a1,
  0x000000018cd6cd43, 0x0000000119ad9a87, 0x00000000335b350f,
  0x0000000066b66a1e, 0x00000000cd6cd43c, 0x000000019ad9a878,
  0x0000000135b350f1, 0x000000006b66a1e3, 0x00000000d6cd43c6,
  0x00000001ad9a878c, 0x000000015b350f19, 0x00000000b66a1e33,
  0x000000016cd43c66, 0x00000000d9a878cd, 0x00000001b350f19a,
  0x0000000166a1e335, 0x00000000cd43c66b, 0x000000019a878cd6,
  0x00000001350f19ad, 0x000000006a1e335b, 0x00000000d43c66b6
};

static const uint64_t CT_group8_31L[31] = {
  0x669139b400000000, 0xcd22736800000000, 0x9a44e6d200000000,
  0x3489cda600000000, 0x69139b4c00000000, 0xd227369800000000,
  0xa44e6d3200000000, 0x489cda6600000000, 0x9139b4cc00000000,
  0x2273699a00000000, 0x44e6d33400000000, 0x89cda66800000000,
  0x139b4cd200000000, 0x273699a400000000, 0x4e6d334800000000,
  0x9cda669000000000, 0x39b4cd2200000000, 0x73699a4400000000,
  0xe6d3348800000000, 0xcda6691200000000, 0x9b4cd22600000000,
  0x3699a44e00000000, 0x6d33489c00000000, 0xda66913800000000,
  0xb4cd227200000000, 0x699a44e600000000, 0xd33489cc00000000,
  0xa669139a00000000, 0x4cd2273600000000, 0x99a44e6c00000000,
  0x33489cda00000000
};

// ===== CT_XOR_9_18 =====
static const uint64_t CT_group9_33R[33] = {
  0x0000000112bacedc, 0x0000000025759db9, 0x000000004aeb3b72,
  0x0000000095d676e4, 0x000000012bacedc8, 0x000000005759db91,
  0x00000000aeb3b722, 0x000000015d676e44, 0x00000000bacedc89,
  0x00000001759db912, 0x00000000eb3b7225, 0x00000001d676e44a,
  0x00000001acedc895, 0x0000000159db912b, 0x00000000b3b72257,
  0x00000001676e44ae, 0x00000000cedc895d, 0x000000019db912ba,
  0x000000013b722575, 0x0000000076e44aeb, 0x00000000edc895d6,
  0x00000001db912bac, 0x00000001b7225759, 0x000000016e44aeb3,
  0x00000000dc895d67, 0x00000001b912bace, 0x000000017225759d,
  0x00000000e44aeb3b, 0x00000001c895d676, 0x00000001912baced,
  0x00000001225759db, 0x0000000044aeb3b7, 0x00000000895d676e
};

static const uint64_t CT_group9_31L[31] = {
  0x36f4413e00000000, 0x6de8827c00000000, 0xdbd104f800000000,
  0xb7a209f200000000, 0x6f4413e600000000, 0xde8827cc00000000,
  0xbd104f9a00000000, 0x7a209f3600000000, 0xf4413e6c00000000,
  0xe8827cda00000000, 0xd104f9b600000000, 0xa209f36e00000000,
  0x4413e6de00000000, 0x8827cdbc00000000, 0x104f9b7a00000000,
  0x209f36f400000000, 0x413e6de800000000, 0x827cdbd000000000,
  0x4f9b7a200000000,  0x9f36f4400000000,  0x13e6de8800000000,
  0x27cdbd1000000000, 0x4f9b7a2000000000, 0x9f36f44000000000,
  0x3e6de88200000000, 0x7cdbd10400000000, 0xf9b7a20800000000,
  0xf36f441200000000, 0xe6de882600000000, 0xcdbd104e00000000,
  0x9b7a209e00000000
};

// ===== CA_XOR_1_10 =====
static const uint64_t CA_group1_33R[33] = {
  0x0000000045391840, 0x000000008a723080, 0x0000000114e46100,
  0x0000000029c8c201, 0x0000000053918402, 0x00000000a7230804,
  0x000000014e461008, 0x000000009c8c2011, 0x0000000139184022,
  0x0000000072308045, 0x00000000e461008a, 0x00000001c8c20114,
  0x0000000191840229, 0x0000000123080453, 0x00000000461008a7,
  0x000000008c20114e, 0x000000011840229c, 0x0000000030804539,
  0x0000000061008a72, 0x00000000c20114e4, 0x00000001840229c8,
  0x0000000108045391, 0x000000001008a723, 0x0000000020114e46,
  0x0000000040229c8c, 0x0000000080453918, 0x00000001008a7230,
  0x000000000114e461, 0x000000000229c8c2, 0x0000000004539184,
  0x0000000008a72308, 0x00000000114e4610, 0x00000000229c8c20
};

static const uint64_t CA_group1_31L[31] = {
  0xd2e69a6200000000, 0xa5cd34c600000000, 0x4b9a698e00000000,
  0x9734d31c00000000, 0x2e69a63a00000000, 0x5cd34c7400000000,
  0xb9a698e800000000, 0x734d31d200000000, 0xe69a63a400000000,
  0xcd34c74a00000000, 0x9a698e9600000000, 0x34d31d2e00000000,
  0x69a63a5c00000000, 0xd34c74b800000000, 0xa698e97200000000,
  0x4d31d2e600000000, 0x9a63a5cc00000000, 0x34c74b9a00000000,
  0x698e973400000000, 0xd31d2e6800000000, 0xa63a5cd200000000,
  0x4c74b9a600000000, 0x98e9734c00000000, 0x31d2e69a00000000,
  0x63a5cd3400000000, 0xc74b9a6800000000, 0x8e9734d200000000,
  0x1d2e69a600000000, 0x3a5cd34c00000000, 0x74b9a69800000000,
  0xe9734d3000000000
};

// ===== CA_XOR_2_11 =====
static const uint64_t CA_group2_33R[33] = {
  0x000000016278deaf, 0x00000000c4f1bd5f, 0x0000000189e37abe,
  0x0000000113c6f57d, 0x00000000278deafb, 0x000000004f1bd5f6,
  0x000000009e37abec, 0x000000013c6f57d8, 0x0000000078deafb1,
  0x00000000f1bd5f62, 0x00000001e37abec4, 0x00000001c6f57d89,
  0x000000018deafb13, 0x000000011bd5f627, 0x0000000037abec4f,
  0x000000006f57d89e, 0x00000000deafb13c, 0x00000001bd5f6278,
  0x000000017abec4f1, 0x00000000f57d89e3, 0x00000001eafb13c6,
  0x00000001d5f6278d, 0x00000001abec4f1b, 0x0000000157d89e37,
  0x00000000afb13c6f, 0x000000015f6278de, 0x00000000bec4f1bd,
  0x000000017d89e37a, 0x00000000fb13c6f5, 0x00000001f6278dea,
  0x00000001ec4f1bd5, 0x00000001d89e37ab, 0x00000001b13c6f57
};

static const uint64_t CA_group2_31L[31] = {
  0xfcdf375200000000, 0xf9be6ea600000000, 0xf37cdd4e00000000,
  0xe6f9ba9e00000000, 0xcdf3753e00000000, 0x9be6ea7e00000000,
  0x37cdd4fe00000000, 0x6f9ba9fc00000000, 0xdf3753f800000000,
  0xbe6ea7f200000000, 0x7cdd4fe600000000, 0xf9ba9fcc00000000,
  0xf3753f9a00000000, 0xe6ea7f3600000000, 0xcdd4fe6e00000000,
  0x9ba9fcde00000000, 0x3753f9be00000000, 0x6ea7f37c00000000,
  0xdd4fe6f800000000, 0xba9fcdf200000000, 0x753f9be600000000,
  0xea7f37cc00000000, 0xd4fe6f9a00000000, 0xa9fcdf3600000000,
  0x53f9be6e00000000, 0xa7f37cdc00000000, 0x4fe6f9ba00000000,
  0x9fcdf37400000000, 0x3f9be6ea00000000, 0x7f37cdd400000000,
  0xfe6f9ba800000000
};

// ===== CA_XOR_3_12 =====
static const uint64_t CA_group3_33R[33] = {
  0x00000001024fd310, 0x00000000049fa621, 0x00000000093f4c42,
  0x00000000127e9884, 0x0000000024fd3108, 0x0000000049fa6210,
  0x0000000093f4c420, 0x0000000127e98840, 0x000000004fd31081,
  0x000000009fa62102, 0x000000013f4c4204, 0x000000007e988409,
  0x00000000fd310812, 0x00000001fa621024, 0x00000001f4c42049,
  0x00000001e9884093, 0x00000001d3108127, 0x00000001a621024f,
  0x000000014c42049f, 0x000000009884093f, 0x000000013108127e,
  0x00000000621024fd, 0x00000000c42049fa, 0x00000001884093f4,
  0x00000001108127e9, 0x0000000021024fd3, 0x0000000042049fa6,
  0x0000000084093f4c, 0x0000000108127e98, 0x000000001024fd31,
  0x000000002049fa62, 0x000000004093f4c4, 0x000000008127e988
};

static const uint64_t CA_group3_31L[31] = {
  0x72e4656e00000000, 0xe5c8cadc00000000, 0xcb9195ba00000000,
  0x97232b7600000000, 0x2e4656ee00000000, 0x5c8caddc00000000,
  0xb9195bb800000000, 0x7232b77200000000, 0xe4656ee400000000,
  0xc8caddca00000000, 0x9195bb9600000000, 0x232b772e00000000,
  0x4656ee5c00000000, 0x8caddcb800000000, 0x195bb97200000000,
  0x32b772e400000000, 0x656ee5c800000000, 0xcaddcb9000000000,
  0x95bb972200000000, 0x2b772e4600000000, 0x56ee5c8c00000000,
  0xaddcb91800000000, 0x5bb9723200000000, 0xb772e46400000000,
  0x6ee5c8ca00000000, 0xddcb919400000000, 0xbb97232a00000000,
  0x772e465600000000, 0xee5c8cac00000000, 0xdcb9195a00000000,
  0xb97232b600000000
};

// ===== CA_XOR_4_13 =====
static const uint64_t CA_group4_33R[33] = {
  0x00000000976fa1f8, 0x000000012edf43f0, 0x000000005dbe87e1,
  0x00000000bb7d0fc2, 0x0000000176fa1f84, 0x00000000edf43f09,
  0x00000001dbe87e12, 0x00000001b7d0fc25, 0x000000016fa1f84b,
  0x00000000df43f097, 0x00000001be87e12e, 0x000000017d0fc25d,
  0x00000000fa1f84bb, 0x00000001f43f0976, 0x00000001e87e12ed,
  0x00000001d0fc25db, 0x00000001a1f84bb7, 0x0000000143f0976f,
  0x0000000087e12edf, 0x000000010fc25dbe, 0x000000001f84bb7d,
  0x000000003f0976fa, 0x000000007e12edf4, 0x00000000fc25dbe8,
  0x00000001f84bb7d0, 0x00000001f0976fa1, 0x00000001e12edf43,
  0x00000001c25dbe87, 0x0000000184bb7d0f, 0x000000010976fa1f,
  0x0000000012edf43f, 0x0000000025dbe87e, 0x000000004bb7d0fc
};

static const uint64_t CA_group4_31L[31] = {
  0xdee651b200000000, 0xbdcca36600000000, 0x7b9946ce00000000,
  0xf7328d9c00000000, 0xee651b3a00000000, 0xdcca367600000000,
  0xb9946cee00000000, 0x7328d9de00000000, 0xe651b3bc00000000,
  0xcca3677a00000000, 0x9946cef600000000, 0x328d9dee00000000,
  0x651b3bdc00000000, 0xca3677b800000000, 0x946cef7200000000,
  0x28d9dee600000000, 0x51b3bdcc00000000, 0xa3677b9800000000,
  0x46cef73200000000, 0x8d9dee6400000000, 0x1b3bdcca00000000,
  0x3677b99400000000, 0x6cef732800000000, 0xd9dee65000000000,
  0xb3bdcca200000000, 0x677b994600000000, 0xcef7328c00000000,
  0x9dee651a00000000, 0x3bdcca3600000000, 0x77b9946c00000000,
  0xef7328d800000000
};

// ===== CA_XOR_5_14 =====
static const uint64_t CA_group5_33R[33] = {
  0x00000001ec8cd8f0, 0x00000001d919b1e1, 0x00000001b23363c3,
  0x000000016466c787, 0x00000000c8cd8f0f, 0x00000001919b1e1e,
  0x0000000123363c3d, 0x00000000466c787b, 0x000000008cd8f0f6,
  0x0000000119b1e1ec, 0x000000003363c3d9, 0x0000000066c787b2,
  0x00000000cd8f0f64, 0x000000019b1e1ec8, 0x00000001363c3d91,
  0x000000006c787b23, 0x00000000d8f0f646, 0x00000001b1e1ec8c,
  0x0000000163c3d919, 0x00000000c787b233, 0x000000018f0f6466,
  0x000000011e1ec8cd, 0x000000003c3d919b, 0x00000000787b2336,
  0x00000000f0f6466c, 0x00000001e1ec8cd8, 0x00000001c3d919b1,
  0x0000000187b23363, 0x000000010f6466c7, 0x000000001ec8cd8f,
  0x000000003d919b1e, 0x000000007b23363c, 0x00000000f6466c78
};

static const uint64_t CA_group5_31L[31] = {
  0xf328890600000000, 0xe651120e00000000, 0xcca2241e00000000,
  0x9944483e00000000, 0x3288907e00000000, 0x651120fc00000000,
  0xca2241f800000000, 0x944483f200000000, 0x288907e600000000,
  0x51120fcc00000000, 0xa2241f9800000000, 0x44483f3200000000,
  0x88907e6400000000, 0x1120fcca00000000, 0x2241f99400000000,
  0x4483f32800000000, 0x8907e65000000000, 0x120fcca200000000,
  0x241f994400000000, 0x483f328800000000, 0x907e651000000000,
  0x20fcca2200000000, 0x41f9944400000000, 0x83f3288800000000,
  0x7e6511200000000,  0xfcca22400000000,  0x1f99444800000000,
  0x3f32889000000000, 0x7e65112000000000, 0xfcca224000000000,
  0xf994448200000000
};

// ===== CA_XOR_6_15 =====
static const uint64_t CA_group6_33R[33] = {
  0x00000000868dad85, 0x000000010d1b5b0a, 0x000000001a36b615,
  0x00000000346d6c2a, 0x0000000068dad854, 0x00000000d1b5b0a8,
  0x00000001a36b6150, 0x0000000146d6c2a1, 0x000000008dad8543,
  0x000000011b5b0a86, 0x0000000036b6150d, 0x000000006d6c2a1a,
  0x00000000dad85434, 0x00000001b5b0a868, 0x000000016b6150d1,
  0x00000000d6c2a1a3, 0x00000001ad854346, 0x000000015b0a868d,
  0x00000000b6150d1b, 0x000000016c2a1a36, 0x00000000d854346d,
  0x00000001b0a868da, 0x000000016150d1b5, 0x00000000c2a1a36b,
  0x00000001854346d6, 0x000000010a868dad, 0x00000000150d1b5b,
  0x000000002a1a36b6, 0x0000000054346d6c, 0x00000000a868dad8,
  0x0000000150d1b5b0, 0x00000000a1a36b61, 0x000000014346d6c2
};

static const uint64_t CA_group6_31L[31] = {
  0x129d255400000000, 0x253a4aa800000000, 0x4a74955000000000,
  0x94e92aa000000000, 0x29d2554200000000, 0x53a4aa8400000000,
  0xa749550800000000, 0x4e92aa1200000000, 0x9d25542400000000,
  0x3a4aa84a00000000, 0x7495509400000000, 0xe92aa12800000000,
  0xd255425200000000, 0xa4aa84a600000000, 0x4955094e00000000,
  0x92aa129c00000000, 0x2554253a00000000, 0x4aa84a7400000000,
  0x955094e800000000, 0x2aa129d200000000, 0x554253a400000000,
  0xaa84a74800000000, 0x55094e9200000000, 0xaa129d2400000000,
  0x54253a4a00000000, 0xa84a749400000000, 0x5094e92a00000000,
  0xa129d25400000000, 0x4253a4aa00000000, 0x84a7495400000000,
  0x94e92aa00000000
};

// ===== CA_XOR_7_16 =====
static const uint64_t CA_group7_33R[33] = {
  0x0000000077652a44, 0x00000000eeca5488, 0x00000001dd94a910,
  0x00000001bb295221, 0x000000017652a443, 0x00000000eca54887,
  0x00000001d94a910e, 0x00000001b295221d, 0x00000001652a443b,
  0x00000000ca548877, 0x0000000194a910ee, 0x00000001295221dd,
  0x0000000052a443bb, 0x00000000a5488776, 0x000000014a910eec,
  0x0000000095221dd9, 0x000000012a443bb2, 0x0000000054887765,
  0x00000000a910eeca, 0x000000015221dd94, 0x00000000a443bb29,
  0x0000000148877652, 0x00000000910eeca5, 0x00000001221dd94a,
  0x00000000443bb295, 0x000000008877652a, 0x0000000110eeca54,
  0x0000000021dd94a9, 0x0000000043bb2952, 0x00000000877652a4,
  0x000000010eeca548, 0x000000001dd94a91, 0x000000003bb29522
};

static const uint64_t CA_group7_31L[31] = {
  0x23f706d400000000, 0x47ee0da800000000, 0x8fdc1b5000000000,
  0x1fb836a200000000, 0x3f706d4400000000, 0x7ee0da8800000000,
  0xfdc1b51000000000, 0xfb836a2200000000, 0xf706d44600000000,
  0xee0da88e00000000, 0xdc1b511e00000000, 0xb836a23e00000000,
  0x706d447e00000000, 0xe0da88fc00000000, 0xc1b511fa00000000,
  0x836a23f600000000, 0x6d447ee00000000,  0xda88fdc00000000,
  0x1b511fb800000000, 0x36a23f7000000000, 0x6d447ee000000000,
  0xda88fdc000000000, 0xb511fb8200000000, 0x6a23f70600000000,
  0xd447ee0c00000000, 0xa88fdc1a00000000, 0x511fb83600000000,
  0xa23f706c00000000, 0x447ee0da00000000, 0x88fdc1b400000000,
  0x11fb836a00000000
};

// ===== CA_XOR_8_17 =====
static const uint64_t CA_group8_33R[33] = {
  0x000000007b9f6d6c, 0x00000000f73edad8, 0x00000001ee7db5b0,
  0x00000001dcfb6b61, 0x00000001b9f6d6c3, 0x0000000173edad87,
  0x00000000e7db5b0f, 0x00000001cfb6b61e, 0x000000019f6d6c3d,
  0x000000013edad87b, 0x000000007db5b0f7, 0x00000000fb6b61ee,
  0x00000001f6d6c3dc, 0x00000001edad87b9, 0x00000001db5b0f73,
  0x00000001b6b61ee7, 0x000000016d6c3dcf, 0x00000000dad87b9f,
  0x00000001b5b0f73e, 0x000000016b61ee7d, 0x00000000d6c3dcfb,
  0x00000001ad87b9f6, 0x000000015b0f73ed, 0x00000000b61ee7db,
  0x000000016c3dcfb6, 0x00000000d87b9f6d, 0x00000001b0f73eda,
  0x0000000161ee7db5, 0x00000000c3dcfb6b, 0x0000000187b9f6d6,
  0x000000010f73edad, 0x000000001ee7db5b, 0x000000003dcfb6b6
};

static const uint64_t CA_group8_31L[31] = {
  0x3fd2c44800000000, 0x7fa5889000000000, 0xff4b112000000000,
  0xfe96224200000000, 0xfd2c448600000000, 0xfa58890e00000000,
  0xf4b1121e00000000, 0xe962243e00000000, 0xd2c4487e00000000,
  0xa58890fe00000000, 0x4b1121fe00000000, 0x962243fc00000000,
  0x2c4487fa00000000, 0x58890ff400000000, 0xb1121fe800000000,
  0x62243fd200000000, 0xc4487fa400000000, 0x8890ff4a00000000,
  0x1121fe9600000000, 0x2243fd2c00000000, 0x4487fa5800000000,
  0x890ff4b000000000, 0x121fe96200000000, 0x243fd2c400000000,
  0x487fa58800000000, 0x90ff4b1000000000, 0x21fe962200000000,
  0x43fd2c4400000000, 0x87fa588800000000, 0xff4b11200000000,
  0x1fe9622400000000
};

// ===== CA_XOR_9_18 =====
static const uint64_t CA_group9_33R[33] = {
  0x000000011139ceea, 0x0000000022739dd5, 0x0000000044e73baa,
  0x0000000089ce7754, 0x00000001139ceea8, 0x000000002739dd51,
  0x000000004e73baa2, 0x000000009ce77544, 0x0000000139ceea88,
  0x00000000739dd511, 0x00000000e73baa22, 0x00000001ce775444,
  0x000000019ceea889, 0x0000000139dd5113, 0x0000000073baa227,
  0x00000000e775444e, 0x00000001ceea889c, 0x000000019dd51139,
  0x000000013baa2273, 0x00000000775444e7, 0x00000000eea889ce,
  0x00000001dd51139c, 0x00000001baa22739, 0x0000000175444e73,
  0x00000000ea889ce7, 0x00000001d51139ce, 0x00000001aa22739d,
  0x000000015444e73b, 0x00000000a889ce77, 0x0000000151139cee,
  0x00000000a22739dd, 0x00000001444e73ba, 0x00000000889ce775
};

static const uint64_t CA_group9_31L[31] = {
  0xa8a3d2ec00000000, 0x5147a5da00000000, 0xa28f4bb400000000,
  0x451e976a00000000, 0x8a3d2ed400000000, 0x147a5daa00000000,
  0x28f4bb5400000000, 0x51e976a800000000, 0xa3d2ed5000000000,
  0x47a5daa200000000, 0x8f4bb54400000000, 0x1e976a8a00000000,
  0x3d2ed51400000000, 0x7a5daa2800000000, 0xf4bb545000000000,
  0xe976a8a200000000, 0xd2ed514600000000, 0xa5daa28e00000000,
  0x4bb5451e00000000, 0x976a8a3c00000000, 0x2ed5147a00000000,
  0x5daa28f400000000, 0xbb5451e800000000, 0x76a8a3d200000000,
  0xed5147a400000000, 0xdaa28f4a00000000, 0xb5451e9600000000,
  0x6a8a3d2e00000000, 0xd5147a5c00000000, 0xaa28f4ba00000000,
  0x5451e97600000000
};

constexpr const uint64_t* MS_TAB_33R_CC[45] = {
  nullptr, nullptr,       nullptr,       nullptr,       nullptr,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 0–9
  nullptr, CC_group2_33R, CC_group3_33R, CC_group2_33R, CC_group3_33R,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 10–19
  nullptr, CC_group4_33R, CC_group1_33R, CC_group5_33R, CC_group1_33R,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 20–29
  nullptr, CC_group2_33R, CC_group3_33R, CC_group2_33R, CC_group3_33R,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr,      // 30–39
  nullptr, CC_group4_33R, CC_group1_33R, CC_group4_33R, CC_group1_33R // 40–44
};

constexpr const uint64_t* MS_TAB_31L_CC[45] = {
  nullptr, nullptr,       nullptr,       nullptr,       nullptr,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 0–9
  nullptr, CC_group2_31L, CC_group3_31L, CC_group2_31L, CC_group3_31L,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 10–19
  nullptr, CC_group4_31L, CC_group1_31L, CC_group5_31L, CC_group1_31L,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 20–29
  nullptr, CC_group2_31L, CC_group3_31L, CC_group2_31L, CC_group3_31L,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr,      // 30–39
  nullptr, CC_group4_31L, CC_group1_31L, CC_group4_31L, CC_group1_31L // 40–44
};

// ===== MS_TAB_33R_CG =====
constexpr const uint64_t* MS_TAB_33R_CG[45] = {
  nullptr, nullptr,       nullptr,       nullptr,       nullptr,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 0–9
  nullptr, CG_group4_33R, CG_group2_33R, CG_group8_33R, CG_group2_33R,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 10–19
  nullptr, CG_group1_33R, CG_group7_33R, CG_group1_33R, CG_group9_33R,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 20–29
  nullptr, CG_group4_33R, CG_group2_33R, CG_group6_33R, CG_group2_33R,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr,      // 30–39
  nullptr, CG_group5_33R, CG_group3_33R, CG_group1_33R, CG_group3_33R // 40–44
};

// ===== MS_TAB_31L_CG =====
constexpr const uint64_t* MS_TAB_31L_CG[45] = {
  nullptr, nullptr,       nullptr,       nullptr,       nullptr,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 0–9
  nullptr, CG_group4_31L, CG_group2_31L, CG_group8_31L, CG_group2_31L,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 10–19
  nullptr, CG_group1_31L, CG_group7_31L, CG_group1_31L, CG_group9_31L,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 20–29
  nullptr, CG_group4_31L, CG_group2_31L, CG_group6_31L, CG_group2_31L,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr,      // 30–39
  nullptr, CG_group5_31L, CG_group3_31L, CG_group1_31L, CG_group3_31L // 40–44
};

// ===== MS_TAB_33R_CA =====
constexpr const uint64_t* MS_TAB_33R_CA[45] = {
  nullptr, nullptr,       nullptr,       nullptr,       nullptr,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 0–9
  nullptr, CA_group3_33R, CA_group2_33R, CA_group7_33R, CA_group2_33R,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 10–19
  nullptr, CA_group1_33R, CA_group6_33R, CA_group9_33R, CA_group8_33R,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 20–29
  nullptr, CA_group3_33R, CA_group2_33R, CA_group5_33R, CA_group2_33R,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr,      // 30–39
  nullptr, CA_group1_33R, CA_group4_33R, CA_group1_33R, CA_group4_33R // 40–44
};

// ===== MS_TAB_31L_CA =====
constexpr const uint64_t* MS_TAB_31L_CA[45] = {
  nullptr, nullptr,       nullptr,       nullptr,       nullptr,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 0–9
  nullptr, CA_group3_31L, CA_group2_31L, CA_group7_31L, CA_group2_31L,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 10–19
  nullptr, CA_group1_31L, CA_group6_31L, CA_group9_31L, CA_group8_31L,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 20–29
  nullptr, CA_group3_31L, CA_group2_31L, CA_group5_31L, CA_group2_31L,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr,      // 30–39
  nullptr, CA_group1_31L, CA_group4_31L, CA_group1_31L, CA_group4_31L // 40–44
};

// ===== MS_TAB_33R_CT =====
constexpr const uint64_t* MS_TAB_33R_CT[45] = {
  nullptr, nullptr,       nullptr,       nullptr,       nullptr,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 0–9
  nullptr, CT_group2_33R, CT_group3_33R, CT_group2_33R, CT_group3_33R,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 10–19
  nullptr, CT_group8_33R, CT_group5_33R, CT_group9_33R, CT_group1_33R,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 20–29
  nullptr, CT_group2_33R, CT_group3_33R, CT_group4_33R, CT_group3_33R,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr,      // 30–39
  nullptr, CT_group6_33R, CT_group1_33R, CT_group7_33R, CT_group1_33R // 40–44
};

// ===== MS_TAB_31L_CT =====
constexpr const uint64_t* MS_TAB_31L_CT[45] = {
  nullptr, nullptr,       nullptr,       nullptr,       nullptr,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 0–9
  nullptr, CT_group2_31L, CT_group3_31L, CT_group2_31L, CT_group3_31L,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 10–19
  nullptr, CT_group8_31L, CT_group5_31L, CT_group9_31L, CT_group1_31L,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr, // 20–29
  nullptr, CT_group2_31L, CT_group3_31L, CT_group4_31L, CT_group3_31L,
  nullptr, nullptr,       nullptr,       nullptr,       nullptr,      // 30–39
  nullptr, CT_group6_31L, CT_group1_31L, CT_group7_31L, CT_group1_31L // 40–44
};

inline uint64_t
srol_bs_table(uint8_t out_idx,
              unsigned d,
              const uint64_t* const* TAB_33R,
              const uint64_t* const* TAB_31L)
{
  d = d / 2;
  return (TAB_31L[out_idx][d < 31 ? d : d % 31] | /* NOLINT */
          TAB_33R[out_idx][d < 33 ? d : d % 33]); /* NOLINT */
}

inline uint64_t
next_forward_bs_hash(uint64_t fh_val,
                     unsigned k,
                     unsigned char char_out1,
                     unsigned char char_out2,
                     unsigned char char_in1,
                     unsigned char char_in2,
                     const uint64_t* DIMER_TAB,
                     const uint64_t* const* TAB_33R,
                     const uint64_t* const* TAB_31L)
{
  uint8_t out_idx = 10 * BS_CONVERT_TAB[char_out1] + BS_CONVERT_TAB[char_out2];
  uint8_t in_idx = 10 * BS_CONVERT_TAB[char_in1] + BS_CONVERT_TAB[char_in2];

  uint64_t h_val = srol(fh_val);

  h_val ^= srol_bs_table(out_idx, k, TAB_33R, TAB_31L);
  h_val ^= DIMER_TAB[in_idx];

  return h_val;
}

inline uint64_t
prev_forward_bs_hash(uint64_t fh_val,
                     unsigned k,
                     unsigned char char_out1,
                     unsigned char char_out2,
                     unsigned char char_in1,
                     unsigned char char_in2,
                     const uint64_t* DIMER_TAB,
                     const uint64_t* const* TAB_33R,
                     const uint64_t* const* TAB_31L)
{
  uint8_t out_idx = 10 * BS_CONVERT_TAB[char_out1] + BS_CONVERT_TAB[char_out2];
  uint8_t in_idx = 10 * BS_CONVERT_TAB[char_in1] + BS_CONVERT_TAB[char_in2];

  uint64_t h_val = fh_val ^ srol_bs_table(in_idx, k, TAB_33R, TAB_31L);
  h_val ^= DIMER_TAB[out_idx];
  h_val = sror(h_val);
  return h_val;
}

// Generic dimer-based reverse hash using pointer table
inline std::vector<uint64_t>
base_reverse_bs_hash(const char* seq,
                     bool has_second,
                     unsigned k,
                     const uint64_t* DIMER_TAB)
{

  uint64_t h0 = 0;
  uint64_t h1 = 0;

  for (int i = (int)k - 1; i >= 1; i -= 2) {
    h0 = srol(h0, 1);
    const uint8_t a = BS_RC_CONVERT_TAB[(unsigned char)seq[i]];
    const uint8_t b = BS_RC_CONVERT_TAB[(unsigned char)seq[i - 1]];
    const uint8_t loc = 10 * a + b;
    h0 ^= DIMER_TAB[loc];
  }

  if (!has_second)
    return { h0, 0 };

  for (int i = (int)k; i >= 2; i -= 2) {
    h1 = srol(h1, 1);
    const uint8_t a = BS_RC_CONVERT_TAB[(unsigned char)seq[i]];
    const uint8_t b = BS_RC_CONVERT_TAB[(unsigned char)seq[i - 1]];
    const uint8_t loc = 10 * a + b;
    h1 ^= DIMER_TAB[loc];
  }

  return { h0, h1 };
}

inline uint64_t
next_reverse_bs_hash(uint64_t rh_val,
                     unsigned k,
                     unsigned char char_out1,
                     unsigned char char_out2,
                     unsigned char char_in1,
                     unsigned char char_in2,
                     const uint64_t* DIMER_TAB,
                     const uint64_t* const* TAB_33R,
                     const uint64_t* const* TAB_31L)
{
  uint8_t out_idx =
    10 * BS_RC_CONVERT_TAB[char_out2] + BS_RC_CONVERT_TAB[char_out1];
  uint8_t in_idx =
    10 * BS_RC_CONVERT_TAB[char_in2] + BS_RC_CONVERT_TAB[char_in1];
  uint64_t h_val = rh_val ^ srol_bs_table(in_idx, k, TAB_33R, TAB_31L);
  h_val ^= DIMER_TAB[out_idx];
  h_val = sror(h_val);
  return h_val;
}

inline uint64_t
prev_reverse_bs_hash(uint64_t rh_val,
                     unsigned k,
                     unsigned char char_out1,
                     unsigned char char_out2,
                     unsigned char char_in1,
                     unsigned char char_in2,
                     const uint64_t* DIMER_TAB,
                     const uint64_t* const* TAB_33R,
                     const uint64_t* const* TAB_31L)
{
  uint8_t out_idx =
    10 * BS_RC_CONVERT_TAB[char_out2] + BS_RC_CONVERT_TAB[char_out1];
  uint8_t in_idx =
    10 * BS_RC_CONVERT_TAB[char_in2] + BS_RC_CONVERT_TAB[char_in1];
  uint64_t h_val = srol(rh_val);
  h_val ^= DIMER_TAB[in_idx];
  h_val ^= srol_bs_table(out_idx, k, TAB_33R, TAB_31L);
  return h_val;
}

} // namespace btllib::hashing_internals
