class Solution {
public:
    int solve(int ind,int transNo,vector<int>& prices,vector<vector<int>>& dp){
        if(ind==prices.size() || transNo==0) return 0;
        if(dp[ind][transNo]!=-1) return dp[ind][transNo];
        
        int profit = 0;
        if(transNo%2==0){//have to buy
            profit = max(-prices[ind]+solve(ind+1,transNo-1,prices,dp),solve(ind+1,transNo,prices,dp));
        }else{//have to sell
            profit = max(prices[ind]+solve(ind+1,transNo-1,prices,dp),solve(ind+1,transNo,prices,dp));
        }
        
        return dp[ind][transNo] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,-1));
        return solve(0,2*k,prices,dp);
    }
};