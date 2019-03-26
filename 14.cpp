//
// Created by 梁栋 on 2019-03-26.
//

#include <iostream>
#include <cstring>
using namespace std;
class SkipRope{
public:
    static int maxProductAfterCutting1(int len){
        if(len == 0)
            return 0;
        if(len < 2)
            return 0;
        if(len == 2)
            return 1;
        if(len == 3)
            return 2;
        int f[len + 1];
        memset(f, 0, sizeof(f));
        f[0] = 0;
        f[1] = 1;
        f[2] = 2;
        f[3] = 3;
        for(int i=4;i<=len;i++){
            for(int j=1;j<=i/2;j++){
                f[i] = max(f[i], f[i-j] * f[j]);
            }
        }
        cout<<f[len]<<endl;
    }
};
class Solution{
public:
    static void solution(){
        SkipRope::maxProductAfterCutting1(8);
    }
};