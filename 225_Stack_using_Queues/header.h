#pragma once

#include <queue>
#include "../common/common.h"


class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        main = &q1;
        storage = &q2;
    }

    /** Push element x onto stack. */
    void push(int x) {
        main->push(x);
        while (main->size() > 1)
        {
            storage->push(main->front());
            main->pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int re = main->front();
        main->pop();
        while (storage->size() > 1)
        {
            main->push(storage->front());
            storage->pop();
        }
        queue<int>* temp = main;
        main = storage;
        storage = temp;

        return re;
    }

    /** Get the top element. */
    int top() {
        return main->front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return main->empty() && storage->empty();
    }

private:
    queue<int> q1;
    queue<int> q2;
    queue<int>* main;
    queue<int>* storage;

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */