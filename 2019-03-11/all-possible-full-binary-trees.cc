/*
A full binary tree is a binary tree where each node has exactly 0 or 2 children.

Return a list of all possible full binary trees with N nodes.  
Each element of the answer is the root node of one possible tree.

Each node of each tree in the answer must have node.val = 0.

You may return the final list of trees in any order.
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    map<int, vector<TreeNode*>> memo;
    vector<TreeNode*> allPossibleFBT(int N) {
        if(memo.find(N) == memo.end()) {
            vector<TreeNode*> ans;
            if(N == 1) ans.push_back(new TreeNode(0));
            else if(N % 2 == 1) {
                for(int x = 0; x < N; ++x) {
                    int y = N - 1 - x;
                    for(TreeNode* left : allPossibleFBT(x))
                        for(TreeNode* right : allPossibleFBT(y)) {
                            TreeNode* bns = new TreeNode(0);
                            bns->left = left;
                            bns->right = right;
                            ans.push_back(bns);
                        }
                }
            }
            memo[N] = ans;
        }
        return memo[N];
    }
};