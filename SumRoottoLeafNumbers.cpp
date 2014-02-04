/*
 Author:     physician
 Date:       Feb 03, 2014
 Update:     Feb 03, 2014
 Problem:    Sum Root to Leaf Numbers
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/sum-root-to-leaf-numbers/

 Problem Description:
 Sum Root to Leaf Numbers: 

 Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

 An example is the root-to-leaf path 1->2->3 which represents the number 123.

 Find the total sum of all root-to-leaf numbers.

 For example,

     1
    / \
   2   3
 The root-to-leaf path 1->2 represents the number 12.
 The root-to-leaf path 1->3 represents the number 13.

 Return the sum = 12 + 13 = 25.

 Notes:
 1. First implementation, recursion.
 2. Compile using g++: g++ SumRoottoLeafNumbers.cpp -o SumRoottoLeafNumbers.
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
    int sumNumbers(TreeNode *root) {
        return sumNumbersRe(root, 0);
    }

private:
    int sumNumbersRe(TreeNode *root, int sum) {
        if (root == NULL)
            return 0;
        sum = 10*sum + root->val;
        if (root->left == NULL && root->right == NULL)
            return sum;
        return sumNumbersRe(root->left, sum) + sumNumbersRe(root->right, sum);
    }
};

int main() {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    node1.left = &node2;
    node1.right = &node4;
    node2.left = &node3;
    node3.right = &node5;
    Solution sol;
    cout << "The sum of root to leaf numbers is: " << sol.sumNumbers(&node1) << endl;
}
