/*
 Author:     physician
 Date:       Jan 12, 2014
 Update:     Jan 29, 2014
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
 2. Second implementation, bitwise operation.
 3. Compile using g++: g++ SingleNumber.cpp -o SingleNumber.
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

    int singleNumber1(int A[], int n) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            int bit = 1 << i;
            for (int j = 0; j < n; ++j)
                if(A[j] & bit)
                    sum++;
            if (sum % 2)
                result |= bit;
        }
        return result;
    }
};

int main() {
    Solution sol;
    int A[9] = {1,2,1,2,3,3,4,5,5};
    cout << "The single number is: " << sol.singleNumber1(A, 9) << endl;
}
