/*
 Author:     physician
 Date:       Jan 26, 2014
 Update:     Jan 26, 2014
 Problem:    Best Time to Buy and Sell Stock II
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

 Problem Description:
 Best Time to Buy and Sell Stock II:

 Say you have an array for which the ith element is the price of a given stock on day i.

 Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

 Notes:
 1. First implementation, greedy algorithm.
 2. Compile using g++: g++ BestTimetoBuyandSellStockII.cpp -o BestTimetoBuyandSellStockII.
*/


# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxProf = 0;
        if(!prices.empty())
            for (int i = 0; i < prices.size()-1; ++i)
                maxProf += (prices[i+1]>prices[i]) ? (prices[i+1]-prices[i]) : 0;
        return maxProf;
    }
};

int main() {
    int A[9] = {2,1,3,4,1,2,1,5,4};
    vector<int> prices(A, A + 9);
    //vector<int> prices;
    Solution sol;
    cout << "The maximum profit is: " << sol.maxProfit(prices) << endl;
}
