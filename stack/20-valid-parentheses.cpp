/**
* @file 20-valid-parentheses.cpp
* @brief 20 有效括号
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-09-01
* @details https://leetcode.cn/problems/valid-parentheses/
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;
        stack<char> sta;
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] = '(') sta.push(')');
            else if (s[i] == '{') sta.push('}');
            else if (s[i] == '[') sta.push(']');
            else if (sta.empty() || sta.top() != s[i]) return false;
            else sta.pop();
        }
        return sta.empty();
    }
};

int main() {
    Solution s;
    string str = "()";
    s.isValid(str);
    return 0;
}