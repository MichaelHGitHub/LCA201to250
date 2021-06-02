#include "header.h"

// Given a tree node in BTS, if node->val is between [p->val, q->val],
// the node is LCA, otherwise search in left(when node->val > max(p->val, q->val)
// or right(when node->val > max(p->val, q->val) sub-tree;
// Iterative

TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q)
{
    while (root)
    {
        if (root->val <= max(p->val, q->val) && root->val >= min(p->val, q->val))
        {
            return root;
        }
        else if (root->val > max(p->val, q->val))
        {
            root = root ->left;
        }
        else
        {
            root = root->right;
        }
    }
    return nullptr;
}
