/*
 Author:     physician
 Date:       Feb 11, 2015
 Update:     Feb 11, 2015
 Problem:    Maximum Gap
 Difficulty: Hard
 Source:     https://oj.leetcode.com/problems/maximum-gap/

 Problem Description:
 Maximum Gap: 

 Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

 Try to solve it in linear time/space.

 Return 0 if the array contains less than 2 elements.

 You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

 Notes:
 1. First implementation, bucket sort.
 2. Compile using g++: g++ -std=c++0x MaximumGap.cpp -o MaximumGap.
*/

# include <iostream>
# include <climits>
# include <vector>
# include <utility>
# include <algorithm>  // min_element, max_element

using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.size() < 2)
            return 0;
        int minVal = *min_element(num.begin(), num.end());
        int maxVal = *max_element(num.begin(), num.end());
        if (minVal == maxVal)
            return 0;
        int bucketLen = (maxVal-minVal-1)/(num.size()-1) + 1;
        int N = (maxVal-minVal)/bucketLen + 1;
        vector<pair<int, int>> bucketMinMax (N, make_pair(INT_MAX, INT_MIN));
        for (int i : num) {
            int index = (i-minVal)/bucketLen;
            bucketMinMax[index].first = min(i, bucketMinMax[index].first);
            bucketMinMax[index].second = max(i, bucketMinMax[index].second);
        }
        int maxGap = 0, prev_max = maxVal;
        for (int i = 0; i < N; ++i) {
            if (bucketMinMax[i].first == INT_MAX)
                continue;
            maxGap = max(bucketMinMax[i].first - prev_max, maxGap);
            prev_max = bucketMinMax[i].second;
        }
        return maxGap;
    }
};

int main() {
    vector<int> num {1,0,6,9,8};
    //vector<int> num {1,10000000};
    cout << "The unsorted array is:" << endl;
    for (int i : num)
        cout << i << " ";
    cout << endl;
    Solution sol;
    int maxGap = sol.maximumGap(num);
    cout << "The maximum gap is: " << maxGap << endl;
}
