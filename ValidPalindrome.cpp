/*
 Author:     physician
 Date:       Aug 29, 2013
 Update:     Aug 29, 2013
 Problem:    Valid Palindrome
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_125

 Problem Description:
 Valid Palindrome:

 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

 For example,
 "A man, a plan, a canal: Panama" is a palindrome.
 "race a car" is not a palindrome.

 Note:
 Have you consider that the string might be empty? This is a good question to ask during an interview.

 For the purpose of this problem, we define empty string as valid palindrome.

 Notes:
 1. First implementation, use two pointers.
 2. <ctype.h> contains a series of useful char functions. e.g. isalnum(), isalpha(), isdigit(), tolower(), toupper(), islower(), isupper(), ..., etc.
 3. Be careful to test special cases, e.g. empty string, non-alphanumeric string(substring).
 4. If only want to increment variable, use pre-increment form ++i instead of post-increment form i++.
 5. Write simpler code. Simplify logic. 
 6. Compile using g++: g++ ValidPalindrome.cpp -o ValidPalindrome.
*/


# include <iostream>
# include <string>
# include <ctype.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // check not necessary
        //if (s.size() == 0) 
        //    return true;       // empty string
        int i = 0;
        int j = s.size()-1;
        while (i <= j) {
            //while (i <= j && !isalpha(s[i]) && !isdigit(s[i]))
            while (i <= j && !isalnum(s[i]))
                ++i;
            //while (i <= j && !isalpha(s[j]) && !isdigit(s[j]))
            while (i <= j && !isalnum(s[j]))
                --j;
            if (i > j)
                return true;   // non-alphanumeric string(substring)
            //if (i <= j && tolower(s[i]) == tolower(s[j])) {
            if (tolower(s[i]) == tolower(s[j])) {
                ++i;
                --j;
            }
            else
                return false;
        }  
        return true;
    }
};

int main() {
    Solution sol;
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    if(sol.isPalindrome(s1))
        cout << "String s1 (" << s1 << "): is palindrome." << endl;
    else
        cout << "String s1 (" << s1 << "): is NOT palindrome." << endl;
    if(sol.isPalindrome(s2))
        cout << "String s2 (" << s2 << "): is palindrome." << endl;
    else
        cout << "String s2 (" << s2 << "): is NOT palindrome." << endl;

}
