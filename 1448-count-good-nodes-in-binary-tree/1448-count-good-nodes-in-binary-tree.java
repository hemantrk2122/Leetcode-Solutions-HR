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
    public int goodNodes(TreeNode root) {
        return solve(root,-100001);
    }
    private int solve(TreeNode node,int ma){
        if(node == null)return 0;
        int res = node.val>=ma ? 1:0;
        
        res+=solve(node.left,Math.max(ma,node.val));
        res+=solve(node.right,Math.max(ma,node.val));
        
        return res;
    }
}