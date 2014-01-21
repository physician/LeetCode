/*
 Author:     physician
 Date:       Jan 20, 2014
 Update:     Jan 20, 2014
 Problem:    Unique Binary Search Trees
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/unique-binary-search-trees/

 Problem Description:
 Unique Binary Search Trees:

 Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

 For example,
 Given n = 3, there are a total of 5 unique BST's.

    1         3     3      2      1
     \       /     /      / \      \
      3     2     1      1   3      2
     /     /       \                 \
    2     1         2                 3

 Notes:
 1. First implementation, DP.
 2. Compile using g++: g++ UniqueBinarySearchTrees.cpp -o UniqueBinarySearchTrees.
*/


# include <iostream>
# include <cstring>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n <= 0)
            return 0;
        int num[n+1];
        memset(num, 0, sizeof(num));
        num[0] = 1;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= i; ++j)
                num[i] += num[j-1] * num[i-j];
        return num[n];
    }
};

int main() {
    int n = 3;
    Solution sol;
    cout << "For given n = " << n << ", there are a total of " << sol.numTrees(n) << " unique BST's." << endl;
}
