#include "header.h"

bool isPowerOfTwo_r2(int n)
{
    int numberOfOne = 0;

    if (n > 0)
    {
        for (int i = 0; i < 32; i++)
        {
            if ((n & 1) > 0)
            {
                ++numberOfOne;
            }
            n >>= 1;
        }
    }

    return numberOfOne == 1;
}
