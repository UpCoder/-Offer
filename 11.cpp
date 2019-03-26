//
// Created by 梁栋 on 2019-03-23.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int s = 0;
        int e = rotateArray.size()-1;
        while(s<e){
            if((e-s) == 1 && rotateArray[e] < rotateArray[s]){
                return rotateArray[e];
            }
            int mid = (s + e) / 2;
            if(rotateArray[mid] > rotateArray[e]){
                s = mid;
                continue;
            }
            if(rotateArray[mid] < rotateArray[s]){
                e = mid;
                continue;
            }
            if(rotateArray[mid] == rotateArray[s] && rotateArray[s] == rotateArray[e]){
                int res = rotateArray[s];
                for(int i=s; i<=e; i++){
                    if(rotateArray[i+1] < rotateArray[i]){
                        res = rotateArray[i+1];
                        return res;
                    }
                }
                return res;
            }
        }
    }
    static void solution(){
        vector<int> rotateArray = {1, 0, 1, 1, 1};
        Solution solution1;
        cout<<solution1.minNumberInRotateArray(rotateArray)<<endl;
    }
};