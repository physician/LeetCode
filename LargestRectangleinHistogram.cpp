/*
 Author:     physician
 Date:       Jun 15, 2014
 Update:     Jun 15, 2014
 Problem:    Largest Rectangle in Histogram
 Difficulty: Hard
 Source:     https://oj.leetcode.com/problems/largest-rectangle-in-histogram/

 Problem Description:
 Largest Rectangle in Histogram:

 Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

 Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

 The largest rectangle is shown in the shaded area, which has area = 10 unit.

 For example,
 Given height = [2,1,5,6,2,3],
 return 10. 

 Notes:
 1. First implementation, use stack. Time O(n), space O(n). Each element will be pushed into and poped out of the stack at most once.
 2. Algorithm: Maintain a non-decreasing stack of height, store their indices.
    Analysis refer to: 
    http://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html 
 3. Compile using g++: g++ LargestRectangleinHistogram.cpp -o LargestRectangleinHistogram.
*/


# include <iostream>
# include <vector>
# include <stack>

using namespace std;

/*
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        stack<int> stk;
        int maxArea = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (stk.empty() || height[i] >= height[stk.top()])
                stk.push(i);
            else {
                while (!stk.empty() && height[stk.top()] > height[i]) {
                    int index = stk.top();
                    stk.pop();
                    int width = stk.empty() ? i : i - stk.top() - 1;
                    maxArea = max(height[index] * width, maxArea);
                }
                stk.push(i);
            }
        }
        return maxArea;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        stack<int> stk;
        int maxArea = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (stk.empty() || height[i] >= height[stk.top()])
                stk.push(i);
            else {
                int index = stk.top();
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                maxArea = max(height[index] * width, maxArea);
                --i;
            }
        }
        return maxArea;
    }
};
*/

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        stack<int> stk;
        int maxArea = 0, i = 0;
        while (i < height.size()) {
            if (stk.empty() || height[i] >= height[stk.top()])
                stk.push(i++); 
            else { 
                int index = stk.top();
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                maxArea = max(height[index] * width, maxArea);
            }
        }
        return maxArea;
    }
};

int main() {
    int h[] = {2,1,5,6,2,3};
    //int h[] = {4,2,0,3,2,5};
    vector<int> height(h, h + sizeof(h)/sizeof(int));
    Solution sol;
    cout << "Height = [ ";
    for (int i = 0; i < height.size(); ++i)
        cout << height[i] << " ";
    cout << "]" << endl;
    cout << "The area of largest rectangle in the histogram is: " << sol.largestRectangleArea(height) << endl;
}
