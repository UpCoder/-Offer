//
// Created by 梁栋 on 2019-03-28.
// 包含min函数的栈
//
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
class StackWithMin{
public:
    stack<int> stack1;
    stack<int> stack_min;
    void push(int value) {
        stack1.push(value);
        if(stack_min.empty()){
            stack_min.push(value);
        }else{
            int min_val = stack_min.top() > value ? value : stack_min.top();
            stack_min.push(min_val);
        }
    }
    void pop() {
        stack1.pop();
        stack_min.pop();
    }
    int top() {
        return stack1.top();
    }
    int min() {
        return stack_min.top();
    }
};
class Solution{
public:
    static void solution(){
        StackWithMin stackWithMin;
        stackWithMin.push(1);
        stackWithMin.push(3);
        stackWithMin.push(0);
        stackWithMin.push(2);
        cout<<stackWithMin.top()<<", "<<stackWithMin.min()<<endl;
        stackWithMin.pop();
        cout<<stackWithMin.top()<<", "<<stackWithMin.min()<<endl;
        stackWithMin.pop();
        cout<<stackWithMin.top()<<", "<<stackWithMin.min()<<endl;
    }
};