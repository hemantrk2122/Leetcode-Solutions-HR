/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        if(root == null){
            List<List<Integer>> bs = new ArrayList<>();
            return bs;
        }
            
        List<List<Integer>> ans = new ArrayList();
        
        LinkedList<Node> que = new LinkedList<>();
        que.add(root);
        
        while(que.size()>0){
            int size = que.size();
            List<Integer> level = new ArrayList<>();
            for(int i =0;i<size;i++){
                Node temp = que.removeFirst();
                level.add(temp.val);
                
                for(Node child:temp.children){
                    que.addLast(child);
                }
            }
            ans.add(level);
        }
        return ans;
    }
}