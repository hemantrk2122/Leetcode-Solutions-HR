class Solution {
public:
    int check(string s){
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' ||  s[i]=='i' || s[i]=='o' || s[i]=='u' ||
              s[i]=='A' || s[i]=='E' ||  s[i]=='I' || s[i]=='O' || s[i]=='U'){
                
                count++;
            }
        }
        return count;
    }
    bool halvesAreAlike(string s) {
    string a="";
    string b="";
    int n=s.size();
    for(int i=0;i<n;i++){
        if(i<n/2){
            a.push_back(s[i]);
        }
        else{
            b.push_back(s[i]);
        }
     } 
     
    
     if(check(a)==check(b)){
      return true; 
       }
     
     return false;   
    }
};