//
// Created by 梁栋 on 2019-04-22.
// 字符串的排列
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    void PermutationBase(char* input, int len, string cur_str, vector<string>& res, bool* used_flag){
        if(cur_str.length() == len){
            res.push_back(cur_str);
            return;
        }
        for(int i=0;i<len;){
            if(used_flag[i]){
                i += 1;
                continue;
            }
            if(i>0 && input[i] == input[i-1] && used_flag[i-1] == false){
                i += 1;
                continue;
            }
            used_flag[i] = true;
            string new_str = cur_str + input[i];
            PermutationBase(input, len, new_str, res, used_flag);
            used_flag[i] = false;
            i += 1;
        }
    }

    vector<string> Permutation(string str) {
        vector<string> res;
        if(str == "")
            return res;
        char* c_str = (char*) str.c_str();
        int len = str.length();
        sort(c_str, c_str + len);
        bool* used_flag = new bool[len];
        memset(used_flag, 0, sizeof(bool) * len);
        PermutationBase(c_str, len, "", res, used_flag);
        return res;
    }

    void queenProblemBase(int* columns, int n, int i, bool* used_flag, int& res){
        if(i == n)
        {
            res += 1;
            return;
        }
        for(int j=0;j<n;j++){
            if(used_flag[j])
                continue;
            bool legal = true;
            for(int z=0;z<i;z++){
                if(abs(columns[z] - j) == abs(z - i)){
                    legal = false;
                    break;
                }
            }
            if(!legal){
                continue;
            }
            columns[i] = j;
            used_flag[j] = true;
            queenProblemBase(columns, n, i+1, used_flag, res);
            used_flag[j] = false;
        }
    }
    int queenProblem(int n=8){
        int columns[n];
        for(int i=0;i<n;i++){
            columns[i] = i;
        }
        bool* used_flag = new bool[n];
        memset(used_flag, 0, sizeof(bool) * n);
        int res = 0;
        queenProblemBase(columns, n, 0, used_flag, res);
        return res;
    }
    static void solution(){
        Solution solution1;
//        string input = "";
//        vector<string> res = solution1.Permutation(input);
//        for(int i=0;i<res.size();i++){
//            cout<<res[i]<<endl;
//        }
        cout<<solution1.queenProblem()<<endl;
    }
};
