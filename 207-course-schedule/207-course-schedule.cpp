class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses == 0)return true;
        vector<int>course(numCourses);
        for(auto ele:prerequisites){
            cout<<ele[1]<<" ";
            course[ele[1]]++;
        }
        cout<<endl;
        vector<bool>visited(prerequisites.size(),false);
        bool flag = true;
        while(flag){
            flag = false;
            for(int i = 0;i<prerequisites.size();i++){
                if(!visited[i]){
                    if(course[prerequisites[i][0]]==0){
                        visited[i] = true;
                        course[prerequisites[i][1]]--;
                        flag = true;
                    }
                }
            }
        }
        for(int i = 0;i<numCourses;i++){
            if(course[i]!=0)return false;
        }return true;
    }
};