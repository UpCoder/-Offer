//
// Created by 梁栋 on 2019-03-12.
//
#include <iostream>
using namespace std;
class Solution {
public:
    static void solution(){
        Solution solution1 = Solution();
        cout<<solution1.Power(10, 8)<<endl;
    }
    double Powerbase(double base, unsigned int exponent){
        if(exponent == 0)
            return 1.0;
        if(exponent == 1)
            return base;
        double res = Powerbase(base, exponent >> 1);
        res *= res;
        if(exponent & 1)
            res *= base;
        return res;
    }
    double Power(double base, int exponent) {
        double res = 1.0;
        bool neg_flag = exponent < 0;
        if(neg_flag)
            exponent *= -1;
        res = Powerbase(base, exponent);
        if(neg_flag)
            return 1.0 / res;
        return res;
    }
};