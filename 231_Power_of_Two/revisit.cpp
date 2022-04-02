#include "header.h"

bool isPowerOfTwo_r(int n)
{
    bool isPowerOfTwo = true;

    if(n <= 0)
    {
        isPowerOfTwo = false;
    }
    else
    {
        while (n > 1)
        {
            if (n % 2 > 0)
            {
                isPowerOfTwo = false;
                break;
            }

            n >>= 1;
        }
    }

    return isPowerOfTwo;
}