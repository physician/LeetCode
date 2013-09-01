/*
 Author:     physician
 Date:       Aug 21, 2013
 Update:     Sep 01, 2013
 Problem:    3Sum
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_15

 Problem Description:
 3Sum: 

 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

 Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a <= b <= c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)


 Notes:
 1. First implementation, convert to 2Sum, use two pointers to solve 2Sum.
 2. Sort the input vector first, avoiding duplicates will be easier and more efficient.
 3. The overall complexity is O(N^2).
 4. Compile using g++: g++ 3Sum.cpp -o 3Sum.
*/

# include <iostream>
# include <vector>
//# include <list>
# include <algorithm>
//# include <cmath>
//# include <set>
//# include <map>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); ++i) {
            int twoSum = -num[i];
            int l = i + 1;
            int r = num.size() - 1;
            while (l < r) {
                if (num[l] + num[r] < twoSum)
                    ++l;
                else if (num[l] + num[r] > twoSum)
                    --r;
                else {
                    vector<int> triplet;
                    triplet.push_back(num[i]);
                    triplet.push_back(num[l]);
                    triplet.push_back(num[r]);
                    result.push_back(triplet);
                    // avoid duplicates
                    while((l < r) && num[l+1] == num[l])
                        ++l;
                    // avoid duplicates
                    while((l < r) && num[r-1] == num[r])
                        --r;
                    ++l;
                    --r;
                }
                // avoid duplicates
                while(num[i+1] == num[i])
                    ++i;
            }
        }
        return result;
   }
};


int main() {
//    int input[] = {-1, 0, 1, 2, -1, -4};
//    int input[] = {5,-11,-7,-2,4,9,4,4,-5,12,12,-14,-5,3,-3,-2,-6,3,3,-9,4,-13,6,2,11,12,10,-14,-15,11,0,5,8,0,10,-11,-6,-1,0,4,-4,-3,5,-2,-15,9,11,-13,-2,-8,-7,9,-6,7,-11,12,4,14,6,-4,3,-9,-14,-12,-2,3,-8,7,-13,7,-12,-9,11,0,4,12,-6,-7,14,-1,0,14,-6,1,6,-2,-9,-4,-11,12,-1,-1,10,-7,-6,-7,11,1,-15,6,-15,-12,12,12,3,1,9,12,9,0,-11,-14,-1};
    int input[] = {-4,-8,7,13,10,1,-14,-13,0,8,6,-13,-5,-4,-12,2,-11,7,-5,0,-9,-14,-8,-9,2,-7,-13,-3,13,9,-14,-6,8,1,14,-5,-13,8,-10,-5,1,11,-11,3,14,-8,-10,-12,6,-8,-5,13,-15,2,11,-5,10,6,-1,1,0,0,2,-7,8,-6,3,3,-13,8,5,-5,-3,9,5,-4,-14,11,-8,7,10,-6,-3,11,12,-14,-9,-1,7,5,-15,14,12,-5,-8,-2,4,2,-14,-2,-12,6,8,0,0,-2,3,-7,-14,2,7,12,12,12,0,9,13,-2,-15,-3,10,-14,-4,7,-12,3,-10};
    vector<int> num (input, input + sizeof(input) / sizeof(int));
    Solution sol;
    vector< vector<int> > solVec = sol.threeSum(num);
    for (int i = 0; i < solVec.size(); i++) {
        cout << "(" << solVec[i][0];
        for (int j = 1; j < solVec[i].size(); j++) {
            cout << ", " << solVec[i][j];
        }
        cout << ")" << endl;
    } 
}
