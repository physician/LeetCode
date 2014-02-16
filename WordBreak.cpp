/*
 Author:     physician
 Date:       Feb 15, 2014
 Update:     Feb 15, 2014
 Problem:    Word Break
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/word-break/

 Problem Description:
 Word Break: 

 Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

 For example, given
 s = "leetcode",
 dict = ["leet", "code"].

 Return true because "leetcode" can be segmented as "leet code".

 Notes:
 1. First implementation, DP.
 2. Compile using g++: g++ -std=c++0x WordBreak.cpp -o WordBreak.
*/

# include <iostream>
# include <string.h>  // memset
# include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int N = s.size();
        bool dp[N+1];
        fill_n(dp, N+1, false);
        //memset(dp, false, sizeof(dp));
        dp[0] = true;
        for(int i = 1; i <= N; ++i)
            for(int j = i-1; j >= 0; --j)
                if (dp[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
        return dp[N];
    }
};


int main() {
    cout << "The dictionary is:" << endl;
    unordered_set<string> dict;
    dict.insert("leet");
    dict.insert("code");
    unordered_set<string>::iterator iter;
    for(iter = dict.begin(); iter != dict.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    string s = "leetcode";
    Solution sol;
    if (sol.wordBreak(s, dict))
        cout << "The word " << "\"" << s << "\" can be segmented using dictionary words." << endl;
    else
        cout << "The word " << "\"" << s << "\" can not be segmented using dictionary words." << endl;
}
