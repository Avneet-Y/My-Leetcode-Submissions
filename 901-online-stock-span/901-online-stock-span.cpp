class StockSpanner {
public:
     stack<int> st;
     vector<int> vec;
     int i=0;
    
    StockSpanner() {
        
    }
    
    int next(int price) 
    {
        vec.push_back(price);
        int span;
        
            while(st.empty()==false && vec[st.top()] <= price)
                st.pop();
            if(st.empty())
                span = i+1;
            else
                span = i - st.top(); 
            
            st.push(i++);
        
        return span;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */