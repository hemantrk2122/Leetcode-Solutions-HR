// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int solve(int coins[],int i,int &V,int &M,int curr_v,vector<vector<int>> &dp){
    if(curr_v==V){
        return 0;
    }
    if(curr_v>V){
        return 1e8;
    }
    if(i==M){
        return 1e8;
    }
    if(dp[i][curr_v]!=-1)
    {
        return dp[i][curr_v];
    }
    
    int a=1+solve(coins,i,V,M,curr_v+coins[i],dp);
    int b=solve(coins,i+1,V,M,curr_v,dp);
    return dp[i][curr_v]=min(a,b);
}

int minCoins(int coins[], int M, int V) 
{ 
    // Your code goes here
    vector<vector<int>> dp(M,vector<int>(V+1,-1));
    
    int ans=solve(coins,0,V,M,0,dp);
    if( ans==1e8){
        return -1;
    }else{
        return ans;
    }
} 
// 	int minCoins(int coins[], int M, int V) 
// 	{ 
// 	    sort(coins,coins+M);
// 	    int c = 0;
// 	    for(int i = M-1;i>=0;i--){
// 	        while(V>=coins[i]){
// 	            V-=coins[i];
// 	            c++;
// 	        }
// 	    }
// 	    return c;
// 	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends