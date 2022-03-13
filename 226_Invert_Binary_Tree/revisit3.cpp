#include "header.h"
#include <queue>

TreeNode* invertTree_r3(TreeNode* root)
{
    if (root != nullptr)
    {
        std::queue<TreeNode*> pending;
        pending.push(root);

        while (!pending.empty())
        {
            TreeNode* node = pending.front();
            pending.pop();

            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;

            if (node->left != nullptr)
            {
                pending.push(node->left);
            }

            if (node->right != nullptr)
            {
                pending.push(node->right);
            }
       }
    }

    return root;
}