/*
 Author:     physician
 Date:       Jan 18, 2015
 Update:     Jan 18, 2015
 Problem:    Excel Sheet Column Number
 Difficulty: Easy 
 Source:     https://oj.leetcode.com/problems/excel-sheet-column-number/

 Problem Description:
 Excel Sheet Column Number: 

 Related to question Excel Sheet Column Title

 Given a column title as appear in an Excel sheet, return its corresponding column number.

 For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 

 Notes:
 1. First implementation, math.
 2. Compile using g++: g++ ExcelSheetColumnNumber.cpp -o ExcelSheetColumnNumber.
*/

# include <iostream>
# include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int colNum = 0;
        for(int i = 0; i <= s.size()-1; ++i)
            colNum = 26 * colNum + (s[i] - 'A') + 1;
        return colNum;
    }
};


int main() {
    string s = "AA";
    Solution sol;
    cout << "The column number for " << s << " is: " << sol.titleToNumber(s) << endl;
}
