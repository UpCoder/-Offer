//
// Created by 梁栋 on 2019-02-19.
//
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
class MaxValuePath{

public:
    struct Result{
        int maxValue;
        vector<int> values;
    };
    static Result findMaxValuePath(vector<vector<int> > data, int n, int m){
        // dp[i,j] = max(dp[i-1, j], dp[i, j-1]) + data[i, j]
        int dp[n][m];
        Result result;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int up = 0;
                int left = 0;
                if(i > 0){
                    up = dp[i-1][j];
                }
                if(j > 0){
                    left = dp[i][j-1];
                }
                dp[i][j] = max(up, left) + data[i][j];
            }
        }
        result.maxValue = dp[n-1][m-1];
        int x = n-1;
        int y = m-1;
        while(true){
            result.values.push_back(data[x][y]);
            cout<<x<<", "<<y<<endl;
            if(x == 0 && y==0)
                break;
            if((dp[x-1][y] + data[x][y]) == dp[x][y]){
                x --;
                continue;
            }else{
                y--;
                continue;
            }
        }
        return result;
    }
};
class Solution{
public:
    static void solution(){
        int n = 4;
        int m = 4;
        vector<vector<int> > data = {
                {1, 10, 3, 8},
                {12, 2, 9, 6},
                {5, 7, 4, 11},
                {3, 7, 16, 5}
        };
        MaxValuePath::Result result = MaxValuePath::findMaxValuePath(data, n, m);
        cout<<"max value is "<<result.maxValue<<endl;
        for(int i=0;i<result.values.size();i++)
            cout<<result.values[i]<<",";
        cout<<endl;
    }
};
