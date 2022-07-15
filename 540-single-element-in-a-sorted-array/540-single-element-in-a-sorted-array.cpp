class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xorr = 0;
        for(auto ele:nums){
            xorr^=ele;
        }
        return xorr;
    }
};