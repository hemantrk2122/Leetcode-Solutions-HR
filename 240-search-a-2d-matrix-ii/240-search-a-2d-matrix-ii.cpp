class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int m = mat.size();
        int n = mat[0].size();
        
        int i = 0, j = n-1;
        while(i<m && j>=0){
            // cout<<i<<" "<<j<<endl;
            if(mat[i][j]==tar)return true;
            else if(mat[i][j]>tar)j--;
            else
                i++;
        }
        return false;
    }
};