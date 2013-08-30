/*
 Author:     physician
 Date:       Aug 30, 2013
 Update:     Aug 30, 2013
 Problem:    Swap Nodes in Pairs
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_24

 Problem Description:
 Swap Nodes in Pairs: 

 Given a linked list, swap every two adjacent nodes and return its head.

 For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3.

 Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

 Notes:
 1. First implementation, use two pointers.
 2. Compile using g++: g++ SwapNodesinPairs.cpp -o SwapNodesinPairs.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
# include <iostream>

using namespace std;
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        if (head->next->next == NULL) {
            head->next->next = head;
            head = head->next;
            head->next->next = NULL;
            return head;
        }
        ListNode *begin = head->next->next;
        ListNode *end = head;
        while (begin != NULL) {
            end->next->next = end;
            if (end == head)
                head = end->next;
            if (begin->next != NULL)
                end->next = begin->next;
            else
                end->next = begin;
            end = begin;
            if (begin->next != NULL)
                begin = begin->next->next;
            else
                begin = begin->next;
        }
        if (begin != NULL)
            begin->next = end;
        else {
            if (end->next != NULL)
                end->next->next = end;
            end->next = NULL;
        }
        return head;
    }
};


int main() {
    ListNode node0(1);
    ListNode node1(2);
    ListNode node2(3);
    ListNode node3(4);
    ListNode node4(5);
    ListNode node5(6);
    node0.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    cout << "Before swap:" << endl;
    ListNode *ptr = &node0;
    if (ptr != NULL) {
        cout << ptr->val;
        ptr = ptr->next;
        while(ptr != NULL) {
            cout << "->" << ptr->val;
            ptr = ptr->next;
        }
    }
    cout << endl;
    Solution sol;
    ListNode *result = sol.swapPairs(&node0);
    cout << "After swap:" << endl;
    ptr = result;
    if (ptr != NULL) {
        cout << ptr->val;
        ptr = ptr->next;
        while(ptr != NULL) {
            cout << "->" << ptr->val;
            ptr = ptr->next;
        }
    }
    cout << endl;
}
