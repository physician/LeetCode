/*
 Author:     physician
 Date:       Jan 12, 2014
 Update:     Jan 12, 2014
 Problem:    Binary Tree Preorder Traversal
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/binary-tree-preorder-traversal/

 Problem Description:
 Binary Tree Preorder Traversal: 

 Given a binary tree, return the preorder traversal of its nodes' values.

 For example:
 Given binary tree {1,#,2,3},
    1
     \
      2
     /
    3
 return [1,2,3].

 Note: Recursive solution is trivial, could you do it iteratively?

 Notes:
 1. First implementation, recursion. Time: O(N), Space: O(N).
 2. Factor the repetitive work into a helper function. e.g. void PreorderTraversalRecursion(TreeNode *, vector<int> &).
 3. Compile using g++: g++ BinaryTreePreorderTraversal.cpp -o BinaryTreePreorderTraversal.
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        preorderTraversalRecursion(root, result);
        return result;
    }

    void preorderTraversalRecursion(TreeNode *root, vector<int> &result) {
        if (root == NULL)
            return;
        result.push_back(root->val);
        preorderTraversalRecursion(root->left, result);
        preorderTraversalRecursion(root->right, result);
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
    vector<int> preorder = sol.preorderTraversal(&node0);
    cout << "Pre order traversal of binary tree:" << endl;
    for (int i = 0; i < preorder.size(); i++) 
        cout << preorder[i] << " ";
    cout << endl;
}
