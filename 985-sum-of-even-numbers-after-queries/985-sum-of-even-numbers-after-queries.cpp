class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries){
        int even = 0;
        for(int i : nums) even += ((i % 2 == 0) ? i : 0);
        vector<int> ans;
        for(auto i : queries){
            int val = i[0];
            int idx = i[1];
            if(nums[idx] % 2 == 0) even -= nums[idx];   //just concerned if its even
            nums[idx] += val;
            if(nums[idx] % 2 == 0) even += nums[idx];   //checks if after updating its even or not
            ans.push_back(even);    //pushes even sum in ans array
        }
        return ans;
    }
};