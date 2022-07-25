class Solution {
public:
    string reverseWords(string s) {
        stringstream x(s);
        string word,ans="";
        while(x>>word){
            ans=word+" "+ans;
        }
        return ans.substr(0,ans.length()-1);
        
    }
};  