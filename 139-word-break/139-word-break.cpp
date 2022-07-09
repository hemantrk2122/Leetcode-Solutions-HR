class Solution {
public:
    int dp[301];
    bool solve(int i,string s,unordered_set<string>&dict){
        if(i==s.size())return 1;
        string temp;
        if(dp[i]!=-1)return dp[i];
        for(int j = i;j<s.size();j++){
            temp+=s[j];
            if(dict.find(temp)!=dict.end()){
                if(solve(j+1,s,dict))
                    return dp[i]=1;
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        memset(dp,-1,sizeof dp);
        for(auto ele:wordDict)st.insert(ele);
        return solve(0,s,st);
    }
};