/*
Given a string containing only digits, 
restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>
using namespace std;

/* class Solution {
public:
    vector<string> res;

    vector<string> restoreIpAddresses(string s) {
        
        int length = s.size();
        if(length < 4 || length > 12)
            return res;
        
        vector<int> sub;
        func(s, 4, sub);

        return res;
    }

    void func(string s, int num, vector<int> sub) {
        int length = s.size();
        if(length < num || length > num*3)
            return;
        if(num == 1) {
            if(s[0] == '0' && length > 1)
                return;

            int subIP = atoi(s.c_str());
            if(subIP <= 255) {
                sub.push_back(subIP);
                intToString(sub);
                sub.pop_back();
            }
            return;
        }
        for(int i = 0; i < 3 && i < length; ++i) {
            string subStr = s.substr(0, i+1);
            if(subStr[0] == '0' && subStr.length() > 1)
                continue;

            int subIP = atoi(subStr.c_str());
            
            if(subIP <= 255) {
                sub.push_back(subIP);
                func(s.substr(i+1, length-i-1), num-1, sub);
                sub.pop_back();
            }
        }
    }

    void intToString(vector<int> sub) {
        if(sub.size() != 4) return;
        res.push_back(to_string(sub[0]) + "." + to_string(sub[1]) + "." + to_string(sub[2]) + "." + to_string(sub[3]));
    }
}; */

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        string ans;
        
        for (int a=1; a<=3; a++)
        for (int b=1; b<=3; b++)
        for (int c=1; c<=3; c++)
        for (int d=1; d<=3; d++)
            if (a+b+c+d == s.length()) {
                int A = stoi(s.substr(0, a));
                int B = stoi(s.substr(a, b));
                int C = stoi(s.substr(a+b, c));
                int D = stoi(s.substr(a+b+c, d));
                if (A<=255 && B<=255 && C<=255 && D<=255)
                    if ( (ans=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D)).length() == s.length()+3)
                        ret.push_back(ans);
            }    
        
        return ret;
    }
};

int main() {
    Solution s;
    vector<string> res = s.restoreIpAddresses("010010");
    for(string s : res) {
        cout << s << endl;
    }
    return 0;
}