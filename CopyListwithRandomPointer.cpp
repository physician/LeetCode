/*
 Author:     physician
 Date:       Jan 19, 2014
 Update:     Jan 19, 2014
 Problem:    Copy List with Random Pointer
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/copy-list-with-random-pointer/

 Problem Description:
 Copy List with Random Pointer: 

 A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

 Return a deep copy of the list.

 Notes:
 1. First implementation, unordered_map. 
 2. Compile using g++: g++ -std=c++0x CopyListwithRandomPointer.cpp -o CopyListwithRandomPointer.
*/


/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
# include <iostream>
# include <unordered_map>

using namespace std;
 
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;
        RandomListNode dummy(0);
        RandomListNode *ptr = head;
        RandomListNode *ptrNew = &dummy;
        unordered_map<RandomListNode *, RandomListNode *> randomListMap;
        while(ptr != NULL){
            if(randomListMap.find(ptr) == randomListMap.end())
                randomListMap[ptr] = new RandomListNode(ptr->label);
            if(ptr->random != NULL && randomListMap.find(ptr->random) == randomListMap.end())
                randomListMap[ptr->random] = new RandomListNode(ptr->random->label);
            ptrNew->next = randomListMap[ptr];
            ptrNew = ptrNew->next;
            ptrNew->random = randomListMap[ptr->random];
            ptr = ptr->next;
        }
        return dummy.next;
    }
};


int main() {
    RandomListNode node0(1);
    RandomListNode node1(2);
    RandomListNode node2(3);
    RandomListNode node3(4);
    RandomListNode node4(5);
    node0.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node0.random = &node0;
    node1.random = &node3;
    node3.random = &node4;
    node4.random = &node1;
    Solution sol;
    RandomListNode *ptr = &node0;
    cout << "Original Linkedlist:" << endl;
    while(ptr != NULL){
        cout << ptr->label << " ";
        if(ptr->next != NULL)
            cout << ptr->next->label << " ";
        if(ptr->random != NULL)
            cout << ptr->random->label << " ";
        cout << endl;
        ptr = ptr->next;
    }
    cout << endl;
    ptr = sol.copyRandomList(&node0);
    cout << "Copied Linkedlist:" << endl;
    while(ptr != NULL){
        cout << ptr->label << " ";
        if(ptr->next != NULL)
            cout << ptr->next->label << " ";
        if(ptr->random != NULL)
            cout << ptr->random->label << " ";
        cout << endl;
        ptr = ptr->next;
    }
    cout << endl;
}
