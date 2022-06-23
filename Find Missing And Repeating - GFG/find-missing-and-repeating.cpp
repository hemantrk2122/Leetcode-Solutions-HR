// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        //repeating and missing
        int x = 0; //repeating
        int y = 0; //missing
        int set_bit;
        int xor1 = arr[0];
        for(int i = 1;i<n;i++){
            xor1 ^= arr[i];
        }
        for(int i = 1;i<=n;i++){
            xor1 ^= i;
        }
        
        // xor1 = x ^ y
        
        set_bit = xor1 & ~(xor1-1);
        
        for(int i = 0;i<n;i++){
            if(arr[i]&set_bit)x^=arr[i];
            else
            y^=arr[i];
        }
        for(int i = 1;i<=n;i++){
            if(i&set_bit)x^=i;
            else
            y^=i;
        }
        int *a = new int[2];
        for(int i = 0;i<n;i++){
            if(arr[i] == x){
                a[1] = y;
                a[0] = x;
            }else if(arr[i] == y){
                a[0] = y;
                a[1] = x;
            }
        }
        
        // a[0] = y;
        // a[1] = x;
        return a;
        
        
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends