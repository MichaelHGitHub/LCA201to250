#include "header.h"

void PrepareTestData(vector<TD_I_I>& testData)
{
    TD_I_I data;

    data.input = 10;
    data.output = 4;
    testData.push_back(data);

    data.input = 1;
    data.output = 0;
    testData.push_back(data);

    data.input = 0;
    data.output = 0;
    testData.push_back(data);
}