class MinStack {
    private:
    stack<int>data;
    stack<int>min;
public:
    
    void push(int val) {
        data.push(val);
        if(min.empty() ||val<= getMin())min.push(val);
        
    }
    
    void pop() {
        if(data.top()==getMin())min.pop();
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */