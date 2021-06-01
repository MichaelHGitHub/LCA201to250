#include "header.h"

static int helper(TreeNode* root, int target, int& pos);

int kthSmallest(TreeNode* root, int k)
{
    int pos = 0;
    return helper(root, k, pos);
}

int helper(TreeNode* root, int target, int& pos)
{
    if (!root)
    {
        return -1;
    }

    int val = helper(root->left, target, pos);
    if (val != -1)
    {
        return val;
    }

    if (++pos == target)
    {
        return root->val;
    }

    val = helper(root->right, target, pos);
    if (val != -1)
    {
        return val;
    }

    return -1;
}