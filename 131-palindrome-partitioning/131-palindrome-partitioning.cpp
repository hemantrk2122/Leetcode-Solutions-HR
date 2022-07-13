class Solution {
public:
    void solve(string s, vector<vector<string>>&ans, vector<string>&curr, int idx){
        if(idx == s.size()){
            ans.push_back(curr);
            return;
        }
        for(int i =idx;i<s.size();i++){
            if(isPalindrome(s,idx,i)){
                curr.push_back(s.substr(idx,i-idx+1));
                solve(s,ans,curr,i+1);
                curr.pop_back(); 
            }
        }
    }
    bool isPalindrome(string s, int i, int j){
        while(i<=j){
            if(s[i++]!=s[j--])return 0;
        }
        return 1;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;
        solve(s,ans,curr,0);
        return ans;
    }
};