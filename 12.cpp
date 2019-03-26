//
// Created by 梁栋 on 2019-03-23.
//
#include <vector>
#include <cstring>
#include <string>
using namespace std;
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, int x, int y, char* str, int index, bool* visits){
        if(str[index] == '\0')
            return true;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        for(int i=0;i<4;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x >=0 && new_x < rows && new_y >= 0 && new_y < cols
            && !visits[new_x * cols + new_y]
            && matrix[new_x * cols + new_y] == str[index]){
                visits[new_x * cols + new_y] = true;
                bool res = hasPath(matrix, rows, cols, new_x, new_y, str, index + 1, visits);
                if(res)
                    return res;
                visits[new_x*cols + new_y] = false;
            }
        }
        return false;
    }
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(str[0] == '\0')
            return true;
        bool visits[rows * cols];
        memset(visits, 0, sizeof(visits));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i*cols + j] == str[0]){
                    visits[i*cols + j] = true;
                    bool res = hasPath(matrix, rows, cols, i, j, str, 1, visits);
                    if(res)
                        return true;
                    visits[i*cols + j] = false;
                }
            }
        }
        return false;
    }
    static void solution(){

    }

};