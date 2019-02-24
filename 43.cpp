//
// Created by 梁栋 on 2019-02-18.
//
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;
class Numberof1{
private:
    static int numberof1(int n){
        int res = 0;
        while(n>0){
            if(n%10 == 1){
                res += 1;
            }
            n /= 10;
        }
        return res;
    }
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
    static int power10(int n){
        int res = 1;
        while(n){
            res *= 10;
            n--;
        }
        return res;
    }
public:
    static int core(int num){
        // 暴力的解法，时间复杂度为O(nlogn)
        int res = 0;
        for(int i=1;i<num;i++){
            res += numberof1(i);
        }
        return res;
    }

    static int core_1(int num){
        // 递归，找规律
        string num_s = int2string(num);
        int length = num_s.length();
        int first_num = num_s[0] - '0';
        int numFirstDigit = 0;
        int numOtherDigit = 0;
        int numRecursive = 0;
        if(length == 1){
            if(first_num == 0){
                return 0;
            }else{
                return 1;
            }
        }
        if(first_num == 1){
            numFirstDigit = string2int(num_s.substr(1)) + 1;
        }else{
            numFirstDigit = power10(length - 1);
        }
        numOtherDigit = first_num * (length - 1) * power10(length - 2);
        numRecursive = core_1(string2int(num_s.substr(1)));
        return numFirstDigit + numOtherDigit + numRecursive;

    }
};
class Solution{
public:
    static void solution(){
        cout<<Numberof1::core(999999999)<<endl;
        cout<<Numberof1::core_1(999999999)<<endl;
    }
};
