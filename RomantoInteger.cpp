/*
 Author:     physician
 Date:       Jan 27, 2014
 Update:     Jan 27, 2014
 Problem:    Roman to Integer
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/roman-to-integer/

 Problem Description:
 Roman to Integer:

 Given a roman numeral, convert it to an integer.

 Input is guaranteed to be within the range from 1 to 3999.

 Notes:
 1. First implementation, unordered_map.
 2. Compile using g++: g++ -std=c++0x RomantoInteger.cpp -o RomantoInteger.
*/


# include <iostream>
# include <string>
# include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0, N = s.size();
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        for(int i = 0; i < N; ++i) {
            if(i < s.size()-1 && roman[s[i]] < roman[s[i+1]])
                result -= roman[s[i]];
            else
                result += roman[s[i]];
        }
        return result;        
    }
};

int main() {
    string romanNum = "MMXVII";
    Solution sol;
    cout << "The integer for " << romanNum << " is: " << sol.romanToInt(romanNum) << endl;
}
