/*
 Author:     physician
 Date:       Aug 29, 2013
 Update:     Aug 29, 2013
 Problem:    Remove Duplicates from Sorted List II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_82

 Problem Description:
 Remove Duplicates from Sorted List II: 

 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

 For example,
 Given 1->2->3->3->4->4->5, return 1->2->5.
 Given 1->1->1->2->3, return 2->3.

 Notes:
 1. First implementation, recursion.
 2. Compile using g++: g++ RemoveDuplicatesfromSortedListII.cpp -o RemoveDuplicatesfromSortedListII
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *ptr = head->next;
        if (head->val == ptr->val) {
            while (ptr->next != NULL && ptr->next->val == head->val)
                ptr = ptr->next;
            head = ptr->next;
            head = deleteDuplicates(head);
        }
        else {
            head->next = deleteDuplicates(ptr);
        }
    }
};


int main() {
    ListNode node0(1);
    ListNode node1(2);
    ListNode node2(3);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(4);
    ListNode node6(5);
    
    node0.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;

    cout << "Before deletion:" << endl;
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
    ListNode *result = sol.deleteDuplicates(&node0);
    cout << "After deletion:" << endl;
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
