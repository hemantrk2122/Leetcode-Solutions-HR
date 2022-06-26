class Solution {
public:

vector<vector<int>> fourSum(vector<int>& v, int t) {
    sort(begin(v),end(v));
    int n=v.size();
    vector<vector<int>>ans;
    long long int tt=t;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            tt-=(v[i]+v[j]);
            int l=j+1;
            int r=n-1;
            
            while(l<r)
            {
                if(tt==v[l]+v[r])
                {
                    ans.push_back({v[i],v[j],v[l],v[r]});
                    while(l<r and v[l]==v[l+1])l++;
                    while(l<r and v[r]==v[r-1])r--;
                    
                    l++;
                    r--;
                    
                }
                else if(v[l]+v[r]<tt)
                {
                    l++;
                }
                else 
                {
                    r--;
                }
            }
            tt+=v[i]+v[j];
        while(j+1<n and v[j]==v[j+1])j++;
        }
        while(i+1<n and v[i]==v[i+1])i++;
    }
    
    return ans ;
    
}
};