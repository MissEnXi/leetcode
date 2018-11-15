/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>
using namespace std;

// Time Limit Exceeded
/* class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i + 1; j < nums.size(); ++j) {
                res += hammingDistance(nums[i], nums[j]);
            }
        }
        return res;
    }

    int hammingDistance(int m, int n) {
        int k = m ^ n;
        int res = 0;
        while(k > 0) {
            if((k & 1) == 1) {
                res++;
            }
            k = k >> 1;
        }
        cout << "m:" << m << "n:" << n << "res:" << res << endl;
        return res;
    }
}; */

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int bit = 0; bit < 32; bit++) {
            int numOneBit = 0;
            for (int i = 0; i < n; i++)
                numOneBit += (nums[i] >> bit) & 1;
            ans += numOneBit * (n - numOneBit);
        }
        return ans;
    }
};

int main() {
    vector<int> a{4, 14, 2, 1};

    Solution s;
    cout << s.totalHammingDistance(a) << endl;
    return 0;
}