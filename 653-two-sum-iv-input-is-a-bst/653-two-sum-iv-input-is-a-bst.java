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
    ArrayList<Integer> arr = new ArrayList<>();
    public boolean findTarget(TreeNode root, int k) {
        inorder(root);
        int i = 0;
        int j = arr.size()-1;
        
        while(i<j){
            if(arr.get(i) + arr.get(j) == k)return true;
            else if(arr.get(i) + arr.get(j) < k)i++;
            else
                j--;
        }
        return false;
    }
    private void inorder(TreeNode node){
        if(node == null)return;
        
        inorder(node.left);
        arr.add(node.val);
        inorder(node.right);
    }
}