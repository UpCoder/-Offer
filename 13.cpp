//
// Created by 梁栋 on 2019-03-25.
//
#include <iostream>
using namespace std;
class Solution {
public:
    int getDigitsSum(int x){
        int res = 0;
        while(x>0){
            res += (x % 10);
            x /= 10;
        }
        return res;
    }
    bool check(int x, int y, int rows, int cols, int threshold, bool* visits){
        if(x>=0 && x<rows && y>=0 && y<cols
        && (getDigitsSum(x) + getDigitsSum(y)) <= threshold && !visits[x * cols + y]){
            return true;
        }
        return false;
    }
    int movingCountCore(int threshold, int rows, int cols, int x, int y, bool* visits){
        int count = 0;
        if(check(x, y, rows, cols, threshold, visits)){
            visits[x * cols + y] = true;
            count = 1 + movingCountCore(threshold, rows, cols, x - 1, y, visits)
                    + movingCountCore(threshold, rows, cols, x, y - 1, visits)
                    + movingCountCore(threshold, rows, cols, x + 1, y, visits)
                    + movingCountCore(threshold, rows, cols, x, y + 1, visits);
        }
        return count;
    }
    int movingCount(int threshold, int rows, int cols)
    {
        bool visits[rows*cols];
        memset(visits, false, sizeof(visits));
        return movingCountCore(threshold, rows, cols, 0, 0, visits);
    }
};