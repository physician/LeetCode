/*
 Author:     physician
 Date:       Aug 20, 2013
 Update:     Aug 21, 2013
 Problem:    Longest Substring Without Repeating Characters
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_3

 Problem Description:
 Longest Substring Without Repeating Characters:

 Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

 Notes:
 1. First implementation, use boolean array as hashtable.
 2. Use hashtable to keep track the character already appeared, lookup operation will be O(1).
 3. Use an array as a hashtable, the hash function is simply the Ascii code of the character.
 4. Overall complexity is O(N).
 5. Be smart when updating start index, also remember to update hashtable for all the characters appeared before the repeating character.
 6. Remember to check whether need to update maxSubLen when exit the mainloop.
 7. Compile using g++: g++ LongestSubstringWithoutRepeatingCharacters.cpp -o LongestSubstringWithoutRepeatingCharacters.
*/


# include <iostream>
# include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxSubLen = 0;
        int start = 0;
        bool exist[256];
        fill_n(exist, sizeof(exist)/sizeof(exist[0]), false);
        for(int i = 0; i < s.size(); i++) {
            if(!exist[int(s[i])]) {
                exist[int(s[i])] = true;
            }
            else {
                if (i - start > maxSubLen) {
                    maxSubLen = i - start;
                }
                while(s[start] != s[i]) {
                    exist[int(s[start])] = false;
                    start++;
                }
                start++;
            }
        } 
        if (s.size() - start > maxSubLen)
            maxSubLen = s.size() - start;
        return maxSubLen;
    }
};

int main() {
    Solution sol;
    string s1 = "abcabcbb";
    int s1Len = sol.lengthOfLongestSubstring(s1);
    string s2 = "bbbbb";
    int s2Len = sol.lengthOfLongestSubstring(s2);
    string s3 = "abcadefgh";
    int s3Len = sol.lengthOfLongestSubstring(s3);
    string s4 = "abcde";
    int s4Len = sol.lengthOfLongestSubstring(s4);
    string s5 = "abcddcbae";
    int s5Len = sol.lengthOfLongestSubstring(s5);
    cout << "Length of the longest substring of \'" << s1
         << "\' is: " << s1Len << endl;
    cout << "Length of the longest substring of \'" << s2 
         << "\' is: " << s2Len << endl;
    cout << "Length of the longest substring of \'" << s3
         << "\' is: " << s3Len << endl;
    cout << "Length of the longest substring of \'" << s4
         << "\' is: " << s4Len << endl;
    cout << "Length of the longest substring of \'" << s5
         << "\' is: " << s5Len << endl;
}
