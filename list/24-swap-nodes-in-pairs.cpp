/**
* @file 24-swap-nodes-in-pairs.cpp
* @brief 两两交换链表中的节点
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-08-29
* @details https://leetcode.cn/problems/swap-nodes-in-pairs/
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
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);  // 设置以虚拟头
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next;
            ListNode* tmp1 = cur->next->next->next;

            cur->next =  cur->next->next;
            cur->next->next = tmp;
            cur->next->next->next = tmp1;

            cur = cur->next->next;
        }
        return dummyHead->next;
    }

};

int main() {
    Solution s;
    return 0;
}
