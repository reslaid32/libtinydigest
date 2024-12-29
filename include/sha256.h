#ifndef SHA256_H
#define SHA256_H

#include "export.h"

#include <stdint.h>
#include <stddef.h>

LIBTINYDIGEST_API void sha256_pad_message(const uint8_t *input, size_t len, uint8_t **padded, size_t *new_len);
LIBTINYDIGEST_API void sha256_process_block(const uint8_t *block, uint32_t H[8]);
LIBTINYDIGEST_API void sha256_compute(const uint8_t *input, size_t len, uint8_t output[32]);

#endif // SHA256_H
