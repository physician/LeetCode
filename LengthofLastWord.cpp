/*
 Author:     physician
 Date:       Aug 22, 2013
 Update:     Aug 22, 2013
 Problem:    Length of Last Word
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_58

 Problem Description:
 Length of Last Word: 

 Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

 If the last word does not exist, return 0.

 Note: A word is defined as a character sequence consists of non-space characters only.

 For example,
 Given s = "Hello World",
 return 5.

 Notes:
 1. First implementation, search backwards.
 2. Be careful for the special case when a string ends with spaces.
 3. Compile using g++: g++ LengthofLastWord.cpp -o LengthofLastWord.
*/

# include <iostream>
# include <string.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (*s == '\0')
            return 0;
        int len = 0;
/*
        const char *t = s;
        while (*t != '\0')
            t++;
        t--;
*/
        const char *t = s + strlen(s) - 1;
        while(t >= s && *t == ' ')
            t--;
        while (t >= s && *t != ' ') {
            t--;
            len++;
        }   
        return len;
    }
};


int main() {
    //const char *s = "Hello World";
    //const char *s = "";
    //const char *s = "Hello";
    //const char *s = "a ";
    const char *s = "    ";
    Solution sol;
    int size = sol.lengthOfLastWord(s);
    cout << "The length of the last word is: " << size << endl;
}
