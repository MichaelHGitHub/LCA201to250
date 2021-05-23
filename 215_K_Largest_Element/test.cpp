#include "header.h"

void PrepareTestData(vector<TD_VI_I_I>& testData)
{
    TD_VI_I_I data;

    data.input = { 1, 2, 3, 4, 6, 10, 9, 8, 7, 5 };
    data.input2 = 6;
    data.output = 5;
    testData.push_back(data);

    data.input = { 3, 2, 1, 5, 6, 4 };
    data.input2 = 2;
    data.output = 5;
    testData.push_back(data);

    data.input = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
    data.input2 = 4;
    data.output = 4;
    testData.push_back(data);

}