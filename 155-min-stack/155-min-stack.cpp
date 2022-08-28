class MinStack {
public:
    //using O(N) extra space
    
//     stack<int> s;
//     stack<int> ss;   //support stack that stores 
    
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         s.push(val);
//         if(ss.size()==0 || ss.top() >= val)
//             ss.push(val);
//         return;
        
//     }
    
//     void pop() {
//         if(s.size()==0)
//             return;
//         int ans = s.top();
//         s.pop();
//         if(ss.top() == ans)
//             ss.pop();
//         return;
        
        
//     }
    
//     int top() {
//         if(ss.size()==0)
//             return -1;
//         return s.top();
        
//     }
    
//     int getMin() {
//         if(ss.size()==0)
//             return -1;
//         return ss.top();
        
    stack<long long int>s;
    
        long long int minele = 0;
    
    void push(int val) {
        
        if(s.size()==0)
        {
            s.push(val);
            minele = val;
        }
        
        else if(val >= minele)
        {
            s.push(val);
        }
        
        else
        {
            long long int p = 2*(long long)val - minele;
            s.push(p);
            minele = val;
        }
    }
    
    void pop() {
        if(s.size()==0) return;
        else
        {
            if(s.top() >= minele)
            {
                s.pop();
            }
            
            else
            {
                int ov = minele;
                minele = 2*minele-s.top();
                s.pop();
            }
        }
    }
    
    int top() {
        if(s.size()==0) return -1;
        
        else
        {
            if(s.top() >= minele)
            {
                return s.top();
            }
            
            else
            {
                return minele;
            }
        }
    }
    
    int getMin() {
        return minele;
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