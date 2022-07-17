class Solution {
public:
    /*long long fun(int n,int k,vector<vector<int> > &dp,long long m){
        if(k==0) return 1;
        if(n==0 || k<0) return 0;
        if((n*(n-1))/2==k) return 1;
        if((n*(n-1))/2<k) return 0;
        if(dp[n][k]!=-1) return dp[n][k]%m;
        long long sum=fun(n-1,k,dp,m)+m-((k-n)>=0 ? fun(n-1,k-1,dp,m) : 0)%m;
        return dp[n][k]=(sum+fun(n,k-1,dp,m))%m;
    }*/
    int kInversePairs(int n, int k) {
        long long m=1e9+7;
        vector<vector<int> > dp(n+2,vector<int>(k+2,0));   
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(j==0){
                    dp[i][j]=1;
                }
                else{
                    int sum=(dp[i-1][j]+m-((j-i)>=0 ? dp[i-1][j-i] : 0))%m;  
                    dp[i][j]=(dp[i][j-1]+sum)%m;
                }
            }
        }
        return (dp[n][k]+m-((k-1)>=0 ? dp[n][k-1] : 0))%m;
        //return fun(n,k,dp,m);
    }
};
