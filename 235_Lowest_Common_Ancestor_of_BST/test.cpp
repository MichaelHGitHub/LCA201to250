#include "header.h"

void PrepareTestData(vector<TD_T_T_T_T>& testData)
{
    TD_T_T_T_T data;

    data.input = GenerateTree({ 6,2,8,0,4,7,9,NULL_NODE_VALUE,NULL_NODE_VALUE,3,5 });
    data.input2 = GenerateTree({2});
    data.input3 = GenerateTree({8});
    data.output = GenerateTree({6});
    testData.push_back(data);

    data.input = GenerateTree({ 6,2,8,0,4,7,9,NULL_NODE_VALUE,NULL_NODE_VALUE,3,5 });
    data.input2 = GenerateTree({ 2 });
    data.input3 = GenerateTree({ 4 });
    data.output = GenerateTree({ 2 });
    testData.push_back(data);

    data.input = GenerateTree({ 2,1 });
    data.input2 = GenerateTree({ 2 });
    data.input3 = GenerateTree({ 1 });
    data.output = GenerateTree({ 2 });
    testData.push_back(data);

}