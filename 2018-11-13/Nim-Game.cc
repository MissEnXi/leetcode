/*
You are playing the following Nim Game with your friend: 
There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. 
The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. 
Write a function to determine whether you can win the game given the number of stones in the heap.
*/

// 只有4的倍数时，后下的一方赢，其它情况下先下的赢，Curtis.

#include <iostream>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        n = n % 4;
        if(n == 0) return false;
        else return true;
};

int main() {
    Solution s;
    cout << s.canWinNim(3) << endl;
    return 0;
}