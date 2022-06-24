// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int count = 0;
    long long int inversionCount(long long arr[], long long N)
    {
        mergeSort(arr,(long long int)0,N-1);
        return count;
    }
    long long int* mergeSort(long long arr[],long long i, long long j){
        if(i == j){
            long long int *base = new long long int[1];
            base[0] = arr[i];
            return base;
        }
        long long int mid = i + (j-i)/2;
        long long int* left = mergeSort(arr,i,mid);
        long long int* right = mergeSort(arr,mid+1,j);
        long long int* merged = merge(left, right, mid - i + 1, j-mid);
        return merged;
    }
    long long int* merge(long long int* left, long long *right, int n, int m){
        long long int i = 0, j = 0, k = 0;
        long long int* merged = new long long int[n+m+1];
        while(i<n && j<m){
            if(left[i]<=right[j]){
                merged[k++] = left[i++];
            }else{
                count += (n-i);
                merged[k++] = right[j++];
            }
        }
        while(i<n){
            merged[k++] = left[i++];
        }
        while(j<m){
            merged[k++] = right[j++];
        }
        return merged;
    }
};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends