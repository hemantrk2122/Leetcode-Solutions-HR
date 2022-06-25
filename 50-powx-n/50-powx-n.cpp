class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1;
        bool isNeg = false;
        if(n<0)isNeg = true;
        n = abs(n);
        double ans = 1;
        while(n>1){
            if(n&1)ans*=x;
            n>>=1;
            x*=x;
        }
        ans*=x;
        if(isNeg)return 1/ans;
        else return ans;
    }
};