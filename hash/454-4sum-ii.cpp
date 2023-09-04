/**
* @file 454-4sum-ii.cpp
* @brief 四数相加 II
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-08-30
* @details https://leetcode.cn/problems/4sum-ii/
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map;  // key:a+b的数值， value:a+b数值出现的次数

        for (auto a : nums1) {
            for (auto b : nums2) {
                map[a+b]++;
            }
        }
        int count = 0;
        for (int c : nums3) {
            for (auto d : nums4) {
                if (map.find(0 - (c + d)) != map.end()) {
                    count += map[0 - (c+d)];
                }
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    return 0;
}