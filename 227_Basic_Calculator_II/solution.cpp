#include <stack>
#include "header.h"

static int cal2Nums(int a, int b, char opr);

// Divid the calculations into difference phases, whenever encounter a "(" or a higher 
// priority operator, the current phase has to be suspended and saved and start calculating
// next phase. When the calculation of a phase is done, try to clear the previous 
// pending results and previous pending operators.
// The result of the current phase is tracked using a variable, say "res".
// The current pending operator is tracked using a variable, say "opr".
// The suspended results are saved in a stack, say pending_res.
// The suspended operatiors are saved in a stack, say pending_oprs.

int calculate(string s)
{
    stack<int> pending_res;
    stack<char> pending_oprs;
    char opr = 'N';

    int opd = 0;
    int res = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            opd = opd * 10 + (s[i] - '0');
        }
        else
        {
            switch (s[i])
            {
            case '+':
            case '-':
                if (opr == 'N')
                {
                    // First ocurrence of operator
                    res = opd;
                    opr = s[i];
                    opd = 0;
                }
                else if (opr == ')')
                {
                    // First ocurrence after a ")", don't change res;
                    opr = s[i];
                    opd = 0;
                }
                else
                {
                    // Calculate the result of res and current pending operand using current pending operator
                    res = cal2Nums(res, opd, opr);
                    // If there is any pending results and operators, calculate and clean them.
                    // This is to keep res as up-to-date as possible to avoid wrong priority of
                    // oeration later.
                    while (!pending_res.empty() && !pending_oprs.empty())
                    {
                        res = cal2Nums(pending_res.top(), res, pending_oprs.top());
                        pending_res.pop();
                        pending_oprs.pop();
                    }
                    opr = s[i];
                    opd = 0;
                }
                break;

            case '*':
            case '/':
                if (opr == 'N')
                {
                    res = opd;
                    opr = s[i];
                    opd = 0;
                }
                else if (opr == ')')
                {
                    opr = s[i];
                    opd = 0;
                }
                else if (opr == '+' || opr == '-')
                {
                    // if current pending opr is lower priority, save the result and start over.
                    // but opd is useful in this case.
                    pending_res.push(res);
                    pending_oprs.push(opr);
                    res = opd;
                    opr = s[i];
                    opd = 0;
                }
                else
                {
                    res = cal2Nums(res, opd, opr);
                    opr = s[i];
                    opd = 0;
                }
                break;

            case '(':
                // Save the result and start over. opd is also need to be rebuilt.
                pending_res.push(res);
                res = 0;
                pending_oprs.push(opr);
                opr = 'N';
                opd = 0;
                break;

            case ')':
                res = cal2Nums(res, opd, opr);
                opr = ')';
                opd = 0;
                while (!pending_res.empty() && !pending_oprs.empty())
                {
                    res = cal2Nums(pending_res.top(), res, pending_oprs.top());
                    pending_res.pop();
                    pending_oprs.pop();
                }
                break;

            default:
                break;
            }
        }
    }

    // Need to handle the last calculation, which is not done in the loop.
    if (opr == 'N')
    {
        res = opd;
    }
    else if (opr != ')')
    {
        res = cal2Nums(res, opd, opr);
    }

    // Clean the pending operands and operators if there are any
    while (!pending_res.empty() && !pending_oprs.empty())
    {
        res = cal2Nums(pending_res.top(), res, pending_oprs.top());
        pending_res.pop();
        pending_oprs.pop();
    }

    return res;
}

int cal2Nums(int a, int b, char opr)
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
    case '/':
        return a / b;
        break;
    default:
        return -1;
        break;
    }
}