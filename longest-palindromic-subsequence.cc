/*
Given a string s, find the longest palindromic subsequence's length in s. 
You may assume that the maximum length of s is 1000.

Example 1:
Input:
"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".

Example 2:
Input:
"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <queue>
using namespace std;

/* class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len));

        for(int i = len - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for(int j = i+1; j < len; ++j) {
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][len-1];
    }
}; */

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size(), res = 0;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            int len = 0;
            for (int j = i - 1; j >= 0; j--) {
                int tmp = dp[j];
                if (s[j] == s[i]) {
                    dp[j] = len + 2;
                }
                len = max(len, tmp);
            }
        }
        for (auto i : dp)
            res = max(res, i);
        return res;
    }
};

int main() {
    Solution s;
    cout << s.longestPalindromeSubseq("bbbcb");
    return 0;
}