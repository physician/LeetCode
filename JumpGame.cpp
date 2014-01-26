/*
 Author:     physician
 Date:       Aug 30, 2013
 Update:     Jan 26, 2014
 Problem:    Jump Game
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/jump-game/

 Problem Description:
 Jump Game: 

 Given an array of non-negative integers, you are initially positioned at the first index of the array.

 Each element in the array represents your maximum jump length at that position.

 Determine if you are able to reach the last index.

 For example:
 A = [2,3,1,1,4], return true.

 A = [3,2,1,0,4], return false.

 Notes:
 1. First implementation, use two pointers.
 2. Compile using g++: g++ JumpGame.cpp -o JumpGame.
*/

# include <iostream>
# include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        int begin = 0, end = 0;
        while(begin <= end && end < n-1) {
            end = max(end, begin + A[begin]);
            begin++;
        }
        return end >= n-1;
    }
};


int main() {
    int A[5] = {2, 3, 1, 1, 4};
    //int A[5] = {3, 2, 1, 0, 4};
    //int A[] = {};
    cout << "The array is:" << endl;
    for (int i = 0; i < sizeof(A)/sizeof(int); i++)
        cout << A[i] << " ";
    cout << endl;
    Solution sol;
    bool can = sol.canJump(A, sizeof(A)/sizeof(int));
    if (can)
        cout << "Can jump to the last index." << endl;
    else
        cout << "Can NOT jump to the last index." << endl;
}
