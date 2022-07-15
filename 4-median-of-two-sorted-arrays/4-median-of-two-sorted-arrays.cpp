class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        for(auto z:nums1)
            v.push_back(z);
        for(auto z:nums2)
            v.push_back(z);
        sort(v.begin(),v.end());
        if(v.size()%2==0){
           // cout<<v[v.size()/2]<<" "<<v[(v.size()/2) -1]<<endl;
            return (double(((double)v[v.size()/2]+(double)v[(v.size()-1)/2])/2));
        }
        else
            return double(v[v.size()/2]);
    }
};