/*
 Author:     physician
 Date:       Jan 26, 2014
 Update:     Jan 26, 2014
 Problem:    Gas Station
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/gas-station/

 Problem Description:
 Gas Station:

 There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

 You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

 Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

 Note:
 The solution is guaranteed to be unique.

 Notes:
 1. First implementation, natural solution. Time complexity O(N).
 2. Compile using g++: g++ GasStation.cpp -o GasStation.
*/


# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sumSoFar = 0, sumTotal = 0, index = 0;
        for(int i = 0; i < gas.size(); ++i) {
            sumSoFar += gas[i]-cost[i];
            sumTotal += gas[i]-cost[i];
            if (sumSoFar < 0) {
                sumSoFar = 0;
                index = i+1;
            }
        }
        return (sumTotal >= 0) ? index : -1;
    }
};

int main() {
    int A[5] = {2,0,3,4,1};
    vector<int> gas(A, A + sizeof(A)/sizeof(int));
    int B[5] = {3,1,1,2,1};
    vector<int> cost(B, B + sizeof(B)/sizeof(int));
    Solution sol;
    cout << "The starting gas station's index is: " << sol.canCompleteCircuit(gas, cost) << endl;
}
