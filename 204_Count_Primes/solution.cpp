#include "header.h"

// We mark the numbers from 2 to n-1 if they are not prime number.
// Start from 2: 2*2, 2*3,...2*(2+k)
//            3: 3*3, 3*4,...3*(3+l)(3*2 is covered above.)
//            4: 4*4, 4*5,...4*(4+m)(4*2, 4*3, are coveredabove.)
// Calculation goes on util i*i < n.
// The remaining numbers in the table are primes.

int countPrimes(int n)
{
    vector<bool> primes(n, true);
    for (int i = 2; i * i < n; i++)
    {
        if (!primes[i])
        {
            continue;
        }

        for (int j = i, product = 0; (product = i * j) < n; j++)
        {
            primes[product] = false;
        }
    }

    int result = 0;
    for (int i = 2; i < n; i++)
    {
        if (primes[i])
        {
            ++result;
        }
    }
    return result;
}