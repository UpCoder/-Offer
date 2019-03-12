//
// Created by 梁栋 on 2019-03-10.
//
#include <iostream>
#include <string>
using namespace std;
class FindRepeatNumber{
public:
    static void findRepeatNumber(int* data, int n){
        int s = 0;
        bool findRepeatNumber = false;
        while(s < n){
            while(data[s] != s){
                if(data[s] == data[data[s]]){
                    cout<<data[s]<<endl;
                    findRepeatNumber = true;
                    break;
                }
                swap(data[s], data[data[s]]);
            }
            s += 1;
            if(findRepeatNumber)
                break;
        }
    }
};
class Solution{
public:
    static void solution(){
        int data[7] = {2, 3, 1, 0, 2, 5, 3};
        FindRepeatNumber::findRepeatNumber(data, 7);
    }
};