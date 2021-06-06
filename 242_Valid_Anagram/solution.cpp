#include "header.h"

bool isAnagram(string s, string t) {

    if (s.length() != t.length())
    {
        return false;
    }

    vector<int> letters_1(26, 0);
    vector<int> letters_2(26, 0);

    for (int i = 0; i < s.length(); i++)
    {
        letters_1[s[i] - 'a'] += 1;
        letters_2[t[i] - 'a'] += 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (letters_1[i] != letters_2[i])
        {
            return false;
        }
    }

    return true;
}