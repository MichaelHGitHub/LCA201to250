#include "header.h"

bool isAnagram_r(string s, string t)
{
    bool result = false;

    if (s.length() == t.length())
    {
        int occurence[26] = { 0 };

        for (int i = 0; i < s.length(); i++)
        {
            ++occurence[s[i] - 'a'];
            --occurence[t[i] - 'a'];
        }

        result = true;
        for (int i = 0; i < 26; i++)
        {
            if (occurence[i] != 0)
            {
                result = false;
                break;
            }
        }
    }
    return result;
}