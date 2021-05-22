#pragma once

#include "../common/common.h"

void PrepareTestData(vector<TD_I_VVI_VI>& testData);

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);

vector<int> findOrder2(int numCourses, vector<vector<int>>& prerequisites);