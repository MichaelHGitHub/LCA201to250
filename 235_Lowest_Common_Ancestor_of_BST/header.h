#pragma once

#include "../common/common.h"

void PrepareTestData(vector<TD_T_T_T_T>& testData);

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q);