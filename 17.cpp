//
// Created by 梁栋 on 2019-03-26.
//

#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class Print1ToMaxOfDigits{
public:
    static void print1ToMaxofDigitsN(string str, int n, int cur_pos){
        if(cur_pos >= n){
            cout<<str<<endl;
            return;
        }
        for(int i=0;i<=9;i++){
            str[cur_pos] = i + '0';
            print1ToMaxofDigitsN(str, n, cur_pos + 1);
        }
    }
    static void print1ToMaxofDigitsN(int n){
        string str = "";
        for(int i=0;i<n;i++){
            str += '0';
        }
        print1ToMaxofDigitsN(str, n, 0);

    }
};
class Solution{
public:
    static void solution(){
        Print1ToMaxOfDigits::print1ToMaxofDigitsN(3);
    }
};