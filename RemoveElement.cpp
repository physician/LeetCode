/*
 Author:     physician
 Date:       Aug 22, 2013
 Update:     Aug 22, 2013
 Problem:    Remove Element
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_27

 Problem Description:
 Remove Element: 

 Given an array and a value, remove all instances of that value in place and return the new length.

 The order of elements can be changed. It doesn't matter what you leave beyond the new length.

 Notes:
 1. First implementation, use head and tail pointers to swap removed elements to the end of the array.
 2. Be careful to handle details and special cases.
 3. Compile using g++: g++ RemoveElement.cpp -o RemoveElement.
*/

# include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (n == 0)
            return 0;
        int head = 0;
        int tail = n - 1;
        while (head < tail) {
            if (A[head] == elem) {
                while (A[tail] == elem && head < tail)
                    tail--;
                if (head < tail) {
                    A[head] = A[tail];
                    A[tail] = elem;
                    tail--;
                    head++;
                }
            }
            else
                head++;
        }
        if (A[head] == elem)
            return head;
        else
            return head + 1;
    }
};


int main() {
    //int A[10] = {1, 2, 5, 4, 1, 1, 7, 9, 10, 1};
    //int A[3] = {2, 2, 2};
    //int A[1] = {2};
    int A[] = {};
    Solution sol;
    //int size = sol.removeElement(A, 10, 1);
    //int size = sol.removeElement(A, 3, 2);
    //int size = sol.removeElement(A, 1, 2);
    int size = sol.removeElement(A, 0, 1);
    for (int i = 0; i < sizeof(A)/sizeof(int); i++) 
        cout << A[i] << " ";
    cout << endl;
    cout << "New array size is: " << size << endl;
}
