/*
Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.

(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        int i = 1;
        while(i < str.length() && str[i - 1] <= str[i]) i++;
        while(i >0 && i < str.length() && str[i - 1] > str[i]) str[--i]--;
        for(int j = i + 1; j < str.length(); ++j) str[j] = '9';
        return stoi(str);
    }
};

int main() {
    Solution s;
    cout << s.monotoneIncreasingDigits(333222) << endl;
    return 0;
}