#pragma once

#include "..\common\common.h"

// Use Trie(Prefix Tree)
// Only tricky part is accommedate '.';

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() :
        root(new TrieNode())
    {

    }

    void addWord(string word) {

        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->links[word[i] - 'a'])
            {
                node->links[word[i] - 'a'] = new TrieNode();
            }
            node = node->links[word[i] - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        return searchHelper(root, word, 0);
    }

private:
    struct TrieNode
    {
        TrieNode* links[26];
        bool isEnd;
        TrieNode() :
            isEnd(false)
        {
            memset(links, 0, 26 * sizeof(TrieNode*));
        }
    };

    bool searchHelper(TrieNode* node, string& word, int start)
    {
        // If word ends, node must be true to return true, otherwise
        // return false, meaning word is too short.
        if (start == word.length() && node)
        {
            return node->isEnd;
        }

        if (word[start] != '.')
        {
            if (!node->links[word[start] - 'a'])
            {
                return false;
            }
            else
            {
                if (!searchHelper(node->links[word[start] - 'a'], word, start + 1))
                {
                    return false;
                }
            }
        }
        else
        {
            // If the current char is '.', need to try all possibility,
            // if one matches, it's good.
            int j = 0;
            for (; j < 26; j++)
            {
                if (node->links[j])
                {
                    if (searchHelper(node->links[j], word, start + 1))
                    {
                        break;
                    }
                }
            }

            if (j == 26)
            {
                return false;
            }
        }
        return true;
    }

    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
