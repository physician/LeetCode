/*
 Author:     physician
 Date:       Aug 20, 2014
 Update:     Aug 20, 2014
 Problem:    Minimum Window Substring
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/minimum-window-substring/

 Problem Description:
 Minimum Window Substring:

 Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

 For example,
 S = "ADOBECODEBANC"
 T = "ABC"
 Minimum window is "BANC".

 Note:
 If there is no such window in S that covers all characters in T, return the emtpy string "".

 If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

 Notes:
 1. First implementation, use two pointers. Time complexity O(N). Space complexity O(N).
 2. Algorithm analysis: http://leetcode.com/2010/11/finding-minimum-window-in-s-which.html
 3. Use hashtable to keep track the chars need to be found and chars already found.
 4. Here used unordered_map as hashtable, could use array (ASCII of char as key).
 5. Compile using g++: g++ -std=c++0x MinimumWindowSubstring.cpp -o MinimumWindowSubstring.
*/


# include <iostream>
# include <string>
# include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        unordered_map<char, int> needToFind;
        unordered_map<char, int> hasFound;
        for(int i = 0; i < T.size(); ++i) {
            if (needToFind.find(T[i]) != needToFind.end())
                needToFind[T[i]]++;
            else
                needToFind[T[i]] = 1;   
        }
        int res_begin = -1, res_end = S.size();
        int begin = 0, end = 0;
        int count = 0;
        while (end < S.size()) {
            if (needToFind.find(S[end]) == needToFind.end()) {
                end++;
                continue;
            }
            if (hasFound[S[end]] < needToFind[S[end]])
                count++;
            hasFound[S[end]]++;
            if (count == T.size()) {
                while (begin < end) {
                    if (needToFind.find(S[begin]) == needToFind.end())
                        begin++;
                    else if (hasFound[S[begin]] > needToFind[S[begin]])
                        hasFound[S[begin++]]--;
                    else
                        break;
                }
                if (end-begin < res_end-res_begin) {
                    res_begin = begin;
                    res_end = end;
                }
            }
            end++;
        }
        return res_begin == -1 ? "" : S.substr(res_begin, res_end-res_begin+1);
    }
};

int main() {
    Solution sol;
    string S = "ADOBECODEBANC";
    string T = "ABC";
    string minWindowSub = sol.minWindow(S, T);
    cout << "Minimum window for " << S << " is: " << minWindowSub << endl;
}
