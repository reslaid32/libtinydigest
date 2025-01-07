#ifndef SHA2_512_H
#define SHA2_512_H

#include "../export.h"

#include <stdint.h>
#include <stddef.h>

#define SHA2_512_OUTPUT_LENGTH 64

LIBTINYDIGEST_API void sha2_512_pad_message(const uint8_t *input, size_t len, uint8_t **padded, size_t *new_len);
LIBTINYDIGEST_API void sha2_512_process_block(const uint8_t *block, uint64_t H[8]);
LIBTINYDIGEST_API void sha2_512_compute(const uint8_t *input, size_t len, uint8_t output[SHA2_512_OUTPUT_LENGTH]);

#endif // SHA2_512_H
