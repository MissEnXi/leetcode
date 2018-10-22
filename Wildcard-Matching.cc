/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
*/

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

/* class Solution {
public:
    bool isMatch(string s, string p) {
        bool **match = new bool*[s.length()+1];
        for(int i = 0; i < s.length()+1; ++i) {
            match[i] = new bool[p.length()+1];
        }

        match[s.length()][p.length()]=true;
        for(int i=p.length()-1; i >= 0; i--){
            if(p[i]!='*')
                break;
            else
                match[s.length()][i]=true;
        }
        for(int i=s.length()-1;i>=0;i--){
            for(int j=p.length()-1;j>=0;j--){
                if(s[i]==p[j]||p[j]=='?')
                        match[i][j]=match[i+1][j+1];
                else if(p[j]=='*')
                        match[i][j]=match[i+1][j]||match[i][j+1];
                else
                    match[i][j]=false;
            }
        }
        return match[0][0];
    }
}; */

/* class Solution {
public:
    bool isMatch(string s, string p) { 
        int m = s.length(), n = p.length();
        vector<bool> cur(m + 1, false); 
        cur[0] = true;
        for (int j = 1; j <= n; j++) {
            bool pre = cur[0]; // use the value before update
            cur[0] = cur[0] && p[j - 1] == '*'; 
            for (int i = 1; i <= m; i++) {
                bool temp = cur[i]; // record the value before update
                if (p[j - 1] != '*')
                    cur[i] = pre && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
                else cur[i] = cur[i - 1] || cur[i];
                pre = temp;
            }
        }
        return cur[m]; 
    }
}; */



class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        int i = 0, j = 0, asterisk = -1, match;
        while (i < m) {
            if (j < n && p[j] == '*') {
                match = i; 
                asterisk = j++;
            }
            else if (j < n && (s[i] == p[j] || p[j] == '?')) {
                i++; 
                j++;
            }
            else if (asterisk >= 0) {
                i = ++match;
                j = asterisk + 1;
            }
            else return false;
        }
        while (j < n && p[j] == '*') j++;
        return j == n;
    }
};

int main() {
    Solution s;
    cout << s.isMatch("abcd", "a*d") << endl;
    return 0;
}