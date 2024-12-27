#ifndef SHA256_H
#define SHA256_H

#include <string>
#include <vector>
#include <array>
#include <cstdint>

namespace SHA256Helpers {
    extern const std::array<uint32_t, 64> K;

    uint32_t rotateRight(uint32_t value, uint32_t bits);
    uint32_t choose(uint32_t e, uint32_t f, uint32_t g);
    uint32_t majority(uint32_t a, uint32_t b, uint32_t c);
    uint32_t sigma0(uint32_t x);
    uint32_t sigma1(uint32_t x);
    uint32_t smallSigma0(uint32_t x);
    uint32_t smallSigma1(uint32_t x);
}

class SHA256 {
public:
    static std::string hash(const std::string &input);

private:
    static void padData(std::vector<uint8_t> &data);
    static std::string computeHash(const std::vector<uint8_t> &data);
    static void toBigEndianWords(const std::vector<uint8_t> &data, std::array<uint32_t, 16> &W);
};

#endif // SHA256_H
