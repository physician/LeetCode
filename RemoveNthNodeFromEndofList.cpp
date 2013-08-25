/*
 Author:     physician
 Date:       Aug 24, 2013
 Update:     Aug 24, 2013
 Problem:    Remove Nth Node From End of List
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_19

 Problem Description:
 Remove Nth Node From End of List: 

 Given a linked list, remove the nth node from the end of list and return its head.

 For example,

    Given linked list: 1->2->3->4->5, and n = 2.

    After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note:
 Given n will always be valid.
 Try to do this in one pass.

 Notes:
 1. First implementation, use two ListNode pointers, maintain front - back = n.
 2. Compile using g++: g++ RemoveNthNodeFromEndofList.cpp -o RemoveNthNodeFromEndofList
*/

# include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *front = head;
        ListNode *back = head;
        int step = 0;
        while (step < n) {
            front = front->next;
            step++;
        }
        // the node to delete is the head
        if (!front) {
            head = head->next;
            return head;
        }
        while (front->next != NULL) {
            front = front->next;
            back = back->next;
        }
     
        ListNode *del = back->next;
        back->next = del->next;
        //delete del;
        
        return head;
    }
};

int main() {
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    ListNode * lnpter = &node1;
    cout << lnpter->val;
    while (lnpter->next != NULL) {
        lnpter = lnpter->next;
        cout << " -> " << lnpter->val;
    }
    cout << endl;

    Solution sol;
    lnpter = sol.removeNthFromEnd(&node1, 5);
    cout << lnpter->val;
    while (lnpter->next != NULL) {
        lnpter = lnpter->next;
        cout << " -> " << lnpter->val;
    }
    cout << endl;
}
