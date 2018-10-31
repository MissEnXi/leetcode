/*
You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.

Example:
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2
Explanation: 
The five points are show in the figure below. The red triangle is the largest.
*/

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res = 0;
        for (auto &i : points)
            for (auto &j : points)
                for (auto &k : points)
            res = max(res, 0.5 * abs(i[0] * j[1] + j[0] * k[1] + k[0] * i[1]- j[0] * i[1] - k[0] * j[1] - i[0] * k[1]));
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> points(5, vector<int>(2, 0));
    points[0][0] = 0;
    points[0][1] = 0;
    points[1][0] = 1;
    points[1][1] = 0;
    points[2][0] = 0;
    points[2][1] = 1;
    points[3][0] = 2;
    points[3][1] = 0;
    points[4][0] = 0;
    points[4][1] = 2;
    cout << s.largestTriangleArea(points) << endl;
    return 0;
}