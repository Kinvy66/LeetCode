/**
* @file 242-valid-anagram.cpp
* @brief 有效的字母异位词
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-08-30
* @details https://leetcode.cn/problems/valid-anagram/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); ++i) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (record[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    return 0;
}
