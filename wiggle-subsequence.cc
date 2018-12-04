/*
A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. 
The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. 
In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, 
the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. 
A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, 
leaving the remaining elements in their original order.

Example 1:
Input: [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence.

Example 2:
Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Example 3:
Input: [1,2,3,4,5,6,7,8,9]
Output: 2

Follow up:
Can you do it in O(n) time?
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <queue>
#include <unordered_map>
using namespace std;

/* class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return len;
        vector<int>up(len);
        vector<int>down(len);

        for(int i = 1; i < len; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j]) up[i] = max(up[i], down[j]+1);
                else if(nums[i] < nums[j]) down[i] = max(down[i], up[j]+1);
            }
        }

        return 1+max(up[len-1], down[len-1]);
    }
}; */

/* class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return len;
        vector<int>up(len);
        vector<int>down(len);

        up[0] = 1;
        down[0] = 1;

        for(int i = 1; i < len; ++i) {
            if(nums[i] > nums[i-1]) {
                up[i] = down[i-1]+1;
                down[i]=down[i-1];
            } else if(nums[i] < nums[i-1]) {
                up[i] = up[i-1];
                down[i]=up[i-1]+1;
            } else {
                up[i] = up[i-1];
                down[i]=down[i-1];
            }
        }

        return max(up[len-1], down[len-1]);
    }
}; */

/* class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return len;

        int up = 1;
        int down = 1;

        for(int i = 1; i < len; ++i) {
            if(nums[i] > nums[i-1]) {
                up = down + 1;
            } else if(nums[i] < nums[i-1]) {
                down = up + 1;
            }
        }

        return max(up, down);
    }
}; */

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return len;

        int prevdiff = nums[1] - nums[0];
        int count = prevdiff != 0 ? 2 : 1;
        for (int i = 2; i < len; i++) {
            int diff = nums[i] - nums[i - 1];
            if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)) {
                count++;
                prevdiff = diff;
            }
        }
        return count;
    }
};