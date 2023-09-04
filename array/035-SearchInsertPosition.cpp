/**
* @file 035-SearchInsertPosition.cpp
* @brief 
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-07-17
* @details https://leetcode.cn/problems/search-insert-position/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + ((right - left) / 2);
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid;
            } else {
                return mid;
            }
        }
        return right;
    }
};

int main() {
    vector<int> nums =  {1,3,5,6};
    int target = 4;
    Solution s;
    int ret =  s.searchInsert(nums, target);
    std::cout << "ret: " << ret << std::endl;
    std::cout << "end" << std::endl;
    return 0;
}
