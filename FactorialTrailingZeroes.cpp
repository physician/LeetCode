/*
 Author:     physician
 Date:       Jan 09, 2015
 Update:     Jan 09, 2015
 Problem:    Factorial Trailing Zeroes
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/factorial-trailing-zeroes/

 Problem Description:
 Factorial Trailing Zeroes:

 Given an integer n, return the number of trailing zeroes in n!.

 Note: Your solution should be in logarithmic time complexity.

 Notes:
 1. First implementation, math. Time complexity O(log(n)).
 2. Compile using g++: g++ FactorialTrailingZeroes.cpp -o FactorialTrailingZeroes.
*/

# include <iostream>
# include <cmath>       // pow(x,n), log()

using namespace std;

// It could be further simplified by calculating the sum explicitly.
class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        if (n > 0) {
            int N = int(log(n)/log(5));
            for(int i = 1; i <= N; ++i)
                result += n/pow(5, i);
        }
        return result;
    }
};


int main() {
    int n = 3125;
    Solution sol;
    cout << "The number of trailing zeros of " << n << "! is: " << sol.trailingZeroes(n) << endl;
}
