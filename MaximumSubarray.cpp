/*
 Author:     physician
 Date:       Jan 20, 2014
 Update:     Jan 20, 2014
 Problem:    Maximum Subarray
 Difficulty: Medium
 Source:     http://oj.leetcode.com/problems/maximum-subarray/

 Problem Description:
 Maximum Subarray:

 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

 For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 the contiguous subarray [4,−1,2,1] has the largest sum = 6.


 More practice:
 If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

 Notes:
 1. First implementation, DP.
 2. Compile using g++: g++ MaximumSubarray.cpp -o MaximumSubarray.
*/


# include <iostream>
# include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int maxSoFar = A[0];
        int maxEndHere = A[0];
        for(int i = 1; i < n; ++i) {
            maxEndHere = max(maxEndHere + A[i], A[i]);
            maxSoFar = max(maxSoFar, maxEndHere);
        }
        return maxSoFar;
    }

    int maxSubArray1(int A[], int n) {
        int maxSoFar = A[0];
        int maxEndHere = A[0];
        int maxBeginTemp = 0;
        int maxBegin = 0;
        int maxEnd = 0;
        for(int i = 1; i < n; ++i) {
            if(maxEndHere + A[i] < A[i]){
                maxEndHere = A[i];
                maxBeginTemp = i;
            }
            else {
                maxEndHere += A[i];
            }
            if(maxEndHere > maxSoFar) {
                maxSoFar = maxEndHere;
                maxBegin = maxBeginTemp;
                maxEnd = i;
            }
        }
        cout << "Maximum contiguous subarray is:" << endl;
        for(int i = maxBegin; i <= maxEnd; ++i)
            cout << A[i] << " ";
        cout << endl;
        return maxSoFar;
    }
};

int main() {
    int A[9] = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    cout << "The largest sum of contiguous subarray of A is: " << sol.maxSubArray1(A, 9) << endl;
}
