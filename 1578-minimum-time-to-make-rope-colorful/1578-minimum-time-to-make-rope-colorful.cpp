class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int n = colors.size();
        for(int i=0;i<n-1;i++){
            if(colors[i] == colors[i+1]){
                int maxi = -1, j = i;
                long long sum = 0;
                while(j<n-1 && colors[j] == colors[j+1]){
                    if(maxi<neededTime[j]) maxi = neededTime[j];
                    sum += neededTime[j]; 
                    j++;
                }
                sum += neededTime[j];
                if(maxi<neededTime[j]) maxi = neededTime[j];
                ans += sum-maxi;
                i = j;
            }
        }
        return ans;
    }
};