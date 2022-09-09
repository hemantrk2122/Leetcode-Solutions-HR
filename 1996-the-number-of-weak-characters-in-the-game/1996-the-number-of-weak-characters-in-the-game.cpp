class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b)
    {
        if(a[0]==b[0]){return a[1]>b[1];}
        return a[0]<b[0];
    }

    int numberOfWeakCharacters(vector<vector<int>>& mat) {
        int n=mat.size();
        sort(mat.begin(),mat.end(),comp);
        int least=INT_MIN;
        int count=0;
        for(int i=n-1;i>=0;i--)
        {
            if(mat[i][1]<least)
            {
                count++;
            }
            least=max(least,mat[i][1]);
        }
        
        return count;
    }
};