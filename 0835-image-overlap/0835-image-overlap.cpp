class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int res = 0;
        int n = img1.size();
        for(int x=n; x>=-n; x--){
            for(int y=n; y>=-n; y--){
                int cur = 0;
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        if(i+x<0 || i+x>=n) continue;
                        if(j+y<0 || j+y>=n) continue;
                        if(img1[i+x][j+y] && img2[i][j]) cur++;
                    }
                }
                res = max(res, cur); 
            }
        }
        return res;
    }
};