/**
* @file 003-longestSubstring.cpp
* @brief  无重复字符的最长子串
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-06-19
* @details https://leetcode.cn/problems/longest-substring-without-repeating-characters/
*/
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        std::unordered_set<char> lookup;
        int left = 0;
        int maxStr = 0;
        for (int i = 0; i < s.size(); ++i) {
            while (lookup.find(s[i]) != lookup.end()) {
                lookup.erase(s[left]);
                left++;
            }
            maxStr = std::max(maxStr, i - left + 1);
            lookup.insert(s[i]);
        }
        return maxStr;
    }
};

int main() {
    Solution s;
    int ret =  s.lengthOfLongestSubstring(std::string("abacabcdd"));
    cout << "maxStr:" << ret << endl;
    return 0;
}