/*
 Author:     physician
 Date:       Sep 05, 2013
 Update:     Sep 05, 2013
 Problem:    Construct Binary Tree from Inorder and Postorder Traversal
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_106

 Problem Description:
 Construct Binary Tree from Inorder and Postorder Traversal: 

 Given inorder and postorder traversal of a tree, construct the binary tree.

 Note:
 You may assume that duplicates do not exist in the tree.

 Notes:
 1. First implementation, recursion.
 2. Compile using g++: g++ ConstructBinaryTreefromInorderandPostorderTraversal.cpp -o ConstructBinaryTreefromInorderandPostorderTraversal.
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() != postorder.size() || inorder.size() == 0)
            return NULL;
        else
            return buildTreeRe(inorder.begin(), postorder.begin(), inorder.size());
    }

private:
    TreeNode *buildTreeRe(vector<int>::iterator in, vector<int>::iterator post, int N) {
        if (N <= 0)
            return NULL;
        TreeNode *root = new TreeNode(*(post+N-1));
        vector<int>::iterator iter_in = find(in, in+N, root->val);
        int newN = iter_in - in;
        root->left = buildTreeRe(in, post, newN);
        root->right = buildTreeRe(in+newN+1, post+newN, N-newN-1);
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


void printTreePostOrder(TreeNode *head) {
    if (head == NULL)
        return;
    else {
        printTreePostOrder(head->left);
        printTreePostOrder(head->right);
        cout << head->val << " ";
    }
}


int main() {
    int in[] = {1, 2, 3, 4, 5, 6, 7};
    int post[] = {2, 4, 3, 1, 7, 6, 5};
    vector<int> inorder(in, in + sizeof(in)/sizeof(int));
    vector<int> postorder(post, post + sizeof(post)/sizeof(int));
    Solution sol;
    TreeNode *head = sol.buildTree(inorder, postorder);
    cout << "In order traversal:" << endl;
    printTreeInOrder(head);
    cout << endl;
    cout << "Post order traversal:" << endl;
    printTreePostOrder(head);
    cout << endl;
}
