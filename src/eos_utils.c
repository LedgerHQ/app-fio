/*******************************************************************************
 *   Taras Shchybovyk
 *   (c) 2018 Taras Shchybovyk
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#include <string.h>
#include "eos_utils.h"
#include "os.h"
#include "cx.h"
#include "utils.h"

unsigned char const BASE58ALPHABET[58] = {
    '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
    'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

#define MAX_B58ENC_LENGTH 60

bool b58enc(uint8_t *bin, uint32_t binsz, char *b58, uint32_t *b58sz) {
    int carry;
    uint32_t i, j, high, zcount = 0;
    uint32_t size;

    while (zcount < binsz && !bin[zcount]) ++zcount;

    size = (binsz - zcount) * 138 / 100 + 1;
    uint8_t buf[MAX_B58ENC_LENGTH];
    ASSERT(size <= MAX_B58ENC_LENGTH);
    explicit_bzero(buf, sizeof(buf));

    for (i = zcount, high = size - 1; i < binsz; ++i, high = j) {
        for (carry = bin[i], j = size - 1; (j > high) || carry; --j) {
            ASSERT(j < size);
            carry += 256 * buf[j];
            buf[j] = carry % 58;
            carry /= 58;
            if (!j) {
                // Otherwise j wraps to maxint which is > high
                break;
            }
        }
    }

    for (j = 0; j < size && !buf[j]; ++j)
        ;

    if (*b58sz <= zcount + size - j) {
        *b58sz = zcount + size - j + 1;
        return false;
    }

    if (zcount) memset(b58, '1', zcount);
    for (i = zcount; j < size; ++i, ++j) {
        ASSERT(buf[j] < 58);
        ASSERT(i < *b58sz);
        b58[i] = BASE58ALPHABET[buf[j]];
    }
    b58[i] = '\0';
    *b58sz = i + 1;

    return true;
}

uint32_t compressed_public_key_to_wif(const uint8_t *publicKey,
                                      uint32_t keyLength,
                                      char *out,
                                      uint32_t outLength) {
    ASSERT(publicKey != NULL);
    ASSERT(keyLength >= 33);
    ASSERT(outLength >= 40);

    uint8_t temp[37];
    explicit_bzero(temp, sizeof(temp));
    memcpy(temp, publicKey, 33);

    uint8_t check[20];
    cx_ripemd160_t riprip;
    cx_ripemd160_init(&riprip);
    ASSERT(cx_hash_no_throw(&riprip.header, CX_LAST, temp, 33, check, sizeof(check)) == CX_OK);
    memcpy(temp + 33, check, 4);

    explicit_bzero(out, outLength);
    out[0] = 'F';
    out[1] = 'I';
    out[2] = 'O';
    uint32_t addressLen = outLength - 3;
    b58enc(temp, sizeof(temp), out + 3, &addressLen);
    ASSERT(addressLen + 3 < outLength);

    return addressLen + 3;
}

uint32_t public_key_to_wif(const uint8_t *publicKey,
                           uint32_t keyLength,
                           char *out,
                           uint32_t outLength) {
    ASSERT(publicKey != NULL);
    ASSERT(keyLength >= 33);
    ASSERT(outLength >= 40);

    uint8_t temp[33];
    // is even?
    temp[0] = (publicKey[64] & 0x1) ? 0x03 : 0x02;
    memcpy(temp + 1, publicKey + 1, 32);
    return compressed_public_key_to_wif(temp, sizeof(temp), out, outLength);
}
