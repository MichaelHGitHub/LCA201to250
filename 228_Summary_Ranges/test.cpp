#include "header.h"

void PrepareTestData(vector<TD_VI_VS>& testData)
{
    TD_VI_VS data;

    data.input = { 0,1,2,4,5,7 };
    data.output = { "0->2","4->5","7" };
    testData.push_back(data);

    data.input = { 0,2,3,4,6,8,9 };
    data.output = { "0","2->4","6","8->9" };
    testData.push_back(data);

    data.input = {};
    data.output = {};
    testData.push_back(data);

    data.input = { -1 };
    data.output = { "-1" };
    testData.push_back(data);

    data.input = { 0 };
    data.output = { "0" };
    testData.push_back(data);
}