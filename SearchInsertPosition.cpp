/*
 Author:     physician
 Date:       Aug 25, 2013
 Update:     Aug 25, 2013
 Problem:    Search Insert Position
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_35

 Problem Description:
 Search Insert Position: 

 Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

 You may assume no duplicates in the array.
 
 Here are few examples.
 [1,3,5,6], 5 → 2
 [1,3,5,6], 2 → 1
 [1,3,5,6], 7 → 4
 [1,3,5,6], 0 → 0
 
 Notes:
 1. First implementation, binary search.
 2. Compile using g++: g++ SearchInsertPosition.cpp -o SearchInsertPosition
*/

# include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int start = 0;
        int end = n - 1;
        while(start <= end) {
            int mid = (start + end)/2;
            if (A[mid] == target)
                return mid; 
            if (A[mid] < target) {
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        return start;
    }
};

int main() {
    int A[2] = {1, 3};
    int B[5] = {0, 1, 2, 4, 6};
    Solution sol;
    int target = 0;
    for(int i = 0; i < sizeof(A)/sizeof(int); i++)
        cout << A[i] << " ";
    cout << endl;
    cout << "The insert position of " << target << " is: " << sol.searchInsert(A, 4, target) << endl;
    for(int i = 0; i < sizeof(B)/sizeof(int); i++)
        cout << B[i] << " ";
    cout << endl;
    cout << "The insert position of " << target << " is: " << sol.searchInsert(B, 5, target) << endl;
}
