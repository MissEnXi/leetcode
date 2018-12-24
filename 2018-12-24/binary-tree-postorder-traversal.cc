/*
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <stack>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
/* class Solution {
public:
    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return res;
        DFS(root);
        return res;
    }
    void DFS(TreeNode* node) {
        if(node->left == NULL && node -> right == NULL) {
            res.push_back(node->val);
            return;
        }
        if(node->left != NULL) DFS(node->left);
        if(node->right != NULL) DFS(node->right);
        res.push_back(node->val);
    }
}; */

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;
        TreeNode* cur = root;
        TreeNode* last = NULL;
        while (cur || !todo.empty()) {
            if (cur) {
                todo.push(cur);
                cur = cur -> left;
            } else {
                TreeNode* top = todo.top();
                if (top -> right && (last != top -> right)) {
                    cur = top -> right;
                } else {
                    nodes.push_back(top -> val);
                    last = top;
                    todo.pop();
                }
            }
        }
        return nodes;
    }
};