class Solution {
public:
    string reverseVowels(string s) {
        stack<int>stk;
        for(int i = 0;i < s.size();i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            stk.push(s[i]);
        }
        for(int i = 0;i < s.size();i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                s[i] = stk.top();
                stk.pop();
            }
        }
        return s;
    }
};