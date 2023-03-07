class MyStack {
public:
    queue<int> q1, q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(q1.size() == 0)
            return -1;
        while(q1.size() > 1)
        {
            int ele = q1.front();
            q1.pop();
            q2.push(ele);
        }
        int val = q1.front();
        q1.pop();
        
        while(q2.size() > 0)
        {
            int ele1 =  q2.front();
            q2.pop();
            q1.push(ele1);
        }
        return val;
    }
    
    int top() {
        if(q1.size() == 0)
            return -1;
        return q1.back();
        
    }
    
    bool empty() {
        return q1.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */