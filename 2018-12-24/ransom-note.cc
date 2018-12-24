/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, 
write a function that will return true if the ransom note can be constructed from the magazines ; 
otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <queue>
#include <unordered_map>
using namespace std;

/* class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> arr(26);
        for(char i : magazine)
            arr[i-'a']++;

        for(char i : ransomNote) {
            if(--arr[i-'a'] < 0)
                return false;
        }
        return true;
    }
}; */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map(26);
        for (int i = 0; i < magazine.size(); ++i)
            ++map[magazine[i]];
        for (int j = 0; j < ransomNote.size(); ++j)
            if (--map[ransomNote[j]] < 0)
                return false;
        return true;
    }
};

int main() {
    Solution s;
    cout << s.canConstruct("aa", "aba") << endl;
    return 0;
}