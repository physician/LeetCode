/*
 Author:     physician
 Date:       Feb 12, 2014
 Update:     Feb 12, 2014
 Problem:    Letter Combinations of a Phone Number
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/

 Problem Description:
 Letter Combinations of a Phone Number:

 Given a digit string, return all possible letter combinations that the number could represent.

 A mapping of digit to letters (just like on the telephone buttons) is given below.

 Input:Digit string "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 Note:
 Although the above answer is in lexicographical order, your answer could be in any order you want.

 Notes:
 1. First implementation, recursion, unordered_map.
 2. Compile using g++: g++ -std=c++0x LetterCombinationsofaPhoneNumber.cpp -o LetterCombinationsofaPhoneNumber.
*/


# include <iostream>
# include <string>
# include <vector>
# include <unordered_map>

using namespace std;

unordered_map<char, string> phone = {
    {'1', ""}, {'2', "abc"}, {'3', "def"}, 
    {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, 
    {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}, {'0', " "}
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        return letterCombinations1(digits);
    }

private:
    vector<string> letterCombinations1(string digits) {
        vector<string> result;
        string path;
        letterCombinations1Re(0, digits, path, result);
        return result;
    }

    void letterCombinations1Re(int begin, string &digits, string &path, vector<string> &result) {
        if (begin == digits.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < phone[digits[begin]].size(); ++i) {
            path.push_back(phone[digits[begin]][i]);
            letterCombinations1Re(begin+1, digits, path, result);
            //path.pop_back();
            path.erase(path.size()-1);
        }
    }
};


int main() {
    string digits = "23";
    Solution sol;
    cout << "The letter combinations of given digits are: " << endl;
    vector<string> solVec = sol.letterCombinations(digits);
    cout << "[ ";
    for (int i = 0; i < solVec.size(); ++i) {
        cout << "\"" << solVec[i] << "\"" << " ";
    }
    cout << "]." << endl;
}
