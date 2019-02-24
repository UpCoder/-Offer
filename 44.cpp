//
// Created by 梁栋 on 2019-02-18.
//
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;
class DigitatIndex{
private:
    static int power10(int n){
        int res = 1;
        while(n){
            res *= 10;
            n--;
        }
        return res;
    }
    static string int2string(int num){
        stringstream ss;
        ss<<num;
        string res;
        ss>>res;
        return res;
    }
    static int totalNumberOfN(int n){
        if(n == 1){
            return 10;
        }
        return n * 9 * power10(n - 1);
    }
    static int findNthNumberinTarget(int target, int n){
        string string1 = int2string(target);
        // cout<<string1<<endl;
        return string1[n] - '0';
    }
public:
    static int digitAtIndex(int index){
        if(index < 10){
            return index;
        }
        int n = 1;
        while(totalNumberOfN(n) < index){
            index -= totalNumberOfN(n);
            n++;
        }
        int divided = index / n;
        int mod = index - (divided * n);
        int start = power10(n-1);
        int target = start + divided;
        return findNthNumberinTarget(target, mod);

    }
};
class Solution{
public:
    static void solution(){
        cout<<DigitatIndex::digitAtIndex(17)<<endl;
    }
};
