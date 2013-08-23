/*
 Author:     physician
 Date:       Aug 23, 2013
 Update:     Aug 23, 2013
 Problem:    Plus One
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_66

 Problem Description:
 Plus One: 

 Given a number represented as an array of digits, plus one to the number.

 Notes:
 1. First implementation, natural solution.
 2. Compile using g++: g++ PlusOne.cpp -o PlusOne
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        if (digits[n - 1] < 9)
            digits[n - 1]++;
        else {
            int i = n - 1;
            while(digits[i] == 9) {
                digits[i] = 0;
                i--;
            }
            if (i >= 0) {
                digits[i]++;
            }
            else {
                digits[0] = 1;
                digits.push_back(0);
            }
        }
        return digits; 
    }
};

int main() {
    //int inputDigit[] = {9,9,9};
    int inputDigit[] = {1, 2, 9, 9};
    vector<int> input(inputDigit, inputDigit + sizeof(inputDigit)/sizeof(int));
    Solution sol;
    cout << "Input number: ";
    for(int i = 0; i < input.size(); i++)
        cout << input[i];
    cout << endl;
    vector<int> output = sol.plusOne(input);
    cout << "Output number: ";
    for(int i = 0; i < output.size(); i++)
        cout << output[i];
    cout << endl;
}
