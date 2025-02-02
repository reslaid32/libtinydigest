#ifndef SHA2_384_H
#define SHA2_384_H

#include "../export.h"

#include <stdint.h>
#include <stddef.h>

#define SHA2_384_DIGEST_SIZE 48

LIBTINYDIGEST_API void sha2_384_compute(const uint8_t *input, size_t len, uint8_t output[SHA2_384_DIGEST_SIZE]);

#endif // SHA2_384_H
