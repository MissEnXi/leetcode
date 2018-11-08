/*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) return ret;
        vector<int> temp;
        binaryTreePathsDFS(root, temp);
        for(auto item : ret) {
            cout << item << endl;
        }
        return ret;
    }

    void binaryTreePathsDFS(TreeNode* root, vector<int> &res) {
        if(root->left == NULL && root->right == NULL) {
            stringstream ss;
            for (auto val : res) {
                ss << val << "->";
            }
            ss << root->val;
            ret.push_back(ss.str());
            return;
        }
        res.push_back(root->val);
        if(root->left != NULL) {
            binaryTreePathsDFS(root->left, res);
        }
        if(root->right != NULL) {
            binaryTreePathsDFS(root->right, res);
        }
        res.pop_back();
    }
private:
    vector<string> ret;
};

int main() {
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t5(5);
    t2.right = &t5;
    t1.left = &t2;
    t1.right = &t3;
    Solution s;
    s.binaryTreePaths(&t1);
    return 0;
}