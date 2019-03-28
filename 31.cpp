//
// Created by 梁栋 on 2019-03-28.
// 给定两个序列，一个输入压栈，判断另一个有没有可能是输出序列
//
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty() && popV.empty())
            return true;
        if(pushV.size() != popV.size())
            return false;
        stack<int> temp;
        int idx = 0;
        int idx_push = 0;
        while(true){
            while(temp.empty() || temp.top() != popV[idx]){
                if(idx_push >= pushV.size()){
                    break;
                }
                temp.push(pushV[idx_push]);
                idx_push++;
            }
            while(!temp.empty() && temp.top() == popV[idx]){
                temp.pop();
                idx += 1;
            }
            if(idx_push >= pushV.size()){
                if(!temp.empty()){
                    return false;
                }
                break;
            }
        }
        return true;
    }
};