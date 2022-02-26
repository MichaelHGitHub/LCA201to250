#include "header.h"

static int Depth(TreeNode* root);

int countNodes_r(TreeNode* root)
{
    int number = 0;

    if (root != nullptr)
    {
        int left_depth = Depth(root->left);
        int right_depth = Depth(root->right);

        if (left_depth == right_depth)
        {
            number =  (1 << left_depth) + countNodes_r(root->right);
        }
        else
        {
            number = countNodes_r(root->left) + (1 << right_depth);
        }
    }
    return number;
}


int Depth(TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + Depth(root->left);
}