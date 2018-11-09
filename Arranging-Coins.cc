/*
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <math.h>
using namespace std;

/* class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        while(n - i >= 0) {
            n = n - i;
            i++;
        }
        return i - 1;
    }
}; */

class Solution {
public:
    int arrangeCoins(int n) {
        return int((sqrt(8.0 * n + 1)-1)/2);
    }
};

int main() {
    Solution s;
    cout << s.arrangeCoins(8) << endl;
    return 0;
}