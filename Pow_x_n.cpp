/*
 Author:     physician
 Date:       Aug 25, 2013
 Update:     Aug 25, 2013
 Problem:    Pow(x, n)
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_50

 Problem Description:
 Pow(x, n): 

 Implement pow(x, n).

 Notes:
 1. First implementation, recursion.
 2. Store intermediate value, avoid repetitive and unnecessary calculation.
 3. std::abs for integer types are found in <cstdlib>, not in <cmath>
 4. Compile using g++: g++ Pow_x_n.cpp -o Pow_x_n
*/

# include <iostream>
//# include <cmath>
# include <cstdlib>

using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        double result;
        if (n == 0)
            return 1.0;
        else {
            double half = pow(x, abs(n)/2);
            if (abs(n) % 2 == 0) {
                result = half * half;
            }
            else {
                result = x * half * half;
            }
        }
        if (n > 0)
            return result;
        else
            return 1.0/result;
    }
};


int main() {
    Solution sol;
    cout << "Pow(2, 4) = " << sol.pow(2.0,4) << endl;
}
