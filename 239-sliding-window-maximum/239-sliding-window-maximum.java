class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] ngr = nextGreaterRight(nums);
        
        int[] ans = new int[n-k+1];
        int idx = 0;
        for(int si = 0;si<=n-k;si++){
            int ei = si+k-1;
            if(idx<si){
                idx = si;
            }
            while(ngr[idx]<=ei){
                idx = ngr[idx];
            }
            ans[si] = nums[idx];
        }
        return ans;
    }
    public static int[] nextGreaterRight(int[] arr){
        int n = arr.length;
        int[] ngr=new int[n];
        Stack<Integer> st = new Stack<>();
        st.push(n-1);
        ngr[n-1]=n;
        for(int i =n-2;i>=0;i--){
            while(st.size()!=0 && arr[i]>=arr[st.peek()]){
                st.pop();
            }
            if(st.size()==0){
                ngr[i]=n;
            }
            else{
                ngr[i]=st.peek();
            }
            st.push(i);
        }
        return ngr;
    }
}