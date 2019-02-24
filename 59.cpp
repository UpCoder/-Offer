//
// Created by 梁栋 on 2019-02-22.
//
#include <vector>
#include <deque>
#include <iostream>
#include <queue>
using namespace std;
class MaxValueInQueue{
private:
    deque<int> deque2;
    queue<int> queue1;
public:
    MaxValueInQueue(vector<int> nums){
        for(int i=0;i<nums.size();i++){
            queue1.push(nums[i]);
            if(deque2.empty() or deque2.back() >= nums[i]){
                deque2.push_back(nums[i]);
            }else{
                while(not deque2.empty() and deque2.back() < nums[i])
                    deque2.pop_back();
                deque2.push_back(nums[i]);
            }
        }
    }

    int top(){
        return this->queue1.front();
    }
    void pop(){
        int val = this->queue1.front();
        if(val == this->deque2.front())
            this->deque2.pop_front();
        this->queue1.pop();
    }
    void push(int x){
        this->queue1.push(x);
        while(not deque2.empty() and deque2.back() < x)
            deque2.pop_back();
        deque2.push_back(x);
    }
    int max(){
        return this->deque2.front();
    }
    static void findMaxValueInWindows(vector<int> nums, int k){
        deque<int> deque1;
        int maximum = nums[0];
        int maximum_index = 0;
        for(int i=1;i<k;i++){
            if(maximum <= nums[i]){
                maximum = nums[i];
                maximum_index = i;
            }
        }
        deque1.push_back(maximum_index);
        cout<<maximum<<", ";
        for(int i=k;i<nums.size();i++){
            while (not deque1.empty() && nums[deque1.back()] < nums[i]){
                deque1.pop_back();
            }
            deque1.push_back(i);
            while((i-deque1.front()) >= k)
                deque1.pop_front();
            cout<<nums[deque1.front()]<<", ";
        }
    }
};
class Solution{
public:
    static void solution(){
        MaxValueInQueue::findMaxValueInWindows({2, 3, 4, 2, 6, 2, 5, 1}, 3);
        MaxValueInQueue queue2({1, 2});
        vector<int> nums = {2, 3, 4, 2, 6, 2, 5, 1};
        for(int i=0;i<nums.size();i++)
            queue2.push(nums[i]);
        for(int i=0;i<nums.size();i++){
            cout<<queue2.max()<<endl;
            queue2.pop();
        }
    }
};
