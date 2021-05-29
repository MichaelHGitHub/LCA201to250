#include <stack>
#include "header.h"

// Intuitive solution.
// Use a stack to save temp value and operators

int calculate(string s)
{
    vector<string> expression;
    size_t start = 0;
    size_t pos = 0;
    string opd_s = "";

    // extract usable elements from the string
    while (start < s.length())
    {
        pos = s.find_first_of("+- ()", start);
        // Find a symbol
        if (pos == s.npos)
        {
            expression.push_back(s.substr (start, s.length() - start));
            break;
        }
        // Find a number plus a symbol, add the number part
        if (start < pos)
        {
            opd_s = s.substr(start, pos - start);
            expression.push_back(opd_s);
        }
        // Add the symbol part
        if (s[pos] != ' ')
        {
            expression.push_back(s.substr(pos, 1));
        }
        start = pos + 1;
    }

    stack<string> pending;

    opd_s = "";
    int opd_i = 0;
    int i = 0;

    while (opd_s.length() || i < expression.size())
    {
        if (opd_s.length())
        {
            // opd still has value, the calculation is not done yet. pop operator 
            // and operand from the stack to calculate.
            if (!pending.empty() && pending.top() == "+")
            {
                pending.pop();
                opd_i = atoi(pending.top().c_str()) + atoi(opd_s.c_str());
                pending.pop();
                opd_s = to_string(opd_i);
            }
            else if (!pending.empty() && pending.top() == "-")
            {
                pending.pop();
                opd_i = atoi(pending.top().c_str()) - atoi(opd_s.c_str());
                pending.pop();
                opd_s = to_string(opd_i);
            }
            else
            {
                // The top of stack is not number, the phase of calculation is done.
                // push the temp value to stack.
                if (opd_s != "")
                {
                    pending.push(opd_s);
                }
                else
                {
                    pending.push(to_string(opd_i));
                }
                opd_s = "";
                opd_i = 0;
            }
        }
        else
        {
            // opd has no value means the phase of calculation is done, move to 
            // next element in the expression.
            opd_s = expression[i++];
            if (opd_s == "+")
            {
                // If the top of the pending is not a number, ignore "+"
                if (!pending.empty() && pending.top() != "-" && pending.top() != "+" && pending.top() != "(")
                {
                    pending.push("+");
                }
                opd_s = "";
            }
            else if(opd_s == "-")
            {
                // If the top of the pending is not a number, add "0-" to the stack
                if (pending.empty() || pending.top() == "-" || pending.top() == "+" || pending.top() == "(")
                {
                    pending.push("0");
                }
                pending.push("-");
                opd_s = "";
            }
            else if (opd_s == "(")
            {
                pending.push("(");
                opd_s = "";
            }
            else if (opd_s == ")")
            {
                // Up to this point, the top 2 elements in stack must be:
                // number + "(".
                opd_s = pending.top();
                opd_i = atoi(opd_s.c_str());
                pending.pop();
                pending.pop();
            }
            else
            {
                // Populate the value to calculate in next iteration.
                opd_i = atoi(opd_s.c_str());
            }
        }
    }

    return (atoi(pending.top().c_str()));
}