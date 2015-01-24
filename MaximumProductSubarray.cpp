/*
 Author:     physician
 Date:       Jan 24, 2015
 Update:     Jan 24, 2015
 Problem:    Maximum Product Subarray
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/maximum-product-subarray/

 Problem Description:
 Maximum Product Subarray:

 Find the contiguous subarray within an array (containing at least one number) which has the largest product.

 For example, given the array [2,3,-2,4],
 the contiguous subarray [2,3] has the largest product = 6.

 Notes:
 1. First implementation, DP.
 2. Compile using g++: g++ MaximumProductSubarray.cpp -o MaximumProductSubarray.
*/


# include <iostream>

using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
        int maxProd = A[0], maxEndHere = A[0], minEndHere = A[0];
        for (int i = 1; i < n; ++i) {
            int maxEndHereOld = maxEndHere;
            maxEndHere = max(minEndHere * A[i], max(maxEndHere * A[i], A[i]));
            minEndHere = min(minEndHere * A[i], min(maxEndHereOld * A[i], A[i]));
            maxProd = max(maxProd, maxEndHere);
        }
        return maxProd;
    }
};

int main() {
    int A[10] = {2,3,-2,2,-1,0,1,+4,-2,-2};
    Solution sol;
    cout << "The contiguous subarray of A has the largest product: " << sol.maxProduct(A, 10) << endl;
}
