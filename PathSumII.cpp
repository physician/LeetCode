/*
 Author:     physician
 Date:       Sep 08, 2013
 Update:     Sep 08, 2013
 Problem:    Path Sum II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_113

 Problem Description:
 Path Sum II: 

 Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 For example:
 Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

 return
 
 [
    [5,4,11,2],
    [5,8,4,5]
 ]


 Notes:
 1. First implementation, recursion, pass by reference.
 2. Second implementation, recursion, pass by value.
 3. Compile using g++: g++ PathSumII.cpp -o PathSumII.
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> path;
        pathSumRe(root, sum, result, path); 
        return result;
    }

    vector<vector<int> > pathSum2(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> path;
        pathSumRe2(root, sum, result, path);
        return result;
    }

private:
    void pathSumRe(TreeNode *root, int sum, vector<vector<int> > &result, vector<int> &path) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum) {
                path.push_back(root->val);
                result.push_back(path);
                path.pop_back();
            }
            return;
        }
        else {
            path.push_back(root->val);
            pathSumRe(root->left, sum-(root->val), result, path);
            pathSumRe(root->right, sum-(root->val), result, path);
            path.pop_back();
        }
    }

    void pathSumRe2(TreeNode *root, int sum, vector<vector<int> > &result, vector<int> path) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum) {
                path.push_back(root->val);
                result.push_back(path);
            }
            return;
        }
        else {
            path.push_back(root->val);
            pathSumRe2(root->left, sum-(root->val), result, path);
            pathSumRe2(root->right, sum-(root->val), result, path);
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
    TreeNode node8(5);
    TreeNode node9(1);
    node0.left = &node1;
    node0.right = &node2;
    node1.left = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    node5.left = &node8;
    node5.right = &node9;
    Solution sol;
    vector<vector<int> > result = sol.pathSum(&node0, 22);
    if (result.size() == 0)
        cout << "There's no root-to-leaf path gives the given path sum." << endl;
    else {
        cout << "[" << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << "  [ ";
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "]" << endl;
        }
        cout << "]" << endl;
    }
}
