#ifndef __CAESAR_CIPHER_H
#define __CAESAR_CIPHER_H
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#include <stdint.h>
// Caesar cipher returning the number of characters shifted in text.
int caesar_shift_c(uint8_t *text, int shift);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __CAESAR_CIPHER_H */