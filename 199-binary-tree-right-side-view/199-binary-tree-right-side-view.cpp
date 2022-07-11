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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>nodes;
        solve(root,nodes,0);
        return nodes;
    }
    void solve(TreeNode* root, vector<int>&nodes, int level){
        if(!root)return;
        if(nodes.size()==level)nodes.push_back(root->val);
        solve(root->right,nodes,level+1);
        solve(root->left,nodes,level+1);
        
    }
};