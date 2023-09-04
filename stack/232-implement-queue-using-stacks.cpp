/**
* @file 232-implement-queue-using-stacks.cpp
* @brief 232. 用栈实现队列
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-09-01
* @details https://leetcode.cn/problems/implement-queue-using-stacks/
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int>  in;
    stack<int> out;
    MyQueue() {

    }

    void push(int x) {
        in.push(x);
    }

    int pop() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        int result = out.top();
        out.pop();
        return result;
    }

    int peek() {
        int res = this->pop();
        out.push(res);
        return res;
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};

int main() {
    // Solution s;
    return 0;
}
