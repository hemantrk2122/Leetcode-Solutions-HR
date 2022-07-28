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
/*
Vertical distance = 0
For Depth = 0 
1 

Vertical distance = -1
For Depth = -1 
2 
For Depth = 0 
1 

Vertical distance = -2
For Depth = -2 
4 
For Depth = -1 
2 
For Depth = 0 
1 

Vertical distance = 0
For Depth = -2 
4 
For Depth = -1 
2 
For Depth = 0 
1 6 

Vertical distance = 1
For Depth = -2 
4 
For Depth = -1 
2 
For Depth = 0 
1 6 
For Depth = 1 
3 

Vertical distance = 0
For Depth = -2 
4 
For Depth = -1 
2 
For Depth = 0 
1 6 5 
For Depth = 1 
3 

Vertical distance = 2
For Depth = -2 
4 
For Depth = -1 
2 
For Depth = 0 
1 6 5 
For Depth = 1 
3 
For Depth = 2 
7 
*/
class Solution {
public:
    void make_map(TreeNode *node, int d,int l, map<int,vector<pair<int,int>>>&mp){
        if(node == NULL)return;
        mp[d].push_back(make_pair(l,node->val));
        make_map(node->left,d-1,l+1,mp);
        make_map(node->right,d+1,l+1,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>mp;
        make_map(root,0,0,mp);
        vector<vector<int>>ans;
        for(auto el:mp){
             sort(el.second.begin(),el.second.end());
            vector<int>tmp;
            for(int i=0; i< el.second.size(); i++){
                tmp.push_back(el.second[i].second);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};