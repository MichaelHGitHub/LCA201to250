#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include "common.h"

using namespace std;

template<typename T>
void PrintData(T t)
{
    std::cout << t;
}

template<>
void PrintData(ListNode* l)
{
    PrintList(l);
}

template<>
void PrintData(TreeNode* t)
{
    PrintTree(t);
}

template<>
void PrintData(GraphNode* t)
{
    PrintGraph(t);
}

template<typename T>
void PrintData(vector<T> v)
{
    std::cout << "{";
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i];
        if (i != v.size() - 1)
        {
            std::cout << " ,";
        }
    }
    std::cout << "}";
}

template<>
void PrintData(vector<int> v)
{
    std::cout << "{";
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == NULL_NODE_VALUE)
        {
            std::cout << "#";
        }
        else
        {
            std::cout << v[i];
        }

        if (i != v.size() - 1)
        {
            std::cout << " ,";
        }
    }
    std::cout << "}";
}

template<>
void PrintData(vector<ListNode*> vl)
{
    for (int i = 0; i < vl.size(); i++)
    {
        PrintList(vl[i]);
        std::cout << endl;
    }
}

template<>
void PrintData(vector<TreeNode*> v)
{
    std::cout << "{";
    for (int i = 0; i < v.size(); i++)
    {
        PrintData(v[i]);
        cout << endl;
    }
    std::cout << "}";
}

template<typename T>
void PrintData(vector<vector<T>> vv)
{
    std::cout << "{" << endl;
    for (int i = 0; i < vv.size(); i++)
    {
        std::cout << "{";
        for (int j = 0; j < vv[i].size(); j++)
        {
            std::cout << vv[i][j];
            if (j != vv[i].size() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "}";

        if (i != vv.size() - 1)
        {
            std::cout << ", ";
        }

        std::cout << endl;
    }
    std::cout << "} ";
}

template<typename T>
bool AreVectorEqual(vector<T> v1, vector<T> v2)
{
    for (int i = 0; i < v1.size(); i++)
    {
        int j = 0;
        for (; j < v2.size(); j++)
        {
            if (v1[i] == v2[j])
            {
                break;
            }
        }

        if (j >= v2.size())
        {
            return false;
        }
    }

    for (int j = 0; j < v2.size(); j++)
    {
        int i = 0;
        for (; i < v1.size(); i++)
        {
            if (v1[i] == v2[j])
            {
                break;
            }
        }

        if (i >= v1.size())
        {
            return false;
        }
    }

    return true;
}

bool AreSameAdjacentList(vector<GraphNode*> v1, vector<GraphNode*> v2)
{
    for (int i = 0; i < v1.size(); i++)
    {
        int j = 0;
        for (; j < v2.size(); j++)
        {
            if (v1[i]->val == v2[j]->val)
            {
                break;
            }
        }

        if (j >= v2.size())
        {
            return false;
        }
    }

    for (int j = 0; j < v2.size(); j++)
    {
        int i = 0;
        for (; i < v1.size(); i++)
        {
            if (v1[i]->val == v2[j]->val)
            {
                break;
            }
        }

        if (i >= v1.size())
        {
            return false;
        }
    }

    return true;
}

template<>
bool AreVectorEqual(std::vector<TreeNode*> v1, std::vector<TreeNode*> v2)
{
    for (int i = 0; i < v1.size(); i++)
    {
        int j = 0;
        for (; j < v2.size(); j++)
        {
            if (IsSameTree(v1[i], v2[j]))
            {
                break;
            }
        }

        if (j >= v2.size())
        {
            return false;
        }
    }

    for (int j = 0; j < v2.size(); j++)
    {
        int i = 0;
        for (; i < v1.size(); i++)
        {
            if (IsSameTree(v1[i], v2[j]))
            {
                break;
            }
        }

        if (i >= v1.size())
        {
            return false;
        }
    }
}

template<typename T>
bool Are2DimensionArrayEqual(vector<vector<T>> array1, vector<vector<T>> array2)
{
    if (array1.size() != array2.size())
    {
        return false;
    }

    for (int i = 0; i < array1.size(); i++)
    {
        if (array1[i].size() != array2[i].size())
        {
            return false;
        }

        for (int j = 0; j < array1[i].size(); j++)
        {
            if (array1[i][j] != array2[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

template<typename T>
bool Are2DimensionSetEqual(vector<vector<T>> array1, vector<vector<T>> array2)
{
    if (array1.size() != array2.size())
    {
        return false;
    }

    {
        int i = 0;
        for (; i < array1.size(); i++)
        {
            int j = 0;
            for (; j < array2.size(); j++)
            {
                if (array1[i].size() == array2[j].size())
                {
                    if (AreVectorEqual(array1[i], array2[j]))
                    {
                        break;
                    }
                }
            }

            if (j >= array2.size())
            {
                return false;
            }

        }
    }

    {
        int i = 0;
        for (; i < array2.size(); i++)
        {
            int j = 0;
            for (; j < array1.size(); j++)
            {
                if (array2[i].size() == array1[j].size())
                {
                    if (AreVectorEqual(array2[i], array1[j]))
                    {
                        break;
                    }
                }
            }

            if (j >= array1.size())
            {
                return false;
            }
        }
    }

    return true;
}


void PrintInput(TD_I_I testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_I_I testData, int result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout<< endl;
    }

    std::cout << endl;
}

void PrintInput(TD_I_I_I testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}

void CheckResults(TD_I_I_I testData, int result)
{

    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_I_I_VVI testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}

void CheckResults(TD_I_I_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionArrayEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void CheckResults_Unorder(TD_I_I_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionSetEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_I_VVI_B testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}
void CheckResults(TD_I_VVI_B testData, bool result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_D_I_D testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}
void CheckResults(TD_D_I_D testData, double result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_I_S testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_I_S testData, string result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout<< endl;
    }

    std::cout << endl;
}

void PrintInput(TD_I_I_S testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}
void CheckResults(TD_I_I_S testData, string result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_I_B testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_I_B testData, bool result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_S_S testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_S_S testData, string result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout<< endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_S_I testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_S_I testData, int result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_S_B testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_S_B testData, bool result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_S_S_I testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;

}

void CheckResults(TD_S_S_I testData, int result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout<< endl;
    }

    std::cout << endl;
}

void PrintInput(TD_S_I_S testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}
void CheckResults(TD_S_I_S testData, string result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_S_S_B testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}

void CheckResults(TD_S_S_B testData, bool result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << testData.output << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_S_S_S_B testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;

    std::cout << "Input3 :";
    PrintData(testData.input3);
    std::cout << endl;

}
void CheckResults(TD_S_S_S_B testData, bool result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << testData.output << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_S_S_S testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}

void CheckResults(TD_S_S_S testData, string result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << testData.output << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_S_VS testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_S_VS testData, vector<string> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_I_VI testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_I_VI testData, vector<int> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (AreVectorEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_I_VS testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_I_VS testData, vector<string> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (AreVectorEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_I testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

}

void CheckResults(TD_VI_I testData, int result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_VS testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_VI_VS testData, vector<string> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_B testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_VI_B testData, bool result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_S testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_VI_S testData, string result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_I_B testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}

void CheckResults(TD_VI_I_B testData, bool result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_I_I_B testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;

    std::cout << "Input3 :";
    PrintData(testData.input3);
    std::cout << endl;
}
void CheckResults(TD_VI_I_I_B testData, bool result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_VI_I testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}
void CheckResults(TD_VI_VI_I testData, int result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VS_I testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_VS_I testData, int result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VS_S testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_VS_S testData, string result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_S_VS_B testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}

void CheckResults(TD_S_VS_B testData, bool result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VS_VVS testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_VS_VVS testData, vector<vector<string>> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionArrayEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void CheckResults_Unoder(TD_VS_VVS testData, vector<vector<string>> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionSetEqual(testData.output,result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_S_VS_VS testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}
void CheckResults(TD_S_VS_VS testData, vector<string> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void CheckResults_Unorder(TD_S_VS_VS testData, vector<string> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (AreVectorEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_S_VVS testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_S_VVS testData, vector<vector<string>> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionArrayEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}
void CheckResults_Unoder(TD_S_VVS testData, vector<vector<string>> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionSetEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}


void PrintInput(TD_VI_I_I testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;

}

void CheckResults(TD_VI_I_I testData, int result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_I_VI_I testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}
void CheckResults(TD_I_VI_I testData, int result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_VVI testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_VI_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionArrayEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;

        std::cout << "Expect: " << endl;
        PrintData(testData.output);
    }

    std::cout << endl;
}

void CheckResults_Unorder(TD_VI_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output :";
    PrintData(result);
    cout << endl;

    if (Are2DimensionSetEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;

        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VVI_VVI testData) 
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_VVI_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionArrayEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;

        std::cout << "Expect: " << endl;
        PrintData(testData.output);
    }

    std::cout << endl;
}
void CheckResults_Unorder(TD_VVI_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionSetEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;

        std::cout << "Expect: " << endl;
        PrintData(testData.output);
    }

    std::cout << endl;
}


void PrintInput(TD_VI_I_VVI testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}

void CheckResults(TD_VI_I_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output :";
    PrintData(result); 
    cout << endl;

    if (Are2DimensionArrayEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;

        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void CheckResults_Unorder(TD_VI_I_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output :";
    PrintData(result);
    cout << endl;

    if (Are2DimensionSetEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;

        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VVC_B testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::wcout << endl;
}

void CheckResults(TD_VVC_B testData, bool result)
{
    std::cout << "Output: ";
    PrintData(result);
    cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VVC_I testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::wcout << endl;
}
void CheckResults(TD_VVC_I testData, int result)
{
    std::cout << "Output: ";
    PrintData(result);
    cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VVC_S_B testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::wcout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::wcout << endl;
}
void CheckResults(TD_VVC_S_B testData, bool result)
{
    std::cout << "Output: ";
    PrintData(result);
    cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_VI_D testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}

void CheckResults(TD_VI_VI_D testData, double result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_VI testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_VI_VI testData, vector<int> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_I_VI_I_VI testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;

    std::cout << "Input3 :";
    PrintData(testData.input3);
    std::cout << endl;

    std::cout << "Input4 :";
    PrintData(testData.input4);
    std::cout << endl;
}
void CheckResults(TD_VI_I_VI_I_VI testData, vector<int> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}


void PrintInput(TD_VVI_I testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_VVI_I testData, int result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VVI_I_B testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}
void CheckResults(TD_VVI_I_B testData, int result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VVI_VI testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_VVI_VI testData, vector<int> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_I_VVI_VI testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}
void CheckResults(TD_I_VVI_VI testData, vector<int> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_I_VVI testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_I_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionArrayEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}


void PrintInput(TD_VVI_VI_VVI testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}
void CheckResults(TD_VVI_VI_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionArrayEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}


void PrintInput(TD_VVC_VVC testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_VVC_VVC testData, vector<vector<char>> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionArrayEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;

        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;

        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_I_VI testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}

void CheckResults(TD_VI_I_VI testData, vector<int> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VL_L testData)
{
    std::cout << "Input :" << endl;
    PrintData(testData.input);
    std::cout << endl;

}

void CheckResults(TD_VL_L testData, ListNode* result)
{
    std::cout << "Output: ";
    PrintList(result);
    std::cout << endl;

    if (IsEqualLinkedList(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintList(testData.output);
    }

    std::cout << endl;
}

void PrintInput(TD_G_G testData)
{
    std::cout << "Input :" << endl;
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_G_G testData, GraphNode* result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (AreSameGraph(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
    }

    std::cout << endl;
}

ListNode* GenerateLinkedList(vector<int> v)
{
    if (v.size() < 1)
    {
        return nullptr;
    }

    ListNode* h = new ListNode(v[0]);
    ListNode* p = h;

    for (int i = 1; i < v.size(); i++)
    {
        p->next = new ListNode(v[i]);
        p = p->next;
    }

    return h;
}

void PrintList(ListNode* l)
{
    if (nullptr == l)
    {
        std::cout << "null";
        return;
    }

    ListNode* p = l;
    while (p)
    {
        std::cout << "[" << p->val << "]";
        if (p->next)
        {
            std::cout << "-";
        }

        p = p->next;
    }
}

bool IsEqualLinkedList(ListNode* l, ListNode* r)
{
    if (nullptr == l && nullptr == r)
    {
        return true;
    }

    bool result = false;

    ListNode* pl = l;
    ListNode* pr = r;
    while (pl && pr)
    {
        if (pl->val != pr->val)
        {
            break;
        }

        pl = pl ->next;
        pr = pr->next;
    }

    if (nullptr == pl && nullptr == pr)
    {
        result = true;
    }

    return result;
}

TreeNode* GenerateTree(vector<int> v)
{
    if (v.size() == 0)
    {
        return nullptr;
    }
    queue< TreeNode*> nodes;
    TreeNode* root = new TreeNode(v[0]);
    nodes.push(root);


    int count = 1;
    while (!nodes.empty())
    {
        TreeNode* cur = nodes.front();
        nodes.pop();

        if (count < v.size() && v[count] != NULL_NODE_VALUE)
        {
            TreeNode* node = new TreeNode(v[count]);
            cur->left = node;
            nodes.push(node);
        }
        else
        {
            cur->left = nullptr;
        }
        ++count;

        if (count < v.size() && v[count] != NULL_NODE_VALUE)
        {
            TreeNode* node = new TreeNode(v[count]);
            cur->right = node;
            nodes.push(node);
        }
        else
        {
            cur->right = nullptr;
        }
        ++count;
    }

    return root;
}

vector<TreeNode*> GenerateTrees(vector<vector<int>> v)
{
    vector<TreeNode*> result;
    for (int i = 0; i < v.size(); i++)
    {
        result.push_back(GenerateTree(v[i]));
    }

    return result;
}

void PrintInput(TD_L_L testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_L_L testData, ListNode* result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (IsEqualLinkedList(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_CL_B testData)
{
    std::cout << "Input :";
    PrintLoopList(testData.input, testData.loop_index);
    std::cout << endl;

    std::cout << "Loop Index :";
    PrintData(testData.loop_index);
    std::cout << endl;

}
void CheckResults(TD_CL_B testData, bool result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}


void PrintInput(TD_CL_L testData)
{
    std::cout << "Input :";
    PrintLoopList(testData.input, testData.loop_index);
    std::cout << endl;

    std::cout << "Loop Index :";
    PrintData(testData.loop_index);
    std::cout << endl;
}
void CheckResults(TD_CL_L testData, ListNode* result)
{
    std::cout << "Output: ";
    PrintLoopList(result, 0);
    std::cout << endl;

    if ((testData.output && result && testData.output->val == result->val) || 
        (!testData.output && !result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintLoopList(testData.output, 0);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_T_VI testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_T_VI testData, vector<int> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_L_T testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_L_T testData, TreeNode* result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (IsSameTree(testData.output,result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_T_I testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_T_I testData, int result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_T_I_I testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}
void CheckResults(TD_T_I_I testData, int result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_T_I_B testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}
void CheckResults(TD_T_I_B testData, bool result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_VI_T testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}
void CheckResults(TD_VI_VI_T testData, TreeNode* result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (IsSameTree(testData.output,result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_T testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_VI_T testData, TreeNode* result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (IsSameTree(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_T_VVI testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_T_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionArrayEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void CheckResults_Unorder(TD_T_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionSetEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_T_I_VVI testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}
void CheckResults(TD_T_I_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionArrayEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}
void CheckResults_Unorder(TD_T_I_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionSetEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}


void PrintInput(TD_I_VT testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_I_VT testData, vector<TreeNode*> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (AreVectorEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_T_T testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_T_T testData)
{
    std::cout << "Output: ";
    PrintData(testData.input);
    std::cout << endl;

    if (IsSameTree(testData.output, testData.input))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void CheckResults(TD_T_T testData, TreeNode* result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (IsSameTree(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_T_B testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_T_B testData, bool result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_T_T_B testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}
void CheckResults(TD_T_T_B testData, bool result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_L_L_L testData)
{
    std::cout << "Input1 :";
    PrintList(testData.input);
    std::cout << endl;
    std::cout << "Input2 :";
    PrintList(testData.input2);
    std::cout << endl;
}

void CheckResults(TD_L_L_L testData, ListNode* result)
{
    std::cout << "Output: ";
    PrintList(result);
    std::cout << endl;

    if (IsEqualLinkedList(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintList(testData.output);
    }

    std::cout << endl;
}

void PrintInput(TD_L_I_L testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}

void CheckResults(TD_L_I_L testData, ListNode* result)
{
    std::cout << "Output: ";
    PrintList(result);
    std::cout << endl;

    if (IsEqualLinkedList(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintList(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_L_I_I_L testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;

    std::cout << "Input3 :";
    PrintData(testData.input3);
    std::cout << endl;
}
void CheckResults(TD_L_I_I_L testData, ListNode* result)
{
    std::cout << "Output: ";
    PrintList(result);
    std::cout << endl;

    if (IsEqualLinkedList(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintList(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

// Print out tree node in width traversal order
void PrintTree(TreeNode* root)
{
    queue<TreeNode*> nodes;
    nodes.push(root);
    cout << "{ ";

    while (!nodes.empty())
    {
        root = nodes.front();
        nodes.pop();

        if (root == nullptr)
        {
            cout << "null" << " ";
        }
        else
        {
            cout << root->val << " ";
            nodes.push(root->left);
            nodes.push(root->right);
        }
    }

    cout << "} ";

}

// Use pre-order traversal, compare each of the node. 
// Note: unlike regual traversal, the null node can't be
// left out without comparing.
bool IsSameTree(TreeNode* p, TreeNode* q)
{
    if (p == nullptr && q == nullptr)
    {
        return true;
    }

    if ((p != nullptr && q == nullptr) ||
        (p == nullptr && q != nullptr))
    {
        return false;
    }

    bool result = true;

    stack<TreeNode*> nodes_p, nodes_q;
    nodes_p.push(p);
    nodes_q.push(q);

    while (!nodes_p.empty() && !nodes_q.empty())
    {
        p = nodes_p.top();
        nodes_p.pop();

        q = nodes_q.top();
        nodes_q.pop();

        if (p == nullptr && q == nullptr)
        {
            continue;
        }

        if ((p != nullptr && q == nullptr) ||
            (p == nullptr && q != nullptr))
        {
            result = false;
            break;
        }

        if (p->val != q->val)
        {
            result = false;
            break;
        }

        // Push right first so that visit it last
        nodes_p.push(p->right);
        nodes_p.push(p->left);

        nodes_q.push(q->right);
        nodes_q.push(q->left);

    }

    if (!nodes_p.empty() || !nodes_q.empty())
    {
        result = false;
    }

    return result;
}

bool CheckResult(vector<int> v, TreeLinkNode* root)
{
    if (v.size() == 0 && root == nullptr)
    {
        return true;
    }

    if (root == nullptr)
    {
        return false;
    }

    queue<TreeLinkNode*> nodes;
    nodes.push(root);

    int count = 0;
    while (!nodes.empty())
    {
        int width_of_level = nodes.size();

        TreeLinkNode* cur = nodes.front();
        TreeLinkNode* next = cur;

        for (int i = 0; i < width_of_level; i++)
        {
            if (next)
            {
                if (next->val != v[count++])
                {
                    return false;
                }
                
                next = next->next;
            }
            

            cur = nodes.front();
            nodes.pop();

            if (cur->left)
            {
                nodes.push(cur->left);
            }

            if (cur->right)
            {
                nodes.push(cur->right);
            }
        }

        if (next != nullptr || v[count++] != NULL_NODE_VALUE)
        {
            return false;
        }
    }

    return true;
}

void PrintData(TreeLinkNode* root)
{
    if (root == nullptr)
    {
        cout << "#";
        return;
    }

    queue<TreeLinkNode*> nodes;
    nodes.push(root);

    while (!nodes.empty())
    {
        int width_of_level = nodes.size();

        TreeLinkNode* cur = nodes.front();
        TreeLinkNode* next = cur;

        for (int i = 0; i < width_of_level; i++)
        {
            if (next)
            {
                cout << next->val << " ,";
                next = next->next;
            }

            cur = nodes.front();
            nodes.pop();

            if (cur->left)
            {
                nodes.push(cur->left);
            }

            if (cur->right)
            {
                nodes.push(cur->right);
            }
        }

        if (next == nullptr)
        {
            cout << "#";
        }

        if (!nodes.empty())
        {
            cout << " ,";
        }
    }
}

void PrintInput(TD_N_VI data)
{
    std::cout << "Input :";
    PrintTree(reinterpret_cast<TreeNode*>(data.input));
    std::cout << endl;
}

void CheckResults(TD_N_VI testData, TreeLinkNode* result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (CheckResult(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}


TreeLinkNode* GenerateTreeLinkedList(vector<int> v)
{
    if (v.size() == 0)
    {
        return nullptr;
    }
    queue<TreeLinkNode*> nodes;
    TreeLinkNode* root = new TreeLinkNode(v[0]);
    nodes.push(root);


    int count = 1;
    while (!nodes.empty())
    {
        TreeLinkNode* cur = nodes.front();
        nodes.pop();

        if (count < v.size() && v[count] != NULL_NODE_VALUE)
        {
            TreeLinkNode* node = new TreeLinkNode(v[count]);
            cur->left = node;
            nodes.push(node);
        }
        else
        {
            cur->left = nullptr;
        }
        ++count;

        if (count < v.size() && v[count] != NULL_NODE_VALUE)
        {
            TreeLinkNode* node = new TreeLinkNode(v[count]);
            cur->right = node;
            nodes.push(node);
        }
        else
        {
            cur->right = nullptr;
        }
        ++count;
    }

    return root;
}

void PrintGraph(GraphNode* start)
{
    if (start == nullptr)
    {
        return;
    }

    cout << "{" << endl;

    unordered_set<GraphNode*> new_visited;
    queue<GraphNode*> pending_vertices;
    pending_vertices.push(start);

    while (!pending_vertices.empty())
    {
        GraphNode* cur_node = pending_vertices.front();
        pending_vertices.pop();

        cout << cur_node->val << "-";
        new_visited.insert(cur_node);

        cout << "{";
        for (int i = 0; i < cur_node->neighbors.size(); i++)
        {
            if (new_visited.find(cur_node->neighbors[i]) == new_visited.end())
            {
                pending_vertices.push(cur_node->neighbors[i]);
                //new_visited.insert(cur_node->neighbors[i]);
            }

            cout<< cur_node->neighbors[i]->val<<" ";
        }

        cout << "}"<<endl;
    }

    cout << "}" << endl;
}

GraphNode* GenerateGraph(vector<vector<int>> v)
{
    if (v.size() == 0)
    {
        return nullptr;
    }

    map<int, GraphNode*> new_visited;
    queue<GraphNode*> pending_vertices;

    GraphNode* new_node = new GraphNode(1);
    pending_vertices.push(new_node);

    while (!pending_vertices.empty())
    {
        GraphNode* cur_node = pending_vertices.front();
        pending_vertices.pop();

        vector<int> children_val = v[cur_node->val - 1];

        new_visited[cur_node->val] = cur_node;

        for (int i = 0; i < children_val.size(); i++)
        {
            if (new_visited.find(children_val[i]) == new_visited.end())
            {
                GraphNode* new_child = new GraphNode(children_val[i]);
                cur_node->neighbors.push_back(new_child);

                pending_vertices.push(new_child);

                new_visited[children_val[i]] = new_child;
            }
            else
            {
                cur_node->neighbors.push_back(new_visited[children_val[i]]);
            }
        }
    }

    return new_node;
}
bool AreSameGraph(GraphNode* p, GraphNode* q)
{
    if (!p && !q)
    {
        return true;
    }

    if (!p || !q)
    {
        return false;
    }

    map<GraphNode*, GraphNode*> new_visited;
    queue<GraphNode*> pending_vertices;
    pending_vertices.push(p);

    new_visited[p]=q;

    while (!pending_vertices.empty())
    {
        GraphNode* cur_p = pending_vertices.front();
        pending_vertices.pop();

        GraphNode* cur_q = new_visited[cur_p];

        if (cur_p->val != cur_q->val)
        {
            return false;
        }

        if (!AreSameAdjacentList(cur_p->neighbors, cur_q->neighbors))
        {
            return false;
        }

        for (int i = 0; i < cur_p->neighbors.size(); i++)
        {
            if (new_visited.find(cur_p->neighbors[i]) == new_visited.end())
            {
                pending_vertices.push(cur_p->neighbors[i]);
                new_visited[cur_p->neighbors[i]] = cur_q->neighbors[i];
            }
        }
    }

    return true;
}


void PrintLoopList(ListNode* l, int loop_index)
{
    if (nullptr == l)
    {
        std::cout << "null";
        return;
    }

    int counter = 0;
    ListNode* loop_node = nullptr;

    ListNode* p = l;
    while (p && p != loop_node)
    {
        if (counter == loop_index)
        {
            loop_node = p;
        }

        ++counter;

        std::cout << "[" << p->val << "]";
        if (p->next)
        {
            std::cout << "-";
        }

        p = p->next;
    }

    if (p && loop_index != -1)
    {
        std::cout << "==>" << loop_node->val << "(index: " << loop_index << ")";
    }
    else
    {
        std::cout << "==>" << "#";
    }
}
ListNode* GenerateLoopLinkedList(vector<int> v, int loop_index)
{
    ListNode* head = GenerateLinkedList(v);

    if (nullptr == head)
    {
        return nullptr;
    }

    int counter = 0;
    ListNode* loop_node = nullptr;

    if (loop_index == 0)
    {
        loop_node = head;
    }

    ListNode* p = head;
    while (p)
    {
        if (counter == loop_index)
        {
            loop_node = p;
        }

        ++counter;

        if (p->next == nullptr)
        {
            break;
        }

        p = p->next;
    }

    if (p->next == nullptr)
    {
        p->next = loop_node;
    }

    return head;
}
bool IsEqualLoopLinkedList(ListNode* l, ListNode* r)
{
    cout << "Not implemented" << endl;

    return false;
}