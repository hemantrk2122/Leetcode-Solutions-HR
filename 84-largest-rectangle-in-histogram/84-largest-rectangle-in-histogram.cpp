class Solution {
    vector<int> getNextSmaller(vector<int>&arr){
        int n = arr.size();
        stack<int>st;
        vector<int>ans(n);
        st.push(n-1);
        ans[n-1]=n;
        for(int i = n-2;i>=0;i--){
            while(st.size()>0 && arr[i]<arr[st.top()])
                st.pop();
            if(st.size()==0)ans[i]=n;
            else
                ans[i]=st.top();
            st.push(i);
        }
        return ans;
        
    }
    vector<int> getPrevSmaller(vector<int>&arr){
        int n = arr.size();
        stack<int>st;
        vector<int>ans(n);
        st.push(0);
        ans[0]=-1;
        for(int i = 1;i<n;i++){
            while(st.size()>0 && arr[i]<=arr[st.top()])
                st.pop();
            if(st.size()==0)ans[i]=-1;
            else
                ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = heights.size();
        vector<int> r = getNextSmaller(heights);
        vector<int> l = getPrevSmaller(heights);
        int area = 0;
        for(int i = 0;i<n;i++){
            int width = r[i]-l[i]-1;
            area = max(area,width*heights[i]);
        }
        return area;
    }
};