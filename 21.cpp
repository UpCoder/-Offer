//
// Created by 梁栋 on 2019-03-12.
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Cell{
    bool is_odd;
    int value;
    int index;
};
bool compare(Cell a, Cell b){
    if(a.is_odd && b.is_odd){
        return a.index < b.index;
    }else{
        if(!a.is_odd && b.is_odd)
            return false;
        if(a.is_odd && !b.is_odd)
            return true;
        return a.index < b.index;
    }
}
class Solution {
public:
    static void solution(){
        vector<int> array = {1, 2, 3, 4, 5, 6};
        Solution solution1 = Solution();
        solution1.reOrderArray(array);
        for(int i=0;i<array.size();i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
    void reOrderArray(vector<int> &array) {
//        int n = array.size();
//        Cell cells[n];
//        for(int i=0;i<n;i++){
//            cells[i].is_odd = (array[i] % 2 != 0);
//            cells[i].index = i;
//            cells[i].value = array[i];
//        }
//        sort(cells, cells + n, compare);
//        for(int i=0;i<n;i++)
//            array[i] = cells[i].value;
        if(array.size() <= 1)
            return;
        int size = (int) array.size();
        int index_even = 0; // 偶数
        int index_odd = 0; // 奇数
        while(index_even < size && index_odd < size){
            while(index_even < size && array[index_even] % 2 != 0){
                index_even += 1;
            }
            index_odd = index_even + 1;
            while(index_odd < size && array[index_odd] % 2 == 0){
                index_odd += 1;
            }
            for(int i=index_odd;i<size && i>index_even;i--){
                swap(array[i], array[i-1]);
            }
            index_even += 1;
            index_odd += 1;
        }
    }
};