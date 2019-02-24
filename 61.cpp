//
// Created by 梁栋 on 2019-02-24.
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution{
public:
    static bool isSeq(vector<int > nums){
        sort(nums.begin(), nums.end());
        int num_zero = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i] != 0){
                num_zero = i;
                break;
            }
        }
        for(int i=num_zero;i<nums.size()-1;i++){
            int diff = nums[i + 1] - nums[i];
            if(diff == 0)
                return false;
            diff--;
            num_zero -= diff;
            if(num_zero < 0)
                return false;
        }
        return true;
    }
    static void solution(){
        cout<<isSeq({0, 1, 2, 3, 4, 7})<<endl;
    }
};
