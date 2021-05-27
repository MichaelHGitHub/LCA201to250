#include "header.h"

int main(char* args[], int argc)
{
    MyStack* obj = new MyStack();
    obj->push(10);
    obj->push(8);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();


    return 0;

}