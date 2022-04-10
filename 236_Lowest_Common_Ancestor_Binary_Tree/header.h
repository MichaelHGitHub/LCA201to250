#pragma once

#include "../common/common.h"

void PrepareTestData(vector<TD_T_T_T_I>& testData);

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q);

TreeNode* lowestCommonAncestor_r(TreeNode* root, TreeNode* p, TreeNode* q);
TreeNode* lowestCommonAncestor_r2(TreeNode* root, TreeNode* p, TreeNode* q);