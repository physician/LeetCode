/*
 Author:     physician
 Date:       Feb 16, 2014
 Update:     Feb 16, 2014
 Problem:    Palindrome Partitioning
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/palindrome-partitioning/

 Problem Description:
 Palindrome Partitioning: 

 Given a string s, partition s such that every substring of the partition is a palindrome.

 Return all possible palindrome partitioning of s.

 For example, given s = "aab",
 Return

   [
     ["aa","b"],
     ["a","a","b"]
   ]

 Notes:
 1. First implementation, recursion. DFS.
 2. Compile using g++: g++ PalindromePartitioning.cpp -o PalindromePartitioning.
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > result;
        vector<string> path;
        partitionRe(s, 0, path, result);
        return result;
    }

private:
    void partitionRe(const string &s, int begin, vector<string> &path, vector<vector<string> > &result) {
        int N = s.size();
        if (begin >= N) {
            result.push_back(path);
            return;   
        }
        string palindrome;
        for (int i = begin; i < N; ++i) {
            palindrome = s.substr(begin, i-begin+1);
            if (isPalindrome(palindrome)) {
                path.push_back(palindrome);
                partitionRe(s, i+1, path, result);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string &s) {
        int N = s.size();
        if (N == 0 || N == 1)
            return true;
        if (s[0] == s[N-1] && isPalindrome(s.substr(1, N-2)))
            return true;
        else
            return false;
    }
};


int main() {
    string s = "aab";
    //string s = "abadd";
    Solution sol;
    vector<vector<string> > result = sol.partition(s);
    cout << "All the possible palindrome partitioning of " << s << ":" << endl;
    cout << "[" << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << "  [ ";
        for (int j = 0; j < result[i].size(); ++j)
            cout << "\"" << result[i][j] << "\" ";
        cout << "]" << endl;
    }
    cout << "]" << endl;
}
