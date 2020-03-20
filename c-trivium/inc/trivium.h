/**
 * @file trivium.h
 * @author Romain Brenaget
 * @brief 
 * @version 0.1
 * @date 2020-03-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef TRIVIUM
#define TRIVIUM

//#include <stdlib.h>
//#include <limits.h>
#include <stdint.h>

#define BLOCK_SIZE 32

#define MAX_KEY_LEN 10
#define MAX_IV_LEN 10

typedef struct {
  uint8_t keylen;
  uint8_t ivlen;

  uint32_t lfsr_a[3];
  uint32_t lfsr_b[3];
  uint32_t lfsr_c[4];

  uint8_t key[MAX_KEY_LEN];
  uint8_t iv[MAX_IV_LEN];

} TRIVIUM_ctx;


int TRIVIUM_init(TRIVIUM_ctx* ctx, const uint8_t key[], const uint8_t iv[], uint8_t keylen, uint8_t ivlen);
void TRIVIUM_keysetup(TRIVIUM_ctx* ctx, const uint8_t key[]);
void TRIVIUM_ivsetup(TRIVIUM_ctx* ctx, const uint8_t iv[]);
void TRIVIUM_keystream(TRIVIUM_ctx* ctx, uint32_t output[], uint32_t n);

void debug_data(const uint32_t* data, uint32_t len);

#endif