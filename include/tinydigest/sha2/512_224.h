#ifndef SHA2_512_224_H
#define SHA2_512_224_H

#include "../export.h"

#include <stdint.h>
#include <stddef.h>

#define SHA2_512_224_DIGEST_SIZE 28

LIBTINYDIGEST_API void sha2_512_224_compute(const uint8_t *input, size_t len, uint8_t output[SHA2_512_224_DIGEST_SIZE]);

#endif // SHA2_512_224_H
