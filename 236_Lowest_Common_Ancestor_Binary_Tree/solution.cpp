#include "header.h"

static TreeNode* helper(TreeNode* root, bool& bp, bool& bq, TreeNode* p, TreeNode* q);

// post order traversal,
// A node is an ancestor of p(q) if its left or right sub-tree has p(q) or 
// the node itself is p(q).
//  return at the first occurrence where a node is the ancestor of both p and q.
// Recursive:

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    bool bp = false, bq = false;
    return helper(root, bp, bq, p, q);
}

TreeNode* helper(TreeNode* root, bool& bp, bool& bq, TreeNode* p, TreeNode* q)
{
    if (!root)
    {
        return nullptr;
    }

    bool cbp = false, cbq = false;
    TreeNode* lca = helper(root->left, cbp, cbq, p, q);
    if (lca)
    {
        return lca;
    }
    if (cbp || root->val == p->val)
    {
        bp = true;
    }
    if (cbq || root->val == q->val)
    {
        bq = true;
    }

    cbp = false, cbq = false;
    lca = helper(root->right, cbp, cbq, p, q);
    if (lca)
    {
        return lca;
    }
    if (cbp || root->val == p->val)
    {
        bp = true;
    }
    if (cbq || root->val == q->val)
    {
        bq = true;
    }

    if (bp && bq)
    {
        return root;
    }
    else
    {
        return nullptr;
    }
}