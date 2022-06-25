class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto ele:nums){
            mp[ele]++;
        }
        int n = nums.size();
        for(auto ele:mp){
            if(ele.second>n/3)ans.push_back(ele.first);
        }
        return ans;
    }
};