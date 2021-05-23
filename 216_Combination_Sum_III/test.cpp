#include "header.h"

void PrepareTestData(vector<TD_I_I_VVI>& testData)
{
    TD_I_I_VVI data;

    data.input = 3;
    data.input2 = 7;
    data.output = {{1, 2, 4}};
    testData.push_back(data);

    data.input = 3;
    data.input2 = 9;
    data.output = {{1, 2, 6}, {1, 3, 5}, {2, 3, 4}};
    testData.push_back(data);

    data.input = 4;
    data.input2 = 1;
    data.output = {};
    testData.push_back(data);

    data.input = 3;
    data.input2 = 2;
    data.output = {};
    testData.push_back(data);

    data.input = 9;
    data.input2 = 45;
    data.output = { { 1,2,3,4,5,6,7,8,9 } };
    testData.push_back(data);
}