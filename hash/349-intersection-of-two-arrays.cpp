/**
* @file 349-intersection-of-two-arrays.cpp
* @brief 两个数组的交集
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-08-30
* @details https://leetcode.cn/problems/intersection-of-two-arrays/
*/

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        // unordered_set<int> nums_set(nums1.begin(), nums1.end());
        int hash[1005] = {0};

        for (auto num : nums1) {
            hash[num] = 1;
        }

        for (auto num : nums2) {
            if (hash[num] == 1) {
                result.insert(num);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};

int main() {
    Solution s;
    return 0;
}