#include "header.h"

int main(char* args[], int argc)
{
    vector<TD_T_T_T_I> test_data;

    PrepareTestData(test_data);

    for (int i = 0; i < test_data.size(); i++)
    {
        PrintInput(test_data[i]);
        TreeNode* result = lowestCommonAncestor_r2(test_data[i].input, test_data[i].input2, test_data[i].input3);

        CheckResults(test_data[i], result->val);
    }

    return 0;
}
