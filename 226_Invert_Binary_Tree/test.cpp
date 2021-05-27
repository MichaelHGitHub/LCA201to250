#include "header.h"

void PrepareTestData(vector<TD_T_T>& testData)
{
    TD_T_T data;

    data.input = GenerateTree({ 4,2,7,1,3,6,9 });
    data.output = GenerateTree({ 4,7,2,9,6,3,1 });
    testData.push_back(data);

    data.input = GenerateTree({ 2,1,3 });
    data.output = GenerateTree({ 2,3,1 });
    testData.push_back(data);

    data.input = GenerateTree({});
    data.output = GenerateTree({});
    testData.push_back(data);
}