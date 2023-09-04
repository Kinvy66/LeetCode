/**
* @file 344-reverse-string.cpp
* @brief 反转字符串
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-08-30
* @details https://leetcode.cn/problems/reverse-string/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--) {
            swap(s[i], s[j]);
            s[i] ^= s[j];
            s[j] ^= s[i];
            s[i] ^= s[j];
        }
    }
};

int main() {
    Solution s;
    return 0;
}
