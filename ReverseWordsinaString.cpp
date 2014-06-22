/*
 Author:     physician
 Date:       Jun 22, 2014
 Update:     Jun 22, 2014
 Problem:    Reverse Words in a String
 Difficulty: Easy 
 Source:     https://oj.leetcode.com/problems/reverse-words-in-a-string/

 Problem Description:
 Reverse Words in a String: 

 Given an input string, reverse the string word by word.

 For example,
 Given s = "the sky is blue",
 return "blue is sky the".

 Clarification:
 1. What constitutes a word?
 A sequence of non-space characters constitutes a word.

 2. Could the input string contain leading or trailing spaces?
 Yes. However, your reversed string should not contain leading or trailing spaces.

 3. How about multiple spaces between two words?
 Reduce them to a single space in the reversed string.

 Notes:
 1. First implementation, use stack. Time complexity O(N), space complexity O(N).
 2. Compile using g++: g++ ReverseWordsinaString.cpp -o ReverseWordsinaString.
*/

# include <iostream>
# include <string>
# include <stack>
# include <algorithm>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        reverseWords2(s);
    }

private:
    void reverseWords1(string &s) {
        if (s.empty())
            return;
        stack<string> stk;
        int i = 0, j = 0;
        while (i < s.size() && j < s.size()) {
            if (s[i] != ' ') {
                j = i;
                while (j < s.size() && s[j] != ' ')
                    j++;
                stk.push(s.substr(i, j-i));
                i = j;
            }
            else
                i++;
        }
        s.clear();
        while (!stk.empty()) {
            s += stk.top();
            s += " ";
            stk.pop();
        }
        if (!s.empty())
            s.erase(s.size()-1, 1);
        return;
    }

    void reverseWords2(string &s) {
        string rs;
        int i = s.size()-1;
        while (i >= 0) {
            if (s[i] == ' ')
                i--;
            else {
                string t;
                while (i >= 0 && s[i] != ' ')
                    t.push_back(s[i--]);
                reverse(t.begin(), t.end());
                if (!rs.empty())
                    rs += ' ';
                rs += t;
            }
        }
        s = rs;
    }
};


int main() {
    string s = "   the   sky   is      blue    ";
    //string s = " ";
    Solution sol;
    cout << "Given string = " << s << endl;
    sol.reverseWords(s);
    cout << "Reversed string = " << s << endl;
}
