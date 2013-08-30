/*
 Author:     physician
 Date:       Aug 30, 2013
 Update:     Aug 30, 2013
 Problem:    Symmetric Tree
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_101

 Problem Description:
 Symmetric Tree:

 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

 For example, this binary tree is symmetric:

     1
    / \
   2   2
  / \ / \
 3  4 4  3

 But the following is not:

     1
    / \
   2   2
    \   \
    3    3

 Note:
 Bonus points if you could solve it both recursively and iteratively.

 Notes:
 1. First implementation, recursion.
 2. Compile using g++: g++ SymmetricTree.cpp -o SymmetricTree.
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
    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
            return true;
        else
            return isMirror(root->left, root->right);    
    }

private:
    bool isMirror(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL)
            return true;
        else if (left == NULL || right == NULL)
            return false;
        else
            return (left->val == right->val) && (isMirror(left->left, right->right)) && (isMirror(left->right, right->left));
    }
};

int main() {
    TreeNode node0(1);
    TreeNode node1(2);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(4);
    TreeNode node6(3);
    node0.left = &node1;
    node0.right = &node2;
    node1.left = &node3;
    node1.right = &node4;
    node2.left = &node5;
    node2.right = &node6;
    Solution sol;
    bool sym = sol.isSymmetric(&node0);
    if (sym) 
        cout << "The given tree is symmetric!" << endl;
    else
        cout << "The given tree is NOT symmetric!" << endl;
}
