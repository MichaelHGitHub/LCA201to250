#include "header.h"

class BSTNode
{
public:
    long long val;
    int pos;
    BSTNode* left;
    BSTNode* right;

    BSTNode(long long num, int index) :
        val(num),
        pos(index),
        left(nullptr),
        right(nullptr)
    {
    }
};

class BST
{
public:
    BST() :
        root(nullptr)
    {
    }

    void Add(int num, int index)
    {
        if (!root)
        {
            root = new BSTNode(num, index);
            return;
        }

        BSTNode* node = root;
        while (node)
        {
            if (node->val == num)
            {
                node->pos = index;
                return;
            }
            else if (node->val > num)
            {
                if (!node->left)
                {
                    node->left = new BSTNode(num, index);
                    return;
                }
                else
                {
                    node = node->left;
                }
            }
            else
            {
                if (!node->right)
                {
                    node->right = new BSTNode(num, index);
                    return;
                }
                else
                {
                    node = node->right;
                }
            }
        }
    }

    void Remove(long long num)
    {
        BSTNode dummy(0, 0);
        dummy.left = root;

        BSTNode* node = root;
        BSTNode* parent = &dummy;

        while (node)
        {
            if (node->val == num)
            {
                BSTNode* left = node->left;
                BSTNode* right = node->right;

                if (left && right)
                {
                    BSTNode* largest_smaller = left;
                    while (largest_smaller->right)
                    {
                        largest_smaller = largest_smaller->right;
                    }
                    largest_smaller->right = right;
                }
                else if (!left)
                {
                    if (node == parent->left)
                    {
                        parent->left = right;
                    }
                    else
                    {
                        parent->right = right;
                    }
                }
                else
                {
                    if (node == parent->left)
                    {
                        parent->left = left;
                    }
                    else
                    {
                        parent->right = left;
                    }
                }
                break;
            }
            else if (node->val > num)
            {
                parent = node;
                node = node->left;
            }
            else
            {
                parent = node;
                node = node->right;
            }
        }
        root = dummy.left;
    }

    int GetEqualOrLarger(long long num)
    {
        BSTNode* node = root;
        int pos = -1;

        while (node)
        {
            if (node->val >= num)
            {
                pos = node->pos;
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }

        return pos;
    }

private:
    BSTNode* root;
};

bool containsNearbyAlmostDuplicate3(vector<int>& nums, int k, int t)
{
    BST visited;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > k)
        {
            visited.Remove(nums[i - k - 1]);
        }
        // -t <= X - nums[i] <= t ==>
        // (X >= nums[i] - t) and (X - nums[i]) <=t
        int pos = visited.GetEqualOrLarger((long long)nums[i] - t);
        if (pos != -1 && (long long)nums[pos] - nums[i] <= t)
        {
            return true;
        }
        else
        {
            visited.Add(nums[i], i);
        }
    }
    return false;
}



