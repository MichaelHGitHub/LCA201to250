#include "header.h"
#include <unordered_set>

bool isHappy_r(int n)
{
    std::unordered_set<int> visited;

    int num1 = n;
    int num2 = 0;

    while (visited.find(num1) == visited.end() && num1 != 1)
    {
        visited.insert(num1);
        while (num1 > 0)
        {
            int root = num1 % 10;
            num2 += root * root;
            num1 /= 10;
        }
        num1 = num2;
        num2 = 0;
    }
    return num1 == 1;
}