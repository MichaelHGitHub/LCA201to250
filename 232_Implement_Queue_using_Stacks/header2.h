#pragma once

#include <stack>
#include "header.h"

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        input.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        peek();
        int r = output.top();;
        output.pop();
        return r;
    }

    /** Get the front element. */
    int peek() {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return input.empty() && output.empty();
    }

private:
    stack<int> input;
    stack<int> output;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */#pragma once
