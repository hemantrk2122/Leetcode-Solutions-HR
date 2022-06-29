class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mp;
        int i = 0, count = 0;
        for(int j = 0;j<s.size();j++){
            if(mp.find(s[j])!=mp.end()){
                i = max(i,mp[s[j]]+1);
            }
            mp[s[j]] = j;
            count = max(count,j-i+1);
        }
        return count;
    }
};

//count = 0->1->2
//[a,b,c,a,b,c,b,b]
//[0,1,2,3,4,5,6,7]

//i->starting index of req subarr
//j -> iter

//i = 0, j = 2

//count = max(count, j-i+1);
//if(ele-> found in map)
//I should have a potential starting point of new subarr