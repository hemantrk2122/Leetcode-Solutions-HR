class Solution {
    private boolean bfs(int[][] graph, int src, int[] vis){
        LinkedList<Integer> q = new LinkedList<>();
        q.add(src);
        int color = 0;
        while(q.size()>0){
            System.out.println(color);
            System.out.println(q);
            int size = q.size();
            while(size-->0){
                int node = q.removeFirst();
                if(vis[node]!=-1){
                    if (vis[node] != color)return false;
                }
                vis[node] = color;
                for(int nbr: graph[node]){
                    if(vis[nbr] == -1){
                        q.addLast(nbr);
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