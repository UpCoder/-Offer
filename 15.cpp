//
// Created by 梁栋 on 2019-03-26.
//
#include <iostream>
#include <string>
using  namespace std;
class Solution {
public:
    int  NumberOf1(int n) {
        int res = 0;
        int target = 0x80000000;
        while(n){
//            if(n&target)
//                res += 1;
//            n <<= 1;
            res += 1;
            n = (n-1) & n;
        }
        return res;
    }
    static void solution(){
        Solution solution1;
        cout<<solution1.NumberOf1(-1)<<endl;
    }
};

