class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int curr = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i] == 0){
                curr = 0;
            }
            if(nums[i]==1){
                curr++;
            }
            ans = max(ans,curr);
        }
        return ans;
    }
};