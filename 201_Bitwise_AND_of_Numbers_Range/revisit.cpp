#include "header.h"

// x & (x + 1) sets the last bit of (x + 1) to 0.
// we can count how many 0s(number) we get by doing x & (x+1) & ... (x+n),
// then x >> number is the result we need.
int rangeBitwiseAnd_r(int left, int right)
{
    int count = 0;

    while (right > left)
    {
        right >>= 1;
        left >>= 1;
        ++count;
    }

    return right << count;
}