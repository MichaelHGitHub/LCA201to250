#include "header.h"

static TreeNode* findKthNode(TreeNode* root, int k, int& index);

int kthSmallest_r(TreeNode* root, int k)
{
    int index = 1;
    TreeNode* node = findKthNode(root, k, index);

    if (node != nullptr)
    {
        return node->val;
    }
    else
    {
        return INT32_MIN;
    }
}

TreeNode* findKthNode(TreeNode* root, int k, int& index)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    TreeNode* node = nullptr;

    if (nullptr != (node = findKthNode(root->left, k, index)))
    {
        return node;
    }

    if (index == k)
    {
        return root;
    }
    ++index;

    if (nullptr != (node = findKthNode(root->right, k, index)))
    {
        return node;
    }

    return nullptr;
}