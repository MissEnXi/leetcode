/*
Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Example 1:
Input: 
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
Explanation: 
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
The second John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Note:

The length of accounts will be in the range [1, 1000].
The length of accounts[i] will be in the range [1, 10].
The length of accounts[i][j] will be in the range [1, 30].
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>
using namespace std;

class Solution {
    int find(vector<int> &union_find, int ind) {
        while(union_find[ind] != ind)
            ind = union_find[ind];
        return ind;
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> m;
        vector<int> union_find(accounts.size(), 0);
        unordered_map<int, vector<string>> res_map;
        for (int i = 0; i < accounts.size(); i++) {
            union_find[i] = i;
            for (int j = 1; j < accounts[i].size(); j++) {
                if (m.find(accounts[i][j]) != m.end()) {
                    int root1 = find(union_find, i);
                    int root2 = find(union_find, m[accounts[i][j]]);
                    union_find[root1] = root2;
                }
                else
                    m[accounts[i][j]] = union_find[i];
            }
        }
        for (auto it : m) {
            int ind = find(union_find, it.second);
            res_map[ind].push_back(it.first);
        }
        vector<vector<string>> res;
        for (auto it : res_map) {
            vector<string> email = it.second;
            sort(email.begin(), email.end());
            email.insert(email.begin(), accounts[it.first][0]);
            res.push_back(email);
        }
        return res;
    }
};