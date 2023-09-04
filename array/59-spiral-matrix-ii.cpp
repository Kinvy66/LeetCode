/**
* @file 59-spiral-matrix-ii.cpp
* @brief 螺旋矩阵
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-08-29
* @details https://leetcode.cn/problems/spiral-matrix-ii
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int num = 1, target = n * n;
        while (num <= target) {
            for (int i = left; i <= right; i++)  ret[top][i] = num++;  // l to r
            top++;
            for (int i = top; i <= bottom; i++) ret[i][right] = num++;
            right--;
            for (int i = right; i >= left; i--) ret[bottom][i] = num++;
            bottom--;
            for (int i = bottom; i >= top; i--) ret[i][left] = num++;
            left++;
        }
        return ret;
    }
};

int main() {
    Solution s;
    return 0;
}