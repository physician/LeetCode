/*
 Author:     physician
 Date:       Jan 19, 2014
 Update:     Jan 19, 2014
 Problem:    Climbing Stairs
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/climbing-stairs/

 Problem Description:
 Climbing Stairs:

 You are climbing a stair case. It takes n steps to reach to the top.

 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 Notes:
 1. First implementation, DP.
 2. Compile using g++: g++ ClimbingStairs.cpp -o ClimbingStairs.
*/


# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
            return n;
        else {
            vector<int> stairs;
            stairs.push_back(1);
            stairs.push_back(2);
            for(int i = 2; i < n; ++i)
                stairs.push_back(stairs[i-1] + stairs[i-2]);
            return stairs[n-1];  
        }      
    }
};

int main() {
    int n = 10;
    Solution sol;
    cout << "There are " << sol.climbStairs(n) << " distinct ways you can climb to the top of the stairs with " << n << " steps." << endl;
}
