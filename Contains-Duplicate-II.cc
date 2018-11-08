/*
Given an array of integers and an integer k, 
find out whether there are two distinct indices i and j in the array 
such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            map<int, int>::iterator iter;
            iter = m.find(nums[i]);
            if (iter != m.end()) {
                // cout << m[n] << endl;
                if(abs(m[nums[i]] - i) <= k)
                    return true;
            }
            m[nums[i]] = i;
            // m.insert(pair<int, int>(nums[i], i));
            cout << "nums[i]: " << nums[i] << "i: " << i << endl;
        }
        return false;
    }
};

int main() {
    vector<int> nums{1,0,1,1};
    // cout << nums.size() << endl;
    Solution s;
    cout << s.containsNearbyDuplicate(nums, 1) << endl;
    return 0;
}