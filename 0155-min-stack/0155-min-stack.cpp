class MinStack {
public:
    stack<int> st1, st2;
    MinStack() {
        
    }
    
    void push(int val) {
        st1.push(val);
        if(st2.size() == 0 || st2.top() >= val)
        {
            st2.push(val);
        }
        return;
    }
    
    void pop() {
        if(st1.size() == 0)
            return;
        int ans = st1.top();
        st1.pop();
        if(st2.top() >= ans)
            st2.pop();
    }
    
    int top() {
        return st1.top();
        
    }
    
    int getMin() {
        if(st2.size() == 0)
            return -1;
        return st2.top();
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