#include <stack>
#include "header.h"

TreeNode* invertTree(TreeNode* root) {

    stack<TreeNode*> pending;

    if (root)
    {
        pending.push(root);
    }

    while (!pending.empty())
    {
        TreeNode* node = pending.top();
        pending.pop();

        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;

        if (node->right)
        {
            pending.push(node->right);
        }

        if (node->left)
        {
            pending.push(node->left);
        }
    }

    return root;
}
