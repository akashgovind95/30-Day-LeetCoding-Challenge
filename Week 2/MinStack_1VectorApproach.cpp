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
1. Maintain 1 vector. 
2. Push every incoming element on even indexes. Push current minimum elemnt on odd indexes
3. Pop/return elements accordingly
*/


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    
    vector<int> Stack;
    int sizeOfStack;
    
    MinStack() {
        sizeOfStack=0;
    }
    
    void push(int x) {
        if(sizeOfStack==0){
            Stack.push_back(x);
            Stack.push_back(x);
        }
        else{
            Stack.push_back(x);
            Stack.push_back(min(x,Stack[sizeOfStack-1]));
        }
        sizeOfStack+=2;
    }
    
    void pop() {
        Stack.pop_back();
        Stack.pop_back();
        sizeOfStack-=2;
    }
    
    int top() {
        return Stack[sizeOfStack-2];
    }
    
    int getMin() {
        return Stack[sizeOfStack-1];
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