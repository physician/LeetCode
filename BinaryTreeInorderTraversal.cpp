/*
 Author:     physician
 Date:       Aug 23, 2013
 Update:     Jun 27, 2014
 Problem:    Binary Tree Inorder Traversal
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/binary-tree-inorder-traversal/ 

 Problem Description:
 Binary Tree Inorder Traversal: 

 Given a binary tree, return the inorder traversal of its nodes' values.

 For example:
 Given binary tree {1,#,2,3},

    1
     \
      2
     /
    3

 return [1,3,2].

 Note: Recursive solution is trivial, could you do it iteratively?

 Notes:
 1. First implementation, recursion. Time: O(N), Space: O(N).
 2. Second implementation, iteration. Use stack. DFS. 
 3. Could factor the repetitive work into a helper function. e.g. void InorderTraversalRecursion(TreeNode *, vector<int> &). More efficient.
 4. Compile using g++: g++ BinaryTreeInorderTraversal.cpp -o BinaryTreeInorderTraversal.
*/

# include <iostream>
# include <vector>
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

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        return inorderTraversal2(root);
    }

private:
    // recursive method
    vector<int> inorderTraversal1(TreeNode *root) {
        vector<int> result;
        inorderTraversalRecursion(root, result);
        return result;
    }

    void inorderTraversalRecursion(TreeNode *root, vector<int> &result) {
        if (root == NULL)
            return;
        inorderTraversalRecursion(root->left, result);
        result.push_back(root->val);
        inorderTraversalRecursion(root->right, result);
    }

    // iterative method
    vector<int> inorderTraversal2(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> stk;
        TreeNode *curr = root;
        while (curr || !stk.empty()) {
            if (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            else {
                curr = stk.top();
                result.push_back(curr->val);
                curr = curr->right;
                stk.pop();
            }
        }
        return result;
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
    vector<int> inorder = sol.inorderTraversal(&node0);
    cout << "In order traversal of binary tree:" << endl;
    for (int i = 0; i < inorder.size(); i++) 
        cout << inorder[i] << " ";
    cout << endl;
}
