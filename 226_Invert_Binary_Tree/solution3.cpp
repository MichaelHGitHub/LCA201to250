#include "header.h"
static void helper(TreeNode* node);


TreeNode* invertTree3(TreeNode* root) {
    helper(root);
    return root;
}

void helper(TreeNode* node)
{
    if (!node)
    {
        return;
    }

    TreeNode* temp = node->left;
    node->left = node->right;
    node->right = temp;

    helper(node->left);
    helper(node->right);
}