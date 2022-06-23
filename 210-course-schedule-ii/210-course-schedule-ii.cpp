class Solution {
public:
    bool dfs(int u, vector<vector<int>>&adj, vector<int>&s, vector<int>&vis){
        vis[u] = 1;
        for(auto v:adj[u]){
            if(vis[v]==1)return true;
            if(vis[v]==0 &&  dfs(v,adj,s,vis))return true;
        }
        vis[u] = 2;
        s.push_back(u);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto ele:prerequisites){
            adj[ele[1]].push_back(ele[0]);
        }
        vector<int>s;
        vector<int>vis(numCourses,0);
        for(int i = 0;i<numCourses;i++){
            if(!vis[i] && dfs(i,adj,s,vis))return {};
        }
        reverse(s.begin(),s.end());
        return s;
    }
};