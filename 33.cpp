//
// Created by 梁栋 on 2019-03-28.
//
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
    bool checkSmall(const vector<int>& sequence, int s, int e, int target){
        bool res = true;
        for(int i=s;i<=e;i++){
            if(sequence[i] > target){
                res = false;
                break;
            }
        }
        return res;
    }
    bool checkBig(const vector<int>& sequence, int s, int e, int target){
        bool res = true;
        for(int i=s;i<=e;i++){
            if(sequence[i] < target){
                res = false;
                break;
            }
        }
        return res;
    }
    bool VerifySquenceOfBSTBase(const vector<int>& sequence, int s, int e){
        if(s >= e)
            return true;
        int rootValue = sequence[e];
        int smaller_index = -1;
        for(int i=s;i<=e;i++){
            if(sequence[i] < rootValue){
                smaller_index = i;
            }else{
                break;
            }
        }
        if(checkSmall(sequence, s, smaller_index, rootValue) && checkBig(sequence, smaller_index + 1, e - 1, rootValue)){
            return VerifySquenceOfBSTBase(sequence, s, smaller_index)
            && VerifySquenceOfBSTBase(sequence, smaller_index + 1, e - 1);
        }
        return false;

    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return true;
        return VerifySquenceOfBSTBase(sequence, 0, (int) sequence.size()-1);
    }
    static void solution(){
        Solution solution1;
        cout<<solution1.VerifySquenceOfBST({5, 7, 6, 9, 11, 10, 8})<<endl;
    }
};

