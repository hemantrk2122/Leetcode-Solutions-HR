class Solution {
public:
    int arrangeCoins(int n) {
        int i=1;

        while(n>=0){
            if(n>0){
                n-=i;
            }
            i++;
        }
        //cout<<n<<endl;

        return i-1;

    }

};
