#include "header.h"

void PrepareTestData(vector<TD_S_S_B>& testData)
{
    TD_S_S_B data;

    data.input = "anagram";
    data.input2 = "nagaram";
    data.output = true;
    testData.push_back(data);

    data.input = "rat";
    data.input2 = "car";
    data.output = false;
    testData.push_back(data);
}