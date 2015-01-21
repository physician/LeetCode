/*
 Author:     physician
 Date:       Jan 21, 2015
 Update:     Jan 21, 2015
 Problem:    Decode Ways
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/decode-ways/

 Problem Description:
 Decode Ways:

 A message containing letters from A-Z is being encoded to numbers using the following mapping:

 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 Given an encoded message containing digits, determine the total number of ways to decode it.

 For example,
 Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

 The number of ways decoding "12" is 2.

 Notes:
 1. First implementation, DP.
 2. Compile using g++: g++ DecodeWays.cpp -o DecodeWays.
*/


# include <iostream>
# include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        return numDecodings2(s);
    }

    int numDecodings1(string s) {
        if (s.empty() || s[0] == '0')
            return 0;
        int N = s.size();
        int dp[N+1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < N; ++i) {
            if (s[i] == '0') {
                if (s[i-1] != '1' && s[i-1] != '2')
                    return 0;
                else
                    dp[i+1] = dp[i-1];
            }
            else {
                int num = 10*(s[i-1]-'0')+(s[i]-'0');
                if (num < 10 || num > 26) 
                    dp[i+1] = dp[i];
                else
                    dp[i+1] = dp[i] + dp[i-1];
            }
        }
        return dp[N];
    }

    int numDecodings2(string s) {
        if (s.empty() || s[0] == '0')
            return 0;
        int d0 = 1, d1 = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '0')
                d1 = 0;
            int num = 10*(s[i-1]-'0')+(s[i]-'0');
            int temp = d1;
            if (num >= 10 && num <= 26) 
                d1 += d0;
            d0 = temp;
        }
        return d1;
    }
};

int main() {
    Solution sol;
    string s = "1234";
    int dways = sol.numDecodings(s);
    cout << "Number of ways to decode message " << s << " is: " << dways << endl;
}
