class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n-2;
        while(l<=h){
            int mid = (l+h)>>1;
            if(nums[mid]==nums[mid^1]){
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        return nums[l];
    }
};