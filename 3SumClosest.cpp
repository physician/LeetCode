/*
 Author:     physician
 Date:       Sep 02, 2013
 Update:     Sep 02, 2013
 Problem:    3Sum Closest
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_16

 Problem Description:
 3Sum Closest: 

 Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


 Notes:
 1. First implementation, similar to 2Sum, use two pointers.
 2. Sort the input vector first, O(NlogN).
 3. The overall complexity is O(N^2).
 4. Compile using g++: g++ 3SumClosest.cpp -o 3SumClosest.
*/

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdlib.h>
# include <climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int closest = INT_MAX;
        if (num.size() <= 3) {
            closest = 0;
            for (int i = 0; i < num.size(); ++i)
                closest += num[i];
            return closest;
        }
        sort(num.begin(), num.end());
        int curMin = INT_MAX;
        int sum = 0;
        for (int i = 0; i < num.size()-2; ++i) {
            int l = i + 1;
            int r = num.size() - 1;
            while (l < r) {
                sum = num[i] + num[l] + num[r];
                if (abs(sum - target) < curMin) {
                    curMin = abs(sum - target);
                    closest = sum;
                }
                if (sum < target)
                    ++l;
                else if (sum > target)
                    --r;
                else
                    return target;
            }
        }
        return closest;
   }
};


int main() {
    int target = -275;
    //int input[] = {-1, 2, 1, -4};
    //int input[] = {1, 1, 1, 1};
    int input[] = {87,6,-100,-19,10,-8,-58,56,14,-1,-42,-45,-17,10,20,-4,13,-17,0,11,-44,65,74,-48,30,-91,13,-53,76,-69,-19,-69,16,78,-56,27,41,67,-79,-2,30,-13,-60,39,95,64,-12,45,-52,45,-44,73,97,100,-19,-16,-26,58,-61,53,70,1,-83,11,-35,-7,61,30,17,98,29,52,75,-73,-73,-23,-75,91,3,-57,91,50,42,74,-7,62,17,-91,55,94,-21,-36,73,19,-61,-82,73,1,-10,-40,11,54,-81,20,40,-29,96,89,57,10,-16,-34,-56,69,76,49,76,82,80,58,-47,12,17,77,-75,-24,11,-45,60,65,55,-89,49,-19,4};
    vector<int> num (input, input + sizeof(input) / sizeof(int));
    Solution sol;
    int closest = sol.threeSumClosest(num, target);
    cout << "The closest 3Sum to target " << target << " is: " << closest << endl;
}
