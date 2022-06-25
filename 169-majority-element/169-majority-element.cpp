class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int elem = nums[0];
        for(auto ele:nums){
            if(count == 0){
                elem = ele;
            }
            count+= (ele == elem) ? 1:-1;
        }
        return elem;
    }
};