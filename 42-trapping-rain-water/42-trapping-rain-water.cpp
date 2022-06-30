class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int l = 0, r = n-1, left_max = h[l], right_max = h[r], res=0;
        while(l<r){
            if(h[l]<h[r]){
                if(left_max<h[l])left_max = h[l];
                else
                    res+=(left_max-h[l]);
                l++;
            }else{
                if(right_max<h[r])right_max = h[r];
                else
                    res+=(right_max-h[r]);
                r--;
            }     
        }
        return res;
    }
};