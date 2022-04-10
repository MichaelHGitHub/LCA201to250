#include "header.h"

TreeNode* lowestCommonAncestor_r2(TreeNode* root, TreeNode* p, TreeNode* q)
{
    TreeNode* candidate = root;
    TreeNode* small = (p->val < q->val) ? p : q;
    TreeNode* large = (p->val < q->val) ? q : p;

    while (candidate != nullptr)
    {
        if (candidate->val >= small->val && candidate->val <= large->val)
        {
            break;
        }
        else if (candidate->val > large->val)
        {
            candidate = candidate->left;
        }
        else
        {
            candidate = candidate->right;
        }
    }

    return candidate;
}