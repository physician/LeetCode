/*
 Author:     physician
 Date:       Jan 30, 2014
 Update:     Jan 30, 2014
 Problem:    ZigZag Conversion
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/zigzag-conversion/

 Problem Description:
 ZigZag Conversion:

 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"
 Write the code that will take a string and make this conversion given a number of rows:

 string convert(string text, int nRows);
 convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

 Notes:
 1. First implementation, use string index. 
 2. Compile using g++: g++ ZigZagConversion.cpp -o ZigZagConversion.
*/


# include <iostream>
# include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1)
            return s;
        int N = s.size();
        string result;
        for (int i = 0; i < nRows && i < N; ++i) {
            int j = 0;
            while (i+j < N) {
                result.push_back(s[i+j]);
                if (i != 0 && i != nRows-1 && i+j+2*(nRows-1-i) < N)
                    result.push_back(s[i+j+2*(nRows-1-i)]);
                j += 2*(nRows-1);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    int nRows = 3;
    string text = "PAYPALISHIRING";
    //string text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //string text = "ABCD";
    //string text = "A";
    //string text = "";
    cout << "Before conversion: " << text << endl;
    cout << "Text size before conversion: " << text.size() << endl;
    cout << "After conversion with nRows = " << nRows << ": " << sol.convert(text, nRows) << endl;
    cout << "Text size after conversion: " << sol.convert(text, nRows).size() << endl;
}
