/*
 Author:     physician
 Date:       Sep 03, 2013
 Update:     Sep 03, 2013
 Problem:    Reverse Linked List II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_92

 Problem Description:
 Reverse Linked List II: 

 Reverse a linked list from position m to n. Do it in-place and in one-pass.

 For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4,

 return 1->4->3->2->5->NULL.

 Note:
 Given m, n satisfy the following condition:
 1 <= m <= n <= length of list.

 Notes:
 1. First implementation, use two pointers.
 2. Compile using g++: g++ ReverseLinkedListII.cpp -o ReverseLinkedListII.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m == n)
            return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *post = &dummy;
        ListNode *curr;
        ListNode *prev;
        ListNode *front;
        for (int i = 0; i < m-1; ++i) {
            post = post->next;
        }
        front = post;
        post = post->next;
        curr = post->next;
        prev = curr->next;
        for (int i = m; i < n; ++i) {
            curr->next = post;
            post = curr;
            curr = prev;
            if (prev != NULL)
                prev = prev->next;
        }
        front->next->next = curr;
        front->next = post;
        return dummy.next;
    }
};


int main() {
    int m = 2;
    int n = 4;
    ListNode node0(1);
    ListNode node1(2);
    ListNode node2(3);
    ListNode node3(4);
    ListNode node4(5);
    node0.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    cout << "Before the reversion:" << endl;
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
    ListNode *result = sol.reverseBetween(&node0, m, n);
    cout << "After the reversion between position " << m << " and " << n << ":" << endl;
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
