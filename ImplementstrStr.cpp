/*
 Author:     physician
 Date:       Jan 31, 2014
 Update:     Jan 31, 2014
 Problem:    Implement strStr()
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/implement-strstr/

 Problem Description:
 Implement strStr():

 Implement strStr().

 Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.

 Notes:
 1. First implementation, use two pointers.
 2. Compile using g++: g++ ImplementstrStr.cpp -o ImplementstrStr.
*/


# include <iostream>

using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        while (true) {
            char *h = haystack, *n = needle;
            while (*h == *n && *n != '\0') {
                h++;
                n++;
            }
            if (*n == '\0')
                return haystack;
            if (*h == '\0')
                return NULL;
            haystack++;
        }
    }
};

int main() {
    //char text[] = "This is a sample text.";
    //char text[] = "";
    char text[] = "mississippi";
    char * haystack = text;
    //char word[] = "sample";
    //char word[] = "";
    char word[] = "issip";
    char * needle = word;
    Solution sol;
    char * result = sol.strStr(haystack, needle);
    if (result == NULL)
        cout << "Not found!" << endl;
    else {
        cout << "Found!" << endl;
        while(*result != '\0') {
            cout << *result;
            result++;
        }
        cout << endl;
    }
}
