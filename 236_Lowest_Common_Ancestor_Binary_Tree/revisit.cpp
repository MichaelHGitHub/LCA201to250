#include "header.h"

static TreeNode* findNode(TreeNode* root, TreeNode* p, TreeNode* q);

TreeNode* lowestCommonAncestor_r(TreeNode* root, TreeNode* p, TreeNode* q)
{
    TreeNode* candidate = nullptr;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    if (root != nullptr)
    {
        if (root->val == p->val || root->val == q->val)
        {
            left = findNode(root->left, p, q);
            if (left == nullptr)
            {
                right = findNode(root->right, p, q);
            }

            if (left != nullptr || right != nullptr)
            {
                candidate = root;
            }
        }
        else
        {
            left = findNode(root->left, p, q);
            right = findNode(root->right, p, q);

            if (left != nullptr && right != nullptr)
            {
                candidate = root;
            }
            else if (left == nullptr)
            {
                candidate = lowestCommonAncestor(root->right, p, q);
            }
            else
            {
                candidate = lowestCommonAncestor(root->left, p, q);
            }
        }
    }

    return candidate;
}

TreeNode* findNode(TreeNode* root, TreeNode* p, TreeNode* q)
{
    TreeNode* node = nullptr;

    if (root != nullptr)
    {
        if (root->val == p->val || root->val == q->val)
        {
            node = root;
        }
        else
        {
            node = findNode(root->left, p, q);
            if (node == nullptr)
            {
                node = findNode(root->right, p, q);
            }
        }
    }

    return node;
}