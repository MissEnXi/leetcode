/*
Given a square array of integers A, we want the minimum sum of a falling path through A.

A falling path starts at any element in the first row, and chooses one element from each row.  
The next row's choice must be in a column that is different from the previous row's column by at most one.

 

Example 1:
Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: 12
Explanation: 
The possible falling paths are:
[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
The falling path with the smallest sum is [1,4,7], so the answer is 12.

*/


#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>
using namespace std;

/* class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        // cout << res << endl;
        vector<int> lll;
        for(int i = 0; i < A.size(); ++i)
            DFS(A, lll, 0, i);
        return res;
    }
    int res = INT_MAX;
    void DFS(vector<vector<int>>& A, vector<int> &lll, int r, int c) {
        int row = A.size();
        if(r >= row || c >= row) return;
        if(r < 0 || c < 0) return;
        if(r == row-1) {
            int sum = 0;
            for(int i = 0; i < row - 1; ++i) {
                sum += lll[i];
            }
            sum += A[r][c];
            if(res > sum) res = sum;
            return;
        }
        lll.push_back(A[r][c]);
        DFS(A, lll, r+1, c-1);
        DFS(A, lll, r+1, c);
        DFS(A, lll, r+1, c+1);
        lll.pop_back();
        return;
    }
}; */

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        for (auto i = 1; i < A.size(); ++i)
            for (auto j = 0; j < A.size(); ++j)
                A[i][j] += min({ A[i-1][j], A[i-1][max(0,j-1)], A[i-1][min((int)A.size()-1,j+1)] });
        return *min_element(begin(A[A.size() - 1]), end(A[A.size() - 1]));
    }
};

int main() {
   
    Solution s;
    vector<vector<int>> A{{1,2,3},{4,5,6},{7,8,9}};
    cout << s.minFallingPathSum(A) << endl;
    return 0;
}