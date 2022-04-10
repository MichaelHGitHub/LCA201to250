#include "header.h"

static TreeNode* findAncestor(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode** ancestor);

TreeNode* lowestCommonAncestor_r2(TreeNode* root, TreeNode* p, TreeNode* q)
{
    TreeNode* ancestor = nullptr;

    findAncestor(root, p, q, &ancestor);

    return ancestor;
}

TreeNode* findAncestor(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode** ancestor)
{
    TreeNode* node = nullptr;

    if (ancestor != nullptr && *ancestor == nullptr && root != nullptr)
    {
        TreeNode* left = nullptr, * right = nullptr;

        left = findAncestor(root->left, p, q, ancestor);
        right = findAncestor(root->right, p, q, ancestor);

        if (*ancestor == nullptr)
        {
            if (left != nullptr && right != nullptr)
            {
                *ancestor = root;
            }
            else if (left != nullptr || right != nullptr)
            {
                if (root->val == p->val || root->val == q->val)
                {
                    *ancestor = root;
                }
                else
                {
                    node = (left != nullptr ? left : right);
                }
            }
            else
            {
                if (root->val == p->val || root->val == q->val)
                {
                    node = root;
                }
            }
        }
    }

    return node;
}