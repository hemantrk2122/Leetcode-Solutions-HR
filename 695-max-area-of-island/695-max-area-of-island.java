class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        
        boolean[][] vis = new boolean[n][m];
        
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    ans = Math.max(ans,dfs(grid,i,j,vis));
                }
            }
        }
        return ans;
    }
    int dfs(int[][] grid,int i,int j,boolean[][] vis){
        int n = grid.length;
        int m = grid[0].length;
        
        vis[i][j] = true;
        
        int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        
        int size = 0;
        for(int[] dir:dirs){
            int x = i+dir[0];
            int y = j+dir[1];
            
            if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && grid[x][y]==1){
                size+=dfs(grid,x,y,vis);
            }
        }
        return size+1;
    }
}