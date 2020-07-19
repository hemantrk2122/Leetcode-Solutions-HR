class Solution {
    void dfs(vector<vector<int>>& grid, int i, int j, int& perimeter){
        grid[i][j] = 2;
        if(i == 0 || grid[i-1][j] == 0) perimeter++;
        if(i == grid.size() - 1 || grid[i+1][j] == 0) perimeter++;
        if(j == 0 || grid[i][j-1] == 0) perimeter++;
        if(j == grid[0].size()-1 || grid[i][j+1] == 0) perimeter++;
        
        if(i > 0 && grid[i-1][j] == 1) dfs(grid, i-1, j, perimeter);
        if(j > 0 && grid[i][j-1] == 1) dfs(grid, i, j-1, perimeter);
        if(i < grid.size()-1 && grid[i+1][j] == 1) dfs(grid, i+1, j, perimeter);
        if(j < grid[0].size()-1 && grid[i][j+1] == 1) dfs(grid, i, j+1, perimeter);
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j)
                if(grid[i][j] == 1) dfs(grid, i, j, perimeter);
        }
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j)
                if(grid[i][j] == 2) grid[i][j] = 1;
        }
        return perimeter;
    }
};