class Solution {
    public int minPartitions(String n) {
        int maxm=0;
        for(int i=0;i<n.length();i++){
            
            maxm=Math.max(maxm,n.charAt(i)-'0');
        }
        return maxm;
    }
}