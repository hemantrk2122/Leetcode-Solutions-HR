class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<int,int>mp;
        int ans = 0, i = 0;
        for(int j = 0;j<n;j++){
            if(mp.find(s[j])!=mp.end())i = max(mp[s[j]]+1,i);
            mp[s[j]] = j;
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};