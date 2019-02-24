//
// Created by 梁栋 on 2019-02-18.
//
#include <vector>
#include <iostream>
using namespace std;
class MaxSumSubArray{
public:
    struct Result{
        int finalMaxSum;
        int start_pos;
        int end_pos;
    };
    static Result core_1(vector<int> nums){
        // 动态规划
        // f(i) = {data[i] if i == 0 or f(i-1) < 0; f(n-1) + data[i] if i != 0 or f(i+1) >= 0}
        int size = nums.size();
        int f[size];
        int start_pos[size];
        memset(f, 0, sizeof(int) * size);
        memset(start_pos, 0, sizeof(int) * size);
        f[0] = nums[0];
        for(int i=1;i<size;i++){
            if(f[i-1] < 0){
                f[i] = nums[i];
                start_pos[i] = i;
                continue;
            }
            start_pos[i] = start_pos[i-1];
            f[i] = f[i-1] + nums[i];
        }
        Result result = Result();
        result.finalMaxSum = 0;
        result.start_pos = 0;
        result.end_pos = 0;
        for(int i=0;i<size;i++){
            if(result.finalMaxSum < f[i]){
                result.finalMaxSum = f[i];
                result.end_pos = i;
                result.start_pos = start_pos[i];
            }
        }
//        delete [] f;
//        delete [] start_pos;
        return result;
    }
    static Result core(vector<int> nums){
        // 贪心的解法
        Result result = Result();
        result.finalMaxSum = 0;
        result.start_pos = 0;
        result.end_pos = 0;
        int curMaxSum = 0;
        for(int i=0;i<nums.size();i++){
            if(curMaxSum < 0){
                curMaxSum = nums[i];
                result.start_pos = i;
                result.end_pos = i;
                result.finalMaxSum  = max(result.finalMaxSum , curMaxSum);
                continue;
            }
            curMaxSum += nums[i];
            if(result.finalMaxSum <= curMaxSum){
                result.end_pos = i;
                result.finalMaxSum = curMaxSum;
            }
        }
        return result;
    }
};
class Solution{
public:
    static void solution(){
        vector<int> nums = {1, -2, 3, 10, -4, 7, 2, -5};
        MaxSumSubArray::Result result = MaxSumSubArray::core_1(nums);
        cout<<"MaxSumSubArray is "<<result.finalMaxSum<<endl;
        for(int i=result.start_pos;i<=result.end_pos;i++){
            cout<<nums[i]<<",";
        }
        cout<<endl;
    }
};