class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        unordered_map<string,int> mp;

        //Trying to find pair of mirrored string so that those can be put
        //in two side of a palindrome string.
        for(string s:words) {
            string rs = "xx";
            rs[0] = s[1];
            rs[1] = s[0];

            if(mp[rs]) {
                ans += 4;
                mp[rs]--;
            } else{
                mp[s]++;
            }
        }

        //If there's any remaining single string in which all element is same
        //Then we can put this in the middle of a palindrome.
        for(auto p:mp) {
            string s = p.first;
            if(p.second && s[0]==s[1]) {
                ans += 2;
                break;
            }
        }

        return ans;
    }
};