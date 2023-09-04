/**
* @file offer58-zuo-xuan-zhuan-zi-fu-chuan-lcof.cpp
* @brief 剑指 Offer 58 - II. 左旋转字符串
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-08-31
* @details https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s, 0, n-1);
        reverse(s, n, s.size() - 1);
        reverse(s, 0, s.size() - 1);
        return s;
    }

    void reverse(string& s, int begin, int end) {
        for (int i = begin, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};

int main() {
    Solution s;
    string str = "abcdefg";
    auto ret = s.reverseLeftWords(str, 2);
    cout << ret << endl;
    return 0;
}
