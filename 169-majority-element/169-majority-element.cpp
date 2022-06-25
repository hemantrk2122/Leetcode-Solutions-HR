class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto ele:nums){
            mp[ele]++;
        }
        int n = nums.size();
        int ans;
        for(auto ele:mp){
            if(ele.second>n/2)ans = ele.first;
        }
        return ans;
    }
};