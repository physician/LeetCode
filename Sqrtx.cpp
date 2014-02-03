/*
 Author:     physician
 Date:       Feb 02, 2014
 Update:     Feb 02, 2014
 Problem:    Sqrt(x)
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/sqrtx/

 Problem Description:
 Sqrt(x):

 Implement int sqrt(int x).

 Compute and return the square root of x.

 Notes:
 1. First implementation, Newton's method. Time complexity O(log(x)).
 2. Compile using g++: g++ Sqrtx.cpp -o Sqrtx.
*/


# include <iostream>
//# include <stdlib.h>    // abs(int)
# include <cmath>       // abs(float)

using namespace std;

class Solution {
public:
    int sqrt(int x) {
        double xold = 0.0;
        double xnew = 1.0;
        while (abs(xnew-xold) > 0.01) {
            xold = xnew;
            xnew = (xold + x/xold)/2.0;
        }
        return int(xnew);
    }
};


int main() {
    int x = 10;
    Solution sol;
    cout << "The int sqrare root of " << x << " is: " << sol.sqrt(x) << endl;
}
