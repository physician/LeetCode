/*
 Author:     physician
 Date:       Jan 31, 2015
 Update:     Jan 31, 2015
 Problem:    Longest Palindromic Substring
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/longest-palindromic-substring/

 Problem Description:
 Longest Palindromic Substring:

 Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

 Notes:
 1. First implementation, DP.
 2. Manacher's Algorithm: http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
 3. Compile using g++: g++ -std=c++0x LongestPalindromicSubstring.cpp -o LongestPalindromicSubstring.
*/


# include <iostream>
# include <string>
# include <cstring> //memset
# include <utility>
# include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        return longestPalindrome3(s);
    }

    // two pointers, time O(N^2), space O(1)
    string longestPalindrome1(string s) {
        int N = s.size();
        if (N <= 1)
            return s;
        string pstr;
        for (int i = 0; i < N; ++i) {
            int j = 0, k = 0;
            if (i+1 < N) {
                while (j <= min(i, N-i-1) && s[i-j] == s[i+j])
                    j++;
                while (k <= min(i, N-i-2) && s[i-k] == s[i+1+k])
                    k++;
            }
            if (2*(j-1)+1 >= 2*(k-1)+2 && 2*(j-1)+1 > pstr.size())
                pstr = s.substr(i-j+1, 2*(j-1)+1);
            if (2*(j-1)+1 < 2*(k-1)+2 && 2*(k-1)+2 > pstr.size())
                pstr = s.substr(i-k+1, 2*(k-1)+2);
        }
        return pstr;
    }

    // DP, time O(N^2), space O(N^2)
    string longestPalindrome2(string s) {
        int N = s.size();
        bool dp[N][N];
        //memset(dp, false, N * N * sizeof(bool));
        pair<int, int> pindex = make_pair(0, 0);
        for (int j = 0; j < N; ++j)
            for (int i = 0; i <= j; ++i) {
                dp[i][j] = s[i] == s[j] && (j-i < 2 || dp[i+1][j-1]);
                if (dp[i][j] && j-i+1 > pindex.second-pindex.first+1)
                    pindex = make_pair(i, j);
            }
        return s.substr(pindex.first, pindex.second-pindex.first+1);
    }

    // DP, time O(N), space O(N), Manacher's algorithm
    string longestPalindrome3(string s) {
        // preprocess string s
        int N = s.size();
        string T = "^";
        for (int i = 0; i < N; ++i)
            T += "#" + s.substr(i, 1);
        T += N == 0 ? "$" : "#$";

        N = T.size();
        int P[N];
        int C = 0, R = 0;
        for (int i = 1; i < N-1; ++i) {
            int i_mirror = 2 * C - i;
            P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
            // Attempt to expand palindrome centered at i
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
                P[i]++;
            // If palindrome centered at i expand past R,
            // adjust center based on expanded palindrome.
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }
        // Find the maximum element in P
        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 1; i < N-1; ++i) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }
        return s.substr((centerIndex-1-maxLen)/2, maxLen);
    }
};

int main() {
    //string s = "";
    //string s = "a";
    //string s = "bb";
    //string s = "ccc";
    string s = "abccbad";
    Solution sol;
    cout << "The longest palindromic substring is: " << sol.longestPalindrome(s) << endl;
}
