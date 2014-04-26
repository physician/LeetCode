/*
 Author:     physician
 Date:       Apr 26, 2014
 Update:     Apr 26, 2014
 Problem:    Insertion Sort List
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/insertion-sort-list/

 Problem Description:
 Insertion Sort List: 

 Sort a linked list using insertion sort.

 Notes:
 1. First implementation, insertion sort, use two pointers.
 2. Compile using g++: g++ InsertionSortList.cpp -o InsertionSortList.
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
# include <limits.h>

using namespace std;
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy = ListNode(INT_MIN);
        dummy.next = head;
        ListNode *ptr1 = &dummy;
        while (ptr1 != NULL) {
            if (ptr1->next == NULL || ptr1->val <= ptr1->next->val)
                ptr1 = ptr1->next;
            else {
                ListNode *ptr2 = &dummy;
                while (ptr2->next != NULL && ptr2->next->val <= ptr1->next->val)
                    ptr2 = ptr2->next;
                ListNode *temp = ptr2->next;
                ptr2->next = ptr1->next;
                ptr1->next = ptr1->next->next;
                ptr2->next->next = temp;
            }
        }
        return dummy.next;
    }
};


int main() {
    ListNode node0(4);
    ListNode node1(2);
    ListNode node2(1);
    ListNode node3(5);
    ListNode node4(3);
    node0.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    Solution sol;
    cout << "Before sorting:" << endl;
    ListNode *ptr = &node0;
    while(ptr->next != NULL){
        cout << ptr->val << " -> ";
        ptr = ptr->next;
    }
    cout << ptr->val << endl;
    cout << "After sorting:" << endl;
    ptr = sol.insertionSortList(&node0);
    while(ptr->next != NULL){
        cout << ptr->val << " -> ";
        ptr = ptr->next;
    }
    cout << ptr->val << endl;
}
