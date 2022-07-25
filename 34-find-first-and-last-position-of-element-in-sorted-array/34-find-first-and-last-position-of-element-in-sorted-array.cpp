class Solution {
public:
    int find(vector<int>nums,int tar, bool first){
        int low = 0;
        int high = nums.size()-1;
        int ans = -1;
        
        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid] == tar){
                ans = mid;
                if(first)high = mid-1;
                else
                    low = mid+1;
            }
            else if(nums[mid]>tar)high = mid-1;
            else
                low = mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int stInd = find(nums,target,true);
        if(stInd == -1)return {-1,-1}; 
        int ltInd = find(nums,target,false);
        return {stInd,ltInd};
    }
};