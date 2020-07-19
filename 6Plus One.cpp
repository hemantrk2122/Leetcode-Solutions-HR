class Solution {
public:
    vector<int> plusOne(vector<int>& a) {
        vector<int >res;
        int n=a.size();
        int t=((a[n-1]+1)%10);
        res.push_back(t);
        int carry=((a[n-1]+1)/10);

        for(int i=n-2;i>=0;i--){
            int tr=a[i]+carry;
            res.push_back(tr%10);
            carry=tr/10;

        }
        if(carry!=0 ){
            res.push_back(carry);

        }
        while(res.back()==0)
        res.pop_back();

        reverse(res.begin(),res.end());
        return res;
        }
};