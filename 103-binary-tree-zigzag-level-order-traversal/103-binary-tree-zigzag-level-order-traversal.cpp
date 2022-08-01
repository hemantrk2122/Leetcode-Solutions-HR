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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        int sidha = 1;
        while(!q.empty()){
            int size = q.size();
            vector<int>temp;
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
            }
            if(sidha){
                ans.push_back(temp);
                sidha = 0;
            }
                
            else{
                reverse(temp.begin(),temp.end());
                sidha = 1;
                ans.push_back(temp);
            }
                
        }
        return ans;
    }
};