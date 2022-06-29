class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto str:strs){
            string s1 = str;
            sort(s1.begin(),s1.end());
            mp[s1].push_back(str);
        }
        vector<vector<string>>ans;
        for(auto ele:mp){
            ans.push_back(ele.second);
        }
        return ans;
    }
};