/*
 Author:     physician
 Date:       Feb 07, 2014
 Update:     Feb 07, 2014
 Problem:    Reverse Integer
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/reverse-integer/

 Problem Description:
 Reverse Integer:

 Reverse digits of an integer.

 Example1: x = 123, return 321
 Example2: x = -123, return -321

 Have you thought about this?
 Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

 If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

 Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

 Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).

 Notes:
 1. First implementation, natural solution. Use / and % iteratively.
 2. Compile using g++: g++ ReverseInteger.cpp -o ReverseInteger.
*/


# include <iostream>
# include <climits>
# include <cassert>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long reverse = 0;
        while(x) {
            reverse = 10*reverse + x%10;
            x /= 10;
        }
        //if (reverse >= INT_MAX || reverse <= INT_MIN)
        //    return 0;
        assert(reverse >= INT_MIN && reverse <= INT_MAX);
        return reverse;
    }
};

int main() {
    int x = -123;
    //int x = 1000000003;
    Solution sol;
    cout << "The reverse integer of " << x << " is: " << sol.reverse(x) << endl;
}
