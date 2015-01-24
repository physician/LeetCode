/*
 Author:     physician
 Date:       Jan 24, 2015
 Update:     Jan 24, 2015
 Problem:    Compare Version Numbers
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/compare-version-numbers/

 Problem Description:
 Compare Version Numbers:

 Compare two version numbers version1 and version1.
 If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

 You may assume that the version strings are non-empty and contain only digits and the . character.
 The . character does not represent a decimal point and is used to separate number sequences.
 For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

 Here is an example of version numbers ordering:

 0.1 < 1.1 < 1.2 < 13.37

 Notes:
 1. First implementation, recursion.
 2. Compile using g++: g++ -std=c++0x CompareVersionNumbers.cpp -o CompareVersionNumbers.
*/


# include <iostream>
# include <string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int pos1 = version1.find('.');
        if (pos1 == string::npos) pos1 = version1.size();
        int pos2 = version2.find('.');
        if (pos2 == string::npos) pos2 = version2.size();
        int version1_first = stoi(version1.substr(0, pos1));
        int version2_first = stoi(version2.substr(0, pos2));
        if (version1_first < version2_first)
            return -1;
        else if (version1_first > version2_first)
            return 1;
        else {
            if (pos1 == version1.size() && pos2 == version2.size())
                return 0;
            else if (pos2 == version2.size())
                return compareVersion(version1.substr(pos1+1, version1.size()-pos1-1), "0");
            else if (pos1 == version1.size())
                return compareVersion("0", version2.substr(pos2+1, version2.size()-pos2-1));
            else
                return compareVersion(version1.substr(pos1+1, version1.size()-pos1-1), version2.substr(pos2+1, version2.size()-pos2-1));
        }
    }
};

int main() {
    string version1 = "1.1";
    string version2 = "1.2";
    Solution sol;
    int n = sol.compareVersion(version1, version2);
    if (n == -1)
        cout << version1 << " < " << version2 << endl;
    if (n == 1)
        cout << version1 << " > " << version2 << endl;
    if (n == 0)
        cout << version1 << " = " << version2 << endl;
}
