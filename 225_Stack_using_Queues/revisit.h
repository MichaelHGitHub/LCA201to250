#pragma once 

#include <queue>

class MyStack {
public:
    MyStack() {
        pQMain = &q1;
        pQTop = &q2;
    }

    void push(int x) {
        pQMain->push(x);

        while (pQMain->size() > 1)
        {
            pQTop->push(pQMain->front());
            pQMain->pop();
        }

        std::queue<int>* temp = pQMain;
        pQMain = pQTop;
        pQTop = temp;
    }

    int pop() {
        int val = pQTop->front();
        pQTop->pop();

        if (pQMain->size() > 0)
        {
            pQTop->push(pQMain->front());
            pQMain->pop();
        }
        return val;
    }

    int top() {
        return pQTop->front();
    }

    bool empty() {
        return q1.empty() && q2.empty();
    }

private:
    std::queue<int> q1;
    std::queue<int> q2;
    std::queue<int>* pQMain;
    std::queue<int>* pQTop;

    void SwapQueue()
    {
        while (pQMain->size() > 1)
        {
            pQTop->push(pQMain->front());
            pQMain->pop();
        }

        std::queue<int>* temp = pQMain;
        pQMain = pQTop;
        pQTop = temp;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */