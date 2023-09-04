/**
* @file 225-implement-stack-using-queues.cpp
* @brief 225. 用队列实现栈
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-09-01
* @details https://leetcode.cn/problems/implement-stack-using-queues/
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> que1;
    queue<int> que2; // 辅助队列，用来备份
    MyStack() {

    }

    void push(int x) {
        que1.push(x);
    }

    int pop() {
        int size = que1.size();
        size--;
        while (size--) {
            que2.push(que1.front());
            que1.pop();
        }

        int result = que1.front();
        que1.pop();
        que1 = que2;
        while (!que2.empty()) {
            que2.pop();
        }

        return result;
    }

    int top() {
        return que1.back();
    }

    bool empty() {
        return que1.empty();
    }
};

int main() {
    // Solution s;
    return 0;
}
