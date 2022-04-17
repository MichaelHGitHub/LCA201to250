#include "header.h"

static int calculate(int opd1, int opd2, char opr);

vector<int> diffWaysToCompute_r(string expression)
{
    vector<int> result;
    size_t pos = expression.find_first_of("+-*");

    if (pos == string::npos)
    {
        result.push_back(atoi(expression.c_str()));
    }
    else
    {
        do
        {
            vector<int> res1 = diffWaysToCompute_r(expression.substr(0, pos));
            vector<int> res2 = diffWaysToCompute_r(expression.substr(pos + 1));

            for (int i = 0; i < res1.size(); i++)
            {
                for (int j = 0; j < res2.size(); j++)
                {
                    result.push_back(calculate(res1[i], res2[j], expression[pos]));
                }
            }
        } while (string::npos != (pos = expression.find_first_of("+-*", pos + 1)));
    }

    return result;
}

int calculate(int opd1, int opd2, char opr)
{
    int result = 0;

    switch (opr)
    {
    case '+':
        result = opd1 + opd2;
        break;
    case '-':
        result = opd1 - opd2;
        break;
    case '*':
        result = opd1 * opd2;
        break;
    }

    return result;
}
