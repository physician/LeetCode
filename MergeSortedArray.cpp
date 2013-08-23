/*
 Author:     physician
 Date:       Aug 23, 2013
 Update:     Aug 23, 2013
 Problem:    Merge Sorted Array
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_88

 Problem Description:
 Merge Sorted Array: 

 Given two sorted integer arrays A and B, merge B into A as one sorted array.

 Note:
 You may assume that A has enough space to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.

 Notes:
 1. First implementation, move backwards.
 2. Write simpler code. Avoid unnecessary operations.
 3. Compile using g++: g++ MergeSortedArray.cpp -o MergeSortedArray
*/

# include <iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] >= B[j])
                A[k--] = A[i--];  // simpler code
            else
                A[k--] = B[j--];
        } 
        // only need to be if (j >= 0)
        if (i < 0 && j >= 0) {
            while(j >= 0)
                A[k--] = B[j--];
        }
        
        // below are waste operations, avoid.        
/*
        if (j < 0 && i >= 0) {
            while(i >= 0)
                A[k--] = A[i--];
        }
*/
    }
};

int main() {
    int A[13] = {3, 5, 7, 9};
    int B[9] = {0, 1, 2, 4, 6, 8, 10, 11, 12};
    Solution sol;
    sol.merge(A, 4, B, 9);
    for(int i = 0; i < sizeof(A)/sizeof(int); i++)
        cout << A[i] << " ";
    cout << endl;
}
