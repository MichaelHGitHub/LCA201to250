#include "header.h"

void PrepareTestData(vector<TD_L_B>& testData)
{
    TD_L_B data;

    data.input = GenerateLinkedList({ });
    data.output = false;
    testData.push_back(data);

    data.input = GenerateLinkedList({ 1 });
    data.output = true;
    testData.push_back(data);

    data.input = GenerateLinkedList({ 1,2 });
    data.output = false;
    testData.push_back(data);

    data.input = GenerateLinkedList({ 1,2,1 });
    data.output = true;
    testData.push_back(data);

    data.input = GenerateLinkedList({ 1,2,2,1 });
    data.output = true;
    testData.push_back(data);
}