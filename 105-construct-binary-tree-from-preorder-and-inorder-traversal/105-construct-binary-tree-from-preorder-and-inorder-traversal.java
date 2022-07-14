/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        
       return build(preorder,0,preorder.length-1,inorder,0,inorder.length-1);
    }
    public TreeNode build(int[] preorder,int psi,int pei,int[] inorder,int isi,int iei){
        if(psi>pei)return null;
        if(isi == iei)return new TreeNode(inorder[isi]);
        
        TreeNode root = new TreeNode(preorder[psi]);
        
        int c = 0;
        int root_idx = isi;
        
        while(inorder[root_idx]!=root.val){
            root_idx++;
            c++;
        }
        root.left = build(preorder,psi+1,psi+c,inorder,isi,root_idx-1);
        root.right = build(preorder,psi+c+1,pei,inorder,root_idx+1,iei);
        return root;
    }
}