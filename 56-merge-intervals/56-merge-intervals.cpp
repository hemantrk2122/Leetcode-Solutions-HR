class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0)return intervals;
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(auto ele:intervals){
            if(end>=ele[0]){
                end = max(ele[1],end);
            }else{
                ans.push_back({start,end});
                start = ele[0];
                end = ele[1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};