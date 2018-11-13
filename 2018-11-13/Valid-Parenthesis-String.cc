/*
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].
*/

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

/* class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        if (n == 0) return true;
        vector<vector<bool>> res(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') res[i][i] = true;
            if (i < n-1 &&
                    (s[i] == '(' || s[i] == '*') &&
                    (s[i+1] == ')' || s[i+1] == '*')) {
                res[i][i+1] = true;
            }
        }

        for (int size = 2; size < n; size++) {
            for (int i = 0; i + size < n; i++) {
                if (s[i] == '*' && res[i+1][i+size] == true) {
                    res[i][i+size] = true;
                } else if (s[i] == '(' || s[i] == '*') {
                    for (int k = i+1; k <= i+size; k++) {
                        if ((s[k] == ')' || s[k] == '*') &&
                                (k == i+1 || res[i+1][k-1]) &&
                                (k == i+size || res[k+1][i+size])) {
                            res[i][i+size] = true;
                        }
                    }
                }
            }
        }
        return res[0][n-1];
    }
}; */

class Solution {
public:
    bool checkValidString(string s) {
       int lo = 0, hi = 0;
       for (auto c: s) {
           lo += c == '(' ? 1 : -1;
           hi += c != ')' ? 1 : -1;
           if (hi < 0) break;
           lo = max(lo, 0);
       }
       return lo == 0;
    }
};

int main() {
    Solution s;
    cout << s.checkValidString("(*())") << endl;
    return 0;
}

