class MyCalendarThree {
public:
    map<int,int> mpp;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mpp[start]++;
        mpp[end]--;
        int maxi=0,cnt=0;
        for(auto x:mpp){
            cnt+=x.second;
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */