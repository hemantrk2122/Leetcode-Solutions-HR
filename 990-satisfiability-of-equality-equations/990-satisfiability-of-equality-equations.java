class Solution {
    int[] par;
    int[] size;
    
    public int find(int u){
        if(par[u]==u) return u;
        
        return par[u]=find(par[u]);
    }
    
    public void merge(int p1, int p2){
        if(size[p1]>=size[p2]){
            par[p2]=p1;
            size[p1]+=size[p2];
        } else {
            par[p1]=p2;
            size[p2]+=size[p1];
        }
    }
    public boolean equationsPossible(String[] equations) {
        par = new int[26];
        size = new int[26];
        
        for(int i =0;i<26;i++){
            par[i] = i;
            size[i] = 1;
        }
        
        for(String e:equations){
            if(e.charAt(1) == '='){
                int u = e.charAt(0)-'a';
                int v = e.charAt(3)-'a';
                
                int lu = find(u);
                int lv = find(v);
                
                if(lu!=lv){
                    merge(lu,lv);
                }
            }
        }
        
        for(String e:equations){
            if(e.charAt(1) == '!'){
                int u = e.charAt(0)-'a';
                int v = e.charAt(3)-'a';
                
                int lu = find(u);
                int lv = find(v);
                
                if(lu == lv)return false;
            }
        }
        return true;
    }
}