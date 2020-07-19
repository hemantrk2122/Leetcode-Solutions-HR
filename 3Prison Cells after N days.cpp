class Solution {
public:
    int nthUglyNumber(int n) {
        int u[n];
        int i2=0,i3=0,i5=0;
        int n2=2;
        int n3=3;
        int n5=5;

        int nu=1;
        u[0]=1;
        for(int i=1;i<n;i++){
            nu=min(n2,min(n3,n5));

            u[i]=nu;
            if(nu==n2){
                i2++;
                n2=u[i2]*2;
            }
            if(nu==n3){
                i3++;
                n3=u[i3]*3;
            }
            if(nu==n5){
                i5++;
                n5=u[i5]*5;
            }


        }
        return nu;
    }
};