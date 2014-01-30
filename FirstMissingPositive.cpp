/*
 Author:     physician
 Date:       Jan 29, 2014
 Update:     Jan 30, 2014
 Problem:    First Missing Positive
 Difficulty: Medium
 Source:     http://oj.leetcode.com/problems/first-missing-positive/

 Problem Description:
 First Missing Positive:

 Given an unsorted integer array, find the first missing positive integer.

 For example,
 Given [1,2,0] return 3,
 and [3,4,-1,1] return 2.

 Your algorithm should run in O(n) time and uses constant space.

 Notes:
 1. First implementation, use array index. Swap array elements to satisfy A[i] == i+1.
 2. Compile using g++: g++ FirstMissingPositive.cpp -o FirstMissingPositive.
*/


# include <iostream>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i = 0;
        while(i < n) {
            if (A[i] >= 1 && A[i] <= n && A[i] != i+1 && A[i] != A[A[i]-1])
                swap(A[i], A[A[i]-1]);
            else
                i++;
        }
        i = 0;
        while(A[i] == i+1)
            i++;
        return i+1;
    }
};



int main() {
    Solution sol;
    //int A[] = {1,2,0};
    //int A[] = {3,4,-1,1};
    int A[] = {-1,3,7,2,1,-5,5,10,4};
    cout << "The first missing positive integer is: " << sol.firstMissingPositive(A, sizeof(A)/sizeof(int)) << endl;
}
