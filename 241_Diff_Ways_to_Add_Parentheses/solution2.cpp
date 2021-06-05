#include "header.h"

static int calculate(int a, int b, char opr);

vector<int> diffWaysToCompute(string expression)
{
    vector<int> result;
    
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '+' ||
            expression[i] == '-' ||
            expression[i] == '*')
        {
            vector<int> res1 = diffWaysToCompute(expression.substr(0, i));
            vector<int> res2 = diffWaysToCompute(expression.substr(i + 1, expression.length() - i - 1));

            for (int j = 0; j < res1.size(); j++)
            {
                for (int k = 0; k < res2.size(); k++)
                {
                    result.push_back(calculate(res1[j], res2[k], expression[i]));
                }
            }
        }
    }

    if (!result.size())
    {
        result.push_back(atoi(expression.c_str()));
    }

    return result;
}

int calculate(int a, int b, char opr)
{
    switch (opr)
    {
    case '+':
        return a + b;
        break;

    case '-':
        return a - b;
        break;

    case '*':
        return a * b;
        break;

    default:
        break;
    }

    return -1;
}