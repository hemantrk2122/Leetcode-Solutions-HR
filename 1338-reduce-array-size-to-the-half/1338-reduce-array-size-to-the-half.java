class Solution {
    public int minSetSize(int[] arr) {
        int n = arr.length;
        
        Map<Integer,Integer> map = new HashMap<>();
        for(int i = 0;i<n;i++){
            map.put(arr[i],map.getOrDefault(arr[i],0)+1);
        }
        List<Integer> freq = new ArrayList<>(map.values());
        Collections.sort(freq,Collections.reverseOrder());
        
        int ans = 0;
        n/=2;
        for(int i = 0;i<freq.size() && n>0;i++){
            ans++;
            n-=freq.get(i);
        }
        return ans;
    }
}