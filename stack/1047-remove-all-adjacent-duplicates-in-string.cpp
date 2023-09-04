/**
* @file 1047-remove-all-adjacent-duplicates-in-string.cpp
* @brief 1047. 删除字符串中的所有相邻重复项
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-09-01
* @details https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (auto i : s) {
            if (st.empty() || i != st.top()) {
                st.push(i);
            } else {
                st.pop();
            }
        }
        string  ret = "";
        while (!st.empty()) {
            ret += st.top();
            st.pop();
        }
        // reverse(ret.begin(), ret.end());

        for (int i = 0, j = ret.size() - 1; i < ret.size()/2; i++, j--) {
            // swap(ret[i], ret[j]);
            ret[i] ^= ret[j];
            ret[j] ^= ret[i];
            ret[i] ^= ret[j];
        }
        return ret;
    }

};

int main() {
    Solution s;
    string str = "abbaca";
    s.removeDuplicates(str);
    return 0;
}
