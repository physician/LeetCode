/*
 Author:     physician
 Date:       Jan 26, 2014
 Update:     Jan 28, 2014
 Problem:    Jump Game II
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/jump-game-ii/

 Problem Description:
 Jump Game II: 

 Given an array of non-negative integers, you are initially positioned at the first index of the array.

 Each element in the array represents your maximum jump length at that position.

 Your goal is to reach the last index in the minimum number of jumps.

 For example:
 Given array A = [2,3,1,1,4]

 The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

 Notes:
 1. First implementation, use two pointers. Every step, jump to the largest (index + A[index]) within current reachable range.
 2. Compile using g++: g++ JumpGameII.cpp -o JumpGameII.
*/

# include <iostream>

using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        int steps = 0, begin = 0, end = 0;
        while(end < n-1) {
            int index = begin;
            for(int i = begin; i <= end; ++i)
                if (i + A[i] > index + A[index])
                    index = i;
            begin = index;
            if (end == index + A[index])
                return 0;
            end = index + A[index];
            steps++;
        }
        return steps;
    }
};


int main() {
    //int A[5] = {2, 3, 1, 1, 4};
    //int A[5] = {3, 2, 1, 0, 4};
    //int A[] = {};
    //int A[] = {0};
    int A[] = {5,9,3,2,1,0,2,3,3,1,0,0};
    cout << "The array is:" << endl;
    for (int i = 0; i < sizeof(A)/sizeof(int); i++)
        cout << A[i] << " ";
    cout << endl;
    Solution sol;
    int steps = sol.jump(A, sizeof(A)/sizeof(int));
    cout << "The minimum number of jumps to reach the last index is: " << steps << endl;
}
