#include "header.h"

void PrepareTestData(vector<TD_VI_VI>& testData)
{
    TD_VI_VI data;

    data.input = { 3,2,3 };
    data.output = {3};
    testData.push_back(data);

    data.input = {1};
    data.output = {1};
    testData.push_back(data);

    data.input = { 1,2 };
    data.output = { 1,2 };
    testData.push_back(data);
}