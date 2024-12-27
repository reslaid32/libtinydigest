#include "crc32.h"

const std::array<uint32_t, 256> CRC32::table = []() {
    std::array<uint32_t, 256> table{};
    for (uint32_t i = 0; i < 256; ++i) {
        uint32_t crc = i;
        for (uint8_t j = 0; j < 8; ++j) {
            crc = (crc >> 1) ^ (0xEDB88320 & -(crc & 1));
        }
        table[i] = crc;
    }
    return table;
}();

uint32_t CRC32::compute(const std::string &data) {
    uint32_t crc = 0xFFFFFFFF;
    for (uint8_t byte : data) {
        crc = (crc >> 8) ^ table[(crc ^ byte) & 0xFF];
    }
    return ~crc;
}
