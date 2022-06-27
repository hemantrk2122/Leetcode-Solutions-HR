class Solution { // T.C --> O(k*(2^N)) not (N*2^N )S.C-->O(2^N)==Number of Function Call
public:
  bool backtrack(vector<int>&a,int start,int curr_sum,int k,int &req_sum,int n,vector<bool>&vis){
      if(k==1)return true;
      if(curr_sum==req_sum)return backtrack(a,0,0,k-1,req_sum,n,vis);
      
      for(int i=start;i<n;i++){
          if(vis[i]==false){
              if(curr_sum+a[i]>req_sum)continue;
              vis[i]=true;
              if(backtrack(a,i+1,curr_sum+a[i],k,req_sum,n,vis))return true;
              vis[i]=false;
                 if(curr_sum==0){cout<<i<<" ";break; } //f a bucket do not find the right number to match the target, so do not procced further in the loop.
      }
          }
      return false;
  }
    bool canPartitionKSubsets(vector<int>& a, int k){
        int sum=accumulate(a.begin(),a.end(),0);
        int n=a.size();
        sort(a.begin(),a.end(),greater<int>()); //This increase time complexity and reduce calls in backtracking break conditions. We can sort it in asccending order also
         if(sum%k ||n<k)return false;
         vector<bool>vis(n,false);
        int req_sum=sum/k;
         return backtrack(a,0,0,k,req_sum,n,vis);
    }
};
static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();