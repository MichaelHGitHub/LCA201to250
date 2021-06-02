#include <unordered_map>
#include "header.h"

// Given a tree node in BTS, if node->val is between [p->val, q->val],
// the node is LCA, otherwise search in left(when node->val > max(p->val, q->val)
// or right(when node->val > max(p->val, q->val) sub-tree;
// Recursive:

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (!root)
    {
        return nullptr;
    }

    if (root->val <= max(p->val, q->val) && root->val >= min(p->val, q->val))
    {
        return root;
    }
    else if (root->val > max(p->val, q->val))
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    else
    {
        return lowestCommonAncestor(root->right, p, q);
    }
}
