/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*>orgQ;
        queue<TreeNode*>clonQ;
        orgQ.push(original);
        orgQ.push(NULL);
        clonQ.push(cloned);
        clonQ.push(NULL);
        
        while(!orgQ.empty()){
            TreeNode *orgNode = orgQ.front();
            TreeNode *clonNode = clonQ.front();
            
            orgQ.pop();
            clonQ.pop();
            
            if(!orgNode){
                if(!orgQ.empty()){
                    orgQ.push(NULL);
                    clonQ.push(NULL);
                }
            }else{
                if(orgNode == target){
                    return clonNode;
                }else{
                    if(orgNode->left){
                        orgQ.push(orgNode->left);
                        clonQ.push(clonNode->left);
                    }
                    if(orgNode->right){
                        orgQ.push(orgNode->right);
                        clonQ.push(clonNode->right);
                    }
                }
            }
        }
        return NULL;
    }
};