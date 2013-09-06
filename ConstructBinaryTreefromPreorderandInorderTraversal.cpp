/*
 Author:     physician
 Date:       Sep 06, 2013
 Update:     Sep 06, 2013
 Problem:    Construct Binary Tree from Preorder and Inorder Traversal
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_105

 Problem Description:
 Construct Binary Tree from Preorder and Inorder Traversal: 

 Given preorder and inorder traversal of a tree, construct the binary tree.

 Note:
 You may assume that duplicates do not exist in the tree.

 Notes:
 1. First implementation, recursion.
 2. Compile using g++: g++ ConstructBinaryTreefromPreorderandInorderTraversal.cpp -o ConstructBinaryTreefromPreorderandInorderTraversal.
*/

# include <iostream>
# include <vector>
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (inorder.size() != preorder.size() || inorder.size() == 0)
            return NULL;
        else
            return buildTreeRe(preorder.begin(), inorder.begin(), inorder.size());
    }

private:
    TreeNode *buildTreeRe(vector<int>::iterator pre, vector<int>::iterator in, int N) {
        if (N <= 0)
            return NULL;
        TreeNode *root = new TreeNode(*pre);
        vector<int>::iterator iter_in = find(in, in+N, root->val);
        int newN = iter_in - in;
        root->left = buildTreeRe(pre+1, in, newN);
        root->right = buildTreeRe(pre+newN+1, in+newN+1, N-newN-1);
        return root;
    }
};


void printTreeInOrder(TreeNode *head) {
    if (head == NULL)
        return;
    else {
        printTreeInOrder(head->left);
        cout << head->val << " ";
        printTreeInOrder(head->right);
    }
}


void printTreePreOrder(TreeNode *head) {
    if (head == NULL)
        return;
    else {
        cout << head->val << " ";
        printTreePreOrder(head->left);
        printTreePreOrder(head->right);
    }
}


int main() {
    int in[] = {1, 2, 3, 4, 5, 6, 7};
    int pre[] = {5, 1, 3, 2, 4, 6, 7};
    vector<int> inorder(in, in + sizeof(in)/sizeof(int));
    vector<int> preorder(pre, pre + sizeof(pre)/sizeof(int));
    Solution sol;
    TreeNode *head = sol.buildTree(preorder, inorder);
    cout << "In order traversal:" << endl;
    printTreeInOrder(head);
    cout << endl;
    cout << "Pre order traversal:" << endl;
    printTreePreOrder(head);
    cout << endl;
}
