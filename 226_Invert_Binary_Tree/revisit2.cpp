#include "header.h"
#include <stack>

TreeNode* invertTree_r2(TreeNode* root)
{
    if (root != nullptr)
    {
        std::stack<TreeNode*> pending;
        pending.push(root);

        while (!pending.empty())
        {
            TreeNode* node = pending.top();
            pending.pop();

            TreeNode* temp = node->left;
            node->left = node->right;
            node -> right = temp;

            if (node->right != nullptr)
            {
                pending.push(node->right);
            }

            if (node->left != nullptr)
            {
                pending.push(node->left);
            }
        }
    }

    return root;
}