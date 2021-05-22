#pragma once

#include "..\common\common.h"

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary():
    root(nullptr)
    {

    }

    void addWord(string word) {
        if (!root)
        {
            root = new TreeNode(word);
        }

        TreeNode* node = root;
        while (node)
        {
            if (node->val == word)
            {
                break;
            }
            else if (node->val > word)
            {
                if (node->left)
                {
                    node = node->left;
                }
                else
                {
                    node->left = new TreeNode(word);
                    break;
                }
            }
            else
            {
                if (node->right)
                {
                    node = node->right;
                }
                else
                {
                    node->right = new TreeNode(word);
                    break;
                }
            }
        }
    }

    bool search(string word) {
        TreeNode* node = root;
        while (node)
        {
            int res = compareWords(node->val, word);
            if (res == 0)
            {
                return true;
            }
            else if(res > 0)
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

    int compareWords(string& s1, string& s2)
    {
        
        for (int i = 0; i < min(s1.length(), s2.length()); i++)
        {
            if (s2[i] == '.' || s1[i] == s2[i])
            {
                continue;
            }
            else if (s1[i] > s2[i])
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }

        if (s1.length() == s2.length())
        {
            return 0;
        }
        else 
        {
            return s1.length() > s2.length() ? 1 : -1;
        }
    }

    struct TreeNode
    {
        string val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(string word):
            val(word),
            left(nullptr),
            right(nullptr)
        {
        }
    };

    TreeNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
