class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto ch:s){
            switch(ch){
                case '(':
                case '[':
                case '{':st.push(ch);
                    break;
                case ')':if(!st.empty() && st.top()=='(')st.pop();
                    else
                        return false;
                    break;
                case ']':if(!st.empty() && st.top()=='[')st.pop();
                    else
                        return false;
                        break;
                case '}':if(!st.empty() && st.top()=='{')st.pop();
                    else
                        return false;
                    break;
            }
        }
        if(st.empty())return true;
        return false;
    }
};