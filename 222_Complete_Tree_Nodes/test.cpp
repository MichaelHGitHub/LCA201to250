#include "header.h"

void PrepareTestData(vector<TD_T_I>& testData)
{
    TD_T_I data;

    data.input = GenerateTree({ 1,2,3,4,5,6});
    data.output = 6;
    testData.push_back(data);

    data.input = GenerateTree({ 1,2,3,4,5,6,7});
    data.output = 7;
    testData.push_back(data);

    data.input = GenerateTree({ 1,2,3,4,5,6,7,8});
    data.output = 8;
    testData.push_back(data);

    data.input = GenerateTree({ 1,2,3,4,5,6,7,8,9});
    data.output = 9;
    testData.push_back(data);

    data.input = GenerateTree({ });
    data.output = 0;
    testData.push_back(data);

    data.input = GenerateTree({ 1 });
    data.output = 1;
    testData.push_back(data);

    data.input = GenerateTree({ 1,2 });
    data.output = 2;
    testData.push_back(data);
}