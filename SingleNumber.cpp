/*
 Author:     physician
 Date:       Jan 12, 2014
 Update:     Jan 12, 2014
 Problem:    Single Number
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/single-number/

 Problem Description:
 Single Number:

 Given an array of integers, every element appears twice except for one. Find that single one.

 Note:
 Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

 Notes:
 1. First implementation, XOR.
 2. Compile using g++: g++ SingleNumber.cpp -o SingleNumber.
*/


# include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        for (int i = 1; i < n; ++i) 
            A[0] ^= A[i]; 
        return A[0];
    }
};

int main() {
    Solution sol;
    int A[9] = {1,2,1,2,3,3,4,5,5};
    cout << "The single number is: " << sol.singleNumber(A, 9) << endl;
}
