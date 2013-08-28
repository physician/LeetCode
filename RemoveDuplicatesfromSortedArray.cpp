/*
 Author:     physician
 Date:       Aug 28, 2013
 Update:     Aug 28, 2013
 Problem:    Remove Duplicates from Sorted Array
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_26

 Problem Description:
 Remove Duplicates from Sorted Array: 

 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

 Do not allocate extra space for another array, you must do this in place with constant memory.

 For example,
 Given input array A = [1,1,2],

 Your function should return length = 2, and A is now [1,2].

 Notes:
 1. First implementation, use two pointers.
 2. Single pass, time complexity O(N). In place, space complexity O(1).
 3. Be careful to handle special cases of input. Simplify logic.
 4. Compile using g++: g++ RemoveDuplicatesfromSortedArray.cpp -o RemoveDuplicatesfromSortedArray
*/

# include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0)
            return 0;
        int i = 0;
        int j = 1;
        while(j < n) {
            if (A[i] != A[j]) {
                i++;
                if ( i != j)     // This can be safely omitted. 
                    A[i] = A[j]; // Combine 3 lines into A[++i] = A[j].
            }
            j++;
        }   
        return i + 1;     
    }
};


int main() {
    int A[10] = {1, 1, 2, 2, 3, 3, 3, 4, 4, 5};
    //int A[] = {};
    cout << "Before duplication removal:" << endl;
    for (int i = 0; i < sizeof(A)/sizeof(int); i++)
        cout << A[i] << " ";
    cout << endl;
    Solution sol;
    int len = sol.removeDuplicates(A, 10);
    cout << "After duplication removal:" << endl;
    for (int i = 0; i < len; i++)
        cout << A[i] << " ";
    cout << endl;
}
