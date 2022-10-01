class LUPrefix {
public:
    vector<int> arr;
            int i=0;
    LUPrefix(int n) {
        arr.resize(n);
        for(int i=0;i<n;i++)
            arr[i]=0;
    }
    
    void upload(int video) {
        arr[video-1]=1;
    }
    
    int longest() {
        int n=arr.size();
        while(i<n)
        {
            if(arr[i]==0)
                break;
            i++;
        }
        return i;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */