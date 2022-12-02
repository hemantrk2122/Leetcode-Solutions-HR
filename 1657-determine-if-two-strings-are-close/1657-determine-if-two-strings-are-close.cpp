class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return 0 ;
        
        vector<char>s1,s2 ;
        vector<int> freq1(26,0), freq2(26,0);
        for(int i = 0 ; i < word1.size() ; i++){
            if(find(s1.begin(),s1.end(),word1[i])==s1.end())s1.push_back(word1[i]);
            if(find(s2.begin(),s2.end(),word2[i])==s2.end())s2.push_back(word2[i]);
            freq1[word1[i]-'a']++;
            freq2[word2[i]-'a']++;
        }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return freq2==freq1&&s1==s2 ;
    }
};