//
// Created by 梁栋 on 2019-02-22.
//
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Solution{
public:
    static void solution(){
        string input = "I am a student.";
        for(int i=0;i<=input.length() / 2;i++){
            swap(input[i], input[input.length()-i-1]);
        }
        cout<<input<<endl;
        int start = 0;
        int end = 0;
        for(int i=0;i<input.length();i++){
            if(input[i] == ' '){
                for(int j=0;j<=(end-start) / 2; j++){
                    swap(input[start + j], input[end-j]);
                }
                start = i + 1;
            }else{
                end = i;
            }

        }
        cout<<input<<endl;
    }
};
