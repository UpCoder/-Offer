//
// Created by 梁栋 on 2019-02-19.
//

#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
class GenerateMinestNumber{
private:
    static int string2int(string s){
        stringstream ss;
        ss<<s;
        int res;
        ss>>res;
        return res;
    }
    static string int2string(int num){
        stringstream ss;
        ss<<num;
        string res;
        ss>>res;
        return res;
    }
    static bool compare(int num1, int num2){
        string s1 = int2string(num1) + int2string(num2);
        string s2 = int2string(num2) + int2string(num1);
        if(s1 > s2){
            return false;
        }
        return true;
    }
public:
    static int generateMinestNumberFromArray(int* nums, int length){
        sort(nums, nums + length, compare);

    }
};
class Solution{
public:
    static void solution(){
        int nums[3] = {3, 32, 321};
        GenerateMinestNumber::generateMinestNumberFromArray(nums, 3);
        for(int i=0;i<3;i++){
            cout<<nums[i]<<",";
        }
        cout<<endl;
    }
};