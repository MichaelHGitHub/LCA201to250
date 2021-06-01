#include <stack>
#include <unordered_set>
#include "header.h"

static int helper(TreeNode* root, int target, int& pos);

int kthSmallest2(TreeNode* root, int k)
{
    int result = -1;

    if (!root)
    {
        return result;
    }

    int pos = 0;
    stack<TreeNode*> pending;

    while (true)
    {
        if (root)
        {
            pending.push(root);
            root = root->left;
        }
        else if(!pending.empty())
        {
            TreeNode* node = pending.top();
            pending.pop();

            if (++pos == k)
            {
                result = node->val;
                break;
            }

            if (node->right)
            {
                root = node->right;
            }
        }
        else
        {
            break;
        }
    }
    return result;
}

