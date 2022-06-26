class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
        int n = nums.size();
        for(int i = 0;i<n-1;i++){
            for(int j = i+1; j<n;j++){
                long long new_target = (long long)target - nums[i] - nums[j];
                int k = j+1;
                int l = n-1;
                while(k<l){
                    long long sum = (nums[k]+nums[l]);
                    if(sum == new_target){
                        ans.insert({nums[i],nums[j],nums[k],nums[l]});
                        while(k<l && nums[k] == nums[k+1])k++;
                        while(k<l && nums[l] == nums[l-1])l--;
                        k++;
                        l--;
                    }
                    else if(sum>new_target)l--;
                    else k++;
                }
            }
        }
        vector<vector<int>>res;
        for(auto ele:ans)res.push_back(ele);
        return res;
    }
};