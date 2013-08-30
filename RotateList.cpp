/*
 Author:     physician
 Date:       Aug 29, 2013
 Update:     Aug 29, 2013
 Problem:    Rotate List
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_61

 Problem Description:
 Rotate List: 

 Given a list, rotate the list to the right by k places, where k is non-negative.

 For example:
 Given 1->2->3->4->5->NULL and k = 2,
 return 4->5->1->2->3->NULL.

 Notes:
 1. First implementation, use two pointers. Maintain begin - end = k mod list.size().
 2. Compile using g++: g++ RotateList.cpp -o RotateList.
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || k == 0)
            return head;
        ListNode *begin = head;
        ListNode *end = head;
        int i = 0;
        while (i < k) {
            if (begin->next != NULL)
                begin = begin->next;
            else {
                begin = head;
            }
            ++i;
        }
        while(begin->next != NULL) {
            begin = begin->next;
            end = end->next;
        }
        begin->next = head;
        head = end->next;
        end->next = NULL;
        return head;
    }
};

int main() {
    int k = 6;
    ListNode node0(1);
    ListNode node1(2);
    ListNode node2(3);
    ListNode node3(4);
    ListNode node4(5);
    node0.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    cout << "Before rotation:" << endl;
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
    ListNode *result = sol.rotateRight(&node0, k);
    cout << "After rotation:" << endl;
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
