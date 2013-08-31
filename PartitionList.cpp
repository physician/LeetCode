/*
 Author:     physician
 Date:       Aug 31, 2013
 Update:     Aug 31, 2013
 Problem:    Partition List
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_86

 Problem Description:
 Partition List: 

 Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

 You should preserve the original relative order of the nodes in each of the two partitions.

 For example,
 Given 1->4->3->2->5->2 and x = 3,
 return 1->2->2->4->3->5.

 Notes:
 1. First implementation, use two pointers.
 2. Compile using g++: g++ PartitionList.cpp -o PartitionList.
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
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL)
            return head;
        ListNode *slow;
        if (head->val < x) {
            slow = head;
            while (slow->next != NULL && slow->next->val < x)
                slow = slow->next;
        }
        else {
            slow = new ListNode(x-1);  // dummy head node
            slow->next = head;   
        }
        ListNode *fast = slow->next;
        ListNode *shadow = slow;
        while (fast != NULL) {
            if (fast->val < x) {
                shadow->next = fast->next;
                fast->next = slow->next;
                if (slow->next == head) {
                    head = fast;
                    delete slow;
                    slow = head; 
                }
                else {
                    slow->next = fast;
                    slow = slow->next;
                }
                fast = shadow->next;
            }
            else {
                fast = fast->next;
                shadow = shadow->next;
            }
        }
        return head;
    }
};


int main() {
    int x = 3;
    ListNode node0(1);
    ListNode node1(4);
    ListNode node2(3);
    ListNode node3(2);
    ListNode node4(5);
    ListNode node5(2);
    node0.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    cout << "Before partition:" << endl;
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
    ListNode *result = sol.partition(&node0, x);
    cout << "After partition:" << endl;
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
