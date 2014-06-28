/*
 Author:     physician
 Date:       Aug 27, 2013
 Update:     Jun 28, 2014
 Problem:    Convert Sorted List to Binary Search Tree
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

 Problem Description:
 Convert Sorted List to Binary Search Tree: 

 Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

 Notes:
 1. First implementation, convert to array, recursion.
 2. Second implementation, recursion, on linkedlist.
 3. Define intermediate variable to avoid repetitive calculation.
 4. Use "new" keyword to define object in c++, return a pointer to the object.
 5. Compile using g++: g++ ConvertSortedListtoBinarySearchTree.cpp -o ConvertSortedListtoBinarySearchTree.
*/

# include <iostream>
# include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        return sortedListToBST2(head);
    }

private:
    TreeNode *sortedListToBST1(ListNode *head) {
        // convert the sorted list to a sorted vector
        vector<int> sortedVec;
        ListNode *ptr = head;
        while(ptr != NULL) {
            sortedVec.push_back(ptr->val);
            ptr = ptr->next;
        } 
        return sortedArrayToBST1Re(sortedVec, 0, sortedVec.size());
    }

    TreeNode *sortedArrayToBST1Re(vector<int> &num, int begin, int end) {
        if (begin >= end)
            return NULL;
        else if (end-begin == 1) {
            TreeNode *node = new TreeNode(num[begin]);
            return node;
        }
        else {
            int mid = (begin+end)/2;
            TreeNode *node = new TreeNode(num[mid]);
            node->left = sortedArrayToBST1Re(num, begin, mid);
            node->right = sortedArrayToBST1Re(num, mid+1, end);
            return node;
        }
    }

    TreeNode *sortedListToBST2(ListNode *head) {
        return sortedListToBST2Re(head, 0, getLength(head)-1);
    }

    TreeNode *sortedListToBST2Re(ListNode *&head, int start, int end) {
        if (start > end)
            return NULL;
        int mid = start + (end-start)/2;
        TreeNode *left = sortedListToBST2Re(head, start, mid-1);
        TreeNode *root = new TreeNode(head->val);
        root->left = left;
        head = head->next;
        root->right = sortedListToBST2Re(head, mid+1, end);
        return root;
    }

    int getLength(ListNode *head) {
        int length = 0;
        while(head != NULL) {
            length++;
            head = head->next;
        }
        return length;
    }
};


void printTree(TreeNode *root) {
    if (root == NULL)
        return;
    else {
        printTree(root->left);
        cout << root->val << " ";
        printTree(root->right);
    }
}

int main() {
    ListNode node0(1);
    ListNode node1(2);
    ListNode node2(3);
    ListNode node3(4);
    ListNode node4(5);
    node0.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    Solution sol;
    TreeNode *root = sol.sortedListToBST(&node0);
    printTree(root);
    cout << endl;
}

