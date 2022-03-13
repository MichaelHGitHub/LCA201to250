#include "header.h"

TreeNode* invertTree_r(TreeNode* root)
{
    if (root != nullptr)
    {
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        root->left = right;
        root->right = left;
    }

    return root;
}