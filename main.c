#include <tinydigest/sha2.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void print_hash(const uint8_t *hash, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int compare_hash(const uint8_t *hash, const char *expected_hash, size_t hash_len) {
    char hash_str[hash_len * 2 + 1];
    for (size_t i = 0; i < hash_len; ++i) {
        sprintf(&hash_str[i * 2], "%02x", hash[i]);
    }
    hash_str[hash_len * 2] = '\0';

    return strcmp(hash_str, expected_hash);
}

void run_test() {
    const char *input = "hello";
    {
        uint8_t output[SHA2_224_DIGEST_SIZE];

        sha2_224_compute((const uint8_t*)input, strlen(input), output);

        const char *expected_hash = "ea09ae9cc6768c50fcee903ed054556e5bfc8347907f12598aa24193";

        assert(compare_hash(output, expected_hash, SHA2_224_DIGEST_SIZE) == 0);

        printf("SHA2-224: Passed\n");
    }
    {
        uint8_t output[SHA2_256_DIGEST_SIZE];

        sha2_256_compute((const uint8_t*)input, strlen(input), output);
        
        const char *expected_hash = "2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824";

        assert(compare_hash(output, expected_hash, SHA2_256_DIGEST_SIZE) == 0);
        printf("SHA2-256: Passed\n");
    }
    {
        uint8_t output[SHA2_384_DIGEST_SIZE];

        sha2_384_compute((const uint8_t*)input, strlen(input), output);

        const char *expected_hash = "59e1748777448c69de6b800d7a33bbfb9ff1b463e44354c3553bcdb9c666fa90125a3c79f90397bdf5f6a13de828684f";

        assert(compare_hash(output, expected_hash, SHA2_384_DIGEST_SIZE) == 0);
        printf("SHA2-384: Passed\n");
    }
    {
        uint8_t output[SHA2_512_DIGEST_SIZE];

        sha2_512_compute((const uint8_t*)input, strlen(input), output);

        const char *expected_hash = "9b71d224bd62f3785d96d46ad3ea3d73319bfbc2890caadae2dff72519673ca72323c3d99ba5c11d7c7acc6e14b8c5da0c4663475c2e5c3adef46f73bcdec043";

        assert(compare_hash(output, expected_hash, SHA2_512_DIGEST_SIZE) == 0);
        printf("SHA2-512: Passed\n");
    }
    {
        uint8_t output[SHA2_512_224_DIGEST_SIZE];

        sha2_512_224_compute((const uint8_t*)input, strlen(input), output);

        const char *expected_hash = "fe8509ed1fb7dcefc27e6ac1a80eddbec4cb3d2c6fe565244374061c";

        assert(compare_hash(output, expected_hash, SHA2_512_224_DIGEST_SIZE) == 0);
        printf("SHA2-512/224: Passed\n");
    }
    {
        uint8_t output[SHA2_512_256_DIGEST_SIZE];

        sha2_512_256_compute((const uint8_t*)input, strlen(input), output);

        const char *expected_hash = "e30d87cfa2a75db545eac4d61baf970366a8357c7f72fa95b52d0accb698f13a";

        assert(compare_hash(output, expected_hash, SHA2_512_256_DIGEST_SIZE) == 0);
        printf("SHA2-512/256: Passed\n");
    }
}

int main() {
    printf("sizeof(size_t): %zu\n", sizeof(size_t));
    run_test();
    printf("All tests passed!");
    return 0;
}