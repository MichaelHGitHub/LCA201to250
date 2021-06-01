#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

#ifdef GRAPH_NODE
    #define Node GraphNode
#endif

#ifdef RANDOM_LIST_NODE
    #define Node RandomListNode
#endif

#ifdef TREE_LINK_NODE
    #define Node TreeLinkNode
#endif

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


// Definition for a Tree-Link TreeLinkNode.
struct TreeLinkNode {
public:
    int val;
    TreeLinkNode* left;
    TreeLinkNode* right;
    TreeLinkNode* next;

    TreeLinkNode() : val(0), left(NULL), right(NULL), next(NULL) {}

    TreeLinkNode(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    TreeLinkNode(int _val, TreeLinkNode* _left, TreeLinkNode* _right, TreeLinkNode* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// Definition for a Graph TreeLinkNode.
struct GraphNode {
public:
    int val;
    vector<GraphNode*> neighbors;
    GraphNode() {
        val = 0;
        neighbors = vector<GraphNode*>();
    }
    GraphNode(int _val) {
        val = _val;
        neighbors = vector<GraphNode*>();
    }
    GraphNode(int _val, vector<GraphNode*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


// Definition for a Node.
class RandomListNode {
public:
    int val;
    RandomListNode* next;
    RandomListNode* random;

    RandomListNode(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


#define NULL_NODE_VALUE INT32_MIN-99

template<typename T>
void PrintData(T t);

template<typename T>
void PrintData(vector<T> v);

template<>
void PrintData(vector<int> v);

template<typename T>
bool AreVectorEqual(vector<T> v1, vector<T> v2);

template<typename T>
bool Are2DimensionArrayEqual(vector<vector<T>> array1, vector<vector<T>> array2);

template<typename T>
bool Are2DimensionSetEqual(vector<vector<T>> array1, vector<vector<T>> array2);

void PrintList(ListNode* l);
ListNode* GenerateLinkedList(vector<int> v);
bool IsEqualLinkedList(ListNode* l, ListNode* r);

void PrintLoopList(ListNode* l, int loop_index);
ListNode* GenerateLoopLinkedList(vector<int> v, int loop_index);
bool IsEqualLoopLinkedList(ListNode* l, ListNode* r);

void PrintTree(TreeNode* root);
TreeNode* GenerateTree(vector<int> v);
bool IsSameTree(TreeNode* p, TreeNode* q);

void PrintGraph(GraphNode* root);
GraphNode* GenerateGraph(vector<vector<int>> v);
bool AreSameGraph(GraphNode* p, GraphNode* q);
bool AreSameAdjacentList(vector<GraphNode*> v1, vector<GraphNode*> v2);

vector<TreeNode*> GenerateTrees(vector<vector<int>> v);

TreeLinkNode* GenerateTreeLinkedList(vector<int> values);

struct TD_N_VI
{
    TreeLinkNode* input;
    vector<int> output;
};

struct TD_L_L
{
    ListNode* input;
    ListNode* output;
};

struct TD_L_L_L
{
    ListNode* input;
    ListNode* input2;
    ListNode* output;
};

struct TD_L_I_L
{
    ListNode* input;
    int input2;
    ListNode* output;
};

struct TD_CL_L
{
    ListNode* input;
    int loop_index;
    ListNode* output;
};

struct TD_CL_B
{
    ListNode* input;
    int loop_index;
    bool output;
};

struct TD_L_I_I_L
{
    ListNode* input;
    int input2;
    int input3;
    ListNode* output;
};

struct TD_L_T
{
    ListNode* input;
    TreeNode* output;
};

struct TD_T_I
{
    TreeNode* input;
    int output;
};

struct TD_T_I_I
{
    TreeNode* input;
    int input2;
    int output;
};

struct TD_T_I_B
{
    TreeNode* input;
    int input2;
    bool output;
};

struct TD_G_G
{
    GraphNode* input;
    GraphNode* output;
};


struct TD_VI_T
{
    vector<int> input;
    TreeNode* output;
};

struct TD_VI_VI_T
{
    vector<int> input;
    vector<int> input2;
    TreeNode* output;
};

struct TD_T_VI
{
    TreeNode* input;
    vector<int> output;
};

struct TD_T_VVI
{
    TreeNode* input;
    vector<vector<int>> output;
};

struct TD_T_I_VVI
{
    TreeNode* input;
    int input2;
    vector<vector<int>> output;
};

struct TD_I_VT
{
    int input;
    vector<TreeNode*> output;
};

struct TD_T_T
{
    TreeNode* input;
    TreeNode* output;
};

struct TD_T_B
{
    TreeNode* input;
    bool output;
};

struct TD_T_T_B
{
    TreeNode* input;
    TreeNode* input2;
    bool output;
};

struct TD_S_S
{
    string input;
    string output;
};

struct TD_S_I
{
    string input;
    int output;
};

struct TD_S_S_I
{
    string input;
    string input2;
    int output;
};

struct TD_S_S_S_B
{
    string input;
    string input2;
    string input3;
    bool output;
};

struct TD_S_I_S
{
    string input;
    int input2;
    string output;
};

struct TD_S_B
{
    string input;
    bool output;
};

struct TD_S_S_B
{
    string input;
    string input2;
    bool output;
};

struct TD_S_S_S
{
    string input;
    string input2;
    string output;
};


struct TD_S_VS
{
    string input;
    vector<string> output;
};

struct TD_VS_I
{
    vector<string> input;
    int output;
};

struct TD_VS_S
{
    vector<string> input;
    string output;
};

struct TD_S_VS_B
{
    string input;
    vector<string> input2;
    bool output;
};

struct TD_S_VS_VS
{
    string input;
    vector<string> input2;
    vector<string> output;
};

struct TD_VS_VVS
{
    vector<string> input;
    vector<vector<string>> output;
};

struct TD_S_VVS
{
    string input;
    vector<vector<string>> output;
};

struct TD_I_S
{
    int input;
    string output;
};

struct TD_I_I_S
{
    int input;
    int input2;
    string output;
};

struct TD_I_B
{
    int input;
    bool output;
};

struct TD_I_VI
{
    int input;
    vector<int> output;
};

struct TD_I_VS
{
    int input;
    vector<string> output;
};

struct TD_I_I
{
    int input;
    int output;
};

struct TD_I_I_I
{
    int input;
    int input2;
    int output;
};

struct TD_I_I_VVI
{
    int input;
    int input2;
    vector<vector<int>> output;
};

struct TD_I_VVI_B
{
    int input;
    vector<vector<int>> input2;
    bool output;
};

struct TD_D_I_D
{
    double input;
    int input2;
    double output;
};

struct TD_VI_I
{
    vector<int> input;
    int output;
};

struct TD_VI_VS
{
    vector<int> input;
    vector<string> output;
};

struct TD_VI_B
{
    vector<int> input;
    bool output;
};

struct TD_VI_S
{
    vector<int> input;
    string output;
};

struct TD_VI_I_B
{
    vector<int> input;
    int input2;
    bool output;
};

struct TD_VI_I_I_B
{
    vector<int> input;
    int input2;
    int input3;
    bool output;
};

struct TD_VI_VI
{
    vector<int> input;
    vector<int> output;
};

struct TD_VI_VI_I
{
    vector<int> input;
    vector<int> input2;
    int output;
};

struct TD_VI_I_VI_I_VI
{
    vector<int> input;
    int input2;
    vector<int> input3;
    int input4;
    vector<int> output;
};

struct TD_VVI_I
{
    vector<vector<int>> input;
    int output;
};

struct TD_VVI_I_B
{
    vector<vector<int>> input;
    int input2;
    bool output;
};

struct TD_VVI_VI
{
    vector<vector<int>> input;
    vector<int> output;
};

struct TD_VVI_VI_VVI
{
    vector<vector<int>> input;
    vector<int> input2;
    vector<vector<int>> output;
};

struct TD_I_VVI_VI
{
    int input;
    vector<vector<int>> input2;
    vector<int> output;
};

struct TD_VI_VI_D
{
    vector<int> input;
    vector<int> input2;
    double output;
};

struct TD_VI_VVI
{
    vector<int> input;
    vector<vector<int>> output;
};

struct TD_I_VVI
{
    int input;
    vector<vector<int>> output;
};

struct TD_VVI_VVI
{
    vector<vector<int>> input;
    vector<vector<int>> output;
};

struct TD_VI_I_VI
{
    vector<int> input;
    int input2;
    vector<int> output;
};

struct TD_VI_I_VVI
{
    vector<int> input;
    int input2;
    vector<vector<int>> output;
};

struct TD_VI_I_I
{
    vector<int> input;
    int input2;
    int output;
};

struct TD_I_VI_I
{
    int input;
    vector<int> input2;
    int output;
};


struct TD_VL_L
{
    vector< ListNode*> input;
    ListNode* output;
};

struct TD_VVC_I
{
    vector<vector<char>> input;
    int output;
};

struct TD_VVC_B
{
    vector<vector<char>> input;
    bool output;
};

struct TD_VVC_S_B
{
    vector<vector<char>> input;
    string input2;
    bool output;
};

struct TD_VVC_VVC
{
    vector<vector<char>> input;
    vector<vector<char>> output;
};

void PrintInput(TD_N_VI data);
void CheckResults(TD_N_VI data, TreeLinkNode* node);
bool CheckResult(vector<int> output, TreeLinkNode* result);

void PrintInput(TD_S_S testData);
void CheckResults(TD_S_S testData, string result);

void PrintInput(TD_S_I testData);
void CheckResults(TD_S_I testData, int result);

void PrintInput(TD_S_B testData);
void CheckResults(TD_S_B testData, bool result);

void PrintInput(TD_S_S_I testData);
void CheckResults(TD_S_S_I testData, int result);

void PrintInput(TD_S_I_S testData);
void CheckResults(TD_S_I_S testData, string result);

void PrintInput(TD_S_S_B testData);
void CheckResults(TD_S_S_B testData, bool result);

void PrintInput(TD_S_S_S_B testData);
void CheckResults(TD_S_S_S_B testData, bool result);

void PrintInput(TD_S_S_S testData);
void CheckResults(TD_S_S_S testData, string result);

void PrintInput(TD_S_VS testData);
void CheckResults(TD_S_VS testData, vector<string> result);

void PrintInput(TD_I_S testData);
void CheckResults(TD_I_S testData, string result);

void PrintInput(TD_I_I_S testData);
void CheckResults(TD_I_I_S testData, string result);

void PrintInput(TD_I_B testData);
void CheckResults(TD_I_B testData, bool result);

void PrintInput(TD_I_I testData);
void CheckResults(TD_I_I testData, int result);

void PrintInput(TD_I_I_I testData);
void CheckResults(TD_I_I_I testData, int result);


void PrintInput(TD_I_I_VVI testData);
void CheckResults(TD_I_I_VVI testData, vector<vector<int>> result);
void CheckResults_Unorder(TD_I_I_VVI testData, vector<vector<int>> result);

void PrintInput(TD_I_VVI_B testData);
void CheckResults(TD_I_VVI_B testData, bool result);

void PrintInput(TD_D_I_D testData);
void CheckResults(TD_D_I_D testData, double result);

void PrintInput(TD_I_VI testData);
void CheckResults(TD_I_VI testData, vector<int> result);

void PrintInput(TD_I_VS testData);
void CheckResults(TD_I_VS testData, vector<string> result);

void PrintInput(TD_VI_I testData);
void CheckResults(TD_VI_I testData, int result);

void PrintInput(TD_VI_VS testData);
void CheckResults(TD_VI_VS testData, vector<string> result);

void PrintInput(TD_VI_B testData);
void CheckResults(TD_VI_B testData, bool result);

void PrintInput(TD_VI_S testData);
void CheckResults(TD_VI_S testData, string result);

void PrintInput(TD_VI_I_B testData);
void CheckResults(TD_VI_I_B testData, bool result);

void PrintInput(TD_VI_I_I_B testData);
void CheckResults(TD_VI_I_I_B testData, bool result);

void PrintInput(TD_VI_VI_I testData);
void CheckResults(TD_VI_VI_I testData, int result);

void PrintInput(TD_VS_I testData);
void CheckResults(TD_VS_I testData, int result);

void PrintInput(TD_VS_S testData);
void CheckResults(TD_VS_S testData, string result);

void PrintInput(TD_S_VS_B testData);
void CheckResults(TD_S_VS_B testData, bool result);

void PrintInput(TD_S_VS_VS testData);
void CheckResults(TD_S_VS_VS testData, vector<string> result);
void CheckResults_Unorder(TD_S_VS_VS testData, vector<string> result);

void PrintInput(TD_VS_VVS testData);
void CheckResults(TD_VS_VVS testData, vector<vector<string>> result);
void CheckResults_Unoder(TD_VS_VVS testData, vector<vector<string>> result);

void PrintInput(TD_S_VVS testData);
void CheckResults(TD_S_VVS testData, vector<vector<string>> result);
void CheckResults_Unoder(TD_S_VVS testData, vector<vector<string>> result);


void PrintInput(TD_VI_I_VI testData);
void CheckResults(TD_VI_I_VI testData, vector<int> result);

void PrintInput(TD_VI_I_I testData);
void CheckResults(TD_VI_I_I testData, int result);

void PrintInput(TD_I_VI_I testData);
void CheckResults(TD_I_VI_I testData, int result);

void PrintInput(TD_VI_VVI testData);
void CheckResults(TD_VI_VVI testData, vector<vector<int>> result);
void CheckResults_Unorder(TD_VI_VVI testData, vector<vector<int>> result);

void PrintInput(TD_VVI_VVI testData);
void CheckResults(TD_VVI_VVI testData, vector<vector<int>> result);
void CheckResults_Unorder(TD_VVI_VVI testData, vector<vector<int>> result);


void PrintInput(TD_VI_I_VVI testData);
void CheckResults(TD_VI_I_VVI testData, vector<vector<int>> result);
void CheckResults_Unorder(TD_VI_I_VVI testData, vector<vector<int>> result);

void PrintInput(TD_VVC_B testData);
void CheckResults(TD_VVC_B testData, bool result);

void PrintInput(TD_VVC_I testData);
void CheckResults(TD_VVC_I testData, int result);

void PrintInput(TD_VVC_S_B testData);
void CheckResults(TD_VVC_S_B testData, bool result);

void PrintInput(TD_VI_VI_D testData);
void CheckResults(TD_VI_VI_D testData, double result);

void PrintInput(TD_VI_VI testData);
void CheckResults(TD_VI_VI testData, vector<int> result);

void PrintInput(TD_VI_I_VI_I_VI testData);
void CheckResults(TD_VI_I_VI_I_VI testData, vector<int> result);

void PrintInput(TD_VVI_I testData);
void CheckResults(TD_VVI_I testData, int result);

void PrintInput(TD_VVI_I_B testData);
void CheckResults(TD_VVI_I_B testData, int result);

void PrintInput(TD_VVI_VI testData);
void CheckResults(TD_VVI_VI testData, vector<int> result);

void PrintInput(TD_I_VVI_VI testData);
void CheckResults(TD_I_VVI_VI testData, vector<int> result);

void PrintInput(TD_I_VVI testData);
void CheckResults(TD_I_VVI testData, vector<vector<int>> result);

void PrintInput(TD_VVI_VI_VVI testData);
void CheckResults(TD_VVI_VI_VVI testData, vector<vector<int>> result);

void PrintInput(TD_VVC_VVC testData);
void CheckResults(TD_VVC_VVC testData, vector<vector<char>> result);

void PrintInput(TD_L_L testData);
void CheckResults(TD_L_L testData, ListNode* result);

void PrintInput(TD_CL_B testData);
void CheckResults(TD_CL_B testData, bool result);

void PrintInput(TD_CL_L testData);
void CheckResults(TD_CL_L testData, ListNode* result);

void PrintInput(TD_L_T testData);
void CheckResults(TD_L_T testData, TreeNode* result);

void PrintInput(TD_T_I testData);
void CheckResults(TD_T_I testData, int result);

void PrintInput(TD_T_I_I testData);
void CheckResults(TD_T_I_I testData, int result);

void PrintInput(TD_T_I_B testData);
void CheckResults(TD_T_I_B testData, bool result);

void PrintInput(TD_VI_VI_T testData);
void CheckResults(TD_VI_VI_T testData, TreeNode* result);

void PrintInput(TD_VI_T testData);
void CheckResults(TD_VI_T testData, TreeNode* result);

void PrintInput(TD_T_VI testData);
void CheckResults(TD_T_VI testData, vector<int> result);

void PrintInput(TD_T_VVI testData);
void CheckResults(TD_T_VVI testData, vector<vector<int>> result);
void CheckResults_Unorder(TD_T_VVI testData, vector<vector<int>> result);

void PrintInput(TD_T_I_VVI testData);
void CheckResults(TD_T_I_VVI testData, vector<vector<int>> result);
void CheckResults_Unorder(TD_T_I_VVI testData, vector<vector<int>> result);

void PrintInput(TD_I_VT testData);
void CheckResults(TD_I_VT testData, vector<TreeNode*> result);

void PrintInput(TD_T_B testData);
void CheckResults(TD_T_B testData, bool result);

void PrintInput(TD_T_T testData);
void CheckResults(TD_T_T testData);
void CheckResults(TD_T_T testData, TreeNode* result);

void PrintInput(TD_T_T_B testData);
void CheckResults(TD_T_T_B testData, bool result);

void PrintInput(TD_L_L_L testData);
void CheckResults(TD_L_L_L testData, ListNode* result);

void PrintInput(TD_L_I_L testData);
void CheckResults(TD_L_I_L testData, ListNode* result);

void PrintInput(TD_L_I_I_L testData);
void CheckResults(TD_L_I_I_L testData, ListNode* result);

void PrintInput(TD_VL_L testData);
void CheckResults(TD_VL_L testData, ListNode* result);

void PrintInput(TD_G_G testData);
void CheckResults(TD_G_G testData, GraphNode* result);


