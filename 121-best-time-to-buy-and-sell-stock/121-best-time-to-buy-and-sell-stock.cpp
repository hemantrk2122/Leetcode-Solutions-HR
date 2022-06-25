class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, minm = INT_MAX;
        for(int ele: prices){
            // cout<<profit<<" ";
            if(ele<minm)minm = ele;
            profit = max(ele-minm,profit);
        }
        return profit;
    }
};