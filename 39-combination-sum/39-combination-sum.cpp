class Solution {
public:
        void solve(vector<int>&nums,int target,vector<vector<int>>&ans,vector<int>curr,int idx){
            if(idx == nums.size()){
                if(target == 0){
                    ans.push_back(curr);
                }
                return;
            }
            if(nums[idx]<=target){
                curr.push_back(nums[idx]);
                solve(nums,target-nums[idx],ans,curr,idx);
                curr.pop_back();
            }
            solve(nums,target,ans,curr,idx+1);
        }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(candidates,target,ans,curr,0);
        return ans;
    }
    
};