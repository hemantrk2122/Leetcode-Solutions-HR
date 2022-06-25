class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int num1 = INT_MIN, num2 = INT_MIN, c1 = 0, c2 = 0;
        for(auto ele:nums){
            if(ele == num1)c1++;
            else if(ele == num2)c2++;
            else if(c1 == 0){
                num1 = ele;
                c1 = 1;
            }
            else if(c2 == 0){
                num2 = ele;
                c2 = 1;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1 = c2 = 0;
        for(auto ele:nums){
            if(ele == num1)c1++;
            if(ele == num2)c2++;
        }
        if(c1>nums.size()/3)ans.push_back(num1);
        if(c2>nums.size()/3)ans.push_back(num2);
        return ans;
    }
};