//
// Created by 梁栋 on 2019-02-24.
//
#include <iostream>
#include <algorithm>
using namespace std;
class Solution{
public:
    static int* compute_B_V2(int* A, int n){
        int B[n];
        int C[n];
        int D[n];
        int res_C = 1;
        int res_D = 1;
        for(int i=0;i<n;i++){
            C[i] = res_C;
            D[n-i-1] = res_D;
            res_C *= A[i];
            res_D *= A[n-i-1];
        }
        for(int i=0;i<n;i++){
            B[i] = C[i] * D[i];
            cout<<"i= "<<B[i]<<endl;
        }
    }
    static int* compute_B(int* A, int n){
        int B[n];
        for(int i=0;i<n;i++)
        {
            int res = 1;
            for(int j=0;j<n;j++){
                if(j != i)
                    res *= A[j];
            }
            B[i] = res;
            cout<<"i= "<<B[i]<<endl;
        }

    }
    static void solution(){
        int n = 5;
        int A[n];
        for(int i=0;i<n;i++)
            A[i] = i + 1;
        compute_B(A, n);
        compute_B_V2(A, n);
    }
};
