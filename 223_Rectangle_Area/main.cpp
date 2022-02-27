#include "header.h"

int main(char* args[], int argc)
{
    vector<TD_VI_I> test_data;

    PrepareTestData(test_data);

    for (int i = 0; i < test_data.size(); i++)
    {
        PrintInput(test_data[i]);
        int result = computeArea_r(
            test_data[i].input[0],
            test_data[i].input[1],
            test_data[i].input[2],
            test_data[i].input[3],
            test_data[i].input[4],
            test_data[i].input[5],
            test_data[i].input[6],
            test_data[i].input[7]);

        CheckResults(test_data[i], result);
    }

    return 0;
}
