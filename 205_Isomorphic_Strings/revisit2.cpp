#include "header.h"
#include <unordered_map>

bool isIsomorphic_r2(string s, string t)
{
    bool result = true;

    if (s.length() == t.length())
    {
        std::unordered_map<char, int> visited_s;
        std::unordered_map<char, int> visited_t;

        for(int i = 0; i < s.length(); i++)
        {
            int pos_s = visited_s.find(s[i]) != visited_s.end() ? visited_s[s[i]] : visited_s[s[i]] = i;
            int pos_t = visited_t.find(t[i]) != visited_t.end() ? visited_t[t[i]] : visited_t[t[i]] = i;
            
            if (pos_s != pos_t)
            {
                result = false;
                break;
            }
        }
    }
    return result;
}