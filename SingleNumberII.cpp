/*
 Author:     physician
 Date:       Jan 29, 2014
 Update:     Jan 29, 2014
 Problem:    Single Number II
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/single-number-ii/

 Problem Description:
 Single Number II:

 Given an array of integers, every element appears three times except for one. Find that single one.

 Note:
 Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

 Notes:
 1. First implementation, bitwise operation.
 2. Compile using g++: g++ SingleNumberII.cpp -o SingleNumberII.
*/


# include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            int bit = 1 << i;
            for (int j = 0; j < n; ++j)
                if(A[j] & bit)
                    sum++;
            if (sum % 3)
                result |= bit; 
        }
        return result;
    }
};

int main() {
    Solution sol;
    int A[] = {1,2,1,2,3,3,5,4,5,5,1,2,3};
    cout << "The single number is: " << sol.singleNumber(A, sizeof(A)/sizeof(int)) << endl;
}
