/*
 Author:     physician
 Date:       Aug 18, 2013
 Update:     Feb 08, 2014
 Problem:    Two Sum
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/two-sum/

 Problem Description:
 Two Sum: 

 Given an array of integers, find two numbers such that they add up to a specific target number.

 The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

 You may assume that each input would have exactly one solution.

 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2

 Notes:
 1. First implementation, unordered_map.
 2. Be careful when handling duplicates.
 3. Compile using g++: g++ -std=c++0x TwoSum.cpp -o TwoSum.
*/

# include <iostream>
# include <vector>
# include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int N = numbers.size();
        unordered_map<int, int> map;
        vector<int> result;
        for(int i = 0; i < N; ++i)
            map[numbers[i]] = i+1;
        for(int i = 0; i < N; ++i) {
            int num = target-numbers[i];
            if(map.find(num) != map.end() && i+1 != map[num]) {
                result.push_back(i+1);
                result.push_back(map[num]);
                if (result[0] > result[1])
                    swap(result[0], result[1]);
                break;
            }
        }
        return result;
    }
};

int main() {
    //int input[] = {2, 7, 11, 15};
    int input[] = {0, 3, 4, 0};
    vector<int> numbers (input, input + sizeof(input) / sizeof(int));
    int target = 0;
    Solution sol;
    vector<int> solVec = sol.twoSum(numbers, target);
    for (int i = 0; i < solVec.size(); i++)
        cout << "index" << (i+1) << " = " << solVec[i] << endl; 
}
