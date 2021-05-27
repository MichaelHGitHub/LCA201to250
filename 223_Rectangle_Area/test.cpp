#include "header.h"

void PrepareTestData(vector<TD_VI_I>& testData)
{
    TD_VI_I data;

    data.input = { -2, -2, 2, 2, -3, -3, 3, -1};
    data.output = 24;
    testData.push_back(data);

    data.input = { -2, -2, 2, 2, 1, 1, 3, 3};
    data.output = 19;
    testData.push_back(data);


    data.input = { -2, -2, 2, 2, -1, -1, 1, 1 };
    data.output = 16;
    testData.push_back(data);

    data.input = { -2, -2, 2, 2, -2, -2, 2, 2 };
    data.output = 16;
    testData.push_back(data);

    data.input = { -3, 0, 3, 4, 0, -1, 9, 2 };
    data.output = 45;
    testData.push_back(data);


}