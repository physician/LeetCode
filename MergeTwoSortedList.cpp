/*
 Author:     physician
 Date:       Sep 04, 2013
 Update:     Sep 04, 2013
 Problem:    Merge Two Sorted Lists
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_21

 Problem Description:
 Merge Two Sorted Lists: 

 Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

 Notes:
 1. First implementation, use two pointers.
 2. Compile using g++: g++ MergeTwoSortedList.cpp -o MergeTwoSortedList.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *pt = &dummy;
        ListNode *pt1 = l1;
        ListNode *pt2 = l2;
        while (pt1 != NULL && pt2 != NULL) {
            if (pt1->val <= pt2->val) {
                pt->next = pt1;
                pt1 = pt1->next;
            }
            else {
                pt->next = pt2;
                pt2 = pt2->next;
            }
            pt = pt->next;
        }
        if (pt1 != NULL)
            pt->next = pt1;
        else
            pt->next = pt2;
        return dummy.next;
    }
};


void printList(ListNode *head) {
    ListNode *ptr = head;
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


int main() {
    ListNode node10(1);
    ListNode node11(3);
    ListNode node12(5);
    ListNode node13(7);
    ListNode node14(9);
    node10.next = &node11;
    node11.next = &node12;
    node12.next = &node13;
    node13.next = &node14;
    cout << "List 1:" << endl;
    printList(&node10);

    ListNode node20(0);
    ListNode node21(2);
    ListNode node22(4);
    ListNode node23(6);
    ListNode node24(8);
    ListNode node25(10);
    node20.next = &node21;
    node21.next = &node22;
    node22.next = &node23;
    node23.next = &node24;
    node24.next = &node25;
    cout << "List 2:" << endl;
    printList(&node20);

    Solution sol;
    ListNode *result = sol.mergeTwoLists(&node10, &node20);
    cout << "After merge: " << endl;
    printList(result);
}
