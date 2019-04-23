//
// Created by 梁栋 on 2019-04-22.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
public:
    int Partition(vector<int>& numbers, int length, int start, int end){
        int pos_start = start;
        int first_num = numbers[start];
        while(start < end){
            while(end > start && numbers[end] >= first_num){
                end -= 1;
            }
            numbers[start] = numbers[end];
            while(end > start && numbers[start] <= first_num){
                start += 1;
            }
            numbers[end] = numbers[start];
        }
        numbers[start] = first_num;
        return start;
    }
    int MoreThanHalfNum_SolutionV2(vector<int> numbers){
        int n = (int) numbers.size();
        if(n == 0)
            return 0;
        int mid = n >> 1;
        int start = 0;
        int end = n-1;
        int pos = Partition(numbers, n, 0, n-1);
        while(pos != mid){
            if(pos > mid){
                end = pos-1;
                pos = Partition(numbers, n, start, end);
            }else{
                start = pos + 1;
                pos = Partition(numbers, n, start, end);
            }
        }
        int last = numbers[pos];
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(numbers[i] == last)
                cnt += 1;
        }
        if(cnt >= ceil(n / 2.)){
            return last;
        }else{
            return 0;
        }
    }
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n = (int) numbers.size();
        if(n == 0)
            return 0;
        int cnt = 0;
        int last;
        for(int i=0;i<n;i++){
            if(cnt == 0){
                cnt += 1;
                last = numbers[i];
            }else{
                if(numbers[i] == last){
                    cnt += 1;
                }else{
                    cnt -= 1;
                }
            }
        }
        if(cnt == 0){
            return 0;
        }
        cnt = 0;
        for(int i=0;i<n;i++){
            if(numbers[i] == last)
                cnt += 1;
        }
        if(cnt >= ceil(n / 2)){
            return last;
        }else{
            return 0;
        }
    }

    static void solution(){
        Solution solution1;
        cout<<solution1.MoreThanHalfNum_SolutionV2({4,2,1,4,2,4})<<endl;
    }
};