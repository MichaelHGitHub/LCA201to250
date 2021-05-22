#include "header.h"

void PrepareTestData(vector<TD_I_VVI_VI>& testData)
{
    TD_I_VVI_VI data;

    data.input = 7;
    data.input2 = {{1,0},{0,3},{0,2},{3,2},{2,5},{4,5},{5,6},{2,4}};
    data.output = {6, 5, 4, 2, 3, 0, 1};
    testData.push_back(data);


    data.input = 2;
    data.input2 = { {0, 1} };
    data.output = { 1, 0 };
    testData.push_back(data);

    data.input = 2;
    data.input2 = {{1, 0}};
    data.output = {0, 1};
    testData.push_back(data);

    data.input = 4;
    data.input2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    data.output = {0, 1, 2, 3};
    testData.push_back(data);

    data.input = 1;
    data.input2 = {};
    data.output = {0};
    testData.push_back(data);

}