/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:
Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.

Example 2:
Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.

Example 3:
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int pos = 0;
        while(pos + 1 < prices.size()) {
            if(prices[pos] < prices[pos+1]) {
                int temp = pos+2;
                while(temp < prices.size() && prices[temp-1] <= prices[temp])
                    temp++;
                res += prices[temp-1] - prices[pos];
                pos = temp;
            }
            else pos++;
        }
        return res;
    }
};

/* class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ret = 0;
        for (size_t p = 1; p < prices.size(); ++p) 
            ret += max(prices[p] - prices[p - 1], 0);    
        return ret;
    }
}; */

int main() {
    vector<int> prices{7,1,5,3,6,4};
    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;
}