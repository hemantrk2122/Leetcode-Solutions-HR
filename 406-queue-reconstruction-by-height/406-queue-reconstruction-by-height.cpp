class Solution {
public:
    
    static bool comp(const vector<int> &v1, const vector<int> &v2)
    {
        if(v1[0]==v2[0])
            return v1[1]<v2[1];
        return v1[0]>v2[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort(people.begin(),people.end(),comp);
        
        vector<vector<int> > ans;
        for(auto x: people)
            ans.insert(ans.begin()+x[1],x);
        
        return ans;
    }
};