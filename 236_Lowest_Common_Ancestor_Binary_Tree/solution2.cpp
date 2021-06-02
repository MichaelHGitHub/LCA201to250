#include <stack>
#include <unordered_map>
#include "header.h"

// post order traversal,
// A node is an ancestor of p(q) if its left or right sub-tree has p(q) or 
// the node itself is p(q).
//  return at the first occurrence where a node is the ancestor of both p and q.
// Iterative:

TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (!root)
    {
        return nullptr;
    }
    unordered_map<TreeNode*, bool> record_p;
    unordered_map<TreeNode*, bool> record_q;

    stack<TreeNode*> pending;
    pending.push(root);

    while (!pending.empty())
    {
        TreeNode* node = pending.top();
        bool right_visited = (record_p.find(node->right) != record_p.end() ||
            record_q.find(node->right) != record_q.end());
        bool left_visited = (record_p.find(node->left) != record_p.end() ||
            record_q.find(node->left) != record_q.end());

        if (node->right && !right_visited)
        {
            pending.push(node->right);
        }

        if (node->left && !left_visited)
        {
            pending.push(node->left);
        }

        if ((!node->right || right_visited) && (!node->left || left_visited))
        {
            pending.pop();

            if (node->val == p->val ||
                (record_p.find(node->right) != record_p.end() && record_p[node->right] == true) ||
                (record_p.find(node->left) != record_p.end() && record_p[node->left] == true))
            {
                record_p[node] = true;
            }
            else
            {
                record_p[node] = false;
            }

            if (node->val == q->val ||
                (record_q.find(node->right) != record_q.end() && record_q[node->right] == true) ||
                (record_q.find(node->left) != record_q.end() && record_q[node->left] == true))
            {
                record_q[node] = true;
            }
            else
            {
                record_q[node] = false;
            }

            if (record_p[node] && record_q[node])
            {
                return node;
            }
        }
    }
    return nullptr;
}
