/*
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

Example 1:
Input: 5
Output: True
Explanation:
The binary representation of 5 is: 101

Example 2:
Input: 7
Output: False
Explanation:
The binary representation of 7 is: 111.
*/

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int flag = n % 2;
        n = n / 2;
        while(n > 0) {
            if(n % 2 == flag) return false;
            flag = n % 2;
            n /= 2;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.hasAlternatingBits(7) << endl;
    return 0;
}