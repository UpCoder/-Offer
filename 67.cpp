//
// Created by 梁栋 on 2019-02-24.
//
#include <iostream>
#include <string>
using namespace std;
class String2Int{
private:
    static int string2IntCore(string x, bool is_negative){
        // x是无符号的整数，is_negative是决定了他的符号
        if(x.length() == 0){
            state= false;
            return 0;
        }
        signed int res = 0;
        for(int i=0;i<x.length();i++){
            int digit = x[i] - '0';
            if(digit < 0 || digit > 9){
                state = false;
                return 0;
            }
            //cout<<"res="<<res<<endl;
            if((res * 10) / 10 != res){
                // 越界
                state =false;
                return 0;
            }
            if(not is_negative){
                if((0x7FFFFFFF - res * 10) < digit){
                    state =false;
                    return 0;
                }
            }else{
                if((0x7FFFFFFF - res * 10) < (digit - 1)){
                    state = false;
                    return 0;
                }
            }
            res = res * 10 + digit;
        }
        return is_negative ? -1 * res : res;
    }
public:
    static bool state;
    static int string2Int(string x){
        // 将字符串转化成数字
        // 如果是非法字符，将state置为false，返回0；
        // 如果输入是""，将state置为false，范围0；
        // 如果数据越界，将state置为false，返回0
        state = true;
        if(x == ""){
            state = false;
            return 0;
        }
        bool negative_flag = false;
        if(x[0] == '-'){
            negative_flag = true;
            x = x.substr(1);
        }else{
            if(x[0] == '+'){
                x = x.substr(1);
            }
        }
        return string2IntCore(x, negative_flag);
    }
};
bool String2Int::state=true;
class Solution{
public:
    static void solution(){
        string str = "-2147483649";
        cout<<0x7FFFFFFF<<endl;
        cout<<(signed int)0x80000000<<endl;
        cout<<String2Int::string2Int(str)<<endl;
    }
};
