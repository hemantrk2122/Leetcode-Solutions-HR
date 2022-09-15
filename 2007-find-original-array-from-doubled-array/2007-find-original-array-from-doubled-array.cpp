class Solution {
public:
    vector<int> findOriginalArray(vector<int>& v) {
       sort(v.begin(),v.end());
        unordered_map<int,int> m;
        vector<int> vi;
        
        if(v.size() & 1)return vi;
       
        for(int i=0;i<v.size();i++)m[v[i]]++;
         
        for(int i=0;i<v.size();i++){
            if(m.find(2*v[i])!=m.end()){
                if(m[v[i]]>0 && m[2*v[i]]>0){
                    vi.push_back(v[i]);
                  m[v[i]]--;m[2*v[i]]--;
                }
            }
        }
        for(auto it:m){
            if(it.second>0){
                vi.clear();break;
            }
        }
        return vi;
    }
};