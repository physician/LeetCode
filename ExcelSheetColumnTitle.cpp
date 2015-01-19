/*
 Author:     physician
 Date:       Jan 18, 2015
 Update:     Jan 18, 2015
 Problem:    Excel Sheet Column Title
 Difficulty: Easy 
 Source:     https://oj.leetcode.com/problems/excel-sheet-column-title/

 Problem Description:
 Excel Sheet Column Title: 

 Given a positive integer, return its corresponding column title as appear in an Excel sheet.

 For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB

 Notes:
 1. First implementation, math.
 2. Compile using g++: g++ ExcelSheetColumnTitle.cpp -o ExcelSheetColumnTitle.
*/

# include <iostream>
# include <string>
# include <algorithm>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string colTitle;
        while (n != 0) {
            colTitle += char((n-1) % 26 + 'A');
            n = (n-1) / 26;
        }
        reverse(colTitle.begin(), colTitle.end());
        return colTitle;
    }
};


int main() {
    int n = 27;
    Solution sol;
    cout << "The column title for " << n << " is: " << sol.convertToTitle(n) << endl;
}
