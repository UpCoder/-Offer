//
// Created by 梁栋 on 2019-02-24.
//
#include <iostream>
#include <cmath>
using namespace std;
class SumEqualToS{
private:
    static const int MAXVALUE = 6;
    static const int MINVALUE = 1;
    static void printProbability_Recursive(int cur, int n, int s, int* probability){
        //cout<<cur<<", "<<n<<", "<<s<<endl;
        if(cur == 1){
            for(int i=MINVALUE;i<=MAXVALUE;i++)
                probability[s+i - (n*MINVALUE)] += 1;
        }
        else{
            for(int i=MINVALUE;i<=MAXVALUE;i++){
                printProbability_Recursive(cur-1, n, s + i, probability);
            }
        }
    }
    static int printProbability_Cycle(int n, int** probability){
        int flag = 0;
        // 对于第一个骰子
        for(int i=MINVALUE;i<=MAXVALUE;i++)
            probability[flag][i] = 1;
        for(int k=2;k<=n;k++){
            // 对于第k个骰子
            for(int i=0;i<=k;i++)
                probability[1-flag][i] = 0; // 将本轮状态外的值都置为0，避免对下次产生影响 比如说第二个骰子的i=1不等于0，则第三个骰子，n=3的时候就会再加上这个数，从而导致最后的概率和大于1
            // f(n) = f(n-1) + f(n-2) + ... + f(n-6)
            for(int i=k*MINVALUE;i<=k*MAXVALUE;i++){
                // 对于每个n来说
                probability[1-flag][i] = 0; //  比如说，第一个骰子我们得到了的1～6的值，等到了第二个骰子的时候，再次计算n=2的值的时候，就需要先把之前的=0，根据公式重新计算
                for(int j=MINVALUE;j<=MAXVALUE && j<=i;j++){
                    probability[1-flag][i] += probability[flag][i-j];
                }
            }
            flag = 1 - flag;
        }
        return flag;
    }
public:
    static void printProbability(int n){
        if(n == 0)
            return;
        int size = n * MAXVALUE - n * MINVALUE + 1;
        cout<<size<<endl;
        int* count_times = new int[size];
        memset(count_times, 0, sizeof(int) * size);
        double total_times = pow(6.0, n);
        cout<<total_times<<endl;
        printProbability_Recursive(n, n, 0, count_times);
        double sum_probability = 0.0;
        for(int s=n*MINVALUE; s<=n*MAXVALUE;s++){
            double probability = (1.0 * count_times[s-n*MINVALUE]) / (1.0 * total_times);
            cout<<s<<": "<< probability <<endl;
            sum_probability += probability;
        }
        cout<<"Sum of Probability is "<<sum_probability<<endl;
    }
    static void printProbability_V2(int n){
        if(n == 0)
            return;
        int size = n * MAXVALUE + 1;
        int* count_times[2];
        count_times[0] = new int[size];
        count_times[1] = new int[size];
        memset(count_times[0], 0, sizeof(int) * size);
        memset(count_times[1], 0, sizeof(int) * size);
        double total_times = pow(6.0, n);
        int flag = printProbability_Cycle(n, count_times);
        double sum_probability = 0.0;
        for(int s=n*MINVALUE; s<=n*MAXVALUE;s++){
            double probability = (1.0 * count_times[flag][s]) / (1.0 * total_times);
            cout<<s<<": "<< probability <<endl;
            sum_probability += probability;
        }
        cout<<"Sum of Probability is "<<sum_probability<<endl;
    }
};
class Solution{
public:
    static void solution(){
        SumEqualToS::printProbability(11);
        SumEqualToS::printProbability_V2(11);
    }
};
