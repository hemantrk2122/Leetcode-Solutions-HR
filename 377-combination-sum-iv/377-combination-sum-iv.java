class Solution {
    public  int tab(int[] arr,int Target) {
        int[] dp = new int[Target+1];
        for(int target = 0;target<=Target;target++){
            if(target == 0) {
                dp[target] = 1;
                continue;
            }
            // if(dp[target]!=0) dp[target];
            int ans = 0;
            for(int i = 0;i<arr.length;i++){
                if(target - arr[i] >=0){
                    ans += dp[target-arr[i]];
                }
            }
             dp[target] = ans;
        }
        return dp[Target];
    }
    public int combinationSum4(int[] nums, int target) {
        return tab(nums,target);
    }
}