#include "header.h"

static int height(TreeNode* root);

// The number of a perfect tree is 2^h - 1, 
// Find out height of left and right sub tree, hl and hr, 
// if hl==hr, left is perfect, if not, right subtree is perfect.

int countNodes(TreeNode* root)
{
    if (!root)
    {
        return 0;
    }

    int hl = height(root->left);
    int hr = height(root->right);

    if (hl == hr)
    {
        // Left sub tree is perfect, its number:
        // 2^hl - 1 + 1(root), which is 1 << hl.
        return (1 << hl) + countNodes(root->right);
    }
    else
    {
        return countNodes(root->left) + (1 << hr);
    }
}

static int height(TreeNode* root)
{
    int height = 0;
    while (root)
    {
        ++height;
        root = root->left;
    }

    return height;
}