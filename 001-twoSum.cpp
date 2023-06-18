/**
* @file 001-twoSum.cpp
* @brief 两数之和
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-06-18
* @details https://leetcode.cn/problems/two-sum/
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if(nums[i] + nums[j] == target) {
                    return vector<int>{i, j};
                }
            }
        }
        return vector<int>{};
    }
};

int main() {
    Solution s;
    vector<int> nums{3, 2, 4};
    auto rt = s.twoSum(nums, 6);
    for (auto i : rt) {
        cout << i << "\t";
    }

    return 0;
}