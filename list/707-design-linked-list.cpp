/**
* @file 707-design-linked-list.cpp
* @brief 设计链表
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-08-29
* @details https://leetcode.cn/problems/design-linked-list/
*/

#include <iostream>
#include <vector>

using namespace std;

class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode *next;

        explicit ListNode(int x = 0) : val(x), next(nullptr) {}
    };

    MyLinkedList() {
        m_head = new ListNode(); // 虚拟头节点
        m_size = 0;
    }

    // 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
    int get(int index) {
        if (index > m_size - 1) return -1;
        ListNode* cur = m_head->next;
        while (index) {
            cur = cur->next;
            index--;
        }
        return cur->val;
    }

    // 将一个值为 val 的节点插入到链表中第一个元素之前。
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = m_head->next;
        m_head->next = newNode;
        m_size++;
    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* cur = m_head;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = newNode;
        m_size++;
    }

    void addAtIndex(int index, int val) {
        if (index > m_size) return;
        ListNode* newNode = new ListNode(val);
        ListNode* cur  = m_head;
        while (index) {
            cur = cur->next;
            index--;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        m_size++;
    }

    void deleteAtIndex(int index) {
        if (index > m_size - 1) return;
        ListNode* cur = m_head;
        while (index) {
            cur = cur->next;
            index--;
        }
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        m_size--;
    }

    void printList() {
        ListNode* cur = m_head->next;
        while (cur) {
            std::cout << cur->val << "->" ;
            cur = cur->next;
        }
        std::cout << "NULL" <<  std::endl;
    }

private:
    int m_size;
    ListNode* m_head;
};

int main() {
     MyLinkedList myLinkedList;
     myLinkedList.addAtHead(4);
     myLinkedList.get(1);
     myLinkedList.addAtHead(1);
     myLinkedList.addAtHead(5);
     myLinkedList.deleteAtIndex(3);
     myLinkedList.addAtHead(7);
     myLinkedList.get(3);
     myLinkedList.get(3);
     myLinkedList.get(3);
     myLinkedList.addAtHead(1);
     myLinkedList.deleteAtIndex(4);

    return 0;
}
