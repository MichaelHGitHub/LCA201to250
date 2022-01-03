#include "header.h"

void PrepareTestData(vector<TD_I_I_I>& testData)
{
    TD_I_I_I data;

    data.input = 5;
    data.input2 = 7;
    data.output = 4;
    testData.push_back(data);

    data.input = 0;
    data.input2 = 0;
    data.output = 0;
    testData.push_back(data);

    data.input = 1;
    data.input2 = 2147483647;
    data.output = 0;
    testData.push_back(data);
}