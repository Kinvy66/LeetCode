/**
* @file 977-squares-of-a-sorted-array.cpp
* @brief 有序数组的平方
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-08-28
* @details https://leetcode.cn/problems/squares-of-a-sorted-array/
*/

/*
 * 双指针
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int k = nums.size() - 1;

        vector<int> ret(nums.size(), 0);
         for (int i = 0, j = nums.size() - 1; i <= j; ) {
             if ( nums[i] * nums[i] < nums[j] * nums[j]) {
                 ret[k--] = nums[j] * nums[j];
                 j--;
             } else {
                 ret[k--] = nums[i]*nums[i];
                 i++;
             }
         }
        return ret;
    }
};

int main() {
    Solution s;
    return 0;
}