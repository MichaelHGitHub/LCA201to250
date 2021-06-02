#include "header.h"

void PrepareTestData(vector<TD_T_T_T_I>& testData)
{
    TD_T_T_T_I data;

    data.input = GenerateTree({ 3,5,1,6,2,0,8,NULL_NODE_VALUE,NULL_NODE_VALUE,7,4 });
    data.input2 = GenerateTree({ 5 });
    data.input3 = GenerateTree({ 1 });
    data.output = 3;
    testData.push_back(data);

    data.input = GenerateTree({ 3,5,1,6,2,0,8,NULL_NODE_VALUE,NULL_NODE_VALUE,7,4 });
    data.input2 = GenerateTree({ 5 });
    data.input3 = GenerateTree({ 4 });
    data.output = 5;
    testData.push_back(data);

    data.input = GenerateTree({ 1,2 });
    data.input2 = GenerateTree({ 1 });
    data.input3 = GenerateTree({ 2 });
    data.output = 1;
    testData.push_back(data);

}