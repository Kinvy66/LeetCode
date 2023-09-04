/**
* @file 027-remove-element.cpp
* @brief 移除元素
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-08-27
* @details https://leetcode.cn/problems/remove-element/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); ++fastIndex) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

int main() {
    Solution s;
    return 0;
}