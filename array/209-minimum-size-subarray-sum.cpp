/**
* @file 209-minimum-size-subarray-sum.cpp
* @brief 长度最小的子数组
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-08-28
* @details https://leetcode.cn/problems/minimum-size-subarray-sum/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0;
        int i = 0;  // 滑动窗口其实位置
        int subLength = 0; // 滑动窗口的长度
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= target) {
                subLength = (j - i + 1);  // 取子序列的长度
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};

int main() {
    Solution s;
    return 0;
}