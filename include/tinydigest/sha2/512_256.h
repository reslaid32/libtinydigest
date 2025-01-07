#ifndef SHA2_512_256_H
#define SHA2_512_256_H

#include "../export.h"

#include <stdint.h>
#include <stddef.h>

#define SHA2_512_256_OUTPUT_LENGTH 32

LIBTINYDIGEST_API void sha2_512_256_compute(const uint8_t *input, size_t len, uint8_t output[SHA2_512_256_OUTPUT_LENGTH]);

#endif // SHA2_512_256_H
