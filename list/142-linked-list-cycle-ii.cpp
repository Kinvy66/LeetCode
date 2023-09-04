/**
* @file 142-linked-list-cycle-ii.cpp
* @brief 环形链表 II
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-08-30
* @details https://leetcode.cn/problems/linked-list-cycle-ii/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                ListNode* index1 = fast; // 相遇点
                ListNode* index2 = head; // 头
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;  // 回环入口
            }
        }
        return nullptr;
    }
};

int main() {
    Solution s;
    return 0;
}