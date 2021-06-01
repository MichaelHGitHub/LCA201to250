#include "header.h"

bool isPowerOfTwo2(int n) {

    int pow = 1;
    while (n > 1)
    {
        if (n % 2)
        {
            return false;
        }
        else
        {
            if (pow == n)
            {
                return true;
            }
            else if (pow > n)
            {
                if (pow % n)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            else
            {
                pow = pow << 1;
                n = n >> 1;
            }
        }

    }

    return n == 1;
}