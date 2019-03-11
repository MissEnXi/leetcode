/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        vector<vector<int>> path(m, vector<int> (n, 0));

        for(int i = 0; i < m; ++i) {
            if(obstacleGrid[i][0] != 1) {
                path[i][0] = 1;
            } else {
                break;
            }
        }

        for(int j = 0; j < n; ++j) {
            if(obstacleGrid[0][j] != 1) {
                path[0][j] = 1;
            } else {
                break;
            }
        }

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    path[i][j] = 0;
                } else {
                    path[i][j] = path[i - 1][j] + path[i][j - 1];
                }
            }
        return path[m - 1][n - 1];
    }
};

/* class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][1] = 1;
        for(int i = 1 ; i <= m ; ++i)
            for(int j = 1 ; j <= n ; ++j)
                if(!obstacleGrid[i-1][j-1])
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
        return dp[m][n];
    }
}; */

/* class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> cur(m, 0);
        for (int i = 0; i < m; i++) {
            if (!obstacleGrid[i][0])
                cur[i] = 1;
            else break;
        }
        for (int j = 1; j < n; j++) {
            bool flag = false;
            if (obstacleGrid[0][j])
                cur[0] = 0;
            else flag = true;
            for (int i = 1; i < m; i++) {
                if (!obstacleGrid[i][j]) {
                    cur[i] += cur[i - 1]; 
                    if (cur[i]) flag = true;
                }
                else cur[i] = 0; 
            }
            if (!flag) return 0;
        }
        return cur[m - 1];
    }
}; */

int main() {
    vector<vector<int>> obstacleGrid(7, vector<int> (5, 0));
    obstacleGrid[3][0] = 1;
    obstacleGrid[0][4] = 1;

    Solution s;
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
}