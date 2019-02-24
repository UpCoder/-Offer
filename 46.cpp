//
// Created by 梁栋 on 2019-02-19.
//
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
class Int2String{
private:
    static string int2string(int num){
        stringstream ss;
        ss<<num;
        string res;
        ss>>res;
        return res;
    }
    static int string2int(string s){
        stringstream ss;
        ss<<s;
        int res;
        ss>>res;
        return res;
    }
public:
    static int numOfInt2String(int n){
        string str1 = int2string(n);
        if(str1.length() == 1){
            return 1;
        }
        int num = 0;
        num += numOfInt2String(string2int(str1.substr(1)));
        if(str1.length() <= 2)
            return num;
        string str2 = str1.substr(0, 2);
        int str2_int = string2int(str2);
        if(str2_int >= 10 && str2_int<=25){
            num += numOfInt2String(string2int(str1.substr(2)));
        }
        return num;
    }
    static int numOfInt2String_1(int n){
        string str1 = int2string(n);
        int length = str1.length();
        int count[length];
        memset(count, 0, sizeof(int) * length);
        for(int i=length-1;i>=0;i--){
            int cur_count = 0;
            if(i < length - 1)
                cur_count = count[i + 1];
            else
                cur_count = 1;
            if(i < length - 1){
                int first_digit = str1[i] - '0';
                int second_digit = str1[i + 1] - '0';
                int digit = first_digit * 10 + second_digit;
                if(digit >= 10 && digit <= 25){
                    if(i < length - 2){
                        cur_count += count[i + 2];
                    }else{
                        cur_count += 1;
                    }
                }
            }
            count[i] = cur_count;
        }
        return count[0];
    }
};
class Solution{
public:
    static void solution(){
        cout<<Int2String::numOfInt2String(12212358)<<endl;
        cout<<Int2String::numOfInt2String_1(12212358)<<endl;
    }
};