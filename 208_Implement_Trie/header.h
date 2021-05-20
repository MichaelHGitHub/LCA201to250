#pragma once

#include <unordered_set>
#include <algorithm>

#include "../common/common.h"

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        data.insert(word);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return data.find(word) != data.end();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        unordered_set<string> target({ prefix });
        return (std::search(data.begin(), data.end(), target.begin(), target.end(),
            [](string s1, string s2) {
            if (s1.length() < s2.length())
            {
                return false;
            }

            if (s1.substr(0, s2.length()) == s2)
            {
                return true;
            }
            else
            {
                return false;
            }

            }) != data.end());

    }

private:
    unordered_set<string> data;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
