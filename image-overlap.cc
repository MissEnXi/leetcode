/*
Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?

Example 1:

Input: A = [[1,1,0],
            [0,1,0],
            [0,1,0]]
       B = [[0,0,0],
            [0,1,1],
            [0,0,1]]
Output: 3
Explanation: We slide A to right by 1 unit and down by 1 unit.
Notes: 

1 <= A.length = A[0].length = B.length = B[0].length <= 30
0 <= A[i][j], B[i][j] <= 1
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        //record the coordinate of all the '1' in A
        //record the coordinate of all the '1' in B
        vector<pair<int,int>> A1;
        vector<pair<int,int>> B1;
        for(int r=0;r<A.size();r++)
            for(int c=0;c<A[0].size();c++){
                if(A[r][c]==1)  A1.push_back(pair<int,int>(r,c));
                if(B[r][c]==1)  B1.push_back(pair<int,int>(r,c));
            }
        

        //Step1: For all '1' in A, find all the movements which we can get score from it.
        unordered_map<int, int> ht;
        for(auto ca:A1){
            for(auto cb:B1){
                int hashkey=(ca.first-cb.first)*100
                    +(ca.second-cb.second);
                ht[hashkey]++;
            }
        }
        
        //Step 2: For all movements found in step1, find the one who scores most. Return the score.
        int ans=0;
        for(auto it:ht){
            ans = max(ans,it.second);            
        }
        
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> A{{0,1,0}, {0,0,0}, {0,0,0}};
    vector<vector<int>> B{{0,0,0}, {1,0,0}, {0,0,0}};

    cout << s.largestOverlap(A, B) << endl;
    return 0;
}