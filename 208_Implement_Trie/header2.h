#pragma once

#include <unordered_set>
#include <algorithm>

#include "../common/common.h"

class Trie {
public:
    /** Initialize your data structure here. */
    Trie()
        :root(nullptr)
    {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        if (root == nullptr)
        {
            root = new TreeNode(word);
        }
        else
        {
            TreeNode* node = root;
            while (node)
            {
                if (node->val == word)
                {
                    return;
                }
                else if (node->val > word)
                {
                    if (!node->left)
                    {
                        node->left = new TreeNode(word);
                        return;
                    }
                    else
                    {
                        node = node->left;
                    }
                }
                else
                {
                    if (!node->right)
                    {
                        node->right = new TreeNode(word);
                        return;
                    }
                    else
                    {
                        node = node->right;
                    }
                }
            }
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (!root)
        {
            return false;
        }

        TreeNode* node = root;
        while (node)
        {
            if (node->val == word)
            {
                return true;
            }
            else if (node->val > word)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }

        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (!root)
        {
            return false;
        }

        TreeNode* node = root;
        while (node)
        {
            if (node->val.length() < prefix.length())
            {
                node = node->right;
                continue;
            }

            if (node->val.substr(0, prefix.length()) == prefix)
            {
                return true;
            }
            else if (node->val.substr(0, prefix.length()) > prefix)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }

        return false;
    }

private:
    struct TreeNode
    {
        string val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(string word):
            left(nullptr),
            right(nullptr)
        {
            val = word;
        }
    };

    TreeNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
