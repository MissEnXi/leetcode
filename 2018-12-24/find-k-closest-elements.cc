/*
Given a sorted array, two integers k and x, find the k closest elements to x in the array. 
The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]

Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104

UPDATE (2017/9/19):
The arr parameter had been changed to an array of integers (instead of a list of integers). 
Please reload the code definition to get the latest changes.
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <queue>
using namespace std;

// 错误，理解题意错了.
/* class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int pos = 0;
        int len = arr.size();
        vector<int> res;

        for(; pos < len; ++pos) {
            if(arr[pos] > x) break;
        }
        // pos -= 1;

        if(pos >= k) {
            int begin = pos - k;
            for(int i = begin; i <= pos-1; ++i) {
                res.push_back(arr[i]);
            }
        } else {
            for(int i = 0; i < pos; ++i) {
                res.push_back(arr[i]);
            }
            for(int i = pos; i < k; ++i) {
                res.push_back(arr[i]);
            }
        }
        return res;
    }
}; */

// 可行，但时间太长
/* class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int pos = 0;
        int len = arr.size();
        vector<int> res;

        

        for(; pos < len; ++pos) {
            if(arr[pos] > x) break;
        }
        pos--;

        vector<int> sub;
        for(int i = 0; i < len; ++i) {
            sub.push_back(abs(arr[i] - x));
        }
        cout << endl;
        int num = 0;
        int left = pos;
        int right = pos+1;
        while(num < k) {
            if(right >= len) {
                res.push_back(arr[left]);
                num++;
                left--;
            } else if(left < 0) {
                res.push_back(arr[right]);
                num++;
                right++;
            } else if(sub[left] <= sub[right]) {
                res.push_back(arr[left]);
                num++;
                left--;
            } else if(sub[left] > sub[right]) {
                res.push_back(arr[right]);
                num++;
                right++;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
}; */

class Solution {
public:
    vector<int> findClosestElements(vector<int>& A, int k, int x) {
        int left = 0, right = A.size() - k;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x - A[mid] > A[mid + k] - x)
                left = mid + 1;
            else
                right = mid;
        }
        return vector<int>(A.begin() + left, A.begin() + left + k);
    }
};

int main() {
    vector<int> a{1,2,3,4,5};
    Solution s;
    vector<int> res = s.findClosestElements(a, 4, -1);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}