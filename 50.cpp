//
// Created by 梁栋 on 2019-02-19.
//
#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;
class FirstNonRepeatChar{
public:
    static char findFirstNonRepeatChar(string str){
        map<char, int> dict;
        for(int i=0;i<str.length();i++){
            if(dict[str[i]] == 0){
                dict[str[i]] = 1;
            }else{
                dict[str[i]] += 1;
            }
        }
        for(int i=0;i<str.length();i++){
            if(dict[str[i]] == 1){
                return str[i];
            }
        }
    }
};
class Solution{
public:
    static void solution(){
        cout<<FirstNonRepeatChar::findFirstNonRepeatChar("ababc")<<endl;
    }
};
