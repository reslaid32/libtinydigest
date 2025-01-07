#ifndef SHA2_224_H
#define SHA2_224_H

#include "../export.h"

#include <stdint.h>
#include <stddef.h>

#define SHA2_224_OUTPUT_LENGTH 28

LIBTINYDIGEST_API void sha2_224_compute(const uint8_t *input, size_t len, uint8_t output[SHA2_224_OUTPUT_LENGTH]);

#endif // SHA2_224_H



