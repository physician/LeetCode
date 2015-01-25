/*
 Author:     physician
 Date:       Jan 25, 2015
 Update:     Jan 25, 2015
 Problem:    Min Stack
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/min-stack/

 Problem Description:
 Min Stack: 

 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

 push(x) -- Push element x onto stack.
 pop() -- Removes the element on top of the stack.
 top() -- Get the top element.
 getMin() -- Retrieve the minimum element in the stack.

 Notes:
 1. First implementation, stack. 
 2. Compile using g++: g++ MinStack.cpp -o MinStack.
*/

 
# include <iostream>
# include <stack>

using namespace std;

class MinStack {
public:
    void push(int x) {
        stk.push(x);
        if (minStk.empty() || x <= minStk.top())
            minStk.push(x);
    }

    void pop() {
        if (stk.top() == minStk.top())
            minStk.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }
    
private:
    stack<int> stk;
    stack<int> minStk;
};


int main() {
    MinStack minStack;
    minStack.push(2);
    minStack.push(1);
    minStack.push(0);
    minStack.push(1);
    minStack.push(3);
    cout << "Push stack: 2,1,0,1,3" << endl;
    cout << "Current top: " << minStack.top() << endl;
    cout << "Current min: " << minStack.getMin() << endl;
    minStack.pop();
    cout << "Pop" << endl;
    cout << "Current top: " << minStack.top() << endl;
    cout << "Current min: " << minStack.getMin() << endl;
    minStack.pop();
    cout << "Pop" << endl;
    cout << "Current top: " << minStack.top() << endl;
    cout << "Current min: " << minStack.getMin() << endl;
    minStack.pop();
    cout << "Pop" << endl;
    cout << "Current top: " << minStack.top() << endl;
    cout << "Current min: " << minStack.getMin() << endl;
    minStack.pop();
    cout << "Pop" << endl;
    cout << "Current top: " << minStack.top() << endl;
    cout << "Current min: " << minStack.getMin() << endl;
}
