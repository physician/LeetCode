/*
 Author:     physician
 Date:       Feb 06, 2014
 Update:     Feb 06, 2014
 Problem:    Best Time to Buy and Sell Stock III
 Difficulty: Medium
 Source:     http://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

 Problem Description:
 Best Time to Buy and Sell Stock III:

 Say you have an array for which the ith element is the price of a given stock on day i.

 Design an algorithm to find the maximum profit. You may complete at most two transactions.

 Note:
 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

 Notes:
 1. First implementation, DP. Use symmetry, forward maximum drawup is equivalent to backward maximum drawdown.
 2. Compile using g++: g++ BestTimetoBuyandSellStockIII.cpp -o BestTimetoBuyandSellStockIII.
*/


# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int N = prices.size();
        if (N <= 1)
            return 0;
        vector<int> maxProfBefore(N, 0);
        int lowestBefore = prices[0];
        for(int i = 1; i < N; ++i) {
            lowestBefore = min(lowestBefore, prices[i]);
            maxProfBefore[i] = max(maxProfBefore[i-1], prices[i]-lowestBefore);
        }
        vector<int> maxProfAfter(N, 0);
        int highestAfter = prices[N-1];
        for(int i = N-2; i >= 0; --i) {
            highestAfter = max(highestAfter, prices[i]);
            maxProfAfter[i] = max(maxProfAfter[i+1], highestAfter-prices[i]);
        }
        int maxProf = 0;
        for(int i = 0; i < N; ++i) {
            maxProf = max(maxProf, maxProfBefore[i]+maxProfAfter[i]);
        }
        return maxProf;
    }


/*  ***** Time Limit Exceeded *****
    int maxProfit(vector<int> &prices) {
        int maxProf = 0;
        for(int i = 0; i < prices.size(); ++i)
            maxProf = max(maxProf, maxProfitSingleTransaction(prices, 0, i) + 
                            maxProfitSingleTransaction(prices, i, prices.size()));
        return maxProf;
    }

private:
    int maxProfitSingleTransaction(vector<int> &prices, int begin, int end) {
        int maxProf = 0;
        if (begin < end) {
            int lowestSoFar = prices[begin];
            for(int i = begin; i < end; ++i) {
                lowestSoFar = min(lowestSoFar, prices[i]);
                maxProf = max(maxProf, prices[i]-lowestSoFar);
            }
        }
        return maxProf;
    }
*/
};

int main() {
    int A[9] = {2,1,3,4,1,2,1,5,4};
    vector<int> prices(A, A + 9);
    //vector<int> prices;
    Solution sol;
    cout << "The maximum profit is: " << sol.maxProfit(prices) << endl;
}
