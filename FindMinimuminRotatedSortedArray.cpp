/*
 Author:     physician
 Date:       Jan 26, 2015
 Update:     Jan 26, 2015
 Problem:    Find Minimum in Rotated Sorted Array
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/

 Problem Description:
 Find Minimum in Rotated Sorted Array: 

 Suppose a sorted array is rotated at some pivot unknown to you beforehand.

 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

 Find the minimum element.

 You may assume no duplicate exists in the array.

 Notes:
 1. First implementation, binary search.
 2. Compile using g++: g++ -std=c++0x FindMinimuminRotatedSortedArray.cpp -o FindMinimuminRotatedSortedArray.
*/


# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        return findMin1(num);
    }

    int findMin1(vector<int> &num) {
        return findMinRe(num, 0, num.size()-1);
    }
    
    int findMinRe(vector<int> &num, int begin, int end) {
        if (end <= begin || num[begin] < num[end])
            return num[begin];
        int mid = begin + (end-begin)/2;
        if (num[mid] >= num[begin])    // or if (num[mid] >= num[end])
            return findMinRe(num, mid+1, end);
        else
            return findMinRe(num, begin, mid);
    }

    int findMin2(vector<int> &num) {
        int begin = 0, end = num.size()-1;
        while (begin < end) {
            if (num[begin] < num[end])
                return num[begin];
            int mid = begin + (end-begin)/2;
            if (num[mid] >= num[begin])    // or if (num[mid] >= num[end])
                begin = mid+1;
            else
                end = mid;
        }
        return num[begin];
    }
};


int main() {
    vector<int> num {4,5,6,7,0,1,2};
    //vector<int> num {1,2};
    //vector<int> num {2,1};
    cout << "The array:" << endl;
    for (int i = 0; i < num.size(); ++i)
        cout << num[i] << " ";
    cout << endl;
    Solution sol;
    int minVal = sol.findMin(num);
    cout << "The minimum element is: " << minVal << endl;
}
