class MinStack {
public:
    //Using extra space
    
    stack<int> s1, s2;
    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
        if(s2.size() == 0 || s2.top() >= val)  //agar s2 empty hai ya koi choti val aa rhi
            s2.push(val);                       //hai tabhi push
        return;
    }
    
    void pop() {
        if(s1.size() == 0)
            return;
        int ans = s1.top();  
        s1.pop();
        if(s2.top() >= ans)  //agar min ele hi s1 se pop kr rhe hai to s2 se bhi
            s2.pop();          //else agar s1 se pop hone vala s2 top i.e. min se bda
                                //tab nhi pop
    }
    
    int top() {
        return s1.top();
        
    }
    
    int getMin() {
        if(s2.size() == 0)  //s2 ka top hme min de dega bcz hmne push hi vaise kiya hai
            return -1;
        return s2.top();
        
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