/*
 Author:     physician
 Date:       Feb 17, 2014
 Update:     Feb 17, 2014
 Problem:    Palindrome Number
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/palindrome-number/

 Problem Description:
 Palindrome Number:

 Determine whether an integer is a palindrome. Do this without extra space.

 Some hints:
 Could negative integers be palindromes? (ie, -1) (No for LeetCode OJ.)

 If you are thinking of converting the integer to string, note the restriction of using extra space.

 You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

 There is a more generic way of solving this problem.

 Notes:
 1. First implementation, natural solution.
 2. For analysis, refer: http://leetcode.com/2012/01/palindrome-number.html. 
 3. Compile using g++: g++ PalindromeNumber.cpp -o PalindromeNumber.
*/


# include <iostream>
# include <cassert>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        return isPalindrome2(x);
    }

private:
    bool isPalindrome1(int x) {
        if (x < 0) return false;
        return (x == reverse(x));
    }

    int reverse(int num) {
        assert(num >= 0);
        long long rev = 0;
        while (num) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }

    bool isPalindrome2(int x) {
        if (x < 0) return false;
        int div = 1;
        while (x/div >= 10)
            div *= 10;
        while (x != 0) {
            if (x / div != x % 10)
                return false;
            x = (x % div) / 10;
            div /= 100;
        }
        return true;
    }
};


int main() {
    int x = 12321;
    Solution sol;
    if (sol.isPalindrome(x))
        cout << x << " is palindrome." << endl;
    else
        cout << x << " is not palindrome." << endl;
}
