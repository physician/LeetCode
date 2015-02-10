/*
 Author:     physician
 Date:       Feb 10, 2015
 Update:     Feb 10, 2015
 Problem:    String to Integer (atoi)
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/string-to-integer-atoi/

 Problem Description:
 String to Integer (atoi):

 Implement atoi to convert a string to an integer.

 Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

 Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

 Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

 The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

 If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

 If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

 Notes:
 1. First implementation, math.
 2. Compile using g++: g++ -std=c++0x StringtoInteger_atoi.cpp -o StringtoInteger_atoi.
*/


# include <iostream>
# include <climits>
# include <string>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        if (str == NULL)
            return 0;
        while (*str == ' ')
            str++;
        bool positive = true;
        if (*str == '+' || *str == '-')
            positive = *str++ == '+';
        long result = 0;
        while (isdigit(*str)) {
            result = result * 10 + (*str++ - '0');
            if (positive && result > INT_MAX)
                return INT_MAX;
            if (!positive && -result < INT_MIN)
                return INT_MIN;
        }
        return positive ? result : -result;
    }
};

int main() {
    const char *str = "  -123  ";
    //const char *str = "9223372036854775809";
    Solution sol;
    cout << "The integer for " << str << " is: " << sol.atoi(str) << endl;
}
