/**
* @file offer05-ti-huan-kong-ge-lcof.cpp
* @brief 剑指 Offer 05. 替换空格
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-08-30
* @details https://leetcode.cn/problems/ti-huan-kong-ge-lcof/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                count++;
            }
        }
        int oldSize = s.size();
        s.resize(s.size() + count*2);
        int newSize = s.size();
        for (int i = newSize - 1, j = oldSize - 1;
             j < i; i--, j--) {
            if (s[j] != ' ') {
                s[i] = s[j];
            } else {
                s[i] = '0';
                s[i-1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};

int main() {
    Solution s;
    return 0;
}
