class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        priority_queue<int> pq;
        vector<int> f(26,0);
        for(int i=0;i<n;i++)
        {
            f[s[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(f[i]!=0)
                pq.push(f[i]);
        }
        int cnt=0;
        while(!pq.empty())
        {
            int x=pq.top();
            pq.pop();
            if(!pq.empty())
            {
                int y=pq.top();
                pq.pop();
                if(x==y)
                {
                    ++cnt;
                    pq.push(x);
                    if(y>1)
                        pq.push(y-1);
                }
                else
                    pq.push(y);
            }
        }
        return cnt;
    }
};