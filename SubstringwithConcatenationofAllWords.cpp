/*
 Author:     physician
 Date:       Aug 24, 2014
 Update:     Aug 24, 2014
 Problem:    Substring with Concatenation of All Words
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/substring-with-concatenation-of-all-words/

 Problem Description:
 Substring with Concatenation of All Words:

 You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

 For example, given:
 S: "barfoothefoobarman"
 L: ["foo", "bar"]

 You should return the indices: [0,9].
 (order does not matter).

 Notes:
 1. First implementation, unordered_map. Time complexity O(|S|). Space complexity O(|L|*|Word|).
 2. Use hashtable to keep track the words need to be found and words already found.
 3. Here used unordered_map as hashtable.
 4. Compile using g++: g++ -std=c++0x SubstringwithConcatenationofAllWords.cpp -o SubstringwithConcatenationofAllWords.
*/


# include <iostream>
# include <string>
# include <vector>
# include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> indices;
        int s = S.size(), l = L.size(), k = L[0].size();
        if (s == 0 || l == 0 || s < l*k) 
            return indices;
        unordered_map<string, int> needToFind;
        unordered_map<string, int> hasFound;
        for(int i = 0; i < l; ++i)
            needToFind[L[i]]++;
        for(int i = 0; i <= s-l*k; ++i) {
            hasFound.clear();
            int j;
            /*for(j = i; j < i+l*k; j = j+k) {
                string word = S.substr(j,k);
                if(needToFind.find(word) == needToFind.end())
                    break;
                else
                    hasFound[word]++;
                if(hasFound[word] > needToFind[word])
                    break;
            }
            if(j == i+l*k)
                indices.push_back(i);
            */
            for(j = 0; j < l; ++j) {
                string word = S.substr(i+j*k, k);
                if(needToFind.find(word) == needToFind.end())
                    break;
                if(hasFound[word] >= needToFind[word])
                    break;
                hasFound[word]++;
            }
            if(j == l)
                indices.push_back(i);
        }
        return indices;
    }
};

int main() {
    Solution sol;
    string S = "barfoothefoobarman";
    vector<string> L;
    L.push_back("foo");
    L.push_back("bar");
    vector<int> result = sol.findSubstring(S, L);
    cout << "Indices: " << endl;
    for(int i = 0; i < result.size(); ++i)
        cout << result[i] << " ";
    cout << endl;
}
