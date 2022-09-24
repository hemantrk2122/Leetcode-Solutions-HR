/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>paths;
        vector<int>curr;
        findPaths(root,targetSum,curr,paths);
        return paths;
    }
    void findPaths(TreeNode* root, int sum, vector<int>curr, vector<vector<int>>&paths){
        if(!root)return;
        curr.push_back(root->val);
        if(root->val == sum && !root->left && !root->right){
            paths.push_back(curr);
            return;
        }
        findPaths(root->left,sum-root->val,curr,paths);
        findPaths(root->right,sum-root->val,curr,paths);
    }
};