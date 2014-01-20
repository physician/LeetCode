/*
 Author:     physician
 Date:       Jan 20, 2014
 Update:     Jan 20, 2014
 Problem:    Best Time to Buy and Sell Stock
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/

 Problem Description:
 Best Time to Buy and Sell Stock:

 Say you have an array for which the ith element is the price of a given stock on day i.

 If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

 Notes:
 1. First implementation, DP.
 2. Compile using g++: g++ BestTimetoBuyandSellStock.cpp -o BestTimetoBuyandSellStock.
*/


# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxProf = 0;
        if(prices.size() != 0){
            int lowestPriceSoFar = prices[0];
            for (int i = 1; i < prices.size(); ++i) {
                if(prices[i] < lowestPriceSoFar)
                    lowestPriceSoFar = prices[i];
                maxProf = max(maxProf, prices[i] - lowestPriceSoFar);
            }
        }
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
