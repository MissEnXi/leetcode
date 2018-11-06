/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

/* class NumArray {
public:
    NumArray(vector<int> nums) {
        a = nums;
    }
    
    int sumRange(int i, int j) {
        int res = 0;
        for(int k = i; k <= j; ++k) {
            res += a[k];
        }
        return res;
    }

    int length() {
        return a.size();
    }
private:
    vector<int> a;
}; */

class NumArray {
public:
    NumArray(vector<int> nums) {
        vector<int> a(nums.size()+1, 0);
        for(int i = 0; i < nums.size(); ++i) {
            a[i+1] = a[i] + nums[i];
        }
        res = a;
    }
    
    int sumRange(int i, int j) {
        return res[j+1] - res[i];
    }

    int length() {
        return res.size();
    }
private:
    vector<int> res;
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

int main() {
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(-5);
    nums.push_back(2);
    nums.push_back(-1);
    NumArray obj(nums);
    // int param_1 = obj.sumRange(0, 2);
    cout << obj.length() << endl;
    cout << obj.sumRange(0, 2) << endl;
}