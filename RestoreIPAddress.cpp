/*
 Author:     physician
 Date:       Mar 07, 2014
 Update:     Mar 07, 2014
 Problem:    Restore IP Addresses
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/restore-ip-addresses/

 Problem Description:
 Restore IP Addresses: 

 Given a string containing only digits, restore it by returning all possible valid IP address combinations.

 For example:
 Given "25525511135",

 return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

 Notes:
 1. First implementation, recursion. DFS.
 2. Compile using g++: g++ RestoreIPAddress.cpp -o RestoreIPAddress.
*/

# include <iostream>
# include <vector>
# include <string>
# include <sstream>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if (s.size() >= 4 && s.size() <= 12) {
            string path;
            dfs1(s, 0, path, result, 4);
        }
        return result;
    }

private:
    void dfs(string s, int begin, string &path, vector<string> &result, int termsLeft) {
        if (begin >= s.size()) {
            if (termsLeft == 0 && path.size() == s.size() + 4) {
                result.push_back(path.substr(0, path.size()-1));
            }
            return;
        }
        if(begin <= s.size()-1) {
            path += s.substr(begin, 1);
            path.push_back('.');
            dfs(s, begin+1, path, result, termsLeft-1);
            path.erase(path.size()-2, 2);
        }
        if(begin <= s.size()-2) {
            int val;
            istringstream iss;
            stringstream ss;
            iss.str(s.substr(begin, 2));
            iss >> val;
            ss << val;
            path += ss.str();
            path.push_back('.');
            dfs(s, begin+2, path, result, termsLeft-1);
            path.erase(path.size()-ss.str().size()-1, ss.str().size()+1);
        }
        if (begin <= s.size()-3) {
            int val;
            istringstream iss;
            stringstream ss;
            iss.str(s.substr(begin, 3));
            iss >> val;
            if (val <= 255) {
                ss << val;
                path += ss.str();
                path.push_back('.');
                dfs(s, begin+3, path, result, termsLeft-1);
                path.erase(path.size()-ss.str().size()-1, ss.str().size()+1);
            }
        }
    }

    void dfs1(string s, int begin, string &path, vector<string> &result, int termsLeft) {
        if (begin == s.size() || termsLeft == 0) {
            if (begin == s.size() && termsLeft == 0)
                result.push_back(path);
            return;
        }
        int num = 0;
        int initLength = path.size();
        if (path.size() != 0)
            path.push_back('.');
        for (int i = begin; i < s.size(); ++i) {
            num = 10 * num + s[i] - '0';
            if (num > 255)
                break;
            path.push_back(s[i]);
            dfs1(s, i+1, path, result, termsLeft-1);
            if (num == 0)
                break;
        }
        path.resize(initLength);
    }
};

int main() {
    //string s = "25525511135";
    string s = "010010";

    cout << "Input string is: \"" << s << "\"." << endl;
    Solution sol;
    cout << "All possible valid IP address combinations are:" << endl;
    vector<string> solVec = sol.restoreIpAddresses(s);
    cout << "[" << endl;;
    for (int i = 0; i < solVec.size(); ++i) {
        cout << "  " << solVec[i] << endl;
    }
    cout << "]" << endl;
}
