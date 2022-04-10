#include "header.h"


TreeNode* findAncestor(TreeNode* node, TreeNode* small, TreeNode* large);

TreeNode* lowestCommonAncestor_r(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (p->val > q->val)
    {
        return findAncestor(root, q, p);
    }
    else
    {
        return findAncestor(root, p, q);
    }
}

TreeNode* findAncestor(TreeNode* node, TreeNode* small, TreeNode* large)
{
    if (node->val >= small->val && node->val <= large->val)
    {
        return node;
    }
    else if (node->val > large->val)
    {
        return findAncestor(node->left, small, large);
    }
    else// if (node->val < small->val)
    {
        return findAncestor(node->right, small, large);
    }

}