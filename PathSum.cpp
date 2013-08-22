/*
 Author:     physician
 Date:       Aug 22, 2013
 Update:     Aug 22, 2013
 Problem:    Path Sum
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_112

 Problem Description:
 Path Sum: 

 Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 For example:
 Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

 return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

 Notes:
 1. First implementation, recursion.
 2. Compile using g++: g++ PathSum.cpp -o PathSum.
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
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL)
            return false;
        else if (root->left == NULL && root->right == NULL && root->val == sum)
            return true;
        else {
            return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
        } 
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
    if(sol.hasPathSum(&node0, 22))
        cout << "Exist a path gives the path sum." << endl;
    else
        cout << "No Path gives the path sum." << endl;
}
