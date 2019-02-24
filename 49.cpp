//
// Created by 梁栋 on 2019-02-19.
//
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class FindKthUglyNumber{
public:
    static int findKthUglyNumber(int index){
        if(index == 0)
            return 0;
        int uglys[index];
        memset(uglys, 0, sizeof(int) * index);
        uglys[0] = 1;
        int* uglys_2 = uglys; //该指针指向的元素乘以2，是最小的乘以2大于已知最大丑数的数字
        int* uglys_3 = uglys; //该指针指向的元素乘以3，是最小的乘以3大于已知最大丑数的数字
        int* uglys_5 = uglys; //该指针指向的元素乘以5，是最小的乘以5大于已知最大丑数的数字
        int cur_index = 1;
        while(cur_index < index){
            uglys[cur_index] = min(*uglys_2 * 2, min(*uglys_3 * 3, *uglys_5 * 5));
            // 更新指针，确保其满足上述规则
            while(*uglys_2 * 2 <= uglys[cur_index])
                uglys_2 += 1;
            while(*uglys_3 * 3 <= uglys[cur_index])
                uglys_3 += 1;
            while(*uglys_5 * 5 <= uglys[cur_index])
                uglys_5 += 1;
            cur_index += 1;
        }
        for(int i=0;i<index;i++)
            cout<<uglys[i]<<",";
        cout<<endl;
        return uglys[index-1];
    }
};
class Solution{
public:
    static void solution(){
        int k = 10;
        cout<<k<<" th ugly number is "<<FindKthUglyNumber::findKthUglyNumber(k)<<endl;
        k = 0;
        cout<<k<<" th ugly number is "<<FindKthUglyNumber::findKthUglyNumber(k)<<endl;
    }
};
