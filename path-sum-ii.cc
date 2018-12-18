/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL) return res;

        vector<int> list;
        DFS(root, sum, list);
        return res;
    }

    void DFS(TreeNode* root, int sum, vector<int> &list) {
        list.push_back(root->val);
        if(root->left == NULL && root->right == NULL) {
            int realSum = 0;
            for(int i : list) {
                realSum += i;
            }
            if(realSum == sum) {
                res.push_back(vector<int>(list));
            }
        }
        if(root->left != NULL)
            DFS(root->left, sum, list);
        if(root->right != NULL)
            DFS(root->right, sum, list);
        list.pop_back();
    }
};