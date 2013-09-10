/*
 Author:     physician
 Date:       Sep 10, 2013
 Update:     Sep 10, 2013
 Problem:    Flatten Binary Tree to Linked List
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_114

 Problem Description:
 Flatten Binary Tree to Linked List: 

 Given a binary tree, flatten it to a linked list in-place.

 For example,
 Given

         1
        / \
       2   5
      / \   \
     3   4   6

 The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

 Hints:

 If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

 Notes:
 1. First implementation, iterative, stack.
 2. Pre-order traversal/DFS of binary tree using stack, push right child first onto stack, then left child.
 3. In C++ STL stack, access empty stack.top() will cause segmentation fault. It won't automatically return NULL.
 4. Compile using g++: g++ FlattenBinaryTreetoLinkedList.cpp -o FlattenBinaryTreetoLinkedList.
*/

# include <iostream>
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
    void flatten(TreeNode *root) {
        if (root == NULL)
            return;
        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *ptr = stk.top();
            stk.pop();
            if (ptr->right != NULL)
                stk.push(ptr->right);
            if (ptr->left != NULL)
                stk.push(ptr->left);
            ptr->left = NULL;
            if (!stk.empty())
                ptr->right = stk.top();
            else
                ptr->right = NULL;
        }
    }
};

int main() {
    TreeNode node0(1);
    TreeNode node1(2);
    TreeNode node2(5);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(6);
    node0.left = &node1;
    node0.right = &node2;
    node1.left = &node3;
    node1.right = &node4;
    node2.right = &node5;
    Solution sol;
    sol.flatten(&node0);
    cout << "After flatten:" << endl;
    TreeNode *ptr = &node0;
    while (ptr != NULL) {
        cout << ptr->val << " ";
        ptr = ptr->right;
    }
    cout << endl;
}
