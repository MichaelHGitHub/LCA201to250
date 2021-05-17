#include <map>
#include "header.h"

// It's all about finding the repetition pattern. Store each char's first 
// occurrence index in arrays, then compare the two resulting arrays to see if 
// the patterns are exactly the same.
// Use two maps to help remember the first occurrence of each char.

bool isIsomorphic(string s, string t)
{
    map<char, int> m1, m2;
    vector<int> pattern1(s.length(), 0), pattern2(t.length(), 0);

    for (int i = 0; i < s.length(); i++)
    {
        if (m1.find(s[i]) == m1.end())
        {
            m1[s[i]] = i;
            pattern1[i] = i;
        }
        else
        {
            pattern1[i] = m1[s[i]];
        }
    }

    for (int j = 0; j < t.length(); j++)
    {
        if (m2.find(t[j]) == m2.end())
        {
            m2[t[j]] = j;
            pattern2[j] = j;
        }
        else
        {
            pattern2[j] = m2[t[j]];
        }
    }

    return (pattern1 == pattern2);
}
