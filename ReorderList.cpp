/*
 Author:     physician
 Date:       Apr 27, 2014
 Update:     Apr 27, 2014
 Problem:    Reorder List
 Difficulty: Medium
 Source:     http://oj.leetcode.com/problems/reorder-list/

 Problem Description:
 Reorder List: 

 Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

 You must do this in-place without altering the nodes' values.

 For example,
 Given {1,2,3,4}, reorder it to {1,4,2,3}.

 Notes:
 1. First implementation, use three pointers. O(N) solution.
 2. O(N) algorithm: First reverse the 2nd half of the list, then reorder the whole list.
 3. Compile using g++: g++ ReorderList.cpp -o ReorderList.
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
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return;
        ListNode *fast = head->next->next, *slow = head->next;
        while(fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // reverse the 2nd half of the linkedlist
        ListNode *curr = slow->next;
        while(curr->next != NULL) {
            fast = curr->next;
            curr->next = fast->next;
            fast->next = slow->next;
            slow->next = fast;
        }
        curr = head;
        while(curr != slow) {
            slow->next = fast->next;
            fast->next = curr->next;
            curr->next = fast;
            fast = slow->next;
            curr = curr->next->next;
        }
    }

/*
    // O(N^2) solution (Time Limit Exceeded)
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return;
        ListNode *ptr1 = head;
        while (ptr1->next != NULL && ptr1->next->next != NULL) {
            ListNode *ptr2 = ptr1;
            while (ptr2->next->next != NULL)
                ptr2 = ptr2->next;
            ptr2->next->next = ptr1->next;
            ptr1->next = ptr2->next;
            ptr2->next = NULL;
            ptr1 = ptr1->next->next;
        }
    }
*/
};


int main() {
    ListNode node0(1);
    ListNode node1(2);
    ListNode node2(3);
    ListNode node3(4);
    //ListNode node4(5);
    //ListNode node5(6);
    node0.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    //node3.next = &node4;
    //node4.next = &node5;
    Solution sol;
    cout << "Before reordering:" << endl;
    ListNode *ptr = &node0;
    while(ptr->next != NULL){
        cout << ptr->val << " -> ";
        ptr = ptr->next;
    }
    cout << ptr->val << endl;
    cout << "After reordering:" << endl;
    sol.reorderList(&node0);
    ptr = &node0;
    while(ptr->next != NULL){
        cout << ptr->val << " -> ";
        ptr = ptr->next;
    }
    cout << ptr->val << endl;
}
