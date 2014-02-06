/*
 Author:     physician
 Date:       Feb 05, 2013
 Update:     Feb 05, 2014
 Problem:    Candy
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/candy/

 Problem Description:
 Candy: 

 There are N children standing in a line. Each child is assigned a rating value.

 You are giving candies to these children subjected to the following requirements:

 Each child must have at least one candy.
 Children with a higher rating get more candies than their neighbors.
 What is the minimum candies you must give?

 Notes:
 1. First implementation, time O(N), space O(1).
 2. Second implementation, time O(N), space O(N).
 3. Symmetry. Walk through the vector in both directions to get O(N) complexity.
 4. Compile using g++: g++ Candy.cpp -o Candy.
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int currentCandy = 1, totalCandy = 1, maxIndex = 0, maxCandy = 1;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] >= ratings[i-1]) {
                currentCandy = (ratings[i] == ratings[i-1] ? 1 : currentCandy+1);
                maxIndex = i;
                maxCandy = currentCandy;
            }
            else {
                if (currentCandy == 1) {
                    if (maxCandy > i-maxIndex)
                        totalCandy += (i - maxIndex - 1);
                    else
                        totalCandy += (i - maxIndex);
                }
                if (currentCandy > 1)
                    currentCandy = 1;
            }
            totalCandy += currentCandy;
        }
        return totalCandy;
    }

    int candy2(vector<int> &ratings) {
        int N = ratings.size();
        int totalCandy = 0;
        vector<int> candys(N, 1);
        for (int i = 1; i < N; ++i)
            if (ratings[i] > ratings[i-1])
                candys[i] = candys[i-1] + 1;
        for (int i = N-2; i >= 0; --i)
            if (ratings[i] > ratings[i+1] && candys[i] <= candys[i+1])
                candys[i] = candys[i+1] + 1;
        for (int i = 0; i < N; ++i)
            totalCandy += candys[i];
        return totalCandy;
    }
};

int main() {
    //int A[] = {2,3,1,1,4};
    //int A[] = {4,2,3,4,1};
    //int A[] = {4,1,5,5,6,4,3,2,2,6};
    int A[] = {1,2,2};
    //int A[] = {2,2,1};
    //int A[] = {1,2,4,4,3};
    vector<int> ratings(A, A + sizeof(A)/sizeof(int));
    cout << "The ratings vector is:" << endl;
    for (int i = 0; i < ratings.size(); i++)
        cout << ratings[i] << " ";
    cout << endl;
    Solution sol;
    int numOfCandy = sol.candy(ratings);
    cout << "The minimum candies you must give is: " << numOfCandy << endl;
}
