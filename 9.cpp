//
// Created by 梁栋 on 2019-03-23.
//
#include <stack>
#include <iostream>
using namespace std;
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(!stack2.empty()){
            int num = stack2.top();
            stack2.pop();
            return num;
        }else{
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
            int num = stack2.top();
            stack2.pop();
            return num;
        }
    }
    static void solution(){

    }
private:
    stack<int> stack1;
    stack<int> stack2;
};