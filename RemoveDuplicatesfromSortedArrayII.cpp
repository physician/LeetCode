/*
 Author:     physician
 Date:       Aug 29, 2013
 Update:     Aug 29, 2013
 Problem:    Remove Duplicates from Sorted Array II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_80

 Problem Description:
 Remove Duplicates from Sorted Array II: 

 Follow up for "Remove Duplicates":
 What if duplicates are allowed at most twice?

 For example,
 Given sorted array A = [1,1,1,2,2,3],

 Your function should return length = 5, and A is now [1,1,2,2,3].

 Notes:
 1. First implementation, use two pointers.
 2. Single pass, time complexity O(N). In place, space complexity O(1).
 3. Be careful to handle special cases of input. Simplify logic.
 4. Compile using g++: g++ RemoveDuplicatesfromSortedArrayII.cpp -o RemoveDuplicatesfromSortedArrayII
*/

/* 
********************************************************************************

General Algorithm:

 Remove Duplicates from Sorted Array: 

 Duplicates are allowed at most k times.


class Solution {
public:
    int removeDuplicates(int A[], int n, int k) {
        if (n < k)
            return k;
        int i = k-1;
        int j = k;
        while (j < n) {
            if (A[j] != A[i-(k-1)]) {
                A[++i] = A[j];
            }
            j++;
        }
        return i + 1;
    }
};

********************************************************************************
*/

# include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0 || n == 1)
            return n;
        int i = 1;
        int j = 2;
        while (j < n) {
            if (A[j] != A[i-1]) {
                A[++i] = A[j];
            }
            j++;
        }
        return i + 1;
    }
};


int main() {
    //int A[6] = {1, 1, 1, 2, 2, 3};
    int A[20] = {1, 1, 1, 2, 2, 3, 3, 3, 3, 3, 4, 5, 6, 6, 6, 6, 6, 7, 8, 8};
    cout << "Before duplication removal:" << endl;
    for (int i = 0; i < sizeof(A)/sizeof(int); i++)
        cout << A[i] << " ";
    cout << endl;
    Solution sol;
    int len = sol.removeDuplicates(A, sizeof(A)/sizeof(int));
    cout << "After duplication removal:" << endl;
    for (int i = 0; i < len; i++)
        cout << A[i] << " ";
    cout << endl;
}
