#include "header.h"

void PrepareTestData(vector<TD_I_VI_I>& testData)
{
    TD_I_VI_I data;

    data.input = 80;
    data.input2 = { 10, 5, 13, 4, 8, 4, 5, 11, 14, 9, 16, 10, 20, 8 };
    data.output = 6;
    testData.push_back(data);

    data.input = 7;
    data.input2 = { 2,3,1,2,4,3 };
    data.output = 2;
    testData.push_back(data);

    data.input = 4;
    data.input2 = { 1,4,4 };
    data.output = 1;
    testData.push_back(data);

    data.input = 11;
    data.input2 = { 1,1,1,1,1,1,1,1 };
    data.output = 0;
    testData.push_back(data);
}