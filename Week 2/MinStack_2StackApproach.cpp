/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

*/

/*
Approach:
1. Maintain 2 stacks. 
2. Push every incoming element on stack 1. Push current minimum elemnt on stack 2
3. Pop/return elements accordingly. For every pop, check if you are popping the minimum element from stack 1. If yes, pop from stack 2 as wel..
*/


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MinStack {
public:
   
    stack<int> minStack;
    stack<int> s;
    MinStack() {}
    
    void push(int x) {
        if (minStack.empty() || x <= minStack.top())
            minStack.push(x);
        s.push(x);
    }
    
    void pop() {
       if (s.top() == minStack.top()) 
            minStack.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

int main()
{
    MinStack* obj = new MinStack();
    vector<string> command = {"push","push","push","getMin","top","pop","getMin"};
    vector <vector<int>> value= {{-2},{0},{-1},{},{},{},{}};
    vector<int> res;
    
    for(int i = 0;i<command.size();i++){
        if(command[i] == "push")
            obj->push(value[i][0]);        
        else if(command[i] == "pop")
            obj->pop();
        else if(command[i] == "getMin")
            res.push_back(obj->getMin());
        else
            res.push_back(obj->top());
    }
    
    
    for(auto i : res)
        cout<<i<<" ";
    return 0;
}