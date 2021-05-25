#include "header.h"

void PrepareTestData(vector<TD_VVC_I>& testData)
{
    TD_VVC_I data;

    data.input = { {'0', '1'} };
    data.output = 1;
    testData.push_back(data);

    data.input = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    data.output = 4;
    testData.push_back(data);

    data.input = {{'0', '1'}, {'1', '0'}};
    data.output = 1;
    testData.push_back(data);


    data.input = {{'0'}};
    data.output = 0;
    testData.push_back(data);
}