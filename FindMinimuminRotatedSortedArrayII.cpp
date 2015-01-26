/*
 Author:     physician
 Date:       Jan 26, 2015
 Update:     Jan 26, 2015
 Problem:    Find Minimum in Rotated Sorted Array II
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

 Problem Description:
 Find Minimum in Rotated Sorted Array II:

 Follow up for "Find Minimum in Rotated Sorted Array":
 What if duplicates are allowed?

 Would this affect the run-time complexity? How and why?

 Suppose a sorted array is rotated at some pivot unknown to you beforehand.

 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

 Find the minimum element.

 The array may contain duplicates.

 Notes:
 1. First implementation, binary search.
 2. Compile using g++: g++ -std=c++0x FindMinimuminRotatedSortedArrayII.cpp -o FindMinimuminRotatedSortedArrayII.
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
        if (num[mid] > num[begin])
            return findMinRe(num, mid+1, end);
        else if (num[mid] < num[begin])
            return findMinRe(num, begin, mid);
        else
            return min(findMinRe(num, begin, mid), findMinRe(num, mid+1, end));
    }

    int findMin2(vector<int> &num) {
        int begin = 0, end = num.size()-1;
        while (begin < end) {
            if (num[begin] < num[end])
                return num[begin];
            int mid = begin + (end-begin)/2;
            if (num[mid] > num[begin])
                begin = mid+1;
            else if (num[mid] < num[begin])
                end = mid;
            else {
                begin++;
                if (num[mid] == num[end]) end--;
            }
        }
        return num[begin];
    }

    int findMin3(vector<int> &num) {
        int minVal = num[0];
        for (int i = 1; i < num.size(); ++i)
            minVal = min(minVal, num[i]);
        return minVal;
    }
};


int main() {
    vector<int> num {2,2,0,0,1,1,1};
    //vector<int> num {3,1,3,3,3};
    //vector<int> num {3,3,3,1,3};
    //vector<int> num {4,5,6,7,0,1,2};
    cout << "The array:" << endl;
    for (int i = 0; i < num.size(); ++i)
        cout << num[i] << " ";
    cout << endl;
    Solution sol;
    int minVal = sol.findMin(num);
    cout << "The minimum element is: " << minVal << endl;
}
