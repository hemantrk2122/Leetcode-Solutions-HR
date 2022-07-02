class Solution {
public:
    bool isQueenSafe(vector<string>&board, int row, int col, int n){
        vector<vector<int>> dir={{1,0},{1,-1},{1,1},{-1,0},{-1,-1},{-1,1},{0,1},{0,-1}};
        for(int dis = 1;dis<=n;dis++){
            for(int i = 0;i<8;i++){
                int rm = dir[i][0]; //row movement
                int cm = dir[i][1]; //col movement
                
                int nrow = row + dis*rm; //next row
                int ncol = col + dis*cm; //next col
                
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n){
                    if(board[nrow][ncol]=='Q')
                    return false;
                }
            }
        }
        return true;
    }
    void solve(vector<string>&board,vector<vector<string>>&ans, int col, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row<n;row++){
            if(isQueenSafe(board,row,col,n)){
                board[row][col] = 'Q';
                solve(board,ans,col+1,n);
                board[row][col] = '.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        vector<vector<string>>ans;
        string s(n,'.');
        for(int i =0;i<n;i++){
            board[i] = s;
        }
        solve(board,ans,0,n);
        return ans;
    }
};