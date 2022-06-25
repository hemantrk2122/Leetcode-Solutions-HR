class Solution {
public:
    void transpose(vector<vector<int>> &a){
        for(int i = 0;i<a.size();i++){
            for(int j = i+1;j<a[i].size();j++){
                swap(a[i][j],a[j][i]);
            }
        }
    }
    void reverse(vector<vector<int>>& a){
        int n = a.size();
        for(int row = 0; row<n; row++){
            int i = 0;
            int j = n-1;
            while(i<j){
                swap(a[row][i++],a[row][j--]);
            }
            
        }
        // for(int i = 0;i<a.size();i++){
        //     for(int j = 0;j<a[i].size()/2;j++){
        //         int n = a[i].size();
        //         swap(a[i][j],a[j][n-j-1]);
        //     }
        // }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        transpose(matrix);
        reverse(matrix);
        
    }
};