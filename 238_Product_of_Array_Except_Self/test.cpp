#include "header.h"

void PrepareTestData(vector<TD_VI_VI>& testData)
{
    TD_VI_VI data;

    data.input = { 1,2,3,4 };
    data.output = { 24,12,8,6 };
    testData.push_back(data);

    data.input = { -1,1,0,-3,3 };
    data.output = { 0,0,9,0,0 };
    testData.push_back(data);

}