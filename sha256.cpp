#include "sha256.h"
#include <sstream>
#include <iomanip>
#include <cstring>

namespace SHA256Helpers {
    const std::array<uint32_t, 64> K = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

    uint32_t rotateRight(uint32_t value, uint32_t bits) {
        return (value >> bits) | (value << (32 - bits));
    }

    uint32_t choose(uint32_t e, uint32_t f, uint32_t g) {
        return (e & f) ^ (~e & g);
    }

    uint32_t majority(uint32_t a, uint32_t b, uint32_t c) {
        return (a & b) ^ (a & c) ^ (b & c);
    }

    uint32_t sigma0(uint32_t x) {
        return rotateRight(x, 2) ^ rotateRight(x, 13) ^ rotateRight(x, 22);
    }

    uint32_t sigma1(uint32_t x) {
        return rotateRight(x, 6) ^ rotateRight(x, 11) ^ rotateRight(x, 25);
    }

    uint32_t smallSigma0(uint32_t x) {
        return rotateRight(x, 7) ^ rotateRight(x, 18) ^ (x >> 3);
    }

    uint32_t smallSigma1(uint32_t x) {
        return rotateRight(x, 17) ^ rotateRight(x, 19) ^ (x >> 10);
    }
}

std::string SHA256::hash(const std::string &input) {
    std::vector<uint8_t> data(input.begin(), input.end());
    padData(data);
    return computeHash(data);
}

void SHA256::padData(std::vector<uint8_t> &data) {
    uint64_t bitLen = data.size() * 8;
    data.push_back(0x80);
    while ((data.size() % 64) != 56) {
        data.push_back(0);
    }
    for (int i = 7; i >= 0; --i) {
        data.push_back(static_cast<uint8_t>((bitLen >> (8 * i)) & 0xFF));
    }
}

std::string SHA256::computeHash(const std::vector<uint8_t> &data) {
    using namespace SHA256Helpers;

    constexpr std::array<uint32_t, 8> H0 = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    std::array<uint32_t, 8> H = H0;
    std::array<uint32_t, 64> W;

    for (size_t i = 0; i < data.size(); i += 64) {
        std::array<uint32_t, 16> block;
        toBigEndianWords({data.begin() + i, data.begin() + i + 64}, block);
        std::copy(block.begin(), block.end(), W.begin());

        for (size_t t = 16; t < 64; ++t) {
            W[t] = smallSigma1(W[t - 2]) + W[t - 7] + smallSigma0(W[t - 15]) + W[t - 16];
        }

        uint32_t a = H[0], b = H[1], c = H[2], d = H[3];
        uint32_t e = H[4], f = H[5], g = H[6], h = H[7];

        for (size_t t = 0; t < 64; ++t) {
            uint32_t T1 = h + sigma1(e) + choose(e, f, g) + K[t] + W[t];
            uint32_t T2 = sigma0(a) + majority(a, b, c);
            h = g; g = f; f = e; e = d + T1;
            d = c; c = b; b = a; a = T1 + T2;
        }

        H[0] += a; H[1] += b; H[2] += c; H[3] += d;
        H[4] += e; H[5] += f; H[6] += g; H[7] += h;
    }

    std::ostringstream result;
    for (uint32_t h : H) {
        result << std::hex << std::setw(8) << std::setfill('0') << h;
    }
    return result.str();
}

void SHA256::toBigEndianWords(const std::vector<uint8_t> &data, std::array<uint32_t, 16> &W) {
    for (size_t i = 0; i < 16; ++i) {
        W[i] = (data[i * 4] << 24) |
               (data[i * 4 + 1] << 16) |
               (data[i * 4 + 2] << 8) |
               data[i * 4 + 3];
    }
}
