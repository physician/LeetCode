/*
 Author:     physician
 Date:       Aug 27, 2013
 Update:     Aug 27, 2013
 Problem:    Binary Tree Level Order Traversal II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_107

 Problem Description:
 Binary Tree Level Order Traversal II: 

 Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

 For example:
 Given binary tree {3,9,20,#,#,15,7},

     3
    / \
   9  20
     /  \
    15   7

 return its bottom-up level order traversal as:

 [
   [15,7]
   [9,20],
   [3],
 ]



 Notes:
 1. First implementation, queue, reverse vector. Refer to Leetcode Q102. 
 2. Use one queue, and two counting variables to keep track of number of nodes in the current level and next level. Use <algorithm> reverse function to reverse the vector.
 3. In c++ STL, void queue.pop(). pop() doesn't return the object in the queue. To access but not to pop the object, use queue.front().
 4. Compile using g++: g++ BinaryTreeLevelOrderTraversalII.cpp -o BinaryTreeLevelOrderTraversalII.
*/

# include <iostream>
# include <queue>
# include <algorithm>

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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        if (root == NULL)
            return result;
        queue<TreeNode *> q;
        vector<int> level;
        int currentLevel = 0;
        int nextLevel = 0;

        q.push(root);
        currentLevel++;
        while(!q.empty()) {
            TreeNode *ptr = q.front();
            q.pop();
            currentLevel--;
            level.push_back(ptr->val);
            if (ptr->left != NULL) {
                q.push(ptr->left);
                nextLevel++;
            }
            if (ptr->right != NULL) {
                q.push(ptr->right);
                nextLevel++;
            }
            if (currentLevel == 0) {
                result.push_back(level);
                level.clear();
                currentLevel = nextLevel;
                nextLevel = 0;
            }
        }
        reverse(result.begin(), result.end());
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
    vector<vector<int> > LOTraversal = sol.levelOrderBottom(&node0);
    cout << "[" << endl;
    for (int i = 0; i < LOTraversal.size(); i++) {
        cout << "  [" << LOTraversal[i][0];
        for (int j = 1; j < LOTraversal[i].size(); j++) {
            cout << "," << LOTraversal[i][j];
        }
        cout << "]" << endl;
    }
    cout << "]" << endl; 
}
