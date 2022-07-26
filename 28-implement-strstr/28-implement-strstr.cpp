class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        for(int i = 0;;i++){
            for(int j = 0;;j++){
                if(j == n)return i;
                if(i+j==m)return -1;
                if(needle[j]!=haystack[i+j])break;
            }
        }
    }
};