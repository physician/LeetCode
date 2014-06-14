/*
 Author:     physician
 Date:       Jun 13, 2014
 Update:     Jun 13, 2014
 Problem:    Merge k Sorted Lists
 Difficulty: Medium 
 Source:     https://oj.leetcode.com/problems/merge-k-sorted-lists/

 Problem Description:
 Merge k Sorted Lists: 

 Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 

 Notes:
 1. First implementation, use heap or priority queue. Find current smallest node using min-heap or min priority_queue(log(k)). Overall time complexity: O(Nlog(K)).
 2. Usage of make_heap, push_heap, pop_heap, and sort_heap in <algorithm>. Max-heap by default. 
 3. Usage of top, push, and pop in <queue>::priority_queue. Max priority_queue by default.
 4. Use user-defined comparator when min-heap or min priority_queue is needed. Define comparison function or define operator().
 5. Compile using g++: g++ MergekSortedLists.cpp -o MergekSortedLists.
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
# include <vector>
# include <algorithm>
# include <queue>

using namespace std;
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList (ListNode *node) {
    ListNode *ptr = node;
    while(ptr != NULL && ptr->next != NULL){
        cout << ptr->val << " -> ";
        ptr = ptr->next;
    }
    cout << ptr->val << endl;
}

bool Greater(ListNode *a, ListNode *b) {
    return a->val > b->val;
}

class PtrCompare {
public:
    bool operator()(ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return mergeKLists1(lists);
    }

    ListNode *mergeKLists1(vector<ListNode *> &lists) {
        ListNode dummy(0);
        ListNode *ptr = &dummy;
        vector<ListNode *> ptrHeap;
        for (int i = 0; i < lists.size(); ++i)
            if (lists[i] != NULL)
                ptrHeap.push_back(lists[i]);
        make_heap(ptrHeap.begin(), ptrHeap.end(), Greater);
        while(!ptrHeap.empty()) {
            ptr->next = ptrHeap.front();
            pop_heap(ptrHeap.begin(), ptrHeap.end(), Greater);
            ptrHeap.pop_back();
            ptr = ptr->next;
            if (ptr->next != NULL) {
                ptrHeap.push_back(ptr->next);
                push_heap(ptrHeap.begin(), ptrHeap.end(), Greater);
            }
        }
        return dummy.next;
    }

    ListNode *mergeKLists2(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, PtrCompare> pq;
        for (int i = 0; i < lists.size(); ++i)
            if (lists[i] != NULL)
                pq.push(lists[i]);
        ListNode dummy(0);
        ListNode *ptr = &dummy;
        while (!pq.empty()) {
            ptr->next = pq.top();
            pq.pop();
            ptr = ptr->next;
            if (ptr->next != NULL)
                pq.push(ptr->next);
        }
        return dummy.next;
    }
};


int main() {
    ListNode node10(1);
    ListNode node11(2);
    ListNode node12(4);
    ListNode node13(8);
    ListNode node20(3);
    ListNode node21(5);
    ListNode node22(6);
    ListNode node23(9);
    ListNode node24(10);
    ListNode node30(0);
    ListNode node31(7);
    node10.next = &node11;
    node11.next = &node12;
    node12.next = &node13;
    node20.next = &node21;
    node21.next = &node22;
    node22.next = &node23;
    node23.next = &node24;
    node30.next = &node31;

    vector<ListNode *> lists;
    lists.push_back(&node10);
    lists.push_back(&node20);
    lists.push_back(&node30);
    Solution sol;
    cout << "Before sorting:" << endl;
    for(int i = 0; i < lists.size(); ++i)
        printList(lists[i]);
    ListNode *ptr = sol.mergeKLists(lists);
    cout << "After sorting:" << endl;
    printList(ptr);
}
