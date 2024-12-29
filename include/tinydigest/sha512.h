#ifndef SHA512_H
#define SHA512_H

#include "export.h"

#include <stdint.h>
#include <stddef.h>

LIBTINYDIGEST_API void sha512_pad_message(const uint8_t *input, size_t len, uint8_t **padded, size_t *new_len);
LIBTINYDIGEST_API void sha512_process_block(const uint8_t *block, uint64_t H[8]);
LIBTINYDIGEST_API void sha512_compute(const uint8_t *input, size_t len, uint8_t output[64]);

#endif // SHA512_H
