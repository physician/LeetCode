/*
 Author:     physician
 Date:       Feb 01, 2015
 Update:     Feb 01, 2015
 Problem:    Search for a Range
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/search-for-a-range/

 Problem Description:
 Search for a Range: 

 Given a sorted array of integers, find the starting and ending position of a given target value.

 Your algorithm's runtime complexity must be in the order of O(log n).

 If the target is not found in the array, return [-1, -1].

 For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].

 Notes:
 1. First implementation, binary search.
 3. Compile using g++: g++ -std=c++0x SearchforaRange.cpp -o SearchforaRange.
*/


# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        return searchRange2(A, n, target);
    }

    vector<int> searchRange1(int A[], int n, int target) {
        vector<int> result = {-1, -1};
        if (n < 1 || A[0] > target || A[n-1] < target)
            return result;
        int begin = 0, end = n;
        while (begin < end) {
            if (A[begin] == target && A[end-1] == target) {
                result = {begin, end-1};
                break;
            }
            if (end - begin == 1 && A[begin] != target)
                break;
            int mid = begin + (end-begin)/2;
            if (A[mid] < target)
                begin = mid;
            else if (A[mid] > target)
                end = mid;
            else {
                begin = mid;
                while (begin >= 0 && A[begin] == target)
                    begin--;
                end = mid;
                while (end < n && A[end] == target)
                    end++;
                result = {begin+1, end-1};
                break;
            }
        }
        return result;
    }

    vector<int> searchRange2(int A[], int n, int target) {
        vector<int> result = {-1, -1};
        if (n < 1 || A[0] > target || A[n-1] < target)
            return result;
        int lower = searchLowerBound(A, n, target);
        int upper = searchUpperBound(A, n, target);
        if (lower <= upper)
            result = {lower, upper};
        return result;
    }
    
    int searchLowerBound(int A[], int n, int target) {
        int begin = 0, end = n-1;
        while (begin <= end) {
            int mid = begin + (end-begin)/2;
            if (A[mid] < target)
                begin = mid + 1;
            else
                end = mid - 1;
        }
        return begin;
    }

    int searchUpperBound(int A[], int n, int target) {
        int begin = 0, end = n-1;
        while (begin <= end) {
            int mid = begin + (end-begin)/2;
            if (A[mid] <= target)
                begin = mid + 1;
            else
                end = mid - 1;
        }
        return end;
    }
};


int main() {
    //int target = 8;
    int target = 4;
    //int A[6] = {5,7,7,8,8,10};
    int A[2] = {1,5};
    cout << "The array:" << endl;
    for (int i = 0; i < sizeof(A)/sizeof(int); i++)
        cout << A[i] << " ";
    cout << endl;
    Solution sol;
    vector<int> range = sol.searchRange(A, sizeof(A)/sizeof(int), target);
    cout << "Target " << target << " index range in the array is: [" << range[0] << ", " << range[1] << "]." << endl;
}
