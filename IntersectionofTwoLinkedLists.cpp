/*
 Author:     physician
 Date:       Jan 24, 2015
 Update:     Jan 24, 2015
 Problem:    Intersection of Two Linked Lists
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/intersection-of-two-linked-lists/

 Problem Description:
 Intersection of Two Linked Lists: 

 Write a program to find the node at which the intersection of two singly linked lists begins.


 For example, the following two linked lists:

 A:          a1 → a2
                    ↘
                      c1 → c2 → c3
                    ↗            
 B:     b1 → b2 → b3
 begin to intersect at node c1.


 Notes:
 
 If the two linked lists have no intersection at all, return null.
 The linked lists must retain their original structure after the function returns.
 You may assume there are no cycles anywhere in the entire linked structure.
 Your code should preferably run in O(n) time and use only O(1) memory.

 Notes:
 1. First implementation, use two pointers.
 2. Compile using g++: g++ IntersectionofTwoLinkedLists.cpp -o IntersectionofTwoLinkedLists.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        return getIntersectionNode1(headA, headB);
    }
    
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode * pta = headA, * ptb = headB;
        while (true) {
            if (pta == ptb)
                return pta;
            if (pta->next == NULL && ptb->next == NULL)
                return NULL;
            pta = (pta->next == NULL) ? headB : pta->next;
            ptb = (ptb->next == NULL) ? headA : ptb->next;
        }
    }

    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode * pta = headA, * ptb = headB;
        int counta = 1, countb = 1;
        while (pta -> next != NULL) {
            pta = pta->next;
            counta++;
        }
        while (ptb -> next != NULL) {
            ptb = ptb->next;
            countb++;
        }
        pta = headA;
        ptb = headB;
        if (counta > countb)
            for (int i = 0; i < (counta - countb); ++i)
                pta = pta->next;
        if (countb > counta)
            for (int i = 0; i < (countb - counta); ++i)
                ptb = ptb->next;
        while (pta != ptb && pta->next != NULL && ptb->next != NULL) {
            pta = pta->next;
            ptb = ptb->next;
        }
        if (pta != ptb)
            return NULL;
        else
            return pta;
    }
};


int main() {
    ListNode nodea1(1);
    ListNode nodea2(2);
    ListNode nodeb1(3);
    ListNode nodeb2(4);
    ListNode nodeb3(5);
    ListNode nodec1(6);
    ListNode nodec2(7);
    ListNode nodec3(8);
    
    nodea1.next = &nodea2;
    nodea2.next = &nodec1;
    nodeb1.next = &nodeb2;
    nodeb2.next = &nodeb3;
    nodeb3.next = &nodec1;
    nodec1.next = &nodec2;
    nodec2.next = &nodec3;

    Solution sol;
    ListNode *ptr = sol.getIntersectionNode(&nodea1, &nodeb1);
    if (ptr != NULL)
        cout << "The node where the intersection begins has value: " << ptr->val << endl;
    else
        cout << "There is no intersection for the given lists." << endl;
}
