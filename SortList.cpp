/*
 Author:     physician
 Date:       Apr 26, 2014
 Update:     Apr 26, 2014
 Problem:    Sort List
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/sort-list/

 Problem Description:
 Sort List: 

 Sort a linked list in O(n log n) time using constant space complexity.

 Notes:
 1. First implementation, merge sort, recursion.
 2. Compile using g++: g++ SortList.cpp -o SortList.
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
    ListNode *sortList(ListNode *head) {
        return mergeSort(head, getLength(head));
    }

private:
    ListNode *splitList(ListNode *head, int length) {
        ListNode *right = head, *temp = head;
        for (int i = 0; i < length/2-1; ++i) 
            right = right->next;
        temp = right;
        right = right->next;
        temp->next = NULL;
        return right;
    }

    ListNode *mergeList(ListNode *left, ListNode *right) {
        ListNode dummy = ListNode(0);
        ListNode *cur = &dummy;
        while (left && right) {
            if (left->val <= right->val) {
                cur->next = left;
                left = left->next;
            }
            else {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        if (left != NULL) 
            cur->next = left;
        else
            cur->next = right;
        return dummy.next;
    }

    ListNode *mergeSort(ListNode *head, int length) {
        if (length <= 1)
            return head;
        ListNode *left = head;
        ListNode *right = splitList(head, length);
        left = mergeSort(left, length/2);
        right = mergeSort(right, length-length/2);
        return mergeList(left, right);
    }

    int getLength(ListNode *head) {
        ListNode *ptr = head;
        int length = 0;
        while (ptr != NULL) {
            ptr = ptr->next;
            length++;
        }
        return length;
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
    ptr = sol.sortList(&node0);
    while(ptr->next != NULL){
        cout << ptr->val << " -> ";
        ptr = ptr->next;
    }
    cout << ptr->val << endl;
}
