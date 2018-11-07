/*
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

Example:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]
*/

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

/* class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int> >& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0, j = 0;
        vector<int> res;
        res.push_back(matrix[0][0]);
        while(i <= row && j <= col) {
            // get new i, j
            if(j-1 >= 0) {
                if(i+1<row) {
                    i++;
                    j--;
                }
                else {
                    if(j+row<col) {
                        j++;
                        i = 0;
                    }
                    else {
                        j = col - 1;
                        if(i+1<row)
                            i++;
                        else i = row - 1;
                    }
                }
            }
            else {
                if(i+1<col) {
                    j = i + 1;
                    i = 0;
                }
                else {
                    j = col - 1;
                    i = i - col + 2;
                }
                
            }
            cout << i << " " << j << " " << matrix[i][j] << endl;
            res.push_back(matrix[i][j]);
            if(i == row - 1 && j == col - 1) {
                break;
            }
        }
        return res;
    }
}; */

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m, n, L, R; vector<int> res;
        if ((m = matrix.size()) && (n = matrix[0].size()))
            for (int i=0; L=max(i-m+1,0), R=min(n-1,i), i<m+n-1; ++i)
                if (i%2) for (int j = R; j >= L; --j) res.push_back(matrix[i-j][j]);
                else     for (int j = L; j <= R; ++j) res.push_back(matrix[i-j][j]);

        return res;
    }
};

int main() {
    /* vector<int> a1;
    a1.push_back(1);
    a1.push_back(2);
    a1.push_back(3);

    vector<int> a2;
    a1.push_back(4);
    a1.push_back(5);
    a1.push_back(6);

    vector<int> a3;
    a1.push_back(7);
    a1.push_back(8);
    a1.push_back(9);

    vector<vector<int>> a;
    a.push_back(a1);
    a.push_back(a2);
    a.push_back(a3); */

    vector<vector<int> > a(3, vector<int>(3, 0));
    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[1][0] = 4;
    a[1][1] = 5;
    a[1][2] = 6;
    a[2][0] = 7;
    a[2][1] = 8;
    a[2][2] = 9;

    Solution s;
    vector<int> v = s.findDiagonalOrder(a);
    // copy (v.begin(), v.end(), ostream_iterator<int> (cout, " "));
    return 0;
}