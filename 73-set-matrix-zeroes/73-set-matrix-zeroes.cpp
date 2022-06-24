class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>row(n,0);
        vector<int>column(m,0);
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j]==0){
                    row[j] += 1;
                    column[i] +=1;
                }
            }
        }
        for(int i = 0;i<n;i++){
            if(row[i] >= 1){
                for(int j = 0;j<m;j++){
                    matrix[j][i] = 0;
                }
            }
        }
        for(int i = 0;i<m;i++){
            if(column[i] >= 1){
                for(int j = 0;j<n;j++){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};