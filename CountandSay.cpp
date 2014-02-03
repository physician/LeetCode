/*
 Author:     physician
 Date:       Feb 02, 2014
 Update:     Feb 02, 2014
 Problem:    Count and Say
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/count-and-say/

 Problem Description:
 Count and Say: 

 The count-and-say sequence is the sequence of integers beginning as follows:
 1, 11, 21, 1211, 111221, ...

 1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 Given an integer n, generate the nth sequence.

 Note: The sequence of integers will be represented as a string.

 Notes:
 1. First implementation, natural solution.
 2. Use stringstream to convert int to string.
 3. Compile using g++: g++ CountandSay.cpp -o CountandSay
*/

# include <iostream>
# include <string>
# include <sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for(int i = 2; i <= n; ++i) {
            int j = 0;
            int count = 1;
            stringstream ss;
            while(j < result.size()) {
                if (j+1 < result.size() && result[j] == result[j+1])
                    count++;
                else {
                    ss << count << result[j];
                    count = 1;
                }
                j++;
            }
            //result = ss.str();
            ss >> result;
        }
        return result;
    }


    string countAndSay1(int n) {
        string result = "1";
        for(int i = 2; i <= n; ++i) {
            int j = 0;
            int count = 1;
            ostringstream ss;
            while(j < result.size()) {
                if (j+1 < result.size() && result[j] == result[j+1])
                    count++;
                else {
                    ss << count << result[j];
                    count = 1;
                }
                j++;
            }
            result = ss.str();
        }
        return result;
    }
};


int main() {
    Solution sol;
    int n = 4;
    cout << "The " << n << "th sequence is: " << sol.countAndSay(n) << endl;
}
