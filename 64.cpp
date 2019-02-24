//
// Created by 梁栋 on 2019-02-24.
//
#include <iostream>
using namespace std;
class SumN{
public:
    static int n;
    static int sum;
    SumN(){
        n += 1;
        sum += n;
    }
};
int SumN::n=0;
int SumN::sum=0;
class Solution{
public:
    static void solution(){
        int n = 3;
        SumN sumN[n];
        cout<<sumN[2].sum<<endl;
    }
};
