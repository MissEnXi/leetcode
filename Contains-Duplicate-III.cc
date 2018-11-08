/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true

Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true

Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <set>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(const std::vector<int>& nums, int k, int t) {
        if (k <= 0) {
            return false;
        }
        std::set<int64_t> slidingKWindow;
        for (size_t i = 0; i < nums.size(); i++) {
            if (i > k) {
                slidingKWindow.erase(nums[i - k - 1]);
            }
            auto it = slidingKWindow.lower_bound(static_cast<int64_t>(nums[i]) - static_cast<int64_t>(t));
            if (it != slidingKWindow.end()) {
                int64_t minDiff = std::abs(static_cast<int64_t>(*it) - static_cast<int64_t>(nums[i]));
                if (minDiff <= static_cast<int64_t>(t)) {
                    return true;
                }
            }
            slidingKWindow.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    vector<int> nums{1,5,9,1,5,9};
    // cout << nums.size() << endl;
    Solution s;
    cout << s.containsNearbyAlmostDuplicate(nums, 2, 3) << endl;
    return 0;
}