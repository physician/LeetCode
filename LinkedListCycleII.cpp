/*
 Author:     physician
 Date:       Jun 14, 2014
 Update:     Jun 14, 2014
 Problem:    Linked List Cycle II
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/linked-list-cycle-ii/

 Problem Description:
 Linked List Cycle II: 

 Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 
 Follow up:
 Can you solve it without using extra space? 

 Notes:
 1. First implementation, use two pointers. If there's a cycle in the linked list, the fast and slow pointers will eventually meet.
 2. Algorithm underneath, it's a math problem!

            beginning
                |
                v
    |<--- X --->|<------------------K
    1 --> 2 --> 3 --> 4 --> 5 --> 6 |
             ^  ^                 | |
             |  |                 v |
             | 10 <-- 9 <-- 8 <-- 7 |
             |        ^             |
             X------->|<------------|
                      |
        slow and fast pointers meet here

    Assume the length of the cycle is Y. 
    When they meet, if the distance slow pointer traveled is t, then the distance fast pointer traveled is 2t. 
    We have the following relations, 

    slow:  t = X + m*Y + K   (m: some integer)
    fast: 2t = X + n*Y + K   (n: some integer)

    so, we get
           X + K = (n-2m)*Y  (X + K is a multiple of cycle length)
           t = (n-m)*Y

    They tell us that, after slow and fast pointers meet, if we keep moving forward X nodes, we get back to the beginning of the cycle. 

 3. Compile using g++: g++ LinkedListCycleII.cpp -o LinkedListCycleII.
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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode *slow = head, *fast = head;
        while(true){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == NULL || fast->next == NULL)
                return NULL;
            if(fast == slow)
                break;
        }
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
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
    ListNode *node = sol.detectCycle(&node0);
    if (node != NULL)
        cout << "Cycle starts at node with value " << node->val << endl;
    else
        cout << "The linkedlist has no cycle!" << endl;
}
