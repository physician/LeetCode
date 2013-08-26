/*
 Author:     physician
 Date:       Aug 22, 2013
 Update:     Aug 22, 2013
 Problem:    Validate Binary Search Tree
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_98

 Problem Description:
 Validate Binary Search Tree: 

 Given a binary tree, determine if it is a valid binary search tree (BST).

 Assume a BST is defined as follows:

 1. The left subtree of a node contains only nodes with keys less than the node's key.
 2. The right subtree of a node contains only nodes with keys greater than the node's key.
 3. Both the left and right subtrees must also be binary search trees.

 Notes:
 1. First implementation, recursion.
 2. Compile using g++: g++ ValidateBinarySearchTree.cpp -o ValidateBinarySearchTree.
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
    bool isValidBST(TreeNode *root) {
        if (root == NULL)
            return true;
        else if (root->left == NULL && root->right == NULL)
            return true;
        else if (root->left != NULL && root->right == NULL)
            return isValidBST(root->left) && (root->val > maxElem(root->left));
        else if (root->right != NULL && root->left == NULL)
            return isValidBST(root->right) && (root->val < minElem(root->right));
        else
            return isValidBST(root->left) && isValidBST(root->right) &&
                    (root->val > maxElem(root->left)) && (root->val < minElem(root->right));
         
    }
private:
    int maxElem(TreeNode *root) {
        TreeNode *ptr = root;
        while (ptr->right != NULL)
            ptr = ptr->right;
        return ptr->val;
    }
    int minElem(TreeNode *root) {
        TreeNode *ptr = root;
        while (ptr->left != NULL)
            ptr = ptr->left;
        return ptr->val;
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
    bool valid = sol.isValidBST(&node0);
    if (valid)
        cout << "This is a valid BST!" << endl;
    else
        cout << "This is NOT a valid BST!" << endl;
}
