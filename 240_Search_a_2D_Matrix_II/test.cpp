#include "header.h"

void PrepareTestData(vector<TD_VVI_I_B>& testData)
{
    TD_VVI_I_B data;

    data.input = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    data.input2 = 5;
    data.output = true;
    testData.push_back(data);

    data.input = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    data.input2 = 20;
    data.output = false;
    testData.push_back(data);
}