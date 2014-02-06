/*
 Author:     physician
 Date:       Feb 05, 2014
 Update:     Feb 05, 2014
 Problem:    Longest Consecutive Sequence
 Difficulty: Hard
 Source:     http://oj.leetcode.com/problems/longest-consecutive-sequence/

 Problem Description:
 Longest Consecutive Sequence:

 Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

 For example,
 Given [100, 4, 200, 1, 3, 2],
 The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

 Your algorithm should run in O(n) complexity.

 Notes:
 1. First implementation, unordered_set.
 2. HashSet(HashMap) searching is O(1) operation. Erase elements afterwards guaranteed O(n) overall complexity.
 3. Compile using g++: g++ -std=c++0x LongestConsecutiveSequence.cpp -o LongestConsecutiveSequence.
*/


# include <iostream>
# include <vector>
# include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> set;
        int result = 0;
        for(int i = 0; i < num.size(); ++i)
            set.insert(num[i]);
        for(int i = 0; i < num.size() && !set.empty(); ++i) {
            int upper = num[i];
            int lower = num[i];
            while(set.find(upper+1) != set.end())
                set.erase(++upper);
            while(set.find(lower-1) != set.end())
                set.erase(--lower);
            result = max(result, upper-lower+1);
        }
        return result;
    }
};

int main() {
    int A[] = {100,4,200,1,3,2};
    vector<int> num(A, A+sizeof(A)/sizeof(int));
    Solution sol;
    cout << "The longest consecutive sequence has length: " << sol.longestConsecutive(num) << endl;
}
