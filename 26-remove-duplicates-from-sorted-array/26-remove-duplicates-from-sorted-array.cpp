class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        int i =0;
        for(int j = 0;j<n;j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};

/*
[0,0,1,1,1,2,2,3,3,4]

o/p->[0,1,2,3,4,2,2,3,3,4]


*/