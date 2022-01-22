#pragma once 
#include "..\common\common.h"

class Trie {

    struct Marker
    {
        int flag; // 1 means a word completes here, otherwise 0;
        Marker* next; // non-null if the letter exists, otherwise null.
    };

public:
    Trie() {
        marks = new Marker[26];
        memset(marks, 0, sizeof(Marker) * 26);
    }

    void insert(string word) {

        Marker* letters = marks;

        for (int i = 0; i < word.length(); i++)
        {
            if (!letters[word[i] - 'a'].next)
            {
                letters[word[i] - 'a'].next = new Marker[26];
                memset(letters[word[i] - 'a'].next, 0, sizeof(Marker) * 26);
            }

            if (i == word.length() - 1)
            {
                letters[word[i] - 'a'].flag = 1;
            }

            letters = (Marker*)(letters[word[i] - 'a'].next);
        }
    }

    bool search(string word) {

        Marker* letters = marks;

        for (int i = 0; i < word.length(); i++)
        {
            if (!letters[word[i] - 'a'].next)
            {
                return false;
            }

            if (i == word.length() - 1 && 0 == letters[word[i] - 'a'].flag)
            {
                return false;
            }
            letters = (Marker*)(letters[word[i] - 'a'].next);
        }

        return true;
    }

    bool startsWith(string prefix) {

        Marker* letters = marks;

        for (int i = 0; i < prefix.length(); i++)
        {
            if (!letters[prefix[i] - 'a'].next)
            {
                return false;
            }
            letters = (Marker*)(letters[prefix[i] - 'a'].next);
        }

        return true;
    }

private:
    Marker* marks;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */