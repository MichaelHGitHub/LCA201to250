#include "header.h"

void PrepareTestData(vector<TD_VI_I>& testData)
{
    TD_VI_I data;

    data.input = { 200, 3, 140, 20, 10 };
    data.output = 340;
    testData.push_back(data);

    data.input = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
    data.output = 16;
    testData.push_back(data);

    data.input = { 2, 1, 1, 2 };
    data.output = 3;
    testData.push_back(data);

    data.input = { 8,2,8,9,2 };
    data.output = 17;
    testData.push_back(data);

    data.input = { 2,1,1,1 };
    data.output = 3;
    testData.push_back(data);



    data.input = {1,3,1,3,100 };
    data.output = 103;
    testData.push_back(data);

    data.input = { 2,3,2 };
    data.output = 3;
    testData.push_back(data);

    data.input = { 1,2,3,1 };
    data.output = 4;
    testData.push_back(data);

    data.input = { 0 };
    data.output = 0;
    testData.push_back(data);

    data.input = { 1 };
    data.output = 1;
    testData.push_back(data);
}