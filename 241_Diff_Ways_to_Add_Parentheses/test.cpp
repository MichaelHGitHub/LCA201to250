#include "header.h"

void PrepareTestData(vector<TD_S_VI>& testData)
{
    TD_S_VI data;

    data.input = "1+2+3+4";
    data.output = { 10 ,10 ,10 ,10 ,10 };
    testData.push_back(data);

    data.input = "1*1";
    data.output = { 1 };
    testData.push_back(data);

    data.input = "1*1*1";
    data.output = { 1, 1 };
    testData.push_back(data);

    data.input = "1*1*1*1";
    data.output = { 1, 1, 1};
    testData.push_back(data);

    data.input = "2-1-1";
    data.output = { 0,2 };
    testData.push_back(data);

    data.input = "2*3-4*5";
    data.output = { -34,-14,-10,-10,10 };
    testData.push_back(data);
}