class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s;
        for(auto z:nums){
            s.insert(z);
        }
        int ls=0;
        for(auto z:nums){
            if(!s.count(z-1)){
                int cn=z;
                int cs=1;
                while(s.count(cn+1)){
                    cn+=1;
                    cs+=1;
                }
                ls=max(ls,cs);
                
            }
        }
        return ls;
        // set<int>s;
        // for(auto num:nums)s.insert(num);
        // int ans = 0;
        // for(auto num:nums){
        //     if(!s.count(num-1)){
        //         int currNum = num;
        //         int currStreak = 1;
        //         while(s.count(++num)){
        //             currNum++;
        //             currStreak++;
        //         }
        //         ans = max(ans, currStreak);
        //     }
        // }
        // return ans;
    }
};