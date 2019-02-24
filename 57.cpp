//
// Created by 梁栋 on 2019-02-22.
//
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
class SumToS{
public:
    static void findTwoNumberSumS(vector<int> nums, int s){
        int start = 0;
        int end = nums.size()-1;
        while(start < end){
            if(nums[start] + nums[end] == s){
                cout<<nums[start]<<" + "<<nums[end]<<" = "<<s<<endl;
                return;
            }
            if((nums[start] + nums[end]) > s)
                end -= 1;
            else
                start += 1;
        }
    }
    static void findNumbersSumS(int s){
        deque<int> record;
        int sum = 0;
        for(int i=1;i<=(s/2+1);i++) {

            sum += i;
            record.push_back(i);
            if(sum == s){
                int start = record.front();
                int end = record.back();
                for(;start<=end;start += 1){
                    cout<<start;
                    if(start != end)
                        cout<<" + ";
                    else
                        cout<<" = "<<s<<endl;
                }
            }
            if(sum > s){
                while(sum > s){
                    sum -= record.front();
                    record.pop_front();
                }
                if(sum == s){
                    int start = record.front();
                    int end = record.back();
                    for(;start<=end;start += 1){
                        cout<<start;
                        if(start != end)
                            cout<<" + ";
                        else
                            cout<<" = "<<s<<endl;
                    }
                }
            }
        }
    }
};
class Solution{
public:
    static void solution(){
        vector<int> nums = {1, 2, 4, 7, 11, 15};
        SumToS::findTwoNumberSumS(nums, 15);
        SumToS::findNumbersSumS(15);
    }
};