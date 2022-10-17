class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char,int>m1,m2;
        if(sentence.size() < 26)
            return 0;
        for(int i = 0;i < 26;i++)
            m1[i+'a'] = 1;
        for(int i = 0;i < sentence.size();i++)
            m2[sentence[i]] = 1;
        if(m1 == m2)
            return 1;
        else
            return 0;
    }
};