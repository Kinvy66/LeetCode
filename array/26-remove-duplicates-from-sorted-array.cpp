/**
* @file 26-remove-duplicates-from-sorted-array.cpp
* @brief 删除有序数组中的重复项
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-08-27
* @details https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
*/

/*
 * 双指针
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slowIndex = 0;
        for (int fastIndex = 1; fastIndex < nums.size(); ++fastIndex) {
            if (nums[slowIndex] != nums[fastIndex]) {
                nums[++slowIndex] = nums[fastIndex];
            }
        }
        return ++slowIndex;
    }
};

int main() {
    Solution s;
    vector<int> vec = {1,1,2};
    int ret = s.removeDuplicates(vec);
    return 0;
}