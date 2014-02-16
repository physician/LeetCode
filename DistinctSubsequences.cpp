/*
 Author:     physician
 Date:       Feb 16, 2014
 Update:     Feb 16, 2014
 Problem:    Distinct Subsequences
 Difficulty: Medium
 Source:     http://oj.leetcode.com/problems/distinct-subsequences/

 Problem Description:
 Distinct Subsequences: 

 Given a string S and a string T, count the number of distinct subsequences of T in S.

 A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

 Here is an example:
 S = "rabbbit", T = "rabbit"

 Return 3.

 Notes:
 1. First implementation, DP. Time O(n^2), space O(n^2).
 2. DP solution idea:
    Iteratively find the number of distinct subsequences of S(ends at i) in T(ends at j), dp[i+1][j+1];
    if S[i] != T[j], then dp[i+1][j+1] is the same as dp[i+1][j];
    if S[i] == T[j], there are two types of possible alignment, dp[i+1][j+1] = dp[i+1][j] + dp[i][j];
    put empty string in front of both S and T in dp[][] as boundary conditions, which makes coding easier.
 3. Compile using g++: g++ DistinctSubsequences.cpp -o DistinctSubsequences.
*/

# include <iostream>

using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        int M = T.size(), N = S.size();
        int dp[M+1][N+1];
        for (int j = 0; j <= N; ++j)
            dp[0][j] = 1;
        for (int i = 1; i <= M; ++i)
            dp[i][0] = 0;
        for (int i = 1; i <= M; ++i)
            for (int j = 1; j <= N; ++j)
                dp[i][j] = dp[i][j-1] + (T[i-1] == S[j-1] ? dp[i-1][j-1] : 0);
        return dp[M][N];
    }
};


int main() {
    string S = "rabbbit";
    string T = "rabbit";
    Solution sol;
    cout << "There are " << sol.numDistinct(S, T) << " distinct subsequences of \"" << T << "\" in \"" << S << "\"." << endl;
}
