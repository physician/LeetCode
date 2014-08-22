/*
 Author:     physician
 Date:       Aug 21, 2014
 Update:     Aug 21, 2014
 Problem:    Permutation Sequence
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/permutation-sequence/

 Problem Description:
 Permutation Sequence: 

 The set [1,2,3,…,n] contains a total of n! unique permutations.

 By listing and labeling all of the permutations in order,
 We get the following sequence (ie, for n = 3):

 "123"
 "132"
 "213"
 "231"
 "312"
 "321"
 Given n and k, return the kth permutation sequence.

 Note: Given n will be between 1 and 9 inclusive.

 Notes:
 1. First implementation, math.
 2. Be smart and efficient when calculating n!.
 3. Compile using g++: g++ PermutationSequence.cpp -o PermutationSequence.
*/

# include <iostream>
# include <vector>
# include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string result, digit;
        int factorial = 1;
        for (int i = 1; i <= n; ++i) {
            digit.push_back(char('0'+i));
            factorial *= i;
        }
        k--;
        while (n) {
            factorial /= n;
            n--;
            int index = k/factorial;
            result += digit[index];
            digit.erase(index, 1);
            k -= index * factorial; // or k %= factorial;
        }
        return result;      
    }
};

int main() {
    int n = 3;
    int k = 2;
    Solution sol;
    string result = sol.getPermutation(n, k);
    cout << "The permutation sequence for (n,k) = (" << n << "," << k << ") is " << result << endl;
}
