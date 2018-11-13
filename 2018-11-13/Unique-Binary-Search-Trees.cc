/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int* s = new int[n+1]();
        s[0] = 1;
        s[1] = 1;
        for(int i = 2; i <= n; ++i) {
            // s[i] = 0;
            for(int j = 1; j <= i; ++j) {
                s[i] += s[j-1] * s[i-j];
            }
        }
        return s[n];
    }
};

int main() {
    Solution s;
    cout << s.numTrees(3) << endl;
    return 0;
}