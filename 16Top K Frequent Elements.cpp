class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        int n = a.size();
        vector<int>res;
        map<int,int >m;
        priority_queue<pair<int,int>>j;
        
        for(int i=0;i<n;i++)
            m[a[i]]++;
        
        for(auto i:m)
            j.push({i.second,i.first});
        
        for(int i=0;i<k;i++){
            res.push_back(j.top().second);
            j.pop();
        }
        return res;
    }
};