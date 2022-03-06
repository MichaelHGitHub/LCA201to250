#include "header.h"

void PrepareTestData(vector<TD_S_I>& testData)
{
    TD_S_I data;

    data.input = "1+(4+5+2)-3+(6+8)";
    data.output = 23;
    testData.push_back(data);

    data.input = "(1+(4+5+2)-3)+(6+8)";
    data.output = 23;
    testData.push_back(data);

    data.input = "(6)-(8)-(7)";
    data.output = -9;
    testData.push_back(data);

    data.input = "(1+(6))";
    data.output = 7;
    testData.push_back(data);

    data.input = "(6)-(8)-(7)+(1+(6))";
    data.output = -2;
    testData.push_back(data);

    data.input = "1-(-1+1)";
    data.output = 1;
    testData.push_back(data);

    data.input = "1+(6)";
    data.output = 7;
    testData.push_back(data);

    data.input = "-2+ 1";
    data.output = -1;
    testData.push_back(data);

    data.input = "1-(1+1)";
    data.output = -1;
    testData.push_back(data);

    data.input = "1+1";
    data.output = 2;
    testData.push_back(data);

    data.input = "1 + 1";
    data.output = 2;
    testData.push_back(data);

    data.input = "1-(1+1)";
    data.output = -1;
    testData.push_back(data);

    data.input = "1-  (1+1)";
    data.output = -1;
    testData.push_back(data);

    data.input = " 2-1 + 2 ";
    data.output = 3;
    testData.push_back(data);

    data.input = "1-(  -1+1)";
    data.output = 1;
    testData.push_back(data);

    //data.input = "1-(+1+1)";
    //data.output = -1;
    //testData.push_back(data);

    //data.input = "+48 + -48";
    //data.output = 0;
    //testData.push_back(data);
}