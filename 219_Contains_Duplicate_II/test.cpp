#include "header.h"

void PrepareTestData(vector<TD_VI_I_B>& testData)
{
    TD_VI_I_B data;

    data.input = { 1,2,3,1 };
    data.input2 = 3;
    data.output = true;
    testData.push_back(data);

    data.input = { 1,0,1,1 };
    data.input2 = 1;
    data.output = true;
    testData.push_back(data);

    data.input = { 1,2,3,1,2,3 };
    data.input2 = 2;
    data.output = false;
    testData.push_back(data);

}