#include "header.h"

void PrepareTestData(vector<TD_L_I_L>& testData)
{
    TD_L_I_L data;

    data.input = GenerateLinkedList({ 1,2,6,3,4,5,6 });
    data.input2 = 6;
    data.output = GenerateLinkedList({ 1,2,3,4,5 });
    testData.push_back(data);

    data.input = GenerateLinkedList({});
    data.input2 = 1;
    data.output = GenerateLinkedList({});
    testData.push_back(data);

    data.input = GenerateLinkedList({ 7,7,7,7 });
    data.input2 = 7;
    data.output = GenerateLinkedList({});
    testData.push_back(data);

}