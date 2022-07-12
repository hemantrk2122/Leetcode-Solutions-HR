class Solution {
public:
    bool dfs(vector<int>&sideLength,vector<int>nums,int index,int target){
        if(index==nums.size())
            return (sideLength[0]==sideLength[1] && sideLength[1]==sideLength[2] && sideLength[2]==sideLength[3]);
            
        for(int i=0;i<4;i++){
            
            if (sideLength[i] + nums[index] > target) continue;
            
            int j = i;
            while (--j >= 0) // third
                if (sideLength[i] == sideLength[j]) 
                    break;
            if (j != -1) continue;
            sideLength[i]+=nums[index];
            if(dfs(sideLength,nums,index+1,target))return true;
            sideLength[i]-=nums[index];
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        if(nums.empty())
            return false;
        
        int sum=0;
        for(auto num:nums)sum+=num;
        if(sum%4!=0)return false;
        
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int>sideLength(4,0);
        return dfs(sideLength,nums,0,sum/4);
        
    }
};