/**
* @file 0207-intersection-of-two-linked-lists-lcci.cpp
* @brief 链表相交
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-08-29
* @details https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/
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

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        while (curA != nullptr) {
            lenA++;
            curA = curA->next;
        }
        while (curB != nullptr) {
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;

        if (lenB > lenA) {
            swap(lenA, lenB);
            swap(curA, curB);
        }

        int gap = lenA - lenB;
        while (gap--) {
            curA = curA->next;
        }

        while (curA != nullptr) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }

};

int main() {
    Solution s;
    return 0;
}
