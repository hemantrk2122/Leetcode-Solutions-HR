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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newNode=new TreeNode(val);
            newNode->left=root;
            return  newNode;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        depth-=1;
        while(q.empty()==false and --depth){
          int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                  if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
              }
            }
            
        }
        
        while(q.empty()==false){
            TreeNode* temp=q.front();
            q.pop();
            TreeNode* temp1=temp->left;
            TreeNode* temp2=temp->right;
            
            TreeNode* node1=new TreeNode(val);
            node1->left=temp1;
            temp->left=node1;
            
            TreeNode* node2=new TreeNode(val);
            node2->right=temp2;
            temp->right=node2;
        }
        
        return root;
    }
};