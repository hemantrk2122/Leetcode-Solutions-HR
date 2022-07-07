class Solution {
public:
    void solve(int i, vector<int>&nums, int n, vector<vector<int>> &ans, vector<int>&temp){
        cout<<i<<endl;
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        
            solve((i+1)%n,nums,n,ans,temp);
            temp.push_back(nums[i]);
            solve((i+1)%n,nums,n,ans,temp);
            temp.pop_back();
            return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        do{
            ans.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return ans;
    }
};