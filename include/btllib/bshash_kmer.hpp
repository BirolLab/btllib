#pragma once

#include <array>
#include <cstdint>
#include <cstring>
#include <deque>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <unordered_set>

#include <btllib/hashing_internals.hpp>
#include <btllib/status.hpp>

namespace btllib {
using hashing_internals::sror;
using hashing_internals::srol;
constexpr uint8_t CONVERT_TAB_SIMPLE[128] = {
    // 0–64
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,
    1,0,2,0,0,
    0,3,0,0,0,0,0,0,0,0,
    0,0,0,0,4,0,0,0,0,0,
    0,0,0,0,0,0,0,
    1,0,2,
    0,0,0,3,0,0,0,0,0,0,
    0,0,0,0,0,0,4,
    0,0,0,
    0,0,0,0,0,0,0,0
};

constexpr uint8_t CONVERT_TAB_RC[128] = {

    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,
    4,0,3,0,0,
    0,2,0,0,0,0,0,0,0,0,
    0,0,0,0,1,0,0,0,0,0,
    0,0,0,0,0,0,0,
    4,0,3,
    0,0,0,2,0,0,0,0,0,0,
    0,0,0,0,0,0,1,
    0,0,0,
    0,0,0,0,0,0,0,0
};

constexpr uint64_t CC_DIMER_TAB[45] = {
    0,0,0,0,0,0,0,0,0,0,                                     // 0–9
    0,0x1bc5d5aba6ea6e02ULL,0x8f15314b06b5ed9cULL,0x1bc5d5aba6ea6e02ULL,0x8f15314b06b5ed9cULL,0,0,0,0,0,  
    0,0x44fec7e4a74bce00ULL,0x77c24a36c934fdc1ULL,0x44fec7e4a74bce00ULL,0x77c24a36c934fdc1ULL,0,0,0,0,0,  
    0,0x1bc5d5aba6ea6e02ULL,0x8f15314b06b5ed9cULL,0x1bc5d5aba6ea6e02ULL,0x8f15314b06b5ed9cULL,0,0,0,0,0,  
    0,0x44fec7e4a74bce00ULL,0x77c24a36c934fdc1ULL,0x44fec7e4a74bce00ULL,0x77c24a36c934fdc1ULL             
};


constexpr uint64_t CG_DIMER_TAB[45] = {
    0,0,0,0,0,0,0,0,0,0,
    0,0x54f8849020caa27fULL,0xab9766c9a48a5d70ULL,0x7f01ee303c53b1bcULL,0xab9766c9a48a5d70ULL,0,0,0,0,0,
    0,0xd22f7891d06d2f5aULL,0xf1bd2f3bbfb10000ULL,0xd22f7891d06d2f5aULL,0xf1bd2f3bbfb10000ULL,0,0,0,0,0,
    0,0x54f8849020caa27fULL,0xab9766c9a48a5d70ULL,0x7f01ee303c53b1bcULL,0xab9766c9a48a5d70ULL,0,0,0,0,0,
    0,0x414ce1fc78d4d36fULL,0xff3adb2d91cd4803ULL,0xd22f7891d06d2f5aULL,0xff3adb2d91cd4803ULL
};

constexpr uint64_t CA_DIMER_TAB[45] = {
    0,0,0,0,0,0,0,0,0,0,
    0,0x7e4a36919c5032afULL,0x95b4b90696718a9fULL,0xf482881f5f3610bfULL,0x95b4b90696718a9fULL,0,0,0,0,0,
    0,0xe12f0e8e678e5d30ULL,0x9ff825331cf8a361ULL,0xf248b960f9159cecULL,0x9ff825331cf8a361ULL,0,0,0,0,0,
    0,0x7e4a36919c5032afULL,0x95b4b90696718a9fULL,0xf482881f5f3610bfULL,0x95b4b90696718a9fULL,0,0,0,0,0,
    0,0xe12f0e8e678e5d30ULL,0x00e055ee083cfcffULL,0xe12f0e8e678e5d30ULL,0x00e055ee083cfcffULL
};

constexpr uint64_t CT_DIMER_TAB[45] = {
    0,0,0,0,0,0,0,0,0,0,
    0,0x9a533a6a5e7b14e2ULL,0x9a533a6a5e7b14e2ULL,0x9a533a6a5e7b14e2ULL,0x897da34f6b464570ULL,0,0,0,0,0,
    0,0xeeaf42d6e10d9ac0ULL,0x049bab70128da11fULL,0x68c7d4adebfb5001ULL,0x049bab70128da11fULL,0,0,0,0,0,
    0,0x9a533a6a5e7b14e2ULL,0x9a533a6a5e7b14e2ULL,0x9a533a6a5e7b14e2ULL,0x897da34f6b464570ULL,0,0,0,0,0,
    0,0x0f1bfc76a0e3e700ULL,0x049bab70128da11fULL,0x282450c57fae339fULL,0x049bab70128da11fULL
};



// Generic dimer-based rolling hash
inline std::vector<uint64_t>
base_forward_bs_hash(const char* seq, bool has_second, unsigned k, const uint64_t* DIMER_TAB)
{
    uint64_t h0 = 0;
    uint64_t h1 = 0;

    std::cout << "[BASE_HASH] Computing forward hashes, k=" << k 
              << ", has_second=" << has_second << "\n";

    for (unsigned i = 0; i < k; i += 2) {
        h0 = srol(h0, 1);
        const char c1 = seq[i];
        const char c2 = seq[i + 1];
        const uint8_t a = CONVERT_TAB_SIMPLE[(unsigned char)c1];
        const uint8_t b = CONVERT_TAB_SIMPLE[(unsigned char)c2];
        const uint8_t loc = 10 * a + b;  // yields 11, 12, ..., 44
        h0 ^= DIMER_TAB[loc];

        std::cout << "[BASE_HASH] h0 loop " << i << " | dimer='" 
                  << c1 << c2 << "' loc=" << (unsigned)loc 
                  << " | h0=" << h0 << "\n";
    }

    if (!has_second)
        return {h0, 0};

    for (unsigned i = 1; i < k + 1; i += 2) {
        h1 = srol(h1, 1);
        const char c1 = seq[i];
        const char c2 = seq[i + 1];
        const uint8_t a = CONVERT_TAB_SIMPLE[(unsigned char)c1];
        const uint8_t b = CONVERT_TAB_SIMPLE[(unsigned char)c2];
        const uint8_t loc = 10 * a + b;
        h1 ^= DIMER_TAB[loc];

        std::cout << "[BASE_HASH] h1 loop " << i << " | dimer='" 
                  << c1 << c2 << "' loc=" << (unsigned)loc 
                  << " | h1=" << h1 << "\n";
    }

    return {h0, h1};
}



// ===== CC_group1 =====
static const uint64_t CC_group1_33R[33] = {
    0xc934fdc1,     0x19269fb82,     0x124d3f705,     0x49a7ee0b,     0x934fdc16,     0x1269fb82c,     0x4d3f7059,     0x9a7ee0b2,     0x134fdc164,     0x69fb82c9,
    0xd3f70592,     0x1a7ee0b24,     0x14fdc1649,     0x9fb82c93,     0x13f705926,     0x7ee0b24d,     0xfdc1649a,     0x1fb82c934,     0x1f7059269,     0x1ee0b24d3,
    0x1dc1649a7,     0x1b82c934f,     0x17059269f,     0xe0b24d3f,     0x1c1649a7e,     0x182c934fd,     0x1059269fb,     0xb24d3f7,     0x1649a7ee,     0x2c934fdc,
    0x59269fb8,     0xb24d3f70,     0x1649a7ee0 
};

static const uint64_t CC_group1_31L[31] = {
    0x77c24a3600000000,     0xef84946c00000000,     0xdf0928da00000000,     0xbe1251b600000000,     0x7c24a36e00000000,     0xf84946dc00000000,     0xf0928dba00000000,     0xe1251b7600000000,     0xc24a36ee00000000,     0x84946dde00000000,
    0x928dbbe00000000,     0x1251b77c00000000,     0x24a36ef800000000,     0x4946ddf000000000,     0x928dbbe000000000,     0x251b77c200000000,     0x4a36ef8400000000,     0x946ddf0800000000,     0x28dbbe1200000000,     0x51b77c2400000000,
    0xa36ef84800000000,     0x46ddf09200000000,     0x8dbbe12400000000,     0x1b77c24a00000000,     0x36ef849400000000,     0x6ddf092800000000,     0xdbbe125000000000,     0xb77c24a200000000,     0x6ef8494600000000,     0xddf0928c00000000,
    0xbbe1251a00000000 
};

// ===== CC_group2 =====
static const uint64_t CC_group2_33R[33] = {
    0x1a6ea6e02,     0x14dd4dc05,     0x9ba9b80b,     0x137537016,     0x6ea6e02d,     0xdd4dc05a,     0x1ba9b80b4,     0x175370169,     0xea6e02d3,     0x1d4dc05a6,
    0x1a9b80b4d,     0x15370169b,     0xa6e02d37,     0x14dc05a6e,     0x9b80b4dd,     0x1370169ba,     0x6e02d375,     0xdc05a6ea,     0x1b80b4dd4,     0x170169ba9,
    0xe02d3753,     0x1c05a6ea6,     0x180b4dd4d,     0x10169ba9b,     0x2d37537,     0x5a6ea6e,     0xb4dd4dc,     0x169ba9b8,     0x2d375370,     0x5a6ea6e0,
    0xb4dd4dc0,     0x169ba9b80,     0xd3753701 
};

static const uint64_t CC_group2_31L[31] = {
    0x1bc5d5aa00000000,     0x378bab5400000000,     0x6f1756a800000000,     0xde2ead5000000000,     0xbc5d5aa200000000,     0x78bab54600000000,     0xf1756a8c00000000,     0xe2ead51a00000000,     0xc5d5aa3600000000,     0x8bab546e00000000,
    0x1756a8de00000000,     0x2ead51bc00000000,     0x5d5aa37800000000,     0xbab546f000000000,     0x756a8de200000000,     0xead51bc400000000,     0xd5aa378a00000000,     0xab546f1600000000,     0x56a8de2e00000000,     0xad51bc5c00000000,
    0x5aa378ba00000000,     0xb546f17400000000,     0x6a8de2ea00000000,     0xd51bc5d400000000,     0xaa378baa00000000,     0x546f175600000000,     0xa8de2eac00000000,     0x51bc5d5a00000000,     0xa378bab400000000,     0x46f1756a00000000,
    0x8de2ead400000000 
};

// ===== CC_group3 =====
static const uint64_t CC_group3_33R[33] = {
    0xa74bce00,     0x14e979c00,     0x9d2f3801,     0x13a5e7002,     0x74bce005,     0xe979c00a,     0x1d2f38014,     0x1a5e70029,     0x14bce0053,     0x979c00a7,
    0x12f38014e,     0x5e70029d,     0xbce0053a,     0x179c00a74,     0xf38014e9,     0x1e70029d2,     0x1ce0053a5,     0x19c00a74b,     0x138014e97,     0x70029d2f,
    0xe0053a5e,     0x1c00a74bc,     0x18014e979,     0x10029d2f3,     0x53a5e7,     0xa74bce,     0x14e979c,     0x29d2f38,     0x53a5e70,     0xa74bce0,
    0x14e979c0,     0x29d2f380,     0x53a5e700 
};

static const uint64_t CC_group3_31L[31] = {
    0x44fec7e400000000,     0x89fd8fc800000000,     0x13fb1f9200000000,     0x27f63f2400000000,     0x4fec7e4800000000,     0x9fd8fc9000000000,     0x3fb1f92200000000,     0x7f63f24400000000,     0xfec7e48800000000,     0xfd8fc91200000000,
    0xfb1f922600000000,     0xf63f244e00000000,     0xec7e489e00000000,     0xd8fc913e00000000,     0xb1f9227e00000000,     0x63f244fe00000000,     0xc7e489fc00000000,     0x8fc913fa00000000,     0x1f9227f600000000,     0x3f244fec00000000,
    0x7e489fd800000000,     0xfc913fb000000000,     0xf9227f6200000000,     0xf244fec600000000,     0xe489fd8e00000000,     0xc913fb1e00000000,     0x9227f63e00000000,     0x244fec7e00000000,     0x489fd8fc00000000,     0x913fb1f800000000,
    0x227f63f200000000 
};

// ===== CC_group4 =====
static const uint64_t CC_group4_33R[33] = {
    0xb06b5ed9,     0x160d6bdb2,     0xc1ad7b65,     0x1835af6ca,     0x106b5ed95,     0xd6bdb2b,     0x1ad7b656,     0x35af6cac,     0x6b5ed958,     0xd6bdb2b0,
    0x1ad7b6560,     0x15af6cac1,     0xb5ed9583,     0x16bdb2b06,     0xd7b6560d,     0x1af6cac1a,     0x15ed95835,     0xbdb2b06b,     0x17b6560d6,     0xf6cac1ad,
    0x1ed95835a,     0x1db2b06b5,     0x1b6560d6b,     0x16cac1ad7,     0xd95835af,     0x1b2b06b5e,     0x16560d6bd,     0xcac1ad7b,     0x195835af6,     0x12b06b5ed,
    0x560d6bdb,     0xac1ad7b6,     0x15835af6c 
};

static const uint64_t CC_group4_31L[31] = {
    0x8f1531400000000,     0x11e2a62800000000,     0x23c54c5000000000,     0x478a98a000000000,     0x8f15314000000000,     0x1e2a628200000000,     0x3c54c50400000000,     0x78a98a0800000000,     0xf153141000000000,     0xe2a6282200000000,
    0xc54c504600000000,     0x8a98a08e00000000,     0x1531411e00000000,     0x2a62823c00000000,     0x54c5047800000000,     0xa98a08f000000000,     0x531411e200000000,     0xa62823c400000000,     0x4c50478a00000000,     0x98a08f1400000000,
    0x31411e2a00000000,     0x62823c5400000000,     0xc50478a800000000,     0x8a08f15200000000,     0x1411e2a600000000,     0x2823c54c00000000,     0x50478a9800000000,     0xa08f153000000000,     0x411e2a6200000000,     0x823c54c400000000,
    0x478a98a00000000 
};

// ===== CG_group1 =====
static const uint64_t CG_group1_33R[33] = {
    0x20caa27f,     0x419544fe,     0x832a89fc,     0x1065513f8,     0xcaa27f1,     0x19544fe2,     0x32a89fc4,     0x65513f88,     0xcaa27f10,     0x19544fe20,
    0x12a89fc41,     0x5513f883,     0xaa27f106,     0x1544fe20c,     0xa89fc419,     0x1513f8832,     0xa27f1065,     0x144fe20ca,     0x89fc4195,     0x113f8832a,
    0x27f10655,     0x4fe20caa,     0x9fc41954,     0x13f8832a8,     0x7f106551,     0xfe20caa2,     0x1fc419544,     0x1f8832a89,     0x1f1065513,     0x1e20caa27,
    0x1c419544f,     0x18832a89f,     0x11065513f 
};

static const uint64_t CG_group1_31L[31] = {
    0x54f8849000000000,     0xa9f1092000000000,     0x53e2124200000000,     0xa7c4248400000000,     0x4f88490a00000000,     0x9f10921400000000,     0x3e21242a00000000,     0x7c42485400000000,     0xf88490a800000000,     0xf109215200000000,
    0xe21242a600000000,     0xc424854e00000000,     0x88490a9e00000000,     0x1092153e00000000,     0x21242a7c00000000,     0x424854f800000000,     0x8490a9f000000000,     0x92153e200000000,     0x1242a7c400000000,     0x24854f8800000000,
    0x490a9f1000000000,     0x92153e2000000000,     0x242a7c4200000000,     0x4854f88400000000,     0x90a9f10800000000,     0x2153e21200000000,     0x42a7c42400000000,     0x854f884800000000,     0xa9f109200000000,     0x153e212400000000,
    0x2a7c424800000000 
};

// ===== CG_group2 =====
static const uint64_t CG_group2_33R[33] = {
    0x1a48a5d70,     0x14914bae1,     0x922975c3,     0x12452eb86,     0x48a5d70d,     0x914bae1a,     0x122975c34,     0x452eb869,     0x8a5d70d2,     0x114bae1a4,
    0x2975c349,     0x52eb8692,     0xa5d70d24,     0x14bae1a48,     0x975c3491,     0x12eb86922,     0x5d70d245,     0xbae1a48a,     0x175c34914,     0xeb869229,
    0x1d70d2452,     0x1ae1a48a5,     0x15c34914b,     0xb8692297,     0x170d2452e,     0xe1a48a5d,     0x1c34914ba,     0x186922975,     0x10d2452eb,     0x1a48a5d7,
    0x34914bae,     0x6922975c,     0xd2452eb8 
};

static const uint64_t CG_group2_31L[31] = {
    0xab9766c800000000,     0x572ecd9200000000,     0xae5d9b2400000000,     0x5cbb364a00000000,     0xb9766c9400000000,     0x72ecd92a00000000,     0xe5d9b25400000000,     0xcbb364aa00000000,     0x9766c95600000000,     0x2ecd92ae00000000,
    0x5d9b255c00000000,     0xbb364ab800000000,     0x766c957200000000,     0xecd92ae400000000,     0xd9b255ca00000000,     0xb364ab9600000000,     0x66c9572e00000000,     0xcd92ae5c00000000,     0x9b255cba00000000,     0x364ab97600000000,
    0x6c9572ec00000000,     0xd92ae5d800000000,     0xb255cbb200000000,     0x64ab976600000000,     0xc9572ecc00000000,     0x92ae5d9a00000000,     0x255cbb3600000000,     0x4ab9766c00000000,     0x9572ecd800000000,     0x2ae5d9b200000000,
    0x55cbb36400000000 
};

// ===== CG_group3 =====
static const uint64_t CG_group3_33R[33] = {
    0x3c53b1bc,     0x78a76378,     0xf14ec6f0,     0x1e29d8de0,     0x1c53b1bc1,     0x18a763783,     0x114ec6f07,     0x29d8de0f,     0x53b1bc1e,     0xa763783c,
    0x14ec6f078,     0x9d8de0f1,     0x13b1bc1e2,     0x763783c5,     0xec6f078a,     0x1d8de0f14,     0x1b1bc1e29,     0x163783c53,     0xc6f078a7,     0x18de0f14e,
    0x11bc1e29d,     0x3783c53b,     0x6f078a76,     0xde0f14ec,     0x1bc1e29d8,     0x1783c53b1,     0xf078a763,     0x1e0f14ec6,     0x1c1e29d8d,     0x183c53b1b,
    0x1078a7637,     0xf14ec6f,     0x1e29d8de 
};

static const uint64_t CG_group3_31L[31] = {
    0x7f01ee3000000000,     0xfe03dc6000000000,     0xfc07b8c200000000,     0xf80f718600000000,     0xf01ee30e00000000,     0xe03dc61e00000000,     0xc07b8c3e00000000,     0x80f7187e00000000,     0x1ee30fe00000000,     0x3dc61fc00000000,
    0x7b8c3f800000000,     0xf7187f000000000,     0x1ee30fe000000000,     0x3dc61fc000000000,     0x7b8c3f8000000000,     0xf7187f0000000000,     0xee30fe0200000000,     0xdc61fc0600000000,     0xb8c3f80e00000000,     0x7187f01e00000000,
    0xe30fe03c00000000,     0xc61fc07a00000000,     0x8c3f80f600000000,     0x187f01ee00000000,     0x30fe03dc00000000,     0x61fc07b800000000,     0xc3f80f7000000000,     0x87f01ee200000000,     0xfe03dc600000000,     0x1fc07b8c00000000,
    0x3f80f71800000000 
};

// ===== CG_group4 =====
static const uint64_t CG_group4_33R[33] = {
    0x1d06d2f5a,     0x1a0da5eb5,     0x141b4bd6b,     0x83697ad7,     0x106d2f5ae,     0xda5eb5d,     0x1b4bd6ba,     0x3697ad74,     0x6d2f5ae8,     0xda5eb5d0,
    0x1b4bd6ba0,     0x1697ad741,     0xd2f5ae83,     0x1a5eb5d06,     0x14bd6ba0d,     0x97ad741b,     0x12f5ae836,     0x5eb5d06d,     0xbd6ba0da,     0x17ad741b4,
    0xf5ae8369,     0x1eb5d06d2,     0x1d6ba0da5,     0x1ad741b4b,     0x15ae83697,     0xb5d06d2f,     0x16ba0da5e,     0xd741b4bd,     0x1ae83697a,     0x15d06d2f5,
    0xba0da5eb,     0x1741b4bd6,     0xe83697ad 
};

static const uint64_t CG_group4_31L[31] = {
    0xd22f789000000000,     0xa45ef12200000000,     0x48bde24600000000,     0x917bc48c00000000,     0x22f7891a00000000,     0x45ef123400000000,     0x8bde246800000000,     0x17bc48d200000000,     0x2f7891a400000000,     0x5ef1234800000000,
    0xbde2469000000000,     0x7bc48d2200000000,     0xf7891a4400000000,     0xef12348a00000000,     0xde24691600000000,     0xbc48d22e00000000,     0x7891a45e00000000,     0xf12348bc00000000,     0xe246917a00000000,     0xc48d22f600000000,
    0x891a45ee00000000,     0x12348bde00000000,     0x246917bc00000000,     0x48d22f7800000000,     0x91a45ef000000000,     0x2348bde200000000,     0x46917bc400000000,     0x8d22f78800000000,     0x1a45ef1200000000,     0x348bde2400000000,
    0x6917bc4800000000 
};

// ===== CG_group5 =====
static const uint64_t CG_group5_33R[33] = {
    0x1bfb10000,     0x17f620001,     0xfec40003,     0x1fd880006,     0x1fb10000d,     0x1f620001b,     0x1ec400037,     0x1d880006f,     0x1b10000df,     0x1620001bf,
    0xc400037f,     0x1880006fe,     0x110000dfd,     0x20001bfb,     0x400037f6,     0x80006fec,     0x10000dfd8,     0x1bfb1,     0x37f62,     0x6fec4,
    0xdfd88,     0x1bfb10,     0x37f620,     0x6fec40,     0xdfd880,     0x1bfb100,     0x37f6200,     0x6fec400,     0xdfd8800,     0x1bfb1000,
    0x37f62000,     0x6fec4000,     0xdfd88000 
};

static const uint64_t CG_group5_31L[31] = {
    0xf1bd2f3a00000000,     0xe37a5e7600000000,     0xc6f4bcee00000000,     0x8de979de00000000,     0x1bd2f3be00000000,     0x37a5e77c00000000,     0x6f4bcef800000000,     0xde979df000000000,     0xbd2f3be200000000,     0x7a5e77c600000000,
    0xf4bcef8c00000000,     0xe979df1a00000000,     0xd2f3be3600000000,     0xa5e77c6e00000000,     0x4bcef8de00000000,     0x979df1bc00000000,     0x2f3be37a00000000,     0x5e77c6f400000000,     0xbcef8de800000000,     0x79df1bd200000000,
    0xf3be37a400000000,     0xe77c6f4a00000000,     0xcef8de9600000000,     0x9df1bd2e00000000,     0x3be37a5e00000000,     0x77c6f4bc00000000,     0xef8de97800000000,     0xdf1bd2f200000000,     0xbe37a5e600000000,     0x7c6f4bce00000000,
    0xf8de979c00000000 
};

// ===== CG_group6 =====
static const uint64_t CG_group6_33R[33] = {
    0x78d4d36f,     0xf1a9a6de,     0x1e3534dbc,     0x1c6a69b79,     0x18d4d36f3,     0x11a9a6de7,     0x3534dbcf,     0x6a69b79e,     0xd4d36f3c,     0x1a9a6de78,
    0x1534dbcf1,     0xa69b79e3,     0x14d36f3c6,     0x9a6de78d,     0x134dbcf1a,     0x69b79e35,     0xd36f3c6a,     0x1a6de78d4,     0x14dbcf1a9,     0x9b79e353,
    0x136f3c6a6,     0x6de78d4d,     0xdbcf1a9a,     0x1b79e3534,     0x16f3c6a69,     0xde78d4d3,     0x1bcf1a9a6,     0x179e3534d,     0xf3c6a69b,     0x1e78d4d36,
    0x1cf1a9a6d,     0x19e3534db,     0x13c6a69b7 
};

static const uint64_t CG_group6_31L[31] = {
    0x414ce1fc00000000,     0x8299c3f800000000,     0x53387f200000000,     0xa670fe400000000,     0x14ce1fc800000000,     0x299c3f9000000000,     0x53387f2000000000,     0xa670fe4000000000,     0x4ce1fc8200000000,     0x99c3f90400000000,
    0x3387f20a00000000,     0x670fe41400000000,     0xce1fc82800000000,     0x9c3f905200000000,     0x387f20a600000000,     0x70fe414c00000000,     0xe1fc829800000000,     0xc3f9053200000000,     0x87f20a6600000000,     0xfe414ce00000000,
    0x1fc8299c00000000,     0x3f90533800000000,     0x7f20a67000000000,     0xfe414ce000000000,     0xfc8299c200000000,     0xf905338600000000,     0xf20a670e00000000,     0xe414ce1e00000000,     0xc8299c3e00000000,     0x9053387e00000000,
    0x20a670fe00000000 
};

// ===== CG_group7 =====
static const uint64_t CG_group7_33R[33] = {
    0x191cd4803,     0x1239a9007,     0x4735200f,     0x8e6a401e,     0x11cd4803c,     0x39a90079,     0x735200f2,     0xe6a401e4,     0x1cd4803c8,     0x19a900791,
    0x135200f23,     0x6a401e47,     0xd4803c8e,     0x1a900791c,     0x15200f239,     0xa401e473,     0x14803c8e6,     0x900791cd,     0x1200f239a,     0x401e4735,
    0x803c8e6a,     0x100791cd4,     0xf239a9,     0x1e47352,     0x3c8e6a4,     0x791cd48,     0xf239a90,     0x1e473520,     0x3c8e6a40,     0x791cd480,
    0xf239a900,     0x1e4735200,     0x1c8e6a401 
};

static const uint64_t CG_group7_31L[31] = {
    0xff3adb2c00000000,     0xfe75b65a00000000,     0xfceb6cb600000000,     0xf9d6d96e00000000,     0xf3adb2de00000000,     0xe75b65be00000000,     0xceb6cb7e00000000,     0x9d6d96fe00000000,     0x3adb2dfe00000000,     0x75b65bfc00000000,
    0xeb6cb7f800000000,     0xd6d96ff200000000,     0xadb2dfe600000000,     0x5b65bfce00000000,     0xb6cb7f9c00000000,     0x6d96ff3a00000000,     0xdb2dfe7400000000,     0xb65bfcea00000000,     0x6cb7f9d600000000,     0xd96ff3ac00000000,
    0xb2dfe75a00000000,     0x65bfceb600000000,     0xcb7f9d6c00000000,     0x96ff3ada00000000,     0x2dfe75b600000000,     0x5bfceb6c00000000,     0xb7f9d6d800000000,     0x6ff3adb200000000,     0xdfe75b6400000000,     0xbfceb6ca00000000,
    0x7f9d6d9600000000 
};

// ===== CT_group1 =====
static const uint64_t CT_group1_33R[33] = {
    0x128da11f,     0x251b423e,     0x4a36847c,     0x946d08f8,     0x128da11f0,     0x51b423e1,     0xa36847c2,     0x146d08f84,     0x8da11f09,     0x11b423e12,
    0x36847c25,     0x6d08f84a,     0xda11f094,     0x1b423e128,     0x16847c251,     0xd08f84a3,     0x1a11f0946,     0x1423e128d,     0x847c251b,     0x108f84a36,
    0x11f0946d,     0x23e128da,     0x47c251b4,     0x8f84a368,     0x11f0946d0,     0x3e128da1,     0x7c251b42,     0xf84a3684,     0x1f0946d08,     0x1e128da11,
    0x1c251b423,     0x184a36847,     0x10946d08f 
};

static const uint64_t CT_group1_31L[31] = {
    0x49bab7000000000,     0x93756e000000000,     0x126eadc000000000,     0x24dd5b8000000000,     0x49bab70000000000,     0x93756e0000000000,     0x26eadc0200000000,     0x4dd5b80400000000,     0x9bab700800000000,     0x3756e01200000000,
    0x6eadc02400000000,     0xdd5b804800000000,     0xbab7009200000000,     0x756e012600000000,     0xeadc024c00000000,     0xd5b8049a00000000,     0xab70093600000000,     0x56e0126e00000000,     0xadc024dc00000000,     0x5b8049ba00000000,
    0xb700937400000000,     0x6e0126ea00000000,     0xdc024dd400000000,     0xb8049baa00000000,     0x7009375600000000,     0xe0126eac00000000,     0xc024dd5a00000000,     0x8049bab600000000,     0x93756e00000000,     0x126eadc00000000,
    0x24dd5b800000000 
};

// ===== CT_group2 =====
static const uint64_t CT_group2_33R[33] = {
    0x5e7b14e2,     0xbcf629c4,     0x179ec5388,     0xf3d8a711,     0x1e7b14e22,     0x1cf629c45,     0x19ec5388b,     0x13d8a7117,     0x7b14e22f,     0xf629c45e,
    0x1ec5388bc,     0x1d8a71179,     0x1b14e22f3,     0x1629c45e7,     0xc5388bcf,     0x18a71179e,     0x114e22f3d,     0x29c45e7b,     0x5388bcf6,     0xa71179ec,
    0x14e22f3d8,     0x9c45e7b1,     0x1388bcf62,     0x71179ec5,     0xe22f3d8a,     0x1c45e7b14,     0x188bcf629,     0x11179ec53,     0x22f3d8a7,     0x45e7b14e,
    0x8bcf629c,     0x1179ec538,     0x2f3d8a71 
};

static const uint64_t CT_group2_31L[31] = {
    0x9a533a6a00000000,     0x34a674d600000000,     0x694ce9ac00000000,     0xd299d35800000000,     0xa533a6b200000000,     0x4a674d6600000000,     0x94ce9acc00000000,     0x299d359a00000000,     0x533a6b3400000000,     0xa674d66800000000,
    0x4ce9acd200000000,     0x99d359a400000000,     0x33a6b34a00000000,     0x674d669400000000,     0xce9acd2800000000,     0x9d359a5200000000,     0x3a6b34a600000000,     0x74d6694c00000000,     0xe9acd29800000000,     0xd359a53200000000,
    0xa6b34a6600000000,     0x4d6694ce00000000,     0x9acd299c00000000,     0x359a533a00000000,     0x6b34a67400000000,     0xd6694ce800000000,     0xacd299d200000000,     0x59a533a600000000,     0xb34a674c00000000,     0x6694ce9a00000000,
    0xcd299d3400000000 
};

// ===== CT_group3 =====
static const uint64_t CT_group3_33R[33] = {
    0xe10d9ac0,     0x1c21b3580,     0x184366b01,     0x1086cd603,     0x10d9ac07,     0x21b3580e,     0x4366b01c,     0x86cd6038,     0x10d9ac070,     0x1b3580e1,
    0x366b01c2,     0x6cd60384,     0xd9ac0708,     0x1b3580e10,     0x166b01c21,     0xcd603843,     0x19ac07086,     0x13580e10d,     0x6b01c21b,     0xd6038436,
    0x1ac07086c,     0x1580e10d9,     0xb01c21b3,     0x160384366,     0xc07086cd,     0x180e10d9a,     0x101c21b35,     0x384366b,     0x7086cd6,     0xe10d9ac,
    0x1c21b358,     0x384366b0,     0x7086cd60 
};

static const uint64_t CT_group3_31L[31] = {
    0xeeaf42d600000000,     0xdd5e85ae00000000,     0xbabd0b5e00000000,     0x757a16be00000000,     0xeaf42d7c00000000,     0xd5e85afa00000000,     0xabd0b5f600000000,     0x57a16bee00000000,     0xaf42d7dc00000000,     0x5e85afba00000000,
    0xbd0b5f7400000000,     0x7a16beea00000000,     0xf42d7dd400000000,     0xe85afbaa00000000,     0xd0b5f75600000000,     0xa16beeae00000000,     0x42d7dd5e00000000,     0x85afbabc00000000,     0xb5f757a00000000,     0x16beeaf400000000,
    0x2d7dd5e800000000,     0x5afbabd000000000,     0xb5f757a000000000,     0x6beeaf4200000000,     0xd7dd5e8400000000,     0xafbabd0a00000000,     0x5f757a1600000000,     0xbeeaf42c00000000,     0x7dd5e85a00000000,     0xfbabd0b400000000,
    0xf757a16a00000000 
};

// ===== CT_group4 =====
static const uint64_t CT_group4_33R[33] = {
    0x1ebfb5001,     0x1d7f6a003,     0x1afed4007,     0x15fda800f,     0xbfb5001f,     0x17f6a003e,     0xfed4007d,     0x1fda800fa,     0x1fb5001f5,     0x1f6a003eb,
    0x1ed4007d7,     0x1da800faf,     0x1b5001f5f,     0x16a003ebf,     0xd4007d7f,     0x1a800fafe,     0x15001f5fd,     0xa003ebfb,     0x14007d7f6,     0x800fafed,
    0x1001f5fda,     0x3ebfb5,     0x7d7f6a,     0xfafed4,     0x1f5fda8,     0x3ebfb50,     0x7d7f6a0,     0xfafed40,     0x1f5fda80,     0x3ebfb500,
    0x7d7f6a00,     0xfafed400,     0x1f5fda800 
};

static const uint64_t CT_group4_31L[31] = {
    0x68c7d4ac00000000,     0xd18fa95800000000,     0xa31f52b200000000,     0x463ea56600000000,     0x8c7d4acc00000000,     0x18fa959a00000000,     0x31f52b3400000000,     0x63ea566800000000,     0xc7d4acd000000000,     0x8fa959a200000000,
    0x1f52b34600000000,     0x3ea5668c00000000,     0x7d4acd1800000000,     0xfa959a3000000000,     0xf52b346200000000,     0xea5668c600000000,     0xd4acd18e00000000,     0xa959a31e00000000,     0x52b3463e00000000,     0xa5668c7c00000000,
    0x4acd18fa00000000,     0x959a31f400000000,     0x2b3463ea00000000,     0x5668c7d400000000,     0xacd18fa800000000,     0x59a31f5200000000,     0xb3463ea400000000,     0x668c7d4a00000000,     0xcd18fa9400000000,     0x9a31f52a00000000,
    0x3463ea5600000000 
};

// ===== CT_group5 =====
static const uint64_t CT_group5_33R[33] = {
    0xa0e3e700,     0x141c7ce00,     0x838f9c01,     0x1071f3802,     0xe3e7005,     0x1c7ce00a,     0x38f9c014,     0x71f38028,     0xe3e70050,     0x1c7ce00a0,
    0x18f9c0141,     0x11f380283,     0x3e700507,     0x7ce00a0e,     0xf9c0141c,     0x1f3802838,     0x1e7005071,     0x1ce00a0e3,     0x19c0141c7,     0x13802838f,
    0x7005071f,     0xe00a0e3e,     0x1c0141c7c,     0x1802838f9,     0x1005071f3,     0xa0e3e7,     0x141c7ce,     0x2838f9c,     0x5071f38,     0xa0e3e70,
    0x141c7ce0,     0x2838f9c0,     0x5071f380 
};

static const uint64_t CT_group5_31L[31] = {
    0xf1bfc7600000000,     0x1e37f8ec00000000,     0x3c6ff1d800000000,     0x78dfe3b000000000,     0xf1bfc76000000000,     0xe37f8ec200000000,     0xc6ff1d8600000000,     0x8dfe3b0e00000000,     0x1bfc761e00000000,     0x37f8ec3c00000000,
    0x6ff1d87800000000,     0xdfe3b0f000000000,     0xbfc761e200000000,     0x7f8ec3c600000000,     0xff1d878c00000000,     0xfe3b0f1a00000000,     0xfc761e3600000000,     0xf8ec3c6e00000000,     0xf1d878de00000000,     0xe3b0f1be00000000,
    0xc761e37e00000000,     0x8ec3c6fe00000000,     0x1d878dfe00000000,     0x3b0f1bfc00000000,     0x761e37f800000000,     0xec3c6ff000000000,     0xd878dfe200000000,     0xb0f1bfc600000000,     0x61e37f8e00000000,     0xc3c6ff1c00000000,
    0x878dfe3a00000000 
};

// ===== CT_group6 =====
static const uint64_t CT_group6_33R[33] = {
    0x17fae339f,     0xff5c673f,     0x1feb8ce7e,     0x1fd719cfd,     0x1fae339fb,     0x1f5c673f7,     0x1eb8ce7ef,     0x1d719cfdf,     0x1ae339fbf,     0x15c673f7f,
    0xb8ce7eff,     0x1719cfdfe,     0xe339fbfd,     0x1c673f7fa,     0x18ce7eff5,     0x119cfdfeb,     0x339fbfd7,     0x673f7fae,     0xce7eff5c,     0x19cfdfeb8,
    0x139fbfd71,     0x73f7fae3,     0xe7eff5c6,     0x1cfdfeb8c,     0x19fbfd719,     0x13f7fae33,     0x7eff5c67,     0xfdfeb8ce,     0x1fbfd719c,     0x1f7fae339,
    0x1eff5c673,     0x1dfeb8ce7,     0x1bfd719cf 
};

static const uint64_t CT_group6_31L[31] = {
    0x282450c400000000,     0x5048a18800000000,     0xa091431000000000,     0x4122862200000000,     0x82450c4400000000,     0x48a188a00000000,     0x914311400000000,     0x1228622800000000,     0x2450c45000000000,     0x48a188a000000000,
    0x9143114000000000,     0x2286228200000000,     0x450c450400000000,     0x8a188a0800000000,     0x1431141200000000,     0x2862282400000000,     0x50c4504800000000,     0xa188a09000000000,     0x4311412200000000,     0x8622824400000000,
    0xc45048a00000000,     0x188a091400000000,     0x3114122800000000,     0x6228245000000000,     0xc45048a000000000,     0x88a0914200000000,     0x1141228600000000,     0x2282450c00000000,     0x45048a1800000000,     0x8a09143000000000,
    0x1412286200000000 
};

// ===== CT_group7 =====
static const uint64_t CT_group7_33R[33] = {
    0x16b464570,     0xd68c8ae1,     0x1ad1915c2,     0x15a322b85,     0xb464570b,     0x168c8ae16,     0xd1915c2d,     0x1a322b85a,     0x1464570b5,     0x8c8ae16b,
    0x11915c2d6,     0x322b85ad,     0x64570b5a,     0xc8ae16b4,     0x1915c2d68,     0x122b85ad1,     0x4570b5a3,     0x8ae16b46,     0x115c2d68c,     0x2b85ad19,
    0x570b5a32,     0xae16b464,     0x15c2d68c8,     0xb85ad191,     0x170b5a322,     0xe16b4645,     0x1c2d68c8a,     0x185ad1915,     0x10b5a322b,     0x16b46457,
    0x2d68c8ae,     0x5ad1915c,     0xb5a322b8 
};

static const uint64_t CT_group7_31L[31] = {
    0x897da34e00000000,     0x12fb469e00000000,     0x25f68d3c00000000,     0x4bed1a7800000000,     0x97da34f000000000,     0x2fb469e200000000,     0x5f68d3c400000000,     0xbed1a78800000000,     0x7da34f1200000000,     0xfb469e2400000000,
    0xf68d3c4a00000000,     0xed1a789600000000,     0xda34f12e00000000,     0xb469e25e00000000,     0x68d3c4be00000000,     0xd1a7897c00000000,     0xa34f12fa00000000,     0x469e25f600000000,     0x8d3c4bec00000000,     0x1a7897da00000000,
    0x34f12fb400000000,     0x69e25f6800000000,     0xd3c4bed000000000,     0xa7897da200000000,     0x4f12fb4600000000,     0x9e25f68c00000000,     0x3c4bed1a00000000,     0x7897da3400000000,     0xf12fb46800000000,     0xe25f68d200000000,
    0xc4bed1a600000000 
};

// ===== CA_group1 =====
static const uint64_t CA_group1_33R[33] = {
    0x678e5d30,     0xcf1cba60,     0x19e3974c0,     0x13c72e981,     0x78e5d303,     0xf1cba606,     0x1e3974c0c,     0x1c72e9819,     0x18e5d3033,     0x11cba6067,
    0x3974c0cf,     0x72e9819e,     0xe5d3033c,     0x1cba60678,     0x1974c0cf1,     0x12e9819e3,     0x5d3033c7,     0xba60678e,     0x174c0cf1c,     0xe9819e39,
    0x1d3033c72,     0x1a60678e5,     0x14c0cf1cb,     0x9819e397,     0x13033c72e,     0x60678e5d,     0xc0cf1cba,     0x1819e3974,     0x1033c72e9,     0x678e5d3,
    0xcf1cba6,     0x19e3974c,     0x33c72e98 
};

static const uint64_t CA_group1_31L[31] = {
    0xe12f0e8e00000000,     0xc25e1d1e00000000,     0x84bc3a3e00000000,     0x978747e00000000,     0x12f0e8fc00000000,     0x25e1d1f800000000,     0x4bc3a3f000000000,     0x978747e000000000,     0x2f0e8fc200000000,     0x5e1d1f8400000000,
    0xbc3a3f0800000000,     0x78747e1200000000,     0xf0e8fc2400000000,     0xe1d1f84a00000000,     0xc3a3f09600000000,     0x8747e12e00000000,     0xe8fc25e00000000,     0x1d1f84bc00000000,     0x3a3f097800000000,     0x747e12f000000000,
    0xe8fc25e000000000,     0xd1f84bc200000000,     0xa3f0978600000000,     0x47e12f0e00000000,     0x8fc25e1c00000000,     0x1f84bc3a00000000,     0x3f09787400000000,     0x7e12f0e800000000,     0xfc25e1d000000000,     0xf84bc3a200000000,
    0xf097874600000000 
};

// ===== CA_group2 =====
static const uint64_t CA_group2_33R[33] = {
    0x96718a9f,     0x12ce3153e,     0x59c62a7d,     0xb38c54fa,     0x16718a9f4,     0xce3153e9,     0x19c62a7d2,     0x138c54fa5,     0x718a9f4b,     0xe3153e96,
    0x1c62a7d2c,     0x18c54fa59,     0x118a9f4b3,     0x3153e967,     0x62a7d2ce,     0xc54fa59c,     0x18a9f4b38,     0x1153e9671,     0x2a7d2ce3,     0x54fa59c6,
    0xa9f4b38c,     0x153e96718,     0xa7d2ce31,     0x14fa59c62,     0x9f4b38c5,     0x13e96718a,     0x7d2ce315,     0xfa59c62a,     0x1f4b38c54,     0x1e96718a9,
    0x1d2ce3153,     0x1a59c62a7,     0x14b38c54f 
};

static const uint64_t CA_group2_31L[31] = {
    0x95b4b90600000000,     0x2b69720e00000000,     0x56d2e41c00000000,     0xada5c83800000000,     0x5b4b907200000000,     0xb69720e400000000,     0x6d2e41ca00000000,     0xda5c839400000000,     0xb4b9072a00000000,     0x69720e5600000000,
    0xd2e41cac00000000,     0xa5c8395a00000000,     0x4b9072b600000000,     0x9720e56c00000000,     0x2e41cada00000000,     0x5c8395b400000000,     0xb9072b6800000000,     0x720e56d200000000,     0xe41cada400000000,     0xc8395b4a00000000,
    0x9072b69600000000,     0x20e56d2e00000000,     0x41cada5c00000000,     0x8395b4b800000000,     0x72b697200000000,     0xe56d2e400000000,     0x1cada5c800000000,     0x395b4b9000000000,     0x72b6972000000000,     0xe56d2e4000000000,
    0xcada5c8200000000 
};

// ===== CA_group3 =====
static const uint64_t CA_group3_33R[33] = {
    0x15f3610bf,     0xbe6c217f,     0x17cd842fe,     0xf9b085fd,     0x1f3610bfa,     0x1e6c217f5,     0x1cd842feb,     0x19b085fd7,     0x13610bfaf,     0x6c217f5f,
    0xd842febe,     0x1b085fd7c,     0x1610bfaf9,     0xc217f5f3,     0x1842febe6,     0x1085fd7cd,     0x10bfaf9b,     0x217f5f36,     0x42febe6c,     0x85fd7cd8,
    0x10bfaf9b0,     0x17f5f361,     0x2febe6c2,     0x5fd7cd84,     0xbfaf9b08,     0x17f5f3610,     0xfebe6c21,     0x1fd7cd842,     0x1faf9b085,     0x1f5f3610b,
    0x1ebe6c217,     0x1d7cd842f,     0x1af9b085f 
};

static const uint64_t CA_group3_31L[31] = {
    0xf482881e00000000,     0xe905103e00000000,     0xd20a207e00000000,     0xa41440fe00000000,     0x482881fe00000000,     0x905103fc00000000,     0x20a207fa00000000,     0x41440ff400000000,     0x82881fe800000000,     0x5103fd200000000,
    0xa207fa400000000,     0x1440ff4800000000,     0x2881fe9000000000,     0x5103fd2000000000,     0xa207fa4000000000,     0x440ff48200000000,     0x881fe90400000000,     0x103fd20a00000000,     0x207fa41400000000,     0x40ff482800000000,
    0x81fe905000000000,     0x3fd20a200000000,     0x7fa414400000000,     0xff4828800000000,     0x1fe9051000000000,     0x3fd20a2000000000,     0x7fa4144000000000,     0xff48288000000000,     0xfe90510200000000,     0xfd20a20600000000,
    0xfa41440e00000000 
};

// ===== CA_group4 =====
static const uint64_t CA_group4_33R[33] = {
    0x19c5032af,     0x138a0655f,     0x7140cabf,     0xe281957e,     0x1c5032afc,     0x18a0655f9,     0x1140cabf3,     0x281957e7,     0x5032afce,     0xa0655f9c,
    0x140cabf38,     0x81957e71,     0x1032afce2,     0x655f9c5,     0xcabf38a,     0x1957e714,     0x32afce28,     0x655f9c50,     0xcabf38a0,     0x1957e7140,
    0x12afce281,     0x55f9c503,     0xabf38a06,     0x157e7140c,     0xafce2819,     0x15f9c5032,     0xbf38a065,     0x17e7140ca,     0xfce28195,     0x1f9c5032a,
    0x1f38a0655,     0x1e7140cab,     0x1ce281957 
};

static const uint64_t CA_group4_31L[31] = {
    0x7e4a369000000000,     0xfc946d2000000000,     0xf928da4200000000,     0xf251b48600000000,     0xe4a3690e00000000,     0xc946d21e00000000,     0x928da43e00000000,     0x251b487e00000000,     0x4a3690fc00000000,     0x946d21f800000000,
    0x28da43f200000000,     0x51b487e400000000,     0xa3690fc800000000,     0x46d21f9200000000,     0x8da43f2400000000,     0x1b487e4a00000000,     0x3690fc9400000000,     0x6d21f92800000000,     0xda43f25000000000,     0xb487e4a200000000,
    0x690fc94600000000,     0xd21f928c00000000,     0xa43f251a00000000,     0x487e4a3600000000,     0x90fc946c00000000,     0x21f928da00000000,     0x43f251b400000000,     0x87e4a36800000000,     0xfc946d200000000,     0x1f928da400000000,
    0x3f251b4800000000 
};

// ===== CA_group5 =====
static const uint64_t CA_group5_33R[33] = {
    0xf9159cec,     0x1f22b39d8,     0x1e45673b1,     0x1c8ace763,     0x19159cec7,     0x122b39d8f,     0x45673b1f,     0x8ace763e,     0x1159cec7c,     0x2b39d8f9,
    0x5673b1f2,     0xace763e4,     0x159cec7c8,     0xb39d8f91,     0x1673b1f22,     0xce763e45,     0x19cec7c8a,     0x139d8f915,     0x73b1f22b,     0xe763e456,
    0x1cec7c8ac,     0x19d8f9159,     0x13b1f22b3,     0x763e4567,     0xec7c8ace,     0x1d8f9159c,     0x1b1f22b39,     0x163e45673,     0xc7c8ace7,     0x18f9159ce,
    0x11f22b39d,     0x3e45673b,     0x7c8ace76 
};

static const uint64_t CA_group5_31L[31] = {
    0xf248b96000000000,     0xe49172c200000000,     0xc922e58600000000,     0x9245cb0e00000000,     0x248b961e00000000,     0x49172c3c00000000,     0x922e587800000000,     0x245cb0f200000000,     0x48b961e400000000,     0x9172c3c800000000,
    0x22e5879200000000,     0x45cb0f2400000000,     0x8b961e4800000000,     0x172c3c9200000000,     0x2e58792400000000,     0x5cb0f24800000000,     0xb961e49000000000,     0x72c3c92200000000,     0xe587924400000000,     0xcb0f248a00000000,
    0x961e491600000000,     0x2c3c922e00000000,     0x5879245c00000000,     0xb0f248b800000000,     0x61e4917200000000,     0xc3c922e400000000,     0x879245ca00000000,     0xf248b9600000000,     0x1e49172c00000000,     0x3c922e5800000000,
    0x79245cb000000000 
};

// ===== CA_group6 =====
static const uint64_t CA_group6_33R[33] = {
    0x11cf8a361,     0x39f146c3,     0x73e28d86,     0xe7c51b0c,     0x1cf8a3618,     0x19f146c31,     0x13e28d863,     0x7c51b0c7,     0xf8a3618e,     0x1f146c31c,
    0x1e28d8639,     0x1c51b0c73,     0x18a3618e7,     0x1146c31cf,     0x28d8639f,     0x51b0c73e,     0xa3618e7c,     0x146c31cf8,     0x8d8639f1,     0x11b0c73e2,
    0x3618e7c5,     0x6c31cf8a,     0xd8639f14,     0x1b0c73e28,     0x1618e7c51,     0xc31cf8a3,     0x18639f146,     0x10c73e28d,     0x18e7c51b,     0x31cf8a36,
    0x639f146c,     0xc73e28d8,     0x18e7c51b0 
};

static const uint64_t CA_group6_31L[31] = {
    0x9ff8253200000000,     0x3ff04a6600000000,     0x7fe094cc00000000,     0xffc1299800000000,     0xff82533200000000,     0xff04a66600000000,     0xfe094cce00000000,     0xfc12999e00000000,     0xf825333e00000000,     0xf04a667e00000000,
    0xe094ccfe00000000,     0xc12999fe00000000,     0x825333fe00000000,     0x4a667fe00000000,     0x94ccffc00000000,     0x12999ff800000000,     0x25333ff000000000,     0x4a667fe000000000,     0x94ccffc000000000,     0x2999ff8200000000,
    0x5333ff0400000000,     0xa667fe0800000000,     0x4ccffc1200000000,     0x999ff82400000000,     0x333ff04a00000000,     0x667fe09400000000,     0xccffc12800000000,     0x99ff825200000000,     0x33ff04a600000000,     0x67fe094c00000000,
    0xcffc129800000000 
};

// ===== CA_group7 =====
static const uint64_t CA_group7_33R[33] = {
    0x83cfcff,     0x1079f9fe,     0x20f3f3fc,     0x41e7e7f8,     0x83cfcff0,     0x1079f9fe0,     0xf3f3fc1,     0x1e7e7f82,     0x3cfcff04,     0x79f9fe08,
    0xf3f3fc10,     0x1e7e7f820,     0x1cfcff041,     0x19f9fe083,     0x13f3fc107,     0x7e7f820f,     0xfcff041e,     0x1f9fe083c,     0x1f3fc1079,     0x1e7f820f3,
    0x1cff041e7,     0x19fe083cf,     0x13fc1079f,     0x7f820f3f,     0xff041e7e,     0x1fe083cfc,     0x1fc1079f9,     0x1f820f3f3,     0x1f041e7e7,     0x1e083cfcf,
    0x1c1079f9f,     0x1820f3f3f,     0x1041e7e7f 
};

static const uint64_t CA_group7_31L[31] = {
    0xe055ee00000000,     0x1c0abdc00000000,     0x38157b800000000,     0x702af7000000000,     0xe055ee000000000,     0x1c0abdc000000000,     0x38157b8000000000,     0x702af70000000000,     0xe055ee0000000000,     0xc0abdc0200000000,
    0x8157b80600000000, 0x2af700e00000000,     0x55ee01c00000000,     0xabdc03800000000,     0x157b807000000000,     0x2af700e000000000,     0x55ee01c000000000,     0xabdc038000000000,     0x57b8070200000000,     0xaf700e0400000000,
    0x5ee01c0a00000000,     0xbdc0381400000000,     0x7b80702a00000000,     0xf700e05400000000,     0xee01c0aa00000000,     0xdc03815600000000,     0xb80702ae00000000,     0x700e055e00000000,     0xe01c0abc00000000,     0xc038157a00000000,
    0x80702af600000000 
};

constexpr const uint64_t* MS_TAB_33R_CC[45] = {
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, // 0–9
    nullptr, CC_group2_33R, CC_group4_33R, CC_group2_33R, CC_group4_33R, nullptr, nullptr, nullptr, nullptr, nullptr, // 10–19
    nullptr, CC_group3_33R, CC_group1_33R, CC_group3_33R, CC_group1_33R, nullptr, nullptr, nullptr, nullptr, nullptr, // 20–29
    nullptr, CC_group2_33R, CC_group4_33R, CC_group2_33R, CC_group4_33R, nullptr, nullptr, nullptr, nullptr, nullptr, // 30–39
    nullptr, CC_group3_33R, CC_group1_33R, CC_group3_33R, CC_group1_33R // 40–44
};

constexpr const uint64_t* MS_TAB_31L_CC[45] = {
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, // 0–9
    nullptr, CC_group2_31L, CC_group4_31L, CC_group2_31L, CC_group4_31L, nullptr, nullptr, nullptr, nullptr, nullptr, // 10–19
    nullptr, CC_group3_31L, CC_group1_31L, CC_group3_31L, CC_group1_31L, nullptr, nullptr, nullptr, nullptr, nullptr, // 20–29
    nullptr, CC_group2_31L, CC_group4_31L, CC_group2_31L, CC_group4_31L, nullptr, nullptr, nullptr, nullptr, nullptr, // 30–39
    nullptr, CC_group3_31L, CC_group1_31L, CC_group3_31L, CC_group1_31L // 40–44
};

// ===== MS_TAB_33R_CG =====
constexpr const uint64_t* MS_TAB_33R_CG[45] = {
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, // 0–9
    nullptr, CG_group1_33R, CG_group2_33R, CG_group3_33R, CG_group2_33R, nullptr, nullptr, nullptr, nullptr, nullptr, // 10–19
    nullptr, CG_group4_33R, CG_group5_33R, CG_group4_33R, CG_group5_33R, nullptr, nullptr, nullptr, nullptr, nullptr, // 20–29
    nullptr, CG_group1_33R, CG_group2_33R, CG_group3_33R, CG_group2_33R, nullptr, nullptr, nullptr, nullptr, nullptr, // 30–39
    nullptr, CG_group6_33R, CG_group7_33R, CG_group4_33R, CG_group7_33R // 40–44
};

// ===== MS_TAB_31L_CG =====
constexpr const uint64_t* MS_TAB_31L_CG[45] = {
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, // 0–9
    nullptr, CG_group1_31L, CG_group2_31L, CG_group3_31L, CG_group2_31L, nullptr, nullptr, nullptr, nullptr, nullptr, // 10–19
    nullptr, CG_group4_31L, CG_group5_31L, CG_group4_31L, CG_group5_31L, nullptr, nullptr, nullptr, nullptr, nullptr, // 20–29
    nullptr, CG_group1_31L, CG_group2_31L, CG_group3_31L, CG_group2_31L, nullptr, nullptr, nullptr, nullptr, nullptr, // 30–39
    nullptr, CG_group6_31L, CG_group7_31L, CG_group4_31L, CG_group7_31L // 40–44
};


// ===== MS_TAB_33R_CA =====
constexpr const uint64_t* MS_TAB_33R_CA[45] = {
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, // 0–9
    nullptr, CA_group4_33R, CA_group2_33R, CA_group3_33R, CA_group2_33R, nullptr, nullptr, nullptr, nullptr, nullptr, // 10–19
    nullptr, CA_group1_33R, CA_group6_33R, CA_group5_33R, CA_group6_33R, nullptr, nullptr, nullptr, nullptr, nullptr, // 20–29
    nullptr, CA_group4_33R, CA_group2_33R, CA_group3_33R, CA_group2_33R, nullptr, nullptr, nullptr, nullptr, nullptr, // 30–39
    nullptr, CA_group1_33R, CA_group7_33R, CA_group1_33R, CA_group7_33R // 40–44
};

// ===== MS_TAB_31L_CA =====
constexpr const uint64_t* MS_TAB_31L_CA[45] = {
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, // 0–9
    nullptr, CA_group4_31L, CA_group2_31L, CA_group3_31L, CA_group2_31L, nullptr, nullptr, nullptr, nullptr, nullptr, // 10–19
    nullptr, CA_group1_31L, CA_group6_31L, CA_group5_31L, CA_group6_31L, nullptr, nullptr, nullptr, nullptr, nullptr, // 20–29
    nullptr, CA_group4_31L, CA_group2_31L, CA_group3_31L, CA_group2_31L, nullptr, nullptr, nullptr, nullptr, nullptr, // 30–39
    nullptr, CA_group1_31L, CA_group7_31L, CA_group1_31L, CA_group7_31L // 40–44
};

// ===== MS_TAB_33R_CT =====
constexpr const uint64_t* MS_TAB_33R_CT[45] = {
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, // 0–9
    nullptr, CT_group2_33R, CT_group2_33R, CT_group2_33R, CT_group7_33R, nullptr, nullptr, nullptr, nullptr, nullptr, // 10–19
    nullptr, CT_group3_33R, CT_group1_33R, CT_group4_33R, CT_group1_33R, nullptr, nullptr, nullptr, nullptr, nullptr, // 20–29
    nullptr, CT_group2_33R, CT_group2_33R, CT_group2_33R, CT_group7_33R, nullptr, nullptr, nullptr, nullptr, nullptr, // 30–39
    nullptr, CT_group5_33R, CT_group1_33R, CT_group6_33R, CT_group1_33R // 40–44
};

// ===== MS_TAB_31L_CT =====
constexpr const uint64_t* MS_TAB_31L_CT[45] = {
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, // 0–9
    nullptr, CT_group2_31L, CT_group2_31L, CT_group2_31L, CT_group7_31L, nullptr, nullptr, nullptr, nullptr, nullptr, // 10–19
    nullptr, CT_group3_31L, CT_group1_31L, CT_group4_31L, CT_group1_31L, nullptr, nullptr, nullptr, nullptr, nullptr, // 20–29
    nullptr, CT_group2_31L, CT_group2_31L, CT_group2_31L, CT_group7_31L, nullptr, nullptr, nullptr, nullptr, nullptr, // 30–39
    nullptr, CT_group5_31L, CT_group1_31L, CT_group6_31L, CT_group1_31L // 40–44
};


inline uint64_t
srol_bs_table(uint8_t out_idx, unsigned d, const uint64_t* const* TAB_33R, const uint64_t* const* TAB_31L)
{
  d= d/2;
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
  // Compute indices for outgoing and incoming dimers
  // Each dimer is encoded as (10 * first + second)
  uint8_t out_idx = 10 * CONVERT_TAB_SIMPLE[char_out1] + CONVERT_TAB_SIMPLE[char_out2];
  uint8_t in_idx  = 10 * CONVERT_TAB_SIMPLE[char_in1]  + CONVERT_TAB_SIMPLE[char_in2];

  // Rotate the hash left by 2 since we move by two bases
  uint64_t h_val = srol(fh_val);

  // XOR out the old dimer and XOR in the new dimer
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
  // Compute indices for outgoing and incoming dimers
  // Each dimer is encoded as (10 * first + second)
  uint8_t out_idx = 10 * CONVERT_TAB_SIMPLE[char_out1] + CONVERT_TAB_SIMPLE[char_out2];
  uint8_t in_idx  = 10 * CONVERT_TAB_SIMPLE[char_in1]  + CONVERT_TAB_SIMPLE[char_in2];

  uint64_t h_val = fh_val ^ srol_bs_table(in_idx, k, TAB_33R, TAB_31L);
  h_val ^= DIMER_TAB[out_idx];
  h_val = sror(h_val);
  return h_val;
}

// Generic dimer-based reverse hash using pointer table
inline std::vector<uint64_t>
base_reverse_bs_hash(const char* seq, bool has_second, unsigned k, const uint64_t* DIMER_TAB)
{

    uint64_t h0 = 0;
    uint64_t h1 = 0;

    // Process pairs from the end for h0
    for (int i = (int)k - 1; i >= 1; i -= 2) {
        h0 = srol(h0, 1);
        const uint8_t a = CONVERT_TAB_RC[(unsigned char)seq[i]];
        const uint8_t b = CONVERT_TAB_RC[(unsigned char)seq[i - 1]];
        const uint8_t loc = 10 * a + b;  // yields 11..44
        h0 ^= DIMER_TAB[loc];         // first element of pointer table
    }

    // If length exactly k, return only h0
    if (!has_second)
        return {h0, 0};

    // Offset by 1 for second hash (mirroring h1 in forward)
    for (int i = (int)k; i >= 2; i -= 2) {
        h1 = srol(h1, 1);
        const uint8_t a = CONVERT_TAB_RC[(unsigned char)seq[i]];
        const uint8_t b = CONVERT_TAB_RC[(unsigned char)seq[i - 1]];
        const uint8_t loc = 10 * a + b;
        h1 ^= DIMER_TAB[loc];
    }

    return {h0, h1};
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
  uint8_t out_idx = 10 * CONVERT_TAB_RC[char_out2] + CONVERT_TAB_RC[char_out1];
  uint8_t in_idx  = 10 * CONVERT_TAB_RC[char_in2]  + CONVERT_TAB_RC[char_in1];
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
  uint8_t out_idx = 10 * CONVERT_TAB_RC[char_out2] + CONVERT_TAB_RC[char_out1];
  uint8_t in_idx  = 10 * CONVERT_TAB_RC[char_in2]  + CONVERT_TAB_RC[char_in1];
  uint64_t h_val = srol(rh_val);
  h_val ^= DIMER_TAB[in_idx];
  h_val ^= srol_bs_table(out_idx, k, TAB_33R, TAB_31L);
  return h_val;
}
}// namespace btllib::hashing_internals

namespace btllib {

using hashing_internals::extend_hashes;
using hashing_internals::sror;
using hashing_internals::srol;
class BsHash
{

public:
  /**
   * Construct an BsHash object for k-mers.
   * @param seq C-string containing sequence data
   * @param seq_len Length of the sequence
   * @param num_hashes Number of hashes to generate per k-mer
   * @param k K-mer size
   * @param pos Position in the sequence to start hashing from
   */
  BsHash(const char* seq,
         size_t seq_len,
         hashing_internals::NUM_HASHES_TYPE num_hashes,
         hashing_internals::K_TYPE k,
         std::string mode,
         size_t pos = 0)
    : seq(seq)
    , seq_len(seq_len)
    , num_hashes(num_hashes)
    , k(k)
    , pos(pos)
    , initialized(false)
    , hash_arr(new uint64_t[num_hashes])
  {
    check_error(k == 0, "BsHash: k must be greater than 0");
    check_error(k % 2 == 1, "BsHash: k must be even");
    check_error(this->seq_len < k,
                "BsHash: sequence length (" + std::to_string(this->seq_len) +
                  ") is smaller than k (" + std::to_string(k) + ")");
    check_error(pos > this->seq_len - k,
                "BsHash: passed position (" + std::to_string(pos) +
                  ") is larger than sequence length (" +
                  std::to_string(this->seq_len) + ")");
    static const std::unordered_set<std::string> valid_modes = {"CG", "CC", "CT", "CA"};
    check_error(valid_modes.find(mode) == valid_modes.end(),
            "BsHash: mode must be one of [CG, CC, CT, CA], but got '" + mode + "'");

    if (mode == "CC") {
        DIMER_TAB = CC_DIMER_TAB;
        TAB_33R = MS_TAB_33R_CC;
        TAB_31L = MS_TAB_31L_CC;
    } else if (mode == "CG") {
        DIMER_TAB = CG_DIMER_TAB;
        TAB_33R = MS_TAB_33R_CG;
        TAB_31L = MS_TAB_31L_CG;
    } else if (mode == "CT") {
        DIMER_TAB = CT_DIMER_TAB;
        TAB_33R = MS_TAB_33R_CT;
        TAB_31L = MS_TAB_31L_CT;
    } else if (mode == "CA") {
        DIMER_TAB = CA_DIMER_TAB;
        TAB_33R = MS_TAB_33R_CA;
        TAB_31L = MS_TAB_31L_CA;
    }
  }

  /**
   * Construct an BsHash object for k-mers.
   * @param seq Sequence string
   * @param num_hashes Number of hashes to produce per k-mer
   * @param k K-mer size
   * @param pos Position in sequence to start hashing from
   */
  BsHash(const std::string& seq,
         hashing_internals::NUM_HASHES_TYPE num_hashes,
         hashing_internals::K_TYPE k,
         std::string mode = "CG",
         size_t pos = 0)
    : BsHash(seq.data(), seq.size(), num_hashes, k, mode, pos)
  {
  }

  BsHash(const BsHash& obj)
    : seq(obj.seq)
    , seq_len(obj.seq_len)
    , num_hashes(obj.num_hashes)
    , k(obj.k)
    , pos(obj.pos)
    , initialized(obj.initialized)
    , fwd_hashes(obj.fwd_hashes)
    , rev_hashes(obj.rev_hashes)
    , hash_arr(new uint64_t[obj.num_hashes] )
  {
    DIMER_TAB = obj.DIMER_TAB;
    TAB_33R = obj.TAB_33R;
    TAB_31L = obj.TAB_31L;
    std::memcpy(
      hash_arr.get(), obj.hash_arr.get(), num_hashes * sizeof(uint64_t));
  }


// TODO
  BsHash(BsHash&&) = default; 

  /**
   * Calculate the hash values of current k-mer and advance to the next k-mer.
   * BsHash advances one nucleotide at a time until it finds a k-mer with valid
   * characters (ACGTU) and skips over those with invalid characters (non-ACGTU,
   * including N). This method must be called before hashes() is accessed, for
   * the first and every subsequent hashed kmer. get_pos() may be called at any
   * time to obtain the position of last hashed k-mer or the k-mer to be hashed
   * if roll() has never been called on this BsHash object. It is important to
   * note that the number of roll() calls is NOT necessarily equal to get_pos(),
   * if there are N's or invalid characters in the hashed sequence.
   * @return \p true on success and \p false otherwise
   */
bool roll()
{
    if (!initialized) {
        std::cout << "[ROLL] Not initialized. Calling init()\n";
        return init();
    }

    std::cout << "[ROLL] Rolling at position " << pos << ", even=" << even << "\n";

    if (even) {
        if (pos >= seq_len - k) {
            std::cout << "[ROLL] Reached end of sequence, cannot roll\n";
            return false;
        }
        char c1 = seq[pos + k - 1];
        char c2 = seq[pos + k];
        uint8_t a = CONVERT_TAB_SIMPLE[(unsigned char)c1];
        uint8_t b = CONVERT_TAB_SIMPLE[(unsigned char)c2];
        uint8_t loc = 10 * a + b;  // yields 11, 12, ..., 44
        if (DIMER_TAB[loc] == 0) {
            std::cout << "[ROLL] Invalid dimer at position " << (pos + k)
                      << ", skipping " << k << " positions and re-initializing\n";
            pos += k;
            return init();
        }
        std::cout << "[ROLL] Even roll, extending hashes at position " << pos << "\n";
        even = false;
        ++pos;
        extend_hashes(fwd_hashes[1], rev_hashes[1], k, num_hashes, hash_arr.get());
        return true;
    }

    if (pos >= seq_len - k) {
        std::cout << "[ROLL] Reached end of sequence, cannot roll\n";
        return false;
    }

    char c1 = seq[pos + k - 1];
    char c2 = seq[pos + k];
    uint8_t a = CONVERT_TAB_SIMPLE[(unsigned char)c1];
    uint8_t b = CONVERT_TAB_SIMPLE[(unsigned char)c2];
    uint8_t loc = 10 * a + b;  // yields 11, 12, ..., 44
    if (DIMER_TAB[loc] == 0) {
        std::cout << "[ROLL] Invalid dimer at position " << (pos + k)
                  << ", skipping " << k << " positions and re-initializing\n";
        pos += k;
        return init();
    }

    bool can_roll_second = true;
    c1 = seq[pos + k];
    c2 = seq[pos + k + 1];
    a = CONVERT_TAB_SIMPLE[(unsigned char)c1];
    b = CONVERT_TAB_SIMPLE[(unsigned char)c2];
    loc = 10 * a + b;
    if (pos + 1 >= seq_len - k || DIMER_TAB[loc] == 0) {
        can_roll_second = false;
        std::cout << "[ROLL] Cannot roll second k-mer at position " << (pos + 1) << "\n";
    }

    for (int i = 0; i < 2; i++) {
        if (i == 0 || can_roll_second) {
            char out1 = seq[pos + i - 1];
            char out2 = seq[pos + i + 1 - 1];
            char in1  = seq[pos + k + i - 1];
            char in2  = seq[pos + k + i + 1 - 1];

            std::cout << "[ROLL] Loop " << i << " at pos=" << pos
                      << " | OUT: " << out1 << out2
                      << " | IN: " << in1 << in2 << "\n";

            fwd_hashes[i] = next_forward_bs_hash(fwd_hashes[i], k,
                                                 out1, out2, in1, in2,
                                                 DIMER_TAB, TAB_33R, TAB_31L);
            rev_hashes[i] = next_reverse_bs_hash(rev_hashes[i], k,
                                                 out1, out2, in1, in2,
                                                 DIMER_TAB, TAB_33R, TAB_31L);
        }
    }

    std::cout << "[ROLL] Extending hashes at position " << pos << "\n";
    extend_hashes(fwd_hashes[0], rev_hashes[0], k, num_hashes, hash_arr.get());

    ++pos;
    even = true;

    std::cout << "[ROLL] Roll complete, new position=" << pos << ", even=" << even << "\n";

    if (!can_roll_second ) {
        fwd_hashes[1] = 0;
        rev_hashes[1] = 0;
    }
    return true;
}


bool is_methylated() {
    if (k < 2) return false; // cannot have a dimer

    // Center dimer index within k-mer
    size_t center_idx;
    size_t num_dimers = k / 2;

    if (num_dimers % 2 == 1) {
        // Odd number of dimers → pick exact center dimer
        center_idx = pos + (num_dimers / 2) * 2;
    } else {
        // Even number of dimers → pick left of two central dimers
        center_idx = pos + ((num_dimers / 2) - 1) * 2;
    }

    // Safety check
    if (center_idx + 1 >= seq_len) return false;

    return seq[center_idx] == 'C' && seq[center_idx + 1] == 'G';
}

  /**
   * Like the roll() function, but advance backwards.
   * @return \p true on success and \p false otherwise
   */
  bool roll_back()
  {

    if (!initialized) {
        return init();
    }

    if (pos == 0) {
        return false;
    }

    if (!even) {
        extend_hashes(fwd_hashes[0], rev_hashes[0], k, num_hashes, hash_arr.get());
        --pos;
        even = true; // toggle to indicate next roll_back can attempt both
        return true;
    }


    char c1 = seq[pos - 1];
    char c2 = seq[pos];
    uint8_t a = CONVERT_TAB_SIMPLE[(unsigned char)c1];
    uint8_t b = CONVERT_TAB_SIMPLE[(unsigned char)c2];
    uint8_t loc = 10 * a + b;  // yields 11, 12, ..., 44
    if (DIMER_TAB[loc] == 0) {
        std::cout << "[ROLL] Invalid dimer at position " << (pos + k)
                  << ", skipping " << k << " positions and re-initializing\n";
        if (pos <= k) {
            return false;
        }
        pos -= k;
        return init();

    }

    c1 = seq[pos - 2];
    c2 = seq[pos - 1];
    a = CONVERT_TAB_SIMPLE[(unsigned char)c1];
    b = CONVERT_TAB_SIMPLE[(unsigned char)c2];
    loc = 10 * a + b; 
    // even step: try to roll back both hashes
    bool can_roll_second = true;
    if (pos <= 1 || DIMER_TAB[loc] == 0) {
        can_roll_second = false;
    }
    if (fwd_hashes[1] != 0) { 
        for (int i = 0; i < 2; i++) {
            if (i == 1 || can_roll_second) {
                fwd_hashes[i] = prev_forward_bs_hash(fwd_hashes[i], k,
                                                    seq[pos + k - 2 + i], seq[pos + k - 1 + i],
                                                    seq[pos - 2 + i], seq[pos - 1 + i],
                                                    DIMER_TAB, TAB_33R, TAB_31L);
                rev_hashes[i] = prev_reverse_bs_hash(rev_hashes[i], k,
                                                    seq[pos + k - 2 + i], seq[pos + k - 1 + i],
                                                    seq[pos - 2 + i], seq[pos - 1 + i],
                                                    DIMER_TAB, TAB_33R, TAB_31L);
            }
        }
    } else {
        std::cerr << "abcdefgh" << std::endl;
        pos -=2;
        init();
        pos++;
        extend_hashes(fwd_hashes[1], rev_hashes[1], k, num_hashes, hash_arr.get());
        even = false;
        return true;
    }

    extend_hashes(fwd_hashes[1], rev_hashes[1], k, num_hashes, hash_arr.get());
    --pos;
    even = false;
    return true;
  }

 
  /**
   * Get the array of current canonical hash values (length = \p get_hash_num())
   * @return Pointer to the hash array
   */
  const uint64_t* hashes() const { return hash_arr.get(); }

  /**
   * Get the position of last hashed k-mer or the k-mer to be hashed if roll()
   * has never been called on this BsHash object.
   * @return Position of the most recently hashed k-mer's first base-pair
   */
  size_t get_pos() const { return pos; }

  /**
   * Get the number of hashes generated per k-mer.
   * @return Number of hashes per k-mer
   */
  hashing_internals::NUM_HASHES_TYPE get_hash_num() const { return num_hashes; }

  /**
   * Get the length of the k-mers.
   * @return \p k
   */
  hashing_internals::K_TYPE get_k() const { return k; }

  /**
   * Get the hash value of the forward strand.
   * @return Forward hash value
   */
  uint64_t get_forward_hash() const { if (even) {return fwd_hashes[0];} else {return fwd_hashes[1];}}

  /**
   * Get the hash value of the reverse strand.
   * @return Reverse-complement hash value
   */
  uint64_t get_reverse_hash() const { if (even) {return rev_hashes[0];} else {return rev_hashes[1];}}

private:
  const char* seq;
  const size_t seq_len;
  hashing_internals::NUM_HASHES_TYPE num_hashes;
  hashing_internals::K_TYPE k;
  size_t pos;
  bool initialized;
  std::vector<uint64_t> fwd_hashes = {0, 0};
  std::vector<uint64_t>  rev_hashes = {0, 0};
  bool even = true;
  std::unique_ptr<uint64_t[]> hash_arr;
  const uint64_t* DIMER_TAB = nullptr;
  const uint64_t* const* TAB_33R = nullptr;
  const uint64_t* const* TAB_31L = nullptr;

  /**
   * Initialize the internal state of the iterator
   * @return \p true if successful, \p false otherwise
   */

bool init()
{
    std::cout << "[INIT] Starting initialization at position " << pos << "\n";

    bool has_n = true;
    while (pos <= seq_len - k + 1 && has_n) {
        has_n = false;
        for (unsigned i = 0; i < k && pos <= seq_len - k + 1; i += 2) {
            const char c1 = seq[pos + k - i - 2];
            const char c2 = seq[pos + k - i - 1];
            const uint8_t a = CONVERT_TAB_SIMPLE[(unsigned char)c1];
            const uint8_t b = CONVERT_TAB_SIMPLE[(unsigned char)c2];
            const uint8_t loc = 10 * a + b;  // yields 11, 12, ..., 44

            std::cout << "[INIT] Checking dimer '" << c1 << c2 
                      << "' -> loc=" << (unsigned)loc << "\n";

            if (DIMER_TAB[loc] == 0) {
                std::cout << "[INIT] Found invalid base at position " << (pos + k - i - 1)
                          << ", skipping " << (k - i) << " positions\n";
                if (b == 0) {
                    pos += k - i;
                } else {
                    pos += k - i - 1;
                }
                
                has_n = true;
            }
        }
    }

    if (pos > seq_len - k) {
        std::cout << "[INIT] Position exceeded sequence length, returning false\n";
        return false;
    }

    bool has_second = true;
    if (pos == seq_len - k) {
        has_second = false;
        std::cout << "[INIT] At last k-mer, no second k-mer available\n";
    }

    std::cout << "[INIT] Computing forward hashes at position " << pos << "\n";
    fwd_hashes = base_forward_bs_hash(seq + pos, has_second, k, DIMER_TAB);

    std::cout << "[INIT] Computing reverse hashes at position " << pos << "\n";
    rev_hashes = base_reverse_bs_hash(seq + pos, has_second, k, DIMER_TAB);

    std::cout << "[INIT] Extending hashes\n";
    extend_hashes(fwd_hashes[0], rev_hashes[0], k, num_hashes, hash_arr.get());

    initialized = true;
    std::cout << "[INIT] Initialization complete at position " << pos << "\n";
    return true;
}

};
}