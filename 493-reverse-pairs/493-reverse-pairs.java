class Solution {
    public int reversePairs(int[] nums) {
        
        return (int)mergeSort(nums, 0, nums.length-1);
        
    }
    
    public static long mergeSort(int[] nums, int low, int high)
    {
        long res = 0;
        if(low == high)return 0;
        
        if(low<high)
        {
            int mid = low+(high-low)/2;
            
            res += mergeSort(nums, low, mid);
            res += mergeSort(nums, mid+1, high);
            
            res += merge(nums, low, mid, high);
        }
        
        return res;
    }
    
    public static long merge(int[] nums, int low, int mid, int high)
    {
        // long res = 0;
        int res = 0;
        int temp1 = mid-low+1;
        int temp2 = high-mid;
        int arr1[] = new int[temp1];
        int arr2[] = new int[temp2];
        for(int i=0;i<temp1;i++)
        {
            arr1[i] = nums[low+i];
        }
        for(int i=0;i<temp2;i++)
        {
            arr2[i] = nums[mid+1+i];
        }
        int p=0, q=0;
        while(p<temp1 && q<temp2)
        {
            if(arr1[p]>((long)2*arr2[q]))
            {
                res+=temp1-p;
                int xyz = temp1-p;
                q++;
            }
            else
                p++;
        }
        int i=0, j=0; 
        int k=low;
        while(i<temp1 && j<temp2)
        {
            if(arr1[i] <= arr2[j])
                nums[k++] = arr1[i++];
            else if(arr1[i]>arr2[j])
            {
                nums[k++] = arr2[j++];
            }
        }
        while(i<temp1)
            nums[k++] = arr1[i++];
        
        while(j<temp2)
            nums[k++] = arr2[j++];
        return res;
    }
}