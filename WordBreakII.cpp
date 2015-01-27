/*
 Author:     physician
 Date:       Jan 27, 2015
 Update:     Jan 27, 2015
 Problem:    Word Break II
 Difficulty: Hard
 Source:     http://oj.leetcode.com/problems/word-break-ii/

 Problem Description:
 Word Break II: 

 Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

 Return all such possible sentences.

 For example, given
 s = "catsanddog",
 dict = ["cat", "cats", "and", "sand", "dog"].

 A solution is ["cats and dog", "cat sand dog"].

 Notes:
 1. First implementation, recursion. 
 2. Keep an indicator vector to avoid unnecessary recursion.
 3. Compile using g++: g++ -std=c++0x WordBreakII.cpp -o WordBreakII.
*/

# include <iostream>
# include <string>
# include <vector>
# include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        return wordBreak2(s, dict);
    }

private:
    vector<string> wordBreak1(string s, unordered_set<string> &dict) {
        vector<string> result;
        vector<string> path;
        vector<bool> possible(s.size()+1, true);
        wordBreak1Re(s, dict, 0, path, result, possible);
        return result;
    }

    void wordBreak1Re(string s, unordered_set<string> &dict, int begin, vector<string> &path, vector<string> &result, vector<bool> &possible) {
        if (begin == s.size()) {
            string words;
            for (auto word : path)
                words += (word + " ");
            result.push_back(words.substr(0, words.size()-1));
            return;   
        }
        for (int i = begin+1; i <= s.size(); ++i) {
            string word = s.substr(begin, i-begin);
            if (dict.find(word) != dict.end() && possible[i]) {
                int old = result.size();
                path.push_back(word);
                wordBreak1Re(s, dict, i, path, result, possible);
                path.pop_back();
                if (result.size() == old)
                    possible[i] = false;
            }
        }        
    }

    vector<string> wordBreak2(string s, unordered_set<string> &dict) {
        vector<string> result;
        string path;
        vector<bool> possible(s.size()+1, true);
        wordBreak2Re(s, dict, 0, path, result, possible);
        return result;
    }

    void wordBreak2Re(string s, unordered_set<string> &dict, int begin, string path, vector<string> &result, vector<bool> &possible) {
        if (begin == s.size()) {
            result.push_back(path);
            return;
        }
        if (path.size() != 0)
            path += " ";
        for (int i = begin+1; i <= s.size(); ++i) {
            string word = s.substr(begin, i-begin);
            if (dict.find(word) != dict.end() && possible[i]) {
                int old = result.size();
                wordBreak2Re(s, dict, i, path + word, result, possible);
                if (result.size() == old)
                    possible[i] = false;
            }
        }
    }
};


int main() {
    cout << "The dictionary is:" << endl;
    unordered_set<string> dict;
    dict.insert("cat");
    dict.insert("cats");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("dog");
    unordered_set<string>::iterator iter;
    for(iter = dict.begin(); iter != dict.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    string s = "catsanddog";
    Solution sol;
    vector<string> result = sol.wordBreak(s, dict);
    cout << "The solution is:" << endl;
    for(int i = 0; i < result.size(); ++i) {
        cout << "\"" << result[i] << "\"" << endl;
    }
}
