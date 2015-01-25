/*
 Author:     physician
 Date:       Jan 25, 2015
 Update:     Jan 25, 2015
 Problem:    Binary Search Tree Iterator
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/binary-search-tree-iterator/

 Problem Description:
 Binary Search Tree Iterator: 

 Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

 Calling next() will return the next smallest number in the BST.

 Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

 Notes:
 1. First implementation, stack. 
 2. Compile using g++: g++ BinarySearchTreeIterator.cpp -o BinarySearchTreeIterator.
*/

 
# include <iostream>
# include <stack>

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

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        TreeNode *ptr = root;
        while (ptr != NULL) {
            stk.push(ptr);
            ptr = ptr->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmp = stk.top();
        int value = tmp->val;
        stk.pop();
        if (tmp->right != NULL) {
            tmp = tmp->right;
            stk.push(tmp);
            while (tmp->left != NULL) {
                tmp = tmp->left;
                stk.push(tmp);
            }
        }
        return value;
    }

private:
    stack<TreeNode *> stk;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);
    TreeNode node7(7);
    TreeNode node8(8);
    TreeNode node9(9);
    TreeNode node10(10);
    TreeNode node11(11);
    TreeNode node12(12);
    TreeNode node13(13);
    TreeNode node14(14);
    TreeNode node15(15);
    node8.left = &node4;
    node8.right = &node12;
    node4.left = &node2;
    node4.right = &node6;
    node2.left = &node1;
    node2.right = &node3;
    node6.left = &node5;
    node6.right = &node7;
    node12.left = &node10;
    node12.right = &node14;
    node10.left = &node9;
    node10.right = &node11;
    node14.left = &node13;
    node14.right = &node15;

    TreeNode *root = &node8;
    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) 
        cout << i.next() << " ";
    cout << endl;
}
