class Solution {
public:
    int largestPerimeter(vector<int>& a) {
        sort(a.begin(),a.end());
        for(int i = a.size() - 1; i >1; i--)if(a[i-2] + a[i-1] >a[i])return a[i-2] + a[i-1] + a[i];
        return 0;
    }
};