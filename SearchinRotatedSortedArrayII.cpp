/*
 Author:     physician
 Date:       Sep 06, 2013
 Update:     Sep 06, 2013
 Problem:    Search in Rotated Sorted Array II
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_81

 Problem Description:
 Search in Rotated Sorted Array II: 

 Follow up for "Search in Rotated Sorted Array":
 What if duplicates are allowed?

 Would this affect the run-time complexity? How and why?

 Write a function to determine if a given target is in the array.

 Notes:
 1. First implementation, recursion and binary search.
 2. Overall worst case complexity O(N).
 3. Compile using g++: g++ SearchinRotatedSortedArrayII.cpp -o SearchinRotatedSortedArrayII.
*/


# include <iostream>

using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
         return searchRe(A, 0, n, target);
    }

private:
    bool binarySearch(int A[], int start, int end, int target) {
        if (start >= end)
            return false;
        int mid = (start + end)/2;
        if (A[mid] == target)
            return true;
        if (A[mid] > target)
            return binarySearch(A, start, mid, target);
        else
            return binarySearch(A, mid+1, end, target);
    }

    bool searchRe(int A[], int start, int end, int target) {
        if (start >= end)
            return false;
        int mid = (start + end)/2;
        if (A[mid] == target)
            return true;
        if (A[start] < A[mid]) {
            if (A[start] <= target && target < A[mid])
                return binarySearch(A, start, mid, target);
            else
                return searchRe(A, mid+1, end, target);
        }
        else if (A[start] > A[mid]) {
            if (A[mid] < target && target <= A[end-1])
                return binarySearch(A, mid+1, end, target);
            else
                return searchRe(A, start, mid, target);
        }
        else
            return searchRe(A, start+1, end, target);
    }
};


int main() {
    int target = 3;
    int A[5] = {1, 1, 1, 3, 1};
    cout << "The array:" << endl;
    for (int i = 0; i < sizeof(A)/sizeof(int); i++)
        cout << A[i] << " ";
    cout << endl;
    Solution sol;
    bool in = sol.search(A, sizeof(A)/sizeof(int), target);
    if (in) 
        cout << "Target " << target << " is in the array." << endl;
    else
        cout << "Target " << target << " is NOT in the array." << endl;
}
