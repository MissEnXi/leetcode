/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4

Example 2:

Input: [0,1]
Output: 0
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) n &= (n - 1);
        return n;
    }
};

int main() {
    Solution s;
    cout << s.rangeBitwiseAnd(5, 7) << endl;
    return 0;
}