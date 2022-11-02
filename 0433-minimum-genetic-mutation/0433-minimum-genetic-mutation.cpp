class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> visit,available;
        int level=0;
        unordered_set<char> characters;
        characters.insert('A');
        characters.insert('C');
        characters.insert('G');
        characters.insert('T');
        available.insert(bank.begin(),bank.end());
        queue<string> que;
        que.push(start);
        visit.insert(start);
        while(!que.empty()){
            int size = que.size();
            while(size--){
                string str = que.front();
                que.pop();
                for(int i=0;i<str.size();i++){
                    for(auto& ch:characters){
                        string changeStr = str;
                        changeStr[i] =ch;
                        if(visit.find(changeStr)==visit.end() && available.find(changeStr)!=available.end()){
                            if(changeStr==end) return level+1;
                            que.push(changeStr);
                            visit.insert(changeStr);
                        }
                    }
                }
            }
            level++;
        }
        
        return -1;
    }
};