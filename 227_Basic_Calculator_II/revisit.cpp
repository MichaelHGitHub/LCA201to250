#include "header.h"
#include <stack>

static int math(int a, int b, char opr);

int calculate_r(string s)
{
    int start = 0;
    int end = 0;
    std::stack<int> opds;
    std::stack<char> oprs;

    do
    {
        string cur_opd;
        char next_opr = ' ';

        // First get the current operand and next operator
        if (start < s.length())
        {
            end = s.find_first_of("+-/*()", start);
            end = (end != s.npos ? end : s.length());

            cur_opd = s.substr(start, end - start);
            next_opr = end < s.length() ? s[end] : ' ';
        }

        // If the opd is valid, push it to the stack
        if (cur_opd.find_first_not_of(' ') != s.npos)
        {
            opds.push(atoi(cur_opd.c_str()));
        }
        start = end + 1;

        // Calculate intermidiate results on the stack
        while (opds.size() > 1 && oprs.size() > 0)
        {
            // if a '(' appears on the top of stack, should give higer priority
            // to next new phase
            if (oprs.top() == '(')
            {
                break;
            }

            // If next opr has higher priority, stack the low priority opers and give 
            // priority to next new phase
            if ((next_opr == '*' || next_opr == '/') &&
                (oprs.top() == '+' || oprs.top() == '-'))
            {
                break;
            }

            int opd2 = opds.top();
            opds.pop();
            int opd1 = opds.top();
            opds.pop();
            char opr = oprs.top();
            oprs.pop();

            opds.push(math(opd1, opd2, opr));
        }

        // Handle the next operator
        if (next_opr == ')')
        {
            oprs.pop();
        }
        else if (next_opr != ' ')
        {
            oprs.push(next_opr);
        }
    } while (start < s.length() || !oprs.empty());

    return opds.top();
}


int math(int a, int b, char opr)
{
    int val = 0;
    switch (opr)
    {
    case '+':
        val = a + b;
        break;
    case '-':
        val = a - b;
        break;
    case '*':
        val = a * b;
        break;
    case '/':
        val = a / b;
        break;
    default:
        break;
    }
    return val;
}