#include "header.h"

void PrepareTestData(vector<TD_I_B>& testData)
{
    TD_I_B data;

    data.input = -2147483646;
    data.output = false;
    testData.push_back(data);

    data.input = 1;
    data.output = true;
    testData.push_back(data);

    data.input = 16;
    data.output = true;
    testData.push_back(data);

    data.input = 3;
    data.output = false;
    testData.push_back(data);

    data.input = 4;
    data.output = true;
    testData.push_back(data);

    data.input = 5;
    data.output = false;
    testData.push_back(data);
}