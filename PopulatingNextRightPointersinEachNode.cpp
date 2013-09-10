/*
 Author:     physician
 Date:       Sep 09, 2013
 Update:     Sep 09, 2013
 Problem:    Populating Next Right Pointers in Each Node
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_116

 Problem Description:
 Populating Next Right Pointers in Each Node: 

 Given a binary tree

     struct TreeLinkNode {
       TreeLinkNode *left;
       TreeLinkNode *right;
       TreeLinkNode *next;
     }

 Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

 Initially, all next pointers are set to NULL.
 
 Note:
 
 You may only use constant extra space.
 You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 For example,
 Given the following perfect binary tree,
 
          1
        /  \
       2    3
      / \  / \
     4  5  6  7
 After calling your function, the tree should look like:

          1 -> NULL
        /  \
       2 -> 3 -> NULL
      / \  / \
     4->5->6->7 -> NULL
 
 Notes:
 1. First implementation, iterative, queue. Use extra space. 
 2. Use one queue, and two counting variables to keep track of number of nodes in the current level and next level.
 3. Compile using g++: g++ PopulatingNextRightPointersinEachNode.cpp -o PopulatingNextRightPointersinEachNode.
*/

# include <iostream>
# include <queue>

using namespace std;


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */


struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        queue<TreeLinkNode *> q;
        int currentLevel = 0;
        int nextLevel = 0;
        q.push(root);
        currentLevel++;
        while(!q.empty()) {
            TreeLinkNode *ptr = q.front();
            q.pop();
            currentLevel--;
            if (ptr->left != NULL) {
                q.push(ptr->left);
                nextLevel++;
            }
            if (ptr->right != NULL) {
                q.push(ptr->right);
                nextLevel++;
            }
            if (currentLevel == 0) {
                ptr->next = NULL;
                currentLevel = nextLevel;
                nextLevel = 0;
            }
            else
                ptr->next = q.front();
        }
    }
};


int main() {
    TreeLinkNode node0(1);
    TreeLinkNode node1(2);
    TreeLinkNode node2(3);
    TreeLinkNode node3(4);
    TreeLinkNode node4(5);
    TreeLinkNode node5(6);
    TreeLinkNode node6(7);
    node0.left = &node1;
    node0.right = &node2;
    node1.left = &node3;
    node1.right = &node4;
    node2.left = &node5;
    node2.right = &node6;
    Solution sol;
    sol.connect(&node0);
    cout << "Level order traversal:" << endl;
    TreeLinkNode *ptr = &node0;
    while (ptr != NULL) {
        TreeLinkNode *ptr2 = ptr;
        while (ptr2 != NULL) {
            cout << ptr2->val << " ";
            ptr2 = ptr2->next;
        }
        ptr = ptr->left;
    }
    cout << endl;
}
