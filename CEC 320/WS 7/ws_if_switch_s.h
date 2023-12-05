#ifndef __WS_IF_SWITCH_S_H
#define __WS_IF_SWITCH_S_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdint.h>

// The if-else-if-else statement
int ws_acrl_cmp_s(int x);
int ws_acrl_cex_s(int x);

// Compound if-else statements
int ws_dcrl_orr_s(int x);
int ws_dcrl_and_s(int x);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __WS_IF_SWITCH_S_H */
