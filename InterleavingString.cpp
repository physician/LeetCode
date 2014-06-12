/*
 Author:     physician
 Date:       Jun 12, 2014
 Update:     Jun 12, 2014
 Problem:    Interleaving String
 Difficulty: Medium 
 Source:     https://oj.leetcode.com/problems/interleaving-string/

 Problem Description:
 Interleaving String: 

 Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

 For example,
 Given:
 s1 = "aabcc",
 s2 = "dbbca",

 When s3 = "aadbbcbcac", return true.
 When s3 = "aadbbbaccc", return false.

 Notes:
 1. First implementation, DP. Time complexity O(MN), space complexity O(MN).
 2. dp[i+1][j+1] == true means that there is at least one way to construct string s3[0...i+j+1] by interleaving s1[0...i] and s2[0...j].
 3. The initial value of local boolean variable is undetermined, not false by default.
 4. Compile using g++: g++ InterleavingString.cpp -o InterleavingString.
*/

# include <iostream>
# include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int N = s1.size();
        int M = s2.size();
        if (s3.size() != N + M)
            return false;
        bool dp[N+1][M+1];
        dp[0][0] = true;
        for (int i = 1; i <= N; ++i)
            dp[i][0] = dp[i-1][0] && s3[i-1] == s1[i-1];
        for (int j = 1; j <= M; ++j)
            dp[0][j] = dp[0][j-1] && s3[j-1] == s2[j-1];
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                dp[i+1][j+1] = (dp[i][j+1] && s3[i+j+1] == s1[i]) || (dp[i+1][j] && s3[i+j+1] == s2[j]);
        return dp[N][M];
    }
};


int main() {
    //string s1 = "aabcc";
    string s1 = "aacaac";
    //string s2 = "dbbca";
    string s2 = "aacaaeaac";
    //string s3 = "aadbbcbcac";
    //string s3 = "aadbbbaccc";
    string s3 = "aacaaeaaeaacaac";
    Solution sol;
    if (sol.isInterleave(s1, s2, s3))
        cout << s3 << " is formed by the interleaving of " << s1 << " and " << s2 << "." << endl;
    else
        cout << s3 << " is NOT formed by the interleaving of " << s1 << " and " << s2 << "." << endl;
}
