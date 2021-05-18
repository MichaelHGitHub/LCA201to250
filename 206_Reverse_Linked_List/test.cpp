#include "header.h"

void PrepareTestData(vector<TD_L_L>& testData)
{
    TD_L_L data;

    data.input = GenerateLinkedList({ 1, 2, 3, 4, 5 });
    data.output = GenerateLinkedList({ 5,4,3,2,1});
    testData.push_back(data);

    data.input = GenerateLinkedList({ 1,2 });
    data.output = GenerateLinkedList({2, 1});
    testData.push_back(data);

    data.input = GenerateLinkedList({});
    data.output = GenerateLinkedList({});
    testData.push_back(data);

}