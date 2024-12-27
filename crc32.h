#ifndef CRC32_H
#define CRC32_H

#include <string>
#include <array>
#include <cstdint>

class CRC32 {
public:
    static uint32_t compute(const std::string &data);

private:
    static const std::array<uint32_t, 256> table;
};

#endif // CRC32_H
