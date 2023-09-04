/**
* @file 206-reverse-linked-list.cpp
* @brief 反转链表
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-08-29
* @details https://leetcode.cn/problems/reverse-linked-list/
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Definition for singly-linked list.


    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur->next) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        cur->next = pre;
        return cur;
    }

};

int main() {
    Solution s;

    ListNode* head =  new ListNode(1);
    ListNode* a =  new ListNode(2);
    ListNode* b =  new ListNode(3);
    ListNode* c =  new ListNode(4);
    ListNode* d =  new ListNode(5);

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;

    s.reverseList(head);

    return 0;
}