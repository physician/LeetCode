/*
 Author:     physician
 Date:       Feb 09, 2014
 Update:     Feb 09, 2014
 Problem:    Trapping Rain Water
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/trapping-rain-water/

 Problem Description:
 Trapping Rain Water:

 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

 For example, 
 Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

 Notes:
 1. First implementation, math. Use symmetry. Time O(n), space O(n). 
 2. Compile using g++: g++ TrappingRainWater.cpp -o TrappingRainWater.
*/


# include <iostream>

using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        int lb[n], rb[n];
        lb[0] = 0, rb[n-1] = 0;
        for(int i = 1; i < n; ++i)
            lb[i] = max(lb[i-1], A[i-1]);
        for(int i = n-2; i >= 0; --i)
            rb[i] = max(rb[i+1], A[i+1]);
        int rainMax = 0;
        for(int i = 0; i < n; ++i)
            rainMax += max(0, min(lb[i], rb[i]) - A[i]);
        return rainMax;
    }
};

int main() {
    int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution sol;
    cout << "The amount of water it is able to trap is: " << sol.trap(A, sizeof(A)/sizeof(int)) << endl;
}
