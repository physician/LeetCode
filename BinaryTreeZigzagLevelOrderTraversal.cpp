/*
 Author:     physician
 Date:       Sep 07, 2013
 Update:     Sep 07, 2013
 Problem:    Binary Tree Zigzag Level Order Traversal
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_103

 Problem Description:
 Binary Tree Zigzag Level Order Traversal: 

 Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

 For example:
 Given binary tree {3,9,20,#,#,15,7},

     3
    / \
   9  20
     /  \
    15   7
 return its zigzag level order traversal as:

 [
   [3],
   [20,9],
   [15,7]
 ]


 Notes:
 1. First implementation, queue. Use one queue, and two counting variables to keep track of number of nodes in the current level and next level. Use another boolean variable to keep track of whether to store the nodes in normal order or reversed order.
 2. In c++ STL, void queue.pop(). pop() doesn't return the object in the queue. To access but not to pop the object, use queue.front().
 3. Compile using g++: g++ BinaryTreeZigzagLevelOrderTraversal.cpp -o BinaryTreeZigzagLevelOrderTraversal.
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (root == NULL)
            return result;
        queue<TreeNode *> q;
        vector<int> level;
        int currentLevel = 0;
        int nextLevel = 0;
        bool reversed = false;

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
                if (reversed)
                    reverse(level.begin(), level.end());
                result.push_back(level);
                level.clear();
                reversed = !reversed;
                currentLevel = nextLevel;
                nextLevel = 0;
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
    vector<vector<int> > ZLOTraversal = sol.zigzagLevelOrder(&node0);
    cout << "[" << endl;
    for (int i = 0; i < ZLOTraversal.size(); i++) {
        cout << "  [" << ZLOTraversal[i][0];
        for (int j = 1; j < ZLOTraversal[i].size(); j++) {
            cout << "," << ZLOTraversal[i][j];
        }
        cout << "]" << endl;
    }
    cout << "]" << endl; 
}
