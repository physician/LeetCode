/*
 Author:     physician
 Date:       Aug 28, 2013
 Update:     Aug 28, 2013
 Problem:    Container With Most Water
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_11

 Problem Description:
 Container With Most Water: 

 Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

 Note: You may not slant the container.

 Notes:
 1. First implementation, two pointers, greedy algorithm.
 2. Complexity O(N).
 3. Compile using g++: g++ ContainerWithMostWater.cpp -o ContainerWithMostWater.
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0;
        int j = height.size()-1;
        int area = 0;
        while(i < j) {
            area = max(area, (j-i) * min(height[i], height[j]));
            if (height[i] <= height[j])
                i++;
            else
                j--;
        }
        return area;
    }
};

int main() {
    int input[] = {1, 5, 3, 4};
    vector<int> height (input, input + sizeof(input) / sizeof(int));
    Solution sol;
    cout << "The maximum area is: " << sol.maxArea(height) << endl;
}
