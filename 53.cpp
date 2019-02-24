//
// Created by 梁栋 on 2019-02-21.
//
#include <iostream>
using namespace std;
class FindNumberInSortedArray{
private:
    static int findNumberInSortedArrayFirst(int* data, int s, int e, int target){
        // 在排序数组中找到target第一次出现的位置，并返回
        if(s > e){
            return -1;
        }
        int mid = (s + e) >> 1;
        if(data[mid] == target){
            if(mid == 0 || data[mid-1] != target){
                return mid;
            }
            else{
                return findNumberInSortedArrayFirst(data, s, mid-1, target);
            }
        }else{
            if(data[mid] > target){
                return findNumberInSortedArrayFirst(data, s, mid-1, target);
            }else{
                return findNumberInSortedArrayFirst(data, mid + 1, e, target);
            }
        }
    }
    static int findNumberInSortedArrayLast(int* data, int s, int e, int len, int target){
        if(s > e){
            return -1;
        }
        int mid = (s + e) >> 1;
        if(data[mid] == target){
            if(mid == (len - 1) || data[mid + 1]  != target){
                return mid;
            }else{

                return findNumberInSortedArrayLast(data, mid + 1, e, len, target);
            }
        }else{
            if(data[mid] > target){
                return findNumberInSortedArrayLast(data, s, mid - 1, len, target);
            }else{
                return findNumberInSortedArrayFirst(data, mid + 1, e, target);
            }
        }
    }

public:
    static int findNumberInSortedArray(int* data, int len, int target){
        // 在排序数组中找到某个数字出现的次数
        int first_pos = findNumberInSortedArrayFirst(data, 0, len, target);
        cout<<"first position is "<<first_pos<<endl;
        int last_pos = findNumberInSortedArrayLast(data, 0, len, len, target);
        cout<<"last position is "<<last_pos<<endl;
        if(first_pos == -1)
            return 0;
        return last_pos - first_pos + 1;
    }
    static int findMissingNumberInSortedArray(int* data, int len){
        int s = 0;
        int e = len;
        int mid = -1;
        while(s <= e){
            mid = (s + e) >> 1;
            if(data[mid] == mid){
                s = mid + 1;
            }else{
                if(mid == 0 || data[mid - 1] == (mid - 1))
                    break;
                else
                    e = mid - 1;
            }
        }
        if(s > e){
            return -1;
        }else{
            return mid;
        }
    }
    static int findFirstNumberEqualtoIndexInSortedArray(int* data, int len){
        // 在排序数组中找到任意一个元素值等于下标的元素
        int s = 0;
        int e = len;
        int mid = -1;
        while(s <= e){
            mid = (s + e) >> 1;
            if(data[mid] == mid){
                break;
            }
            if(data[mid] > mid){
                // 比下标大，则一定在左边
                e = mid - 1;
            }else{
                // 比下标小，则一定在右边
                s = mid + 1;
            }
        }
        if(s > e || s >= len || s < 0){
            return -1;
        }else{
            return mid;
        }
    }
};
class Solution{
public:
    static void solution(){
        int data[7] = {0, 1, 1, 2, 2, 3, 4};
        for(int i=0;i<7;i++){
            cout<<data[i]<<",";
        }
        cout<<endl;
        FindNumberInSortedArray::findNumberInSortedArray(data, 7, 2);
        int data2[5] = {1, 2, 3, 4, 5};
        for(int i=0;i<5;i++){
            cout<<data2[i]<<", ";
        }
        cout<<endl;
        cout<<"Missing number is "<<FindNumberInSortedArray::findMissingNumberInSortedArray(data2, 5)<<endl;
        int data3[5] = {-3, -1, 1, 2, 3};
        for(int i=0;i<5;i++){
            cout<<data3[i]<<", ";
        }
        cout<<endl;
        cout<<"Index equal to value is "<<FindNumberInSortedArray::findFirstNumberEqualtoIndexInSortedArray(data3, 5)<<endl;
    }
};