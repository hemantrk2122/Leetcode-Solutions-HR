class Solution {
    private boolean dfs(int[][] graph, int src, int[]vis){
        vis[src] = 1;
        for(int nbr:graph[src]){
            if(vis[nbr] == 0){
                boolean cycle = dfs(graph,nbr,vis);
                if(cycle)return true;
            }
            if(vis[nbr] == 1){
                return true;
            }
        }
        vis[src] = 2;
        return false;
    }
    public List<Integer> eventualSafeNodes(int[][] graph) {
        int vtces = graph.length;
        int[] vis = new int[vtces];
        Arrays.fill(vis,0);
        for(int i = 0;i<vtces;i++){
            if(vis[i]==0){
                boolean cycle = dfs(graph,i,vis);
            }
        }
        List<Integer> ans = new ArrayList<>();
        for(int i = 0;i<vtces;i++){
            if(vis[i] == 2){
                ans.add(i);
            }
        }
        return ans;
    }
}