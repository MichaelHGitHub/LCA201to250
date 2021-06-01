#include "header.h"

void PrepareTestData(vector<TD_T_I_I>& testData)
{
    TD_T_I_I data;

    data.input = GenerateTree({ 3,1,4, NULL_NODE_VALUE,2 });
    data.input2 = 1;
    data.output = 1;
    testData.push_back(data);

    data.input = GenerateTree({ 5,3,6,2,4,NULL_NODE_VALUE,NULL_NODE_VALUE,1 });
    data.input2 = 3;
    data.output = 3;
    testData.push_back(data);
}