#include "header.h"

void PrepareTestData(vector<TD_VI_B>& testData)
{
    TD_VI_B data;

    data.input = { 1,2,3,1 };
    data.output = true;
    testData.push_back(data);

    data.input = { 1,2,3,4 };
    data.output = false;
    testData.push_back(data);

    data.input = { 1,1,1,3,3,4,3,2,4,2 };
    data.output = true;
    testData.push_back(data);

}