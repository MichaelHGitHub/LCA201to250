

bool isPowerOfTwo(int n) {

    while (n > 1)
    {
        if (n % 2)
        {
            return false;
        }
        else
        {
            n = n >> 1;
        }

    }

    return n == 1;
}