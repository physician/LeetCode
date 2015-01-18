/*
 Author:     physician
 Date:       Jan 18, 2015
 Update:     Jan 18, 2015
 Problem:    Majority Element
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/majority-element/

 Problem Description:
 Majority Element:

 Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

 You may assume that the array is non-empty and the majority element always exist in the array.

 Notes:
 1. First implementation, Moore voting algorithm. Time O(N), space O(1).
 2. Compile using g++: g++ -std=c++0x MajorityElement.cpp -o MajorityElement.
*/


# include <iostream>
# include <vector>
# include <unordered_map>

using namespace std;

class Solution {

public:
    // Moore voting algorithm (works when majority exists and occurrence > n/2)
    int majorityElement(vector<int> &num) {
        int major, count = 0;
        for(int number : num) {
            if(count == 0) {
                major = number;
                count++;
            }
            else if(major == number)
                count++;
            else
                count--;
        }
        return major;    
    }

    int majorityElement1(vector<int> &num) {
        unordered_map<int, int> count;
        int major, cnt = 0;
        for(int number : num) {
            if(count.find(number) != count.end())
                count[number]++;
            else
                count[number] = 1;
        }
        for(auto kv : count)
            if (kv.second > cnt) {
                major = kv.first;
                cnt = kv.second;
            }
        return major;
    }
};


int main() {
    int arr[9] = {1,1,2,0,1,0,1,2,1};
    vector<int> num (arr, arr + sizeof(arr) / sizeof(arr[0]));
    Solution sol;
    cout << "The majority element is: " << sol.majorityElement(num) << endl;
}
