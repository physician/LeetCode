/*
 Author:     physician
 Date:       Jan 20, 2015
 Update:     Jan 20, 2015
 Problem:    Find Peak Element
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/find-peak-element/

 Problem Description:
 Find Peak Element:

 A peak element is an element that is greater than its neighbors.

 Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

 The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

 You may imagine that num[-1] = num[n] = -∞.

 For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

 Note:
 Your solution should be in logarithmic complexity.

 Notes:
 1. First implementation, binary search. Time complexity O(log(N)).
 2. Compile using g++: g++ -std=c++0x FindPeakElement.cpp -o FindPeakElement.
*/


# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        return findPeakElement1(num);
    }

    int findPeakElement1(const vector<int> &num) {
        return findPeakElementHelper(num, 0, num.size());
    }

    int findPeakElementHelper(const vector<int> &num, int begin, int end) {
        if (end - begin == 1)
            return begin;
        int mid = (begin + end)/2;
        if (num[mid] > num[mid-1] && num[mid] > num[mid+1])
            return mid;
        else if (num[mid-1] > num[mid])
            return findPeakElementHelper(num, begin, mid);
        else
            return findPeakElementHelper(num, mid, end);
    }

    int findPeakElement2(const vector<int> &num) {
        int begin = 0;
        int end = num.size();
        while (begin < end) {
            if (end - begin == 1)
                return begin;
            int mid = (begin + end)/2;
            if (num[mid] > num[mid-1] && num[mid] > num[mid+1])
                return mid;
            else if (num[mid-1] > num[mid])
                end = mid;
            else
                begin = mid;
        }
    }
};

int main() {
    vector<int> num {2, 0, 3, 4, 1};
    Solution sol;
    int id = sol.findPeakElement(num);
    cout << "The peak value is: " << num[id] << ", the index is: " << id << endl;
}
