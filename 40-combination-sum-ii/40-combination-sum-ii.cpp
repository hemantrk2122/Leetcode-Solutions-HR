class Solution {
public:
    void solve(vector<int>&nums,int target, int &sum, vector<vector<int>>&ans, vector<int>&curr, int idx){
        if(sum>target)return;
        if(sum == target){
            ans.push_back(curr);
            return;
        }
        for(int i = idx;i<nums.size();i++){
            if(i>idx && nums[i] == nums[i-1])continue;            
            sum+=nums[i];
            curr.push_back(nums[i]);
            solve(nums,target,sum,ans,curr,i+1);
            sum-=nums[i];
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>curr;
        int sum = 0;
        solve(candidates,target,sum,ans,curr,0);
        return ans;
    }
};