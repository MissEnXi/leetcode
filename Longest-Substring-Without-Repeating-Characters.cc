/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 

Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /* int lengthOfLongestSubstring(string s) {
        vector<char> res;
        int length = 0;
        for(auto byte : s) {
            cout << "for:" << byte << endl;
            printVector(res);
            vector<char>::iterator it=res.begin();
            for(;it!=res.end();++it) {
                if(*it == byte) {
                    break;
                }
            }
            if(it!=res.end()) {
                ++it;
                res.erase(res.begin(), it);
            }
            
            res.push_back(byte);
            
            if(length < res.size())
                length = res.size();
            printVector(res);
        }
        return length;
    } */

    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
    
    void printVector(vector<char> a) {
        for(int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("aabaabcbb") << endl;
    return 0;
}
