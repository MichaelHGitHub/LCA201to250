#include "header.h"

static vector<int> helper(vector<int>& opds, int opd_i, vector<char>& oprs, int opr_i);

static int calculate(int a, int b, char opr);

vector<int> diffWaysToCompute0(string expression)
{
    vector<int> opds;
    vector<char> oprs;

    int i = 0;
    while (i < expression.length())
    {
        int pos = expression.find_first_of("+-*", i);

        if (pos != expression.npos)
        {
            opds.push_back(atoi(expression.substr(i, pos - i + 1).c_str()));
            oprs.push_back(expression[pos]);
            i = pos + 1;
        }
        else
        {
            opds.push_back(atoi(expression.substr(i, expression.length() - i).c_str()));
            break;
        }
    }

    return helper(opds, 0, oprs, 0);
}

vector<int> helper(vector<int>& opds, int opd_i, vector<char>& oprs, int opr_i)
{
    vector<int> result;

    if (opd_i == opds.size() - 1)
    {
        cout << opds[opd_i] << endl;
        result.push_back(opds[opd_i]);
        return result;
    }
    else if (opd_i == opds.size())
    {
        return result;
    }

    char pre_opr = '+';
    int sum = 0;

    int i = opd_i;
    int j = opr_i;
    while (i < opds.size())
    {
        if (i != opd_i)
        {
            cout << sum << pre_opr<< opds[i] << endl;
        }
        else
        {
            cout << opds[i] << endl;
        }

        sum = calculate(sum, opds[i], pre_opr);
        if (j < oprs.size())
        {
            pre_opr = oprs[j];
            vector<int> sub_result = helper(opds, i + 1, oprs, j + 1);

            for (int num : sub_result)
            {
                result.push_back(calculate(sum, num, pre_opr));
            }
        }

        ++i;
        ++j;
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