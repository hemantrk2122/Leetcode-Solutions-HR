class Solution {
    private boolean bfs(int[][] graph, int src, int[] vis){
        LinkedList<Integer> que = new LinkedList<>();
        que.add(src);
        
        int color = 0;
        
        while(que.size()>0){
            int size = que.size();
            
            while(size-->0){
                int t = que.removeFirst();
                
                if(vis[t]!=-1){
                    if(vis[t]!=color)return false;
                }
                vis[t] = color;
                
                for(int nbr:graph[t]){
                    if(vis[nbr]==-1){
                        que.addLast(nbr);
                    }
                }
            }
            color = (color+1)%2;
        }
        return true;
    }
    public boolean isBipartite(int[][] graph) {
        int vtces = graph.length;
        
        int[] vis = new int[vtces];
        Arrays.fill(vis,-1);
        
        for(int i =0;i<vtces;i++){
            if(vis[i]==-1){
                boolean even = bfs(graph,i,vis);
                if(even == false)return false;
            }
        }
        return true;
    }
}