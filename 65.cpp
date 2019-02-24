//
// Created by 梁栋 on 2019-02-24.
//
#include <iostream>
using namespace std;
class Solution{
public:
    static void solution(){
        int a = 0x7FFFFFFF;
        int b = 0x80000000;
        int res = 0;
        int sum, carry;
        do{
            sum = a ^ b;
            carry = (a & b) << 1;
            a = sum;
            b = carry;
        }while(b != 0);
        cout<<"sum is "<<sum<<endl;
        cout<<(signed int)0x80000000<<endl;
        cout<< sizeof(int)<<endl;
    }
};
