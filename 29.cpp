//
// Created by 梁栋 on 2019-03-27.
//

#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int start = 0;
        int nRows = (int) matrix.size();
        int nCols = (int) matrix[0].size();
        vector<int> res;
        while(nRows > 2*start && nCols > 2*start){
            int endX = nRows - start - 1;
            int endY = nCols - start - 1;
            for(int j=start;j<=endY;j++){
                res.push_back(matrix[start][j]);
            }
            if(start < endX){
                // 有大于两行的数据
                for(int i=start+1; i<=endX;i++){
                    res.push_back(matrix[i][endY]);
                }
            }
            if(start < endX && start < endY){
                // 有大于两列的数据
                for(int j=endY-1;j>=start;j--){
                    res.push_back(matrix[endX][j]);
                }
            }
            if(start < endX-1 && start < endY){
                for(int i=endX-1;i>start;i--){
                    res.push_back(matrix[i][start]);
                }
            }
            start += 1;
        }
        return res;
    }
    static void solution(){
        Solution solution1;
        vector<vector<int> > matrix = {
                {1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12}
        };
        vector<int> res = solution1.printMatrix(matrix);
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<", ";
        }
        cout<<endl;
    }
};