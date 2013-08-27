/*
 Author:     physician
 Date:       Aug 26, 2013
 Update:     Aug 26, 2013
 Problem:    Convert Sorted Array to Binary Search Tree
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_108

 Problem Description:
 Convert Sorted Array to Binary Search Tree: 

 Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 Notes:
 1. First implementation, recursion.
 2. Define intermediate variable to avoid repetitive calculation.
 3. Use "new" keyword to define object in c++, return a pointer to the object.
 4. Compile using g++: g++ ConvertSortedArraytoBinarySearchTree.cpp -o ConvertSortedArraytoBinarySearchTree.
*/

# include <iostream>
# include <vector>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST1(num, 0, num.size()); 
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
    int number[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> num(number, number + sizeof(number)/sizeof(int));
    Solution sol;
    TreeNode *root = sol.sortedArrayToBST(num);
    printTree(root);
    cout << endl;
}
