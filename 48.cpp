//
// Created by 梁栋 on 2019-02-19.
//

#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class MaxLengthSubString{
    // 计算最长不含重复字符的子字符串
public:
    struct Result{
        int maxLength = 0;
        string subStr = "";
    };
    static Result maxLengthSubString(string str1){
        int charPos[26];
        for(int i=0;i<26;i++)
            charPos[i] = -1;
        int curMaxLength = 0;
        Result result;
        int start = 0;
        for(int i=0;i<str1.length();i++){
            char curChar = str1[i];
            if(charPos[curChar - 'a'] == -1){
                curMaxLength += 1;
            }else{
                int d = i - charPos[curChar - 'a'];
                if(d <= curMaxLength){
                    curMaxLength = d;
                    start = i - d + 1;
                }else{
                    curMaxLength += 1;
                }
            }
            charPos[curChar - 'a'] = i;
            if(result.maxLength < curMaxLength){
                result.maxLength = curMaxLength;
                result.subStr = str1.substr(start, i - start + 1);
            }
        }
        return result;
    }
};
class Solution{
public:
    static void solution(){
        MaxLengthSubString::Result result = MaxLengthSubString::maxLengthSubString("arabcacfr");
        cout<<"Max Length is "<<result.maxLength<<" Sub Str is "<<result.subStr<<endl;
    }
};