#ifndef CRC32_H
#define CRC32_H

#include "export.h"

#include <stdint.h>
#include <stddef.h>

LIBTINYDIGEST_API void crc32_init_table();
LIBTINYDIGEST_API uint32_t crc32_compute(const char *data, size_t length);

#endif // CRC32_H