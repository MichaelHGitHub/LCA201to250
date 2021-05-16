#include "header.h"

int rangeBitwiseAnd(int left, int right)
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