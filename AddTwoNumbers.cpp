/*
 Author:     physician
 Date:       Aug 19, 2013
 Update:     Aug 19, 2013
 Problem:    Add Two Numbers
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_2

 Problem Description:
 Add Two Numbers: 

 You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8

 Notes:
 1. First implementation, use two ListNode pointers. 
 2. Compile using g++: g++ AddTwoNumbers.cpp -o AddTwoNumbers.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *pt1 = l1;
        ListNode *pt2 = l2;
        int carry = 0;

        ListNode *newNode = new ListNode(0);
        ListNode *oldNode;
        ListNode *result;
        if (pt1->val + pt2->val < 10) {
            newNode->val = pt1->val + pt2->val;
        }
        else {
            newNode->val = pt1->val + pt2->val - 10;
            carry = 1;
        }
        pt1 = pt1->next;
        pt2 = pt2->next;

        newNode->next = NULL;
        oldNode = newNode;
        result = newNode;
        while(pt1 != NULL && pt2 != NULL) {
            newNode = new ListNode(0);
            if (pt1->val + pt2->val + carry < 10) {
                newNode->val = pt1->val + pt2->val + carry;
                carry = 0;
            }
            else {
                newNode->val = pt1->val + pt2->val + carry - 10;
                carry = 1;
            }
            newNode->next = NULL;
            oldNode->next = newNode;
            oldNode = newNode;
            pt1 = pt1->next;
            pt2 = pt2->next;
        }

		
        if(pt1 == NULL && pt2 == NULL) { 
            if(carry == 1) {
                newNode = new ListNode(1);
                carry = 0;
                oldNode->next = newNode;
            }
        }

        else {
            ListNode *pt;
            if(pt1 != NULL && pt2 == NULL)
                pt = pt1;
            if(pt1 == NULL && pt2 != NULL)
                pt = pt2;

            while(pt != NULL) {
                if (pt->val + carry < 10) {
                    newNode = new ListNode(pt->val + carry);
                    carry = 0;
                }
                else {
                    newNode = new ListNode(pt->val + carry - 10);
                    carry = 1;
                }
                newNode->next = NULL;
                oldNode->next = newNode;
                oldNode = newNode;
                pt = pt->next;
            }
            if(carry == 1) {
                newNode = new ListNode(1);
                newNode->next = NULL;
                oldNode->next = newNode;
                oldNode = newNode;
            }
        }
        return result;
    }
};

int main() {
    ListNode node15(2);
    ListNode node14(9);
    ListNode node13(9);
    ListNode node12(4);
    ListNode node11(2);
    node14.next = &node15;
    node13.next = &node14;
    node12.next = &node13;
    node11.next = &node12;
    ListNode node23(4);
    ListNode node22(6);
    ListNode node21(5);
    node22.next = &node23;
    node21.next = &node22;

    ListNode * lnpter = &node11;
    cout << lnpter->val;
    while (lnpter->next != NULL) {
        lnpter = lnpter->next;
        cout << " -> " << lnpter->val;
    }
    cout << endl;
    lnpter = &node21;
    cout << lnpter->val;
    while (lnpter->next != NULL) {
        lnpter = lnpter->next;
        cout << " -> " << lnpter->val;
    }
    cout << endl;

    Solution sol;
    lnpter = sol.addTwoNumbers(&node11, &node21);
    cout << lnpter->val;
    while (lnpter->next != NULL) {
        lnpter = lnpter->next;
        cout << " -> " << lnpter->val;
    }
    cout << endl;
}
