class Solution {
public:
    void solve(vector<int>nums, set<vector<int>>&ans, vector<int>&curr, int idx){
        ans.insert(curr);
        for(int i = idx;i<nums.size();i++){
            if(i==idx || nums[i]!=nums[i-1] ){
                curr.push_back(nums[i]);
                solve(nums,ans,curr,i+1);
                curr.pop_back();}
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
        vector<int>curr;
        vector<vector<int>>res;
        if(nums.size()==0)return res;
        solve(nums,ans,curr,0);
        for(auto ele:ans)res.push_back(ele);
        return res;
    }
};