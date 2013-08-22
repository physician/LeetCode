/*
 Author:     physician
 Date:       Aug 22, 2013
 Update:     Aug 22, 2013
 Problem:    Minimum Depth of Binary Tree
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_111

 Problem Description:
 Minimum Depth of Binary Tree: 

 Given a binary tree, find its minimum depth.

 The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

 Notes:
 1. First implementation, recursion.
 2. Compile using g++: g++ MinimumDepthofBinaryTree.cpp -o MinimumDepthofBinaryTree.
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
    int minDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        else if (root->left == NULL && root->right == NULL)
            return 1;
        else if (root->left == NULL)
            return 1 + minDepth(root->right);
        else if (root->right == NULL)
            return 1 + minDepth(root->left);
        else
            return 1 + min(minDepth(root->left), minDepth(root->right));
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
    cout << "Minimum depth of the binary tree is: " << sol.minDepth(&node0) << endl;
}
