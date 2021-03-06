/*
 Author:     physician
 Date:       Jan 12, 2014
 Update:     Jun 27, 2014
 Problem:    Binary Tree Postorder Traversal
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/binary-tree-postorder-traversal/

 Problem Description:
 Binary Tree Postorder Traversal: 

 Given a binary tree, return the postorder traversal of its nodes' values.

 For example:
 Given binary tree {1,#,2,3},
    1
     \
      2
     /
    3
 return [3,2,1].

 Note: Recursive solution is trivial, could you do it iteratively?

 Notes:
 1. First implementation, recursion. Time: O(N), Space: O(N).
 2. Second implementation, iteration. Use stack. DFS.
 3. Factor the repetitive work into a helper function. e.g. void PostorderTraversalRecursion(TreeNode *, vector<int> &).
 4. In iterative method, remember the last node processed. Use it to determine which way we are moving up the tree.
 5. Compile using g++: g++ BinaryTreePostorderTraversal.cpp -o BinaryTreePostorderTraversal.
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
    vector<int> postorderTraversal(TreeNode *root) {
        return postorderTraversal2(root);
    }

private:
    // recursive method
    vector<int> postorderTraversal1(TreeNode *root) {
        vector<int> result;
        postorderTraversalRecursion(root, result);
        return result;
    }
	
    void postorderTraversalRecursion(TreeNode *root, vector<int> &result) {
        if (root == NULL)
            return;
        postorderTraversalRecursion(root->left, result);
        postorderTraversalRecursion(root->right, result);
        result.push_back(root->val);
    }

    // iterative method
    vector<int> postorderTraversal2(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> stk;
        TreeNode *curr = root;
        TreeNode *last = NULL;
        while (curr || !stk.empty()) {
            if (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            else {
                TreeNode *peak = stk.top();
                // moving up the tree from left child, go down the right child if exists
                if (peak->right && last != peak->right)
                    curr = peak->right;
                // no right child, or moving up the tree from right child, process the node and pop
                else {
                    result.push_back(peak->val);
                    stk.pop();
                    last = peak;
                }
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
    vector<int> postorder = sol.postorderTraversal(&node0);
    cout << "Post order traversal of binary tree:" << endl;
    for (int i = 0; i < postorder.size(); i++) 
        cout << postorder[i] << " ";
    cout << endl;
}
