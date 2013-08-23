/*
 Author:     physician
 Date:       Aug 23, 2013
 Update:     Aug 23, 2013
 Problem:    Same Tree
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_100

 Problem Description:
 Same Tree:

 Given two binary trees, write a function to check if they are equal or not.

 Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

 Notes:
 1. First implementation, recursion.
 2. Compile using g++: g++ SameTree.cpp -o SameTree.
*/

# include <iostream>

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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL)
            return true;
        else if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
            return false;
        else {
            return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        }
    }
};

int main() {
    TreeNode node0(0);
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);
    TreeNode node7(7);
    TreeNode node8(8);
    node0.left = &node1;
    node0.right = &node2;
    node1.left = &node3;
    node1.right = &node4;
    node2.left = &node5;
    node4.left = &node6;
    node4.right = &node7;
    node6.right = &node8;
    Solution sol;
    bool same = sol.isSameTree(&node0, &node1);
    if (same) 
        cout << "The given trees are the same!" << endl;
    else
        cout << "The given trees are not the same!" << endl;
}
