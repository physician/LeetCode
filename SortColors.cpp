/*
 Author:     physician
 Date:       Jan 15, 2014
 Update:     Jan 15, 2014
 Problem:    Sort Colors
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/sort-colors/

 Problem Description:
 Sort Colors:

 Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

 Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

 Note:
 You are not suppose to use the library's sort function for this problem.

 Follow up:
 A rather straight forward solution is a two-pass algorithm using counting sort.
 First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

 Could you come up with an one-pass algorithm using only constant space?

 Notes:
 1. First implementation, use two pointers.
 2. Compile using g++: g++ SortColors.cpp -o SortColors.
*/


# include <iostream>

using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        int begin = 0;
        int end = n-1;
        int oneStart = n;
        while(begin <= end){
            if(A[begin] == 0) {
                if(begin > oneStart) {
                    swap(A[begin], A[oneStart]);    
                    oneStart++;
                }    
                begin++;
            }
            else if(A[begin] == 1) {
                if(begin < oneStart)
                    oneStart = begin;
                begin++;
            }
            else {
                while(A[end] == 2)
                    end--;
                if(begin < end) {
                    swap(A[begin], A[end]);
                    end--;
                }
            }
        }
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
};

int main() {
    Solution sol;
    int n = 9;
    int A[9] = {1,2,0,2,0,0,1,1,2};
    //int n = 2;
    //int A[2] = {2,2};
    cout << "Before sorting:" << endl;
    for(int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;
    sol.sortColors(A, n);
    cout << "After sorting:" << endl;
    for(int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;
}
