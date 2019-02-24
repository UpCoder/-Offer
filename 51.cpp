//
// Created by 梁栋 on 2019-02-19.
//
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class NumberOfInversePairs{
private:
    static int findNumberOfInversePairs_Core(int* nums, int* copy, int start, int end){
        if(start == end){
            copy[start] = nums[start];
            return 0;
        }
        int mid = (end-start) >> 1;
        int left = findNumberOfInversePairs_Core(nums, copy, start, start + mid);
        int right = findNumberOfInversePairs_Core(nums, copy, start + mid + 1, end);
        int i = start + mid;
        int j = end;
        int index = end;
        int count = 0;
        while(i >=start && j >= (start + mid  + 1)){
            if(nums[i] > nums[j]){
                copy[index] = nums[i];
                i--;
                index--;
                count += (j - start - mid);
            }else{
                copy[index] = nums[j];
                j--;
                index --;
            }
        }
        while(j >= (start + mid  + 1)){
            copy[index] = nums[j];
            index--;
            j--;
        }
        while(i>=start){
            copy[index] = nums[i];
            index--;
            i--;
        }
        for(int i=start;i<=end;i++){
            nums[i] = copy[i];
        }
        return count + left + right;
    }
public:
    static int findNumberOfInversePairs(int* nums, int n){
        if(nums == NULL){
            return 0;
        }
        int copy[n];
        return findNumberOfInversePairs_Core(nums, copy, 0, n-1);
    }
};
class Solution{
public:
    static void solution(){
        int nums[4] = {7, 5, 6, 4};
        cout<<"The number of inversed pair is "<<NumberOfInversePairs::findNumberOfInversePairs(nums, 4)<<endl;
        for(int i=0;i<4;i++){
            cout<<nums[i]<<",";
        }
        cout<<endl;
    }
};
