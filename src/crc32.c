#ifndef LIBTINYDIGEST_LIBRARY_BUILD
#define LIBTINYDIGEST_LIBRARY_BUILD
#endif

#include <tinydigest/crc32.h>

static uint32_t crc32_table[256];

LIBTINYDIGEST_API void crc32_init_table() {
    for (uint32_t i = 0; i < 256; ++i) {
        uint32_t crc = i;
        for (uint8_t j = 0; j < 8; ++j) {
            crc = (crc >> 1) ^ (0xEDB88320 & -(crc & 1));
        }
        crc32_table[i] = crc;
    }
}

LIBTINYDIGEST_API uint32_t crc32_compute(const char *data, size_t length) {
    static int table_initialized = 0;
    if (!table_initialized) {
        crc32_init_table();
        table_initialized = 1;
    }

    uint32_t crc = 0xFFFFFFFF;
    for (size_t i = 0; i < length; ++i) {
        uint8_t byte = (uint8_t)data[i];
        crc = (crc >> 8) ^ crc32_table[(crc ^ byte) & 0xFF];
    }
    return ~crc;
}