#ifndef SHA2_256_H
#define SHA2_256_H

#include "../export.h"

#include <stdint.h>
#include <stddef.h>

#define SHA2_256_OUTPUT_LENGTH 32

LIBTINYDIGEST_API void sha2_256_pad_message(const uint8_t *input, size_t len, uint8_t **padded, size_t *new_len);
LIBTINYDIGEST_API void sha2_256_process_block(const uint8_t *block, uint32_t H[8]);
LIBTINYDIGEST_API void sha2_256_compute(const uint8_t *input, size_t len, uint8_t output[SHA2_256_OUTPUT_LENGTH]);

#endif // SHA2_256_H
