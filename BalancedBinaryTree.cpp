/*
 Author:     physician
 Date:       Aug 24, 2013
 Update:     Aug 24, 2013
 Problem:    Balanced Binary Tree
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_110

 Problem Description:
 Balanced Binary Tree: 

 Given a binary tree, determine if it is height-balanced.

 For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

 Notes:
 1. First implementation, recursion.
 2. Compile using g++: g++ BalancedBinaryTree.cpp -o BalancedBinaryTree.
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
    bool isBalanced(TreeNode *root) {
        if (root == NULL)
            return true;
        else if (root->left == NULL && root->right == NULL)
            return true;
        else {
            int heightDiff = getHeight(root->left) - getHeight(root->right);
            return isBalanced(root->left) && isBalanced(root->right) && 
                    (heightDiff == 1 || heightDiff == 0 || heightDiff == -1);
        }
    }

private:
    int getHeight(TreeNode *root) {
        if (root == NULL)
            return 0;
        else if (root->left == NULL && root->right == NULL)
            return 1;
        else
            return 1 + max(getHeight(root->left), getHeight(root->right));
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
    bool isBal = sol.isBalanced(&node0);
    if (isBal)
        cout << "The binary tree is balanced." << endl;
    else
        cout << "The binary tree is not balanced." << endl;
}
