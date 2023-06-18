/**
* @file 002-addTwoNumbers.cpp
* @brief 
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-06-18
* @details https://leetcode.cn/problems/add-two-numbers/
*/
#include <iostream>
#include <vector>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* rt = new ListNode();
        ListNode* cur = rt;
        int flag = 0;
        while (h1 != nullptr || h2 != nullptr) {
            ListNode* node = new ListNode();
            cur->next = node;
            int v1 = (h1 == nullptr) ? 0 : h1->val;
            int v2 = (h2 == nullptr) ? 0 : h2->val;
            node->val = (v1 + v2 + flag) % 10 ;
            flag = ((v1 + v2 + flag) >= 10 ) ? 1 : 0;
            h1 = (h1 == nullptr) ? nullptr : h1->next;
            h2 = (h2 == nullptr) ? nullptr : h2->next;
            cur = node;
        }
        if (flag == 1) {
            ListNode* node = new ListNode();
            cur->next = node;
            node->val = 1;
        }
        return rt->next;
    }
};

ListNode* addEle(std::vector<int>& vec) {
    ListNode* head = new ListNode();
    ListNode* cur = head;
    for (auto e : vec) {
        ListNode* node = new ListNode();
        cur->next = node;
        node->val = e;
        cur = node;
    }
    return head->next;
}

void printList(ListNode* listNode) {
    ListNode* cur = listNode;
    while (cur != nullptr) {
        std::cout << cur->val << "\t";
        cur = cur->next;
    }
    std::cout << std::endl;
}

int main() {
    vector<int> v1 = {9,9,9,9,9,9,9};
    vector<int> v2 = {9,9,9,9};
    ListNode* l1 = addEle(v1);
    ListNode* l2 = addEle(v2);

    printList(l1);
    printList(l2);

    Solution s;
    ListNode* result =  s.addTwoNumbers(l1, l2);
    printList(result);
    return 0;
}
