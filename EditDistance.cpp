/*
 Author:     physician
 Date:       Aug 22, 2014
 Update:     Aug 22, 2014
 Problem:    Edit Distance
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/edit-distance/

 Problem Description:
 Edit Distance:

 Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

 You have the following 3 operations permitted on a word:

 a) Insert a character
 b) Delete a character
 c) Replace a character

 Notes:
 1. First implementation, DP. Time complexity O(MN). Space complexity O(MN).
 2. Compile using g++: g++ EditDistance.cpp -o EditDistance.
*/


# include <iostream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int N = word1.size();
        int M = word2.size();
        int dp[M+1][N+1];
        dp[0][0] = 0;
        for(int i = 1; i <= M; ++i)
            dp[i][0] = i;
        for(int j = 1; j <= N; ++j)
            dp[0][j] = j;
        for(int i = 1; i <= M; ++i)
            for(int j = 1; j <= N; ++j)
                //dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + 1;
                //if (word1[j-1] == word2[i-1])
                //    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                //else
                //    dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
                if (word1[j-1] == word2[i-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]))+1;
        return dp[M][N];
    }
};

int main() {
    Solution sol;
    string word1 = "abcd";
    string word2 = "aab";
    int editDist = sol.minDistance(word1, word2);
    cout << "Edit distance between \"" << word1 << "\" and \"" << word2 << "\" is: " << editDist << endl;
}
