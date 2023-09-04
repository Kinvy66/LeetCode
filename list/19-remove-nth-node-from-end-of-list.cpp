/**
* @file 19-remove-nth-node-from-end-of-list.cpp
* @brief 删除链表的倒数第 N 个结点
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-08-29
* @details https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        while (n-- && fast != NULL){
            fast = fast->next;
        }
        fast =  fast->next;
        while (fast != nullptr) {
         slow = slow->next;
         fast = fast->next;
        }
        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        return dummyHead->next;
    }
};

int main() {
    Solution s;
    return 0;
}
