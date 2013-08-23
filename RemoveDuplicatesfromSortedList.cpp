/*
 Author:     physician
 Date:       Aug 23, 2013
 Update:     Aug 23, 2013
 Problem:    Remove Duplicates from Sorted List
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_83

 Problem Description:
 Remove Duplicates from Sorted List: 

 Given a sorted linked list, delete all duplicates such that each element appear only once.

 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.

 Notes:
 1. First implementation, use two pointers.
 2. Compile using g++: g++ RemoveDuplicatesfromSortedList.cpp -o RemoveDuplicatesfromSortedList
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
        if (head == NULL)
            return head;
        ListNode *pt1 = head;
        ListNode *pt2 = head;
        while(pt1->next != NULL) {
            pt2 = pt1->next;
            while (pt2 != NULL && pt1->val == pt2->val) {
                pt1->next = pt2->next;
                pt2 = pt1->next;
            }
            if (pt2 != NULL)
                pt1 = pt2;
        }
        return head;
    }
};


int main() {
    ListNode node0(1);
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(3);
    node0.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
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
