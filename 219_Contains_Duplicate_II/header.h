#pragma once

#include "../common/common.h"

void PrepareTestData(vector<TD_VI_I_B>& testData);

bool containsNearbyDuplicate(vector<int>& nums, int k);

bool containsNearbyDuplicate_r(vector<int>& nums, int k);