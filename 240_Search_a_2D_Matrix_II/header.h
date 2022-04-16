#pragma once

#include "../common/common.h"

void PrepareTestData(vector<TD_VVI_I_B>& testData);

bool searchMatrix(vector<vector<int>>& matrix, int target);
bool searchMatrix2(vector<vector<int>>& matrix, int target);

bool searchMatrix_r(vector<vector<int>>& matrix, int target);
bool searchMatrix_r2(vector<vector<int>>& matrix, int target);