/**
* @file 030-substringWithConcatenationOfAllWords.cpp
* @brief 串联所有单词的子串
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-06-29
* @details https://leetcode.cn/problems/substring-with-concatenation-of-all-words/
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    // FIXME 执行超时
    vector<int> findSubstringTimeout(string s, vector<string>& words) {
        vector<int> ret;
        size_t window = words.size() * words[0].size();
        size_t wordSize = words[0].size();
        for (int i = 0; i < s.size() - window + 1; i += wordSize) {
            // std::multiset<string> temp(words.begin(), words.end());
            std::vector<string> temp = words;
            for(int j = 0; j < words.size(); ++j) {
                std::string sub = s.substr(i + j * wordSize, wordSize);
                // auto it = temp.find(sub);
                auto it = std::find(temp.begin(), temp.end(), sub);
                if (it != temp.end()) {
                    temp.erase(it);
                }
            }
            if (temp.empty()) {
                ret.push_back(i);
            }
        }
        return ret;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        size_t window = words.size() * words[0].size();
        size_t wordSize = words[0].size();
        for (int i = 0; i < s.size() - window + 1; i += wordSize) {
            // std::multiset<string> temp(words.begin(), words.end());
            std::vector<string> temp = words;
            for(int j = 0; j < words.size(); ++j) {
                std::string sub = s.substr(i + j * wordSize, wordSize);
                // auto it = temp.find(sub);
                auto it = std::find(temp.begin(), temp.end(), sub);
                if (it != temp.end()) {
                    temp.erase(it);
                }
            }
            if (temp.empty()) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};

int main() {

    std::string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";

    std::vector<string> words ={"fooo","barr","wing","ding","wing"};
    Solution solution;
    auto ret = solution.findSubstring(s, words);
    for (auto i : ret) {
        std::cout << i << "\t";
    }
    std::cout << "end" << std::endl;
    return 0;
}