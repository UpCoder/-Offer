//
// Created by 梁栋 on 2019-02-24.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution{
public:
    static void solution(){
        vector<int> nums = {9, 11, 8, 5, 7, 12, 16, 14};
        int min_value = nums[0];
        int max_benefit = 0;
        for(int i=1;i<nums.size();i++){
            max_benefit = max(max_benefit, nums[i] - min_value);
            min_value = min(min_value, nums[i]);
        }
        cout<<"max benefit is "<<max_benefit<<endl;
    }
};
