/*
 Author:     physician
 Date:       Jan 14, 2014
 Update:     Jan 14, 2014
 Problem:    Linked List Cycle
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/linked-list-cycle/

 Problem Description:
 Linked List Cycle: 

 Given a linked list, determine if it has a cycle in it.

 Follow up:
 Can you solve it without using extra space?

 Notes:
 1. First implementation, use two pointers. If there's a cycle in the linked list, the fast and slow pointers will eventually meet.
 2. Compile using g++: g++ LinkedListCycle.cpp -o LinkedListCycle.
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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;
        ListNode *slow = head, *fast = head;
        while(true){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == NULL || fast->next == NULL)
                return false;
            if(fast == slow)
                return true;
        }
    }
};


int main() {
    ListNode node0(1);
    ListNode node1(2);
    ListNode node2(3);
    ListNode node3(4);
    ListNode node4(5);
    node0.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node2;
    Solution sol;
    if(sol.hasCycle(&node0))
        cout << "The linked list has a cycle in it." << endl;
    else
        cout << "The linked list has no cycle in it." << endl;
}
