#pragma once

#include "..\common\common.h"

// Struct Trie and TrieNode 
// Trie is a rooted tree.Its nodes have the following fields :
//   Maximum of R links to its children, where each link corresponds to one of R character values from dataset alphabet.In this article we assume that RR is 26, the number of lowercase latin letters.
//   Boolean field which specifies whether the node corresponds to the end of the key, or is just a key prefix.

class TrieNode
{
public:
    TrieNode()
    {};

    void insert(char c, TrieNode* node)
    {
        links[c - 'a'] = node;
    }

    TrieNode* find(char c)
    {
        return links[c - 'a'];
    }

    bool IsEnd()
    {
        return isEnd;
    }

    void SetEnd()
    {
        isEnd = true;
    }

private:
    TrieNode* links[26] = {};
    bool isEnd = false;
};

class Trie
{
public:
    Trie()
        :root(new TrieNode())
    {

    }

    void insert(string word)
    {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++)
        {
            TrieNode* new_node = node->find(word[i]);
            if (new_node)
            {
                node = new_node;
            }
            else
            {
                new_node = new TrieNode();
                node->insert(word[i], new_node);
                node = new_node;
            }
        }
        node->SetEnd();
    }

    bool search(string word)
    {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++)
        {
            TrieNode* new_node = node->find(word[i]);
            if (new_node)
            {
                node = new_node;
            }
            else
            {
                return false;
            }
        }

        return node->IsEnd();
    }

    bool startsWith(string prefix)
    {
        TrieNode* node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            TrieNode* new_node = node->find(prefix[i]);
            if (new_node)
            {
                node = new_node;
            }
            else
            {
                return false;
            }
        }

        return true;
    }

private:
    TrieNode* root;
};