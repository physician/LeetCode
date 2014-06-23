/*
 Author:     physician
 Date:       Jun 23, 2014
 Update:     Jun 23, 2014
 Problem:    Merge Intervals
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/merge-intervals/

 Problem Description:
 Merge Intervals: 

 Given a collection of intervals, merge all overlapping intervals.

 For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18].

 Notes:
 1. First implementation, natural solution. Time complexity O(N).
 2. Compile using g++: g++ MergeIntervals.cpp -o MergeIntervals.
*/


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;
 
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool IntervalLessThan (Interval a, Interval b) {
    return a.start < b.start;
}

// pop, merge and push
/*
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() <= 1) 
            return intervals;
        sort(intervals.begin(), intervals.end(), IntervalLessThan);
        vector<Interval> result;
        vector<Interval>::iterator iter = intervals.begin();
        result.push_back(*iter++);
        Interval intvl;
        while (iter != intervals.end()) {
            if (result.back().end < iter->start)
                result.push_back(*iter);
            else {
                intvl.start = min(iter->start, result.back().start);
                intvl.end = max(iter->end, result.back().end);
                result.pop_back();
                result.push_back(intvl);
            }
            iter++;
        }
        return result;
    }
};
*/


// merge and push
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() <= 1) 
            return intervals;
        sort(intervals.begin(), intervals.end(), IntervalLessThan);
        vector<Interval> result;
        vector<Interval>::iterator iter = intervals.begin();
        Interval intvl = *iter++;
        while (iter != intervals.end()) {
            if (intvl.end < iter->start) {
                result.push_back(intvl);
                intvl = *iter;
            }
            else
                intvl.end = max(iter->end, intvl.end);
            iter++;
        }
        result.push_back(intvl);
        return result;
    }
};


int main() {
    vector<Interval> vec;
    vec.push_back(Interval(1,3));
    vec.push_back(Interval(2,6));
    vec.push_back(Interval(8,10));
    vec.push_back(Interval(15,18));
    
    cout << "Before merging:" << endl;
    for (int i = 0; i < vec.size(); ++i)
        cout << "[" << vec[i].start << "," << vec[i].end << "] ";
    cout << endl;
    Solution sol;
    vec = sol.merge(vec);
    cout << "After merging:" << endl;
    for (int i = 0; i < vec.size(); ++i)
        cout << "[" << vec[i].start << "," << vec[i].end << "] ";
    cout << endl;
}
