//
// Created by 梁栋 on 2019-04-23.
// 找到最小的K个数
//
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
struct cmp{
    bool operator()(int a, int b){
        if(a > b)
            return true;
        return false;
    }
};
class Solution {
public:
    int Partition(vector<int>& input, int start, int end){
        if(start < 0 || end >= input.size()){
            return -1;
        }
        if(start > end)
            return -1;
        int first_num = input[start];
        while(start < end){
            while(start < end && input[end] >= first_num){
                end -= 1;
            }
            input[start] = input[end];
            while (start < end && input[start] <= first_num){
                start += 1;
            }
            input[end] = input[start];
        }
        input[start] = first_num;
        return start;
    }
    vector<int> GetLeastNumbers_SolutionV2(vector<int> input, int k) {

        if(input.size() == 0)
            return {};
        vector<int> res;
        priority_queue<int, vector<int>, cmp> queue1; // 默认为最大堆
        for(int i=0;i<input.size();i++){
            queue1.push(input[i]);
        }
        int cnt = 0;
        while(!queue1.empty() && cnt < k){
            res.push_back(queue1.top());
            queue1.pop();
            cnt += 1;
        }
        return res;

    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.size() == 0)
            return {};
        int start_pos = 0;
        int end_pos = input.size()-1;
        int pos = Partition(input, start_pos, end_pos);
        while(pos != (k-1)){
            if(pos > (k-1)){
                end_pos = pos - 1;
                pos = Partition(input, start_pos, end_pos);
                if(pos == -1)
                    return {};
            }else{
                start_pos = pos + 1;
                pos = Partition(input, start_pos, end_pos);
                if(pos == -1)
                    return {};
            }
        }
        vector<int> res = {};
        for(int i=0;i<k;i++){
            res.push_back(input[i]);
        }
        return res;
    }
    static void solution(){
        Solution solution1;
        vector<int> input = {4,5,1,6,2,7,3,8};
        vector<int> res = solution1.GetLeastNumbers_SolutionV2(input, 4);
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<",";
        }
        cout<<endl;
    }
};