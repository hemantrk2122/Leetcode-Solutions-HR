class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string source = a;
        int n = b.size();
        
        int count = 1;
        while(source.size()<n){
            count++;
            source+=a;
        }
        
        if(source == b)return count;
        if(rk(source,b))return count;
        if(rk(source+a,b))return count + 1;
        
        return -1;
    }
    
    int rk(string s1, string s2){
        long p = 31;
        long pow = 1;
        long dsv = 0;
        long mod = 1000000007;
        for (int i = 0; i < s2.length(); i++) {
            dsv = (dsv + (s2[i] - 'a' + 1) * pow) % mod;
            pow = (pow * p) % mod; // 29 , 29^2 , 29^3...
        }

        // Rabin karp
        vector<long>pha(s1.size());
        vector<long>pith(s1.size());
        // long[] pha = new long[s1.size()]; // prefix hash array
        // long[] pith = new long[s1.size()]; // power for substring starting from ith index

        pha[0] = s1[0] - 'a' + 1;
        pith[0] = 1;
        pow = p;

        // generating hash for s1
        for (int i = 1; i < s1.length(); i++) {
            pha[i] = (pha[i - 1] + (s1[i] - 'a' + 1) * pow) % mod;
            pith[i] = pow;
            pow = (pow * p) % mod;
        }

        // using sliding window to check which substring of s1 has hash similar to s2
        int si = 0;
        int ei = s2.length() - 1;

        while (ei < s1.length()) {

            long hith = pha[ei]; // hash value of string till ei

            if (si > 0) {
                hith = (hith - pha[si - 1] + mod) % mod;
            }

            if ((dsv * pith[si]) % mod==hith) {
                return true;
            }
            si++;
            ei++;
        }
        
        return false;
    }
};