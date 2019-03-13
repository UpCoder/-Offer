//
// Created by 梁栋 on 2019-03-13.
//
#include <iostream>
using namespace std;
class QuickSort{
public:
    static int quickSortPartition(int* data, int s, int e){
        // [s,e]
        int target = data[s];
        cout<<"target is "<<target<<endl;
        while(s < e){
            while(data[e] >= target && e > s){
                e--;
            }
            data[s] = data[e];
            cout<<"1: "<<data[s]<<", "<<data[e]<<endl;
            while(data[s] <= target && s < e){
                s++;
            }
            data[e] = data[s];
            cout<<"2: "<<data[s]<<", "<<data[e]<<endl;
        }
        data[s] = target;
        return s;
    }
    static void quickSort(int* data, int s, int n){
        if(s>=n)
            return;
        int index = quickSortPartition(data, s, n);
        quickSort(data, s, index-1);
        quickSort(data, index + 1, n);
    }
};
class Solution{
public:
    static void solution(){
        int data[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        QuickSort::quickSort(data, 0, 9);
        for(int i=0;i<10;i++)
            cout<<data[i]<<",";
        cout<<endl;
    }
};