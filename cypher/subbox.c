#include "subbox.h"

unsigned char subbytes(unsigned char ch) {
    static unsigned char s[256] = SUBBOX;
    return s[ch];
}

unsigned char inv_subbytes(unsigned char ch) {
    static unsigned char inv_s[256] = INV_SUBBOX;
    return inv_s[ch];
}

