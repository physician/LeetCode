/*
 Author:     physician
 Date:       Aug 18, 2013
 Update:     Aug 18, 2013
 Problem:    Two Sum
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_1

 Problem Description:
 Two Sum: 

 Given an array of integers, find two numbers such that they add up to a specific target number.

 The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

 You may assume that each input would have exactly one solution.

 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2

 Notes:
 1. The implementation uses unordered_map to construct hash table.
 2. Use unordered_map.find() for lookup to avoid unintended insertion.
 3. The hash function is simply to mod the number against the predefined hash size, here it's set to be HASHSIZE = 10000.
 4. Compile using g++: g++ -std=c++0x TwoSum.cpp -o TwoSum
*/

# include <iostream>
# include <vector>
# include <list>
# include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {    	
        vector<int> result;
        int HASHSIZE = 10000;
        typedef unordered_map< int, list<tuple> > hashTable;
        hashTable HT;
        for(int i = 0; i < numbers.size(); i++) {
            tuple newNum;
            newNum.index = i + 1;
            newNum.value = numbers[i];
            HT[(numbers[i]) % HASHSIZE].push_front(newNum);
        }
        int i = 0;
        bool found = false;
        while (!found && i < numbers.size()) {
            int num1 = numbers[i];
            int num1Index = i + 1;
            int num2 = target - num1;
            int num2Index = 0;
            hashTable::const_iterator it = HT.find(num2 % HASHSIZE);
            if (it != HT.end()) {
                for(list<tuple>::const_iterator iter = HT[num2 % HASHSIZE].begin(); iter != HT[num2 % HASHSIZE].end(); iter++) {
                    if(iter->value == num2) {
                        num2Index = iter->index;
                        result.push_back(num1Index < num2Index ? num1Index : num2Index);
                        result.push_back(num1Index > num2Index ? num1Index : num2Index);
                        found = true;
                        break;
                    }
                }
            }
            i++;
        }
        return result;
    }

private:
    struct tuple {
        int index;
        int value;
    };
};

int main() {
    int input[] = {2, 7, 11, 15};
    vector<int> numbers (input, input + sizeof(input) / sizeof(int));
    int target = 9;
    Solution sol;
    vector<int> solVec = sol.twoSum(numbers, target);
    for (int i = 0; i < solVec.size(); i++)
        cout << "index" << (i+1) << " = " << solVec[i] << endl; 
}
