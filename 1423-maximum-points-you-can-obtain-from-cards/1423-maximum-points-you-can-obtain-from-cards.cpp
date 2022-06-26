class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total = accumulate(cardPoints.begin(),cardPoints.end(),0);
        int mini = total,n = cardPoints.size(),sum=0;
        
        for(int i=0,j=0;i<=k;i++){
                while(j<n && j-i<n-k) sum+=cardPoints[j],j++;
                mini = min(mini,sum);
                sum-=cardPoints[i];
        }
        return total-mini;
        
    }
};