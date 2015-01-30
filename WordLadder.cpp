/*
 Author:     physician
 Date:       Jan 30, 2015
 Update:     Jan 30, 2015
 Problem:    Word Ladder
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/word-ladder/

 Problem Description:
 Word Ladder: 

 Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

 Only one letter can be changed at a time
 Each intermediate word must exist in the dictionary
 For example,

 Given:
 start = "hit"
 end = "cog"
 dict = ["hot","dot","dog","lot","log"]
 As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 return its length 5.

 Note:
 Return 0 if there is no such transformation sequence.
 All words have the same length.
 All words contain only lowercase alphabetic characters.

 Notes:
 1. First implementation, BFS.
 2. Compile using g++: g++ -std=c++0x WordLadder.cpp -o WordLadder.
*/

# include <iostream>
# include <vector>
# include <string>
# include <queue>
# include <utility>
# include <unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        return ladderLength1(start, end, dict);
    }

    int ladderLength1(string start, string end, unordered_set<string> &dict) {
        queue<pair<string, int> > q;
        q.push(make_pair(start, 1));
        while (!q.empty()) {
            pair<string, int> qfront = q.front();
            q.pop();
            string word = qfront.first;
            string originalWord = word;
            for (int i = 0; i < word.size(); ++i)
                for (char c = 'a'; c <= 'z'; ++c) {
                    word[i] = c;
                    if (word == end)
                        return qfront.second + 1;
                    if (dict.find(word) != dict.end()) {
                        q.push(make_pair(word, qfront.second + 1));
                        dict.erase(word);
                    }
                    word = originalWord;
                }
        }
        return 0;
    }

    // Time Limit Exceeded
    int ladderLength2(string start, string end, unordered_set<string> &dict) {
        queue<pair<string, int> > q;
        q.push(make_pair(start, 1));
        while (!q.empty()) {
            string word = q.front().first;
            if (countDiffChar(word, end) == 1) 
                return q.front().second + 1;
            else
                for (auto iter = dict.begin(); iter != dict.end(); ) {
                    string nextWord = *iter;
                    if (countDiffChar(nextWord, word) == 1) {
                        q.push(make_pair(nextWord, q.front().second + 1));
                        iter = dict.erase(iter);
                    }
                    else
                        iter++;
                }
            q.pop();
        }
        return 0;
    }

private:
    int countDiffChar(string s1, string s2) {
        int count = 0;
        int N = min(s1.size(), s2.size());
        for (int i = 0; i < N; ++i) {
            if (s1[i] != s2[i])
                count++;
        }
        count += max(s1.size(), s2.size()) - N;
        return count;
    }
};


int main() {
    string start = "hit";
    string end = "cog";
    unordered_set<string> dict = {"hot", "dot", "dog", "lot", "log"};
    unordered_set<string>::iterator iter;
    cout << "The dictionary is: [ ";
    for(iter = dict.begin(); iter != dict.end(); ++iter)
        cout << *iter << " ";
    cout << "]" << endl;
    Solution sol;
    cout << "The shortest transformation length from \'" << start << "\' to \'" << end << "\' is: " << sol.ladderLength(start, end, dict) << endl;
}
