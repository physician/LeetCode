/*
 Author:     physician
 Date:       Jan 19, 2015
 Update:     Jan 19, 2015
 Problem:    Dungeon Game
 Difficulty: Hard
 Source:     https://oj.leetcode.com/problems/dungeon-game/

 Problem Description:
 Dungeon Game: 

 The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

 The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

 Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

 In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


 Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

 For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

 -2(K)  -3    3
  -5   -10    1
  10    30  -5(P)

 Notes:

 The knight's health has no upper bound.
 Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

 Notes:
 1. First implementation, DP.
 2. Compile using g++: g++ -std=c++0x DungeonGame.cpp -o DungeonGame.
*/

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int M = dungeon.size();
        int N = dungeon[0].size();
        int dp[M][N];
        dp[M-1][N-1] = (dungeon[M-1][N-1] >= 0) ? 1 : (1 - dungeon[M-1][N-1]);
        for (int i = M-2; i >= 0; --i)
            dp[i][N-1] = getHPHelper(dungeon[i][N-1], dp[i+1][N-1]);
        for (int j = N-2; j >= 0; --j)
            dp[M-1][j] = getHPHelper(dungeon[M-1][j], dp[M-1][j+1]);
        for (int i = M-2; i >= 0; --i) 
            for (int j = N-2; j >= 0; --j) 
                dp[i][j] = min(getHPHelper(dungeon[i][j], dp[i+1][j]), 
                               getHPHelper(dungeon[i][j], dp[i][j+1]));
        return dp[0][0];
    }

private:
    int getHPHelper(int curVal, int nextHP) {
        int hp = 0;
        if (curVal >= 0)
            hp = (nextHP - curVal > 0) ? (nextHP - curVal) : 1;
        else
            hp = nextHP - curVal;
        return hp;
    }
};


int main() {
    vector<vector<int> > dungeon { {-2, -3,  3},
                                   {-5, -10, 1},
                                   {10, 30, -5} };
    cout << "The dungeon is:" << endl;
    for (int i = 0; i < dungeon.size(); ++i) {
        cout << "[ ";
        for (int j = 0; j < dungeon[0].size(); ++j)
            cout << dungeon[i][j] << " ";
        cout << "]" << endl;
    }
    Solution sol;
    int initHP = sol.calculateMinimumHP(dungeon);
    cout << "The initial health of the knight must be at least: " << initHP << endl;
}
