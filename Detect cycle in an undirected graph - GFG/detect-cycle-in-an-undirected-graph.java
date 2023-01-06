//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int V = Integer.parseInt(s[0]);
            int E = Integer.parseInt(s[1]);
            ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < V; i++) adj.add(i, new ArrayList<Integer>());
            for (int i = 0; i < E; i++) {
                String[] S = br.readLine().trim().split(" ");
                int u = Integer.parseInt(S[0]);
                int v = Integer.parseInt(S[1]);
                adj.get(u).add(v);
                adj.get(v).add(u);
            }
            Solution obj = new Solution();
            boolean ans = obj.isCycle(V, adj);
            if (ans)
                System.out.println("1");
            else
                System.out.println("0");
        }
    }
}
// } Driver Code Ends


class Solution {
    // Function to detect cycle in an undirected graph.
    public boolean isCycle(int n, ArrayList<ArrayList<Integer>> adj) {
        boolean[] vis = new boolean[n];
        boolean ans = false;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                ans = ans||bfs(adj,i,vis);
            }
        }
        return ans;
    }
    public boolean bfs(ArrayList<ArrayList<Integer>> graph, int src, boolean[] vis){
        LinkedList<Integer> q = new LinkedList<>();
        q.addLast(src);
        while(q.size()>0){
            int size = q.size();
            while(size-->0){
                int node = q.removeFirst();
                if(vis[node])return true;
                vis[node] = true;
                for(int nbr:graph.get(node)){
                    if(!vis[nbr]){
                        q.addLast(nbr);
                    }
                }
            }
        }
        return false;
    }
}