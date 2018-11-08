/*
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true

Example 2:

Input: [1,2,3,4]
Output: false

Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> m;
        for(auto n : nums) {
            map<int, bool>::iterator iter;
            iter = m.find(n);
            if (iter != m.end()) {
                // cout << m[n] << endl;
                return true;
            }
            m.insert(pair<int, bool>(n, true));
        }
        return false;
    }
};

int main() {
    vector<int> nums{1,2,3};
    // cout << nums.size() << endl;
    Solution s;
    cout << s.containsDuplicate(nums) << endl;
    return 0;
}