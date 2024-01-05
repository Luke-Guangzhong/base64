#ifndef BASE64_H
#define BASE64_H

#define BASE64_ENCODE_OUT_SIZE(s) ((unsigned int)((((s) + 2) / 3) * 4 + 1))
#define BASE64_DECODE_OUT_SIZE(s) ((unsigned int)(((s) / 4) * 3))

/**
 * @brief encode string
 *
 * @param[in] in input raw string
 * @param[in] inlen string length
 * @param[out] out output string
 * @return unsigned int
 */
unsigned int base64_encode(const unsigned char* in, unsigned int inlen, char* out);

/**
 * @brief decode string
 *
 * @param[in] in input raw string
 * @param[in] inlen string length
 * @param[out] out output string
 * @return unsigned int
 */
unsigned int base64_decode(const char* in, unsigned int inlen, unsigned char* out);

#endif /* BASE64_H */
