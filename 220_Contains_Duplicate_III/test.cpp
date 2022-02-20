#include "header.h"

void PrepareTestData(vector<TD_VI_I_I_B>& testData)
{
    TD_VI_I_I_B data;

    data.input = { 7, 1, 3 };
    data.input2 = 2;
    data.input3 = 3;
    data.output = true;
    testData.push_back(data);

    data.input = { 1,5,9,1,5,9 };
    data.input2 = 2;
    data.input3 = 3;
    data.output = false;
    testData.push_back(data);

    data.input = { 3, 6, 0, 4 };
    data.input2 = 2;
    data.input3 = 2;
    data.output = true;
    testData.push_back(data);

    data.input = { 2147483641, 2147483640 };
    data.input2 = 1;
    data.input3 = 100;
    data.output = true;
    testData.push_back(data);

    data.input = { 2147483640, 2147483641 };
    data.input2 = 1;
    data.input3 = 100;
    data.output = true;
    testData.push_back(data);

    data.input = { 1, 2, 5, 6, 7, 2, 4 };
    data.input2 = 4;
    data.input3 = 0;
    data.output = true;
    testData.push_back(data);

    data.input = { 4,8,12 };
    data.input2 = 2;
    data.input3 = 3;
    data.output = false;
    testData.push_back(data);

    data.input = { 1,2,3,1 };
    data.input2 = 3;
    data.input3 = 0;
    data.output = true;
    testData.push_back(data);

    data.input = { 1,0,1,1 };
    data.input2 = 1;
    data.input3 = 2;
    data.output = true;
    testData.push_back(data);



}