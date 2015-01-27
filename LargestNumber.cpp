/*
 Author:     physician
 Date:       Jan 26, 2015
 Update:     Jan 26, 2015
 Problem:    Largest Number
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/largest-number/

 Problem Description:
 Largest Number:

 Given a list of non negative integers, arrange them such that they form the largest number.

 For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

 Note: The result may be very large, so you need to return a string instead of an integer.

 Notes:
 1. First implementation, sort. Use comparator.
 2. Compile using g++: g++ -std=c++0x LargestNumber.cpp -o LargestNumber.
*/


# include <iostream>
# include <vector>
# include <string>
# include <algorithm>

using namespace std;

/*
bool cmp(const string &a, const string &b) {
    return a+b > b+a;
}
*/

class Solution {
public:
    string largestNumber(vector<int> &num) {
        string result;
        vector<string> numstr;
        for (auto n : num)
            numstr.push_back(to_string(n));
        sort(numstr.begin(), numstr.end(), cmp);
        for (auto n : numstr)
            result += n;
        return result[0] == '0' ? "0" : result;
    }

private:
    static bool cmp(const string &a, const string &b) {
        return a+b > b+a;
    }
};

int main() {
    vector<int> num {3,30,34,5,9};
    //vector<int> num {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Solution sol;
    cout << "The list of numbers are:" << endl;
    for (int i = 0; i < num.size(); ++i)
        cout << num[i] << " ";
    cout << endl;
    cout << "The largest formed number is: " << sol.largestNumber(num) << endl;
}
