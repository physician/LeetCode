/*
 Author:     physician
 Date:       Jun 23, 2014
 Update:     Jun 23, 2014
 Problem:    Insert Interval
 Difficulty: Medium
 Source:     http://oj.leetcode.com/problems/insert-interval/

 Problem Description:
 Insert Interval: 

 Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

 You may assume that the intervals were initially sorted according to their start times.

 Example 1:
 Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

 Example 2:
 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

 This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

 Notes:
 1. First implementation, natural solution. Time complexity O(N).
 2. vector.erase() method is O(N) operation in the worst case.
 3. Compile using g++: g++ InsertInterval.cpp -o InsertInterval.
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

using namespace std;
 
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// Use erase method, insert interval in place, but Time Limit Exceeded. Time complexity O(N^2).
/*
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval>::iterator iter = intervals.begin();
        while(iter != intervals.end()) {
            if (newInterval.end < iter->start) {
                intervals.insert(iter, newInterval);
                return intervals;
            }
            else if (newInterval.start > iter->end)
                iter++;
            else {
                newInterval.start = min(iter->start, newInterval.start);
                newInterval.end = max(iter->end, newInterval.end);
                iter = intervals.erase(iter);
            }
        }
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }
};
*/

// Insert into new vector without erase. Time complexity O(N).
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval>::iterator iter = intervals.begin();
        vector<Interval> result;
        bool inserted = false;
        while(iter != intervals.end()) {
            if (!inserted && newInterval.end < iter->start) {
                result.push_back(newInterval);
                result.push_back(*iter);
                inserted = true;
            }
            else if (inserted || iter->end < newInterval.start)
                result.push_back(*iter);
            else {
                newInterval.start = min(iter->start, newInterval.start);
                newInterval.end = max(iter->end, newInterval.end);
            }
            iter++;
        }
        if (!inserted)
            result.push_back(newInterval);
        return result;
    }
};


int main() {
    vector<Interval> vec1, vec2;
    vec1.push_back(Interval(1,3));
    vec1.push_back(Interval(6,9));
    vec2.push_back(Interval(1,2));
    vec2.push_back(Interval(3,5));
    vec2.push_back(Interval(6,7));
    vec2.push_back(Interval(8,10));
    vec2.push_back(Interval(12,16));
    Interval newInterval1 = Interval(2,5);
    Interval newInterval2 = Interval(4,9);
    cout << "Example 1: before insersion:" << endl;
    for (int i = 0; i < vec1.size(); ++i)
        cout << "[" << vec1[i].start << "," << vec1[i].end << "] ";
    cout << endl;
    Solution sol;
    vec1 = sol.insert(vec1, newInterval1);
    cout << "Example 1: after insersion new interval [" << newInterval1.start << "," << newInterval1.end << "]" << endl;
    for (int i = 0; i < vec1.size(); ++i)
        cout << "[" << vec1[i].start << "," << vec1[i].end << "] ";
    cout << endl;
    cout << "Example 2: before insersion:" << endl;
    for (int i = 0; i < vec2.size(); ++i)
        cout << "[" << vec2[i].start << "," << vec2[i].end << "] ";
    cout << endl;
    vec2 = sol.insert(vec2, newInterval2);
    cout << "Example 2: after insersion new interval [" << newInterval2.start << "," << newInterval2.end << "]" << endl;
    for (int i = 0; i < vec2.size(); ++i)
        cout << "[" << vec2[i].start << "," << vec2[i].end << "] ";
    cout << endl;
}
