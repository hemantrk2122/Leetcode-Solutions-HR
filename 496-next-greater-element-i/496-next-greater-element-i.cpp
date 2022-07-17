class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n = nums2.size();
        vector<int>nge(nums2.size(),-1);
        map<int,int>mp;//{ele,nge}
        for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums2[i]) {
          st.pop();
        }
        if (i < n) {
          if (!st.empty()) mp[nums2[i]] = st.top();
          else
              mp[nums2[i]]=-1;
            
        }
        if(i<n)
            st.push(nums2[i]);
      }
       
        vector<int>ans;
        for(auto ele:nums1){
            ans.push_back(mp[ele]);
        }
        return ans;
    }
};