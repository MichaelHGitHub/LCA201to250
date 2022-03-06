#include "header.h"
#include <stack>


static int evaluate(int opd1, int opd2, char opr);
static bool IsNagetiveSign(string& s, int pos);

int calculate_r(string s)
{
    std::stack<int> operands;
    std::stack<char>operators;
    size_t left = 0;
    size_t right = s.length();

    do
    {
        string sub;
        right = s.length();

        // Get operand
        if (left < s.length())
        {
             right = s.find_first_of("+-()", left);

             // If it is the last phase
            if (right == s.npos)
            {
                right = s.length();
            }
            sub = s.substr(left, right - left);
            left = right + 1;

            // If the sub string is all blank
            if (sub.find_last_not_of(' ') == sub.npos)
            {
                sub = "";
            }
            // Add operand to stack
            if (sub.length() > 0)
            {
                operands.push(stoi(sub));
            }
        }

        // If encount a '(', no calculation needed for this round
        if (right < s.length() && s[right] == '(')
        {
            operators.push(s[right]);
            continue;
        }

        // Calculate the temp result
        if (operands.size() > 1 && operators.size() > 0 && operators.top() != '(')
        {
            int opd2 = operands.top();
            operands.pop();
            int opd1 = operands.top();
            operands.pop();

            operands.push(evaluate(opd1, opd2, operators.top()));
            operators.pop();
        }

        // Add the next operator
        if (right != s.length())
        {
            if (s[right] == ')')
            {
                operators.pop();
            }
            else
            {
                // If found nagetive sign, Add a 0 to minus the following number to turn it to
                // nagetive.
                if(sub.length() == 0 && IsNagetiveSign(s, right))
                {
                    operands.push(0);
                }
                operators.push(s[right]);
            }
        }
    } while (operands.empty() > 1 || operators.size() > 0 || left < s.length());

    return operands.top();
}

int evaluate(int opd1, int opd2, char opr)
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

    default:
        break;
    }

    return result;
}

bool IsNagetiveSign(string& s, int pos)
{
    bool result = false;

    if (pos < s.length())
    {
        if (s[pos] == '-')
        {
            if (pos == 0 || s[pos - 1] == '(')
            {
                result = true;
            }
            else if(s[pos - 1] == ' ')
            {
                int i = pos - 1;
                while (i >= 0 && s[i] == ' ')
                {
                    --i;
                }

                if (i >= 0 && s[i] == '(')
                {
                    result = true;
                }
            }
        }
    }
    return result;
}
