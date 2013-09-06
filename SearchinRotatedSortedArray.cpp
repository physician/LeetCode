/*
 Author:     physician
 Date:       Sep 06, 2013
 Update:     Sep 06, 2013
 Problem:    Search in Rotated Sorted Array
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_33

 Problem Description:
 Search in Rotated Sorted Array: 

 Suppose a sorted array is rotated at some pivot unknown to you beforehand.

 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

 You are given a target value to search. If found in the array return its index, otherwise return -1.

 You may assume no duplicate exists in the array.

 Notes:
 1. First implementation, recursion and binary search.
 2. Overall complexity is O(logN).
 3. Compile using g++: g++ SearchinRotatedSortedArray.cpp -o SearchinRotatedSortedArray
*/


# include <iostream>

using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
         return searchRe(A, 0, n, target);
    }

private:
    int binarySearch(int A[], int start, int end, int target) {
        if (start >= end)
            return -1;
        int mid = (start + end)/2;
        if (A[mid] == target)
            return mid;
        if (A[mid] > target)
            return binarySearch(A, start, mid, target);
        else
            return binarySearch(A, mid+1, end, target);
    }

    int searchRe(int A[], int start, int end, int target) {
        if (start >= end)
            return -1;
        int mid = (start + end)/2;
        if (A[mid] == target)
            return mid;
        if (A[start] < A[mid]) {
            if (A[start] <= target && target < A[mid])
                return binarySearch(A, start, mid, target);
            else
                return searchRe(A, mid+1, end, target);
        }
        else {
            if (A[mid] < target && target <= A[end-1])
                return binarySearch(A, mid+1, end, target);
            else
                return searchRe(A, start, mid, target);
        }
    }
};


int main() {
    int target = 5;
    int A[7] = {4, 5, 6, 7, 0, 1, 2};
    cout << "The array:" << endl;
    for (int i = 0; i < sizeof(A)/sizeof(int); i++)
        cout << A[i] << " ";
    cout << endl;
    Solution sol;
    int index = sol.search(A, sizeof(A)/sizeof(int), target);
    if (index == -1) 
        cout << "Target " << target << " is not in the array." << endl;
    else
        cout << "Target " << target << " is in the array. The index is: " << index << endl;
}
