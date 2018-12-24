/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]] 
Explanation: The first 3 pairs are returned from the sequence: 
             [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [1,1],[1,1]
Explanation: The first 2 pairs are returned from the sequence: 
             [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

Example 3:

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [1,3],[2,3]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <queue>
using namespace std;

/* class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int i = 0, j = 0;
        vector<pair<int, int>> res;
        while(i < nums1.size() && j < nums2.size()) {
            if(res.size() >= k) return res;
            res.push_back(make_pair(nums1[i], nums2[j]));

            if(i+1 >= nums1.size() && j+1 >= nums2.size()) return res;
            if(i+1 >= nums1.size()) {
                j++;
            } else if(j+1 >= nums2.size()) {
                i++;
            } else if((nums1[i+1] + nums2[j]) < (nums1[i] + nums2[j+1])) {
                i++;
            } else if((nums1[i+1] + nums2[j]) == (nums1[i] + nums2[j+1])){
                res.push_back(make_pair(nums1[i+1], nums2[j]));
                j++;
            }
        }
        return res;
    }
}; */

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0)
            return result;
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);
        min_heap.emplace(0, 0);
        while(k-- > 0 && min_heap.size())
        {
            auto idx_pair = min_heap.top(); min_heap.pop();
            result.emplace_back(nums1[idx_pair.first], nums2[idx_pair.second]);
            if (idx_pair.first + 1 < nums1.size())
                min_heap.emplace(idx_pair.first + 1, idx_pair.second);
            if (idx_pair.first == 0 && idx_pair.second + 1 < nums2.size())
                min_heap.emplace(idx_pair.first, idx_pair.second + 1);
        }
        return result;
    }
};

int main() {
   
    Solution s;
    vector<int> A{1,1,2};
    vector<int> B{1,2,3};
    vector<pair<int, int>> res = s.kSmallestPairs(A, B, 10);
    for(auto item : res) {
        cout << item.first << " " << item.second << endl;
    }
    return 0;
}