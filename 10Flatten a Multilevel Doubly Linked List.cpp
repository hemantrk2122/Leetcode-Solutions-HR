class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        vector<vector<int >>ans;
        
        int n=a.size();
        int  count = pow(2,n);
    
        for (int i = 0; i < count; i++)
        {   
            vector<int >v;

            for (int j = 0; j < n; j++)
            {

                if ((i & (1 << j)) > 0)
                    v.push_back(a[j]);
            }
            ans.push_back(v);
            //cout << "\n";
        }
        return ans;
    }
};