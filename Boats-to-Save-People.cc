/*
The i-th person has weight people[i], and each boat can carry a maximum weight of limit.

Each boat carries at most 2 people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.  (It is guaranteed each person can be carried by a boat.)

 

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
Example 2:

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
Example 3:

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
Note:

1 <= people.length <= 50000
1 <= people[i] <= limit <= 30000
*/

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

/* class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0;
        for(int i = 0; i < people.size(); i++) {
            if(people[i] == -1)
                continue;
            if (people[i] == limit) {
                res++;
                continue;
            }
            int pos = 0, temp = 0;
            for(int j = i + 1; j < people.size(); ++j) {
                if(people[i] + people[j] <= limit && people[i] + people[j] > temp) {
                    pos = j;
                    temp = people[i] + people[j];
                }
            }
            if(pos != 0) {
                people[pos] = -1;
            }
            res++;
        }
        return res;
    }
}; */

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int ans = 0;

        while (i <= j) {
            ans++;
            if (people[i] + people[j] <= limit)
                i++;
            j--;
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> res(4);
    res[0] = 3;
    res[1] = 4;
    res[2] = 1;
    res[3] = 2;
    cout << s.numRescueBoats(res, 5) << endl;
    return 0;
}