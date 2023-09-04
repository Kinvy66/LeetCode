/**
* @file 704-BinarySearch.cpp
* @brief 二分查找
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-07-17
* @details https://leetcode.cn/problems/binary-search/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @brief
     * @param nums
     * @param target
     * @details 两种区间选择： [left, right] , [left, right)
     */
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + ((right - left) / 2); // 防止溢出 等同于(left + right)/2
            if (nums[mid] < target) {
                left = mid + 1;  // 注意边界
            } else if (nums[mid] > target) {
                right = mid;  // 注意边界
            } else {
                return mid;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {5};
    int target = 5;
    Solution s;
    int ret =  s.search(nums, target);
    std::cout << "ret: " << ret << std::endl;
    std::cout << "end" << std::endl;
    return 0;
}


