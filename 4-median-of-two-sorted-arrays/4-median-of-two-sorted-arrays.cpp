class Solution {
public:
    double solve(vector<int>nums){
        int n = nums.size();
        if(n==1)return nums[0];
        if(n%2==0){
            return 1.0 * (nums[(n+1)/2] + nums[(n+1)/2-1])/2;
        }else
            return nums[(n)/2];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { 
        int m = nums1.size();
        int n = nums2.size();
       int finalArray[n+m];
    int i=0,j=0,k=0;
    while(i<m && j<n) {
        if(nums1[i]<nums2[j]) {
            finalArray[k++] = nums1[i++];
        }
        else {
            finalArray[k++] = nums2[j++];
        }
    }
    if(i<m) {
        while(i<m) 
            finalArray[k++] = nums1[i++];
    }
    if(j<n) {
        while(j<n)
            finalArray[k++] = nums2[j++];
    }
    n = n+m;
    if(n%2==1) 
        return finalArray[((n+1)/2)-1];
    else return ((float)finalArray[(n/2)-1]+(float)finalArray[(n/2)])/2;
    }
};