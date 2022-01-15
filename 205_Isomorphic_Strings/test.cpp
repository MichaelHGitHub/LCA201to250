#include "header.h"

void PrepareTestData(vector<TD_S_S_B>& testData)
{
    TD_S_S_B data;

    data.input = "badc";
    data.input2 = "baba";
    data.output = false;
    testData.push_back(data);

    data.input = "egg";
    data.input2 = "add";
    data.output = true;
    testData.push_back(data);

    data.input = "foo";
    data.input2 = "bar";
    data.output = false;
    testData.push_back(data);

    data.input = "paper";
    data.input2 = "title";
    data.output = true;
    testData.push_back(data);
}