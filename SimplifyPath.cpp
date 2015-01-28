/*
 Author:     physician
 Date:       Jan 27, 2015
 Update:     Jan 27, 2015
 Problem:    Simplify Path
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/simplify-path/

 Problem Description:
 Simplify Path: 

 Given an absolute path for a file (Unix-style), simplify it.

 For example,
 path = "/home/", => "/home"
 path = "/a/./b/../../c/", => "/c"

 Corner Cases:
 Did you consider the case where path = "/../"?
 In this case, you should return "/".
 Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 In this case, you should ignore redundant slashes and return "/home/foo".

 Notes:
 1. First implementation, stack. Use vector to implement a stack. 
 2. Add an additional '/' to the end of 'path' for simpler detection of the end.
 3. Compile using g++: g++ -std=c++0x SimplifyPath.cpp -o SimplifyPath.
*/

# include <iostream>
# include <string>
# include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string outPath;
        vector<string> pathVec;
        string dir;
        path += "/";
        for (auto c : path)
            if (c == '/') {
                if (dir.size() != 0) {
                    if (dir == "..") {
                        if (pathVec.empty())
                            pathVec.push_back("/");
                        else
                            pathVec.pop_back();
                    }
                    else if (dir != ".")
                        pathVec.push_back(dir);
                    dir = "";
                }
            }
            else
                dir += c;
        if (pathVec.empty() || pathVec.size() == 1 && pathVec[0] == "/")
            outPath = "/";
        else {
            while (pathVec[0] == "/")
                pathVec.erase(pathVec.begin()); 
            for (auto i : pathVec)
                outPath += "/" + i;
        }
        return outPath;
    }
};

int main() {
    //string inputPath = "/home/";
    //string inputPath = "/a/./b/../../c/";
    //string inputPath = "/../";
    //string inputPath = "/home//foo/";
    //string inputPath = "/";
    //string inputPath = "/...";
    //string inputPath = "/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///";
    //string inputPath = "///eHx/..";
    string inputPath = "/..";
    Solution sol;
    cout << "Input path = " << inputPath << endl;
    cout << "Output path = " << sol.simplifyPath(inputPath) << endl;
}
