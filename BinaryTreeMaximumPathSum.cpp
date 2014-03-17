/*
 Author:     physician
 Date:       Mar 16, 2013
 Update:     Mar 16, 2013
 Problem:    Binary Tree Maximum Path Sum
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/binary-tree-maximum-path-sum/

 Problem Description:
 Binary Tree Maximum Path Sum: 

 Given a binary tree, find the maximum path sum.

 The path may start and end at any node in the tree.

 For example:
 Given the below binary tree,

        1
       / \
      2   3

 Return 6.

 Notes:
 1. First implementation, recursion.
 2. Important: differentiate "connectable sum" and "unconnectable sum" in recursion function. Treat the maximum path sum as a "global" variable. And return "connectable sum" each time in recursion.
 3. Compile using g++: g++ BinaryTreeMaximumPathSum.cpp -o BinaryTreeMaximumPathSum.
*/

# include <iostream>
# include <climits>  // <limits.h>

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
    int maxPathSum(TreeNode *root) {
        if (root == NULL)
            return 0;
        int maxSum = INT_MIN;
        maxPathSumRe(root, maxSum);
        return maxSum;
    }

private:
    int maxPathSumRe(TreeNode *root, int &maxPathSum) {
        if (root == NULL)
            return 0;
        int lsub = maxPathSumRe(root->left, maxPathSum);
        int rsub = maxPathSumRe(root->right, maxPathSum);
        int sum = max(root->val, root->val + max(lsub, rsub));
        maxPathSum = max(maxPathSum, max(sum, root->val + lsub + rsub)); 
        return sum;
    }
};

int main() {
    TreeNode node0(5);
    TreeNode node1(4);
    TreeNode node2(8);
    TreeNode node3(11);
    TreeNode node4(13);
    TreeNode node5(4);
    TreeNode node6(7);
    TreeNode node7(2);
    TreeNode node8(1);
    node0.left = &node1;
    node0.right = &node2;
    node1.left = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    node5.right = &node8;
    Solution sol;
    cout << "The maximum path sum is: " << sol.maxPathSum(&node0) << endl;
}
