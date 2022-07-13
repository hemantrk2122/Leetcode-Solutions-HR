class Solution {
public:
    void solve(vector<int>nums, vector<vector<int>>&ans, vector<int>&curr,int idx){
        
            ans.push_back(curr);
            
        
        for(int i = idx;i<nums.size();i++){
            curr.push_back(nums[i]);
            solve(nums,ans,curr,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        if(nums.size()==0)return ans;
        solve(nums,ans,curr,0);
        return ans;
    }
};