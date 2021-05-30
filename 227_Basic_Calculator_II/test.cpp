#include "header.h"

void PrepareTestData(vector<TD_S_I>& testData)
{
    TD_S_I data;
    data.input = "1";
    data.output = 1;
    testData.push_back(data);

    data.input = "1*(2-3) + 10+2*3-(5-3)";
    data.output = 13;
    testData.push_back(data);

    data.input = "1*(2-3) + 10";
    data.output = 9;
    testData.push_back(data);

    data.input = "1*2-3/4+5*6-7*8+9/10";
    data.output = -24;
    testData.push_back(data);

    data.input = "3+2*2";
    data.output = 7;
    testData.push_back(data);

    data.input = "282-1*2*13-30-2*2*2/2-95/5*2+55+804+3024";
    data.output = 4067;
    testData.push_back(data);

    data.input = "0";
    data.output = 0;
    testData.push_back(data);





    data.input = " 3/2 ";
    data.output = 1;
    testData.push_back(data);

    data.input = " 3+5 / 2 ";
    data.output = 5;
    testData.push_back(data);

}