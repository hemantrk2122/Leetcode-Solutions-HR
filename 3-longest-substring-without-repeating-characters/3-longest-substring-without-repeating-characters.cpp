class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mp;
        int n = s.size();
        int i = 0;
        int ans = 0;
        for(int j = 0;j<n;j++){
            if(mp.find(s[j])!=mp.end())i = max(i,mp[s[j]]+1);
            mp[s[j]]=j;
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};