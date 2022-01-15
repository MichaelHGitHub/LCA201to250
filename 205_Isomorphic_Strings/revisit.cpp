#include "header.h"

bool isIsomorphic_r(string s, string t)
{
    bool result = true;

    if (s.length() == t.length())
    {
        vector<bool> visited(s.length(), false);

        for (int i = 0; i < s.length(); i++)
        {
            if (visited[i])
            {
                continue;
            }

            visited[i] = true;
            for (int j = i + 1; j < s.length(); j++)
            {
                if (s[i] == s[j])
                {
                    visited[j] = true;
                    if (t[i] != t[j])
                    {
                        result = false;
                        break;
                    }
                }
                else
                {
                    if (t[i] == t[j])
                    {
                        result = false;
                        break;
                    }
                }
            }

            if (!result)
            {
                break;
            }
        }
    }
    return result;
}