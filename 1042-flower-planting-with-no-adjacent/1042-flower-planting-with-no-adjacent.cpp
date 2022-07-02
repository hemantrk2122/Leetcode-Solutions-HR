class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        map<int,vector<int>>m;
        vector<int>ans(N);
        for(auto a: paths){
            m[a[0]].push_back(a[1]);
            m[a[1]].push_back(a[0]);
        }
        for(int  i =1 ;i<=N;i++){
            vector<int>color(5,0);
            for(auto a:m[i]){
                color[ans[a-1]]=1;
            }
            for(int j = 1;j<5;j++){
                if(color[j]==0){
                    ans[i-1]=j;
                    break;
                }
            }
        }
        return ans;
        
    }
};