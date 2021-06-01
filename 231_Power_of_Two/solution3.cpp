#include "header.h"

bool isPowerOfTwo3(int n) {
    return (n > 0 && (n & (n - 1)) == 0);
}