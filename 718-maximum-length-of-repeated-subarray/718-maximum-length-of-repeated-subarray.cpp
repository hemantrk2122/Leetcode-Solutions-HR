class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1));
        
        for(int i=nums1.size()-1; i>=0; i--)
        {
            for(int j=nums2.size()-1; j>=0; j--)
            {
                if(nums1[i] == nums2[j])
                {
                    // cout<<"i "<<i<<"j"<<j<<" ";
                    // cout<<dp[i+1][j+1]<<endl;
                    dp[i][j] = dp[i+1][j+1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};