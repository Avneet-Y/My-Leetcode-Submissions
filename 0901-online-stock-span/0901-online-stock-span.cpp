// class StockSpanner {
// public:
//      stack<int> st;
//      vector<int> vec;
//      int i=0;
    
//     StockSpanner() {
        
//     }
    
//     int next(int price) 
//     {
//         vec.push_back(price);
//         int span;
        
//             while(st.empty()==false && vec[st.top()] <= price)
//                 st.pop();
//             if(st.empty())
//                 span = i+1;
//             else
//                 span = i - st.top(); 
            
//             st.push(i++);
        
//         return span;
        
//     }
// };

// /**
//  * Your StockSpanner object will be instantiated and called as such:
//  * StockSpanner* obj = new StockSpanner();
//  * int param_1 = obj->next(price);
//  */



// class StockSpanner {
// public:
//      stack<int> st;
    
//     StockSpanner() {
        
//     }
    
//     int next(int price) 
//     {
//         int span;
        
//             while(st.empty()==false && vec[st.top()] <= price)
//                 st.pop();
//             if(st.empty())
//                 span = i+1;
//             else
//                 span = i - st.top(); 
            
//             st.push(i++);
        
//         return span;
        
//     }
// };



class StockSpanner {
public:
     stack<pair<int, int>> st;
    
    StockSpanner() {
        
    }
    
    int next(int price) 
    {
        int span = 1;
        while(st.size()>0 && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    
    }
};




/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */