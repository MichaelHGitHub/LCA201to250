#pragma once

#include <stack>
#include "header.h"

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        main = &s;
        helper1 = &s1;
        helper2 = &s2;
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        helper1->push(x);

        // Need to flip the elements twice to get it right.
        while (!main->empty())
        {
            helper2->push(main->top());
            main->pop();
        }
        while (!helper2->empty())
        {
            helper1->push(helper2->top());
            helper2->pop();
        }

        // Swap main and helper1;
        stack<int>* temp = main;
        main = helper1;
        helper1 = temp;
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int r = main->top();
        main->pop();
        return r;
    }

    /** Get the front element. */
    int peek() {
        return main->top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return main->empty();
    }

    stack<int> s;
    stack<int> s1;
    stack<int> s2;
    stack<int>* main;
    stack<int>* helper1;
    stack<int>* helper2;

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */