#include "ws_if_switch_c.h"


// The if-else-if-else statement
int ws_acrl_c(int x) {
    if (x < 0) {
        x = 0;
    } else if (x >= 8) {
        x = 8;
    }
    return x;  
}

// Compound if-else statements
int ws_dcrl_orr_c(int x) {
    if ((x < 0) || (x >= 8)) {
        x = 0;
    } else {
        x = 1;
    }
    return x;  
}

int ws_dcrl_and_c(int x) {
    if ((x >= 0) && (x < 8)) {
        x = 1;
    } else {
        x = 0;
    }
    return x;  
}
