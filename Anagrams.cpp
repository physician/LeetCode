/*
 Author:     physician
 Date:       Jan 29, 2015
 Update:     Jan 29, 2015
 Problem:    Anagrams
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/anagrams/

 Problem Description:
 Anagrams:

 Given an array of strings, return all groups of strings that are anagrams.

 Note: All inputs will be in lower-case.

 Notes:
 1. First implementation, unordered_map.
 2. Compile using g++: g++ -std=c++0x Anagrams.cpp -o Anagrams.
*/


# include <iostream>
# include <string>
# include <vector>
# include <unordered_map>
# include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        unordered_map<string, vector<string> > ht;
        for (string word : strs) {
            string wordkey = word;
            sort(wordkey.begin(), wordkey.end()); 
            ht[wordkey].push_back(word);
        }
        for (auto kv : ht)
            if (kv.second.size() > 1)
                result.insert(result.end(), kv.second.begin(), kv.second.end());
        return result;
    }
};

int main() {
    vector<string> strs {"tea","and","ate","eat","den"};
    cout << "Input: " << endl;
    for(auto word : strs)
        cout << word << " ";
    cout << endl;
    Solution sol;
    vector<string> result = sol.anagrams(strs);
    cout << "Output: " << endl;
    for(auto word : result)
        cout << word << " ";
    cout << endl;
}
