/*
 Author:     physician
 Date:       Aug 27, 2013
 Update:     Aug 27, 2013
 Problem:    Convert Sorted List to Binary Search Tree
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_109

 Problem Description:
 Convert Sorted List to Binary Search Tree: 

 Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

 Notes:
 1. First implementation, convert to array, recursion. Refer to Leetcode Q108.
 2. Define intermediate variable to avoid repetitive calculation.
 3. Use "new" keyword to define object in c++, return a pointer to the object.
 4. Compile using g++: g++ ConvertSortedListtoBinarySearchTree.cpp -o ConvertSortedListtoBinarySearchTree.
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
        // convert the sorted list to a sorted vector
        vector<int> sortedVec;
        ListNode *ptr = head;
        while(ptr != NULL) {
            sortedVec.push_back(ptr->val);
            ptr = ptr->next;
        } 
        return sortedArrayToBST1(sortedVec, 0, sortedVec.size());
    }

private:
    TreeNode *sortedArrayToBST1(vector<int> &num, int begin, int end) {
        if (begin >= end)
            return NULL;
        else if (end-begin == 1) {
            TreeNode *node = new TreeNode(num[begin]);
            return node;
        }
        else {
            int mid = (begin+end)/2;
            TreeNode *node = new TreeNode(num[mid]);
            node->left = sortedArrayToBST1(num, begin, mid);
            node->right = sortedArrayToBST1(num, mid+1, end);
            return node;
        }
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

