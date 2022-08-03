/* class MyCalendar {
    
   private: map<int,int> m;
public:
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        int sum = 0;
        for(auto itr = m.begin(); itr!=m.end(); itr++)
        {
            sum += itr->second; 
            
            //before closing if any event other start in time range then, we could give -1 and +1 for closing, and gave extra +1 i.e intersection ..eg 10 to 20  10 is -1 and 20 is +1 (+1-1=0), 15 to 25, 15 is -1 ,25 is +1 now 15 is coming so sum is 1+1 that is 2 so false
            
            if(sum>1)
            {
                m[start]--;
                m[end]++;
                return false;
            }
        }
        return true;
    }
};
*/




class MyCalendar {
    private: vector<pair<int, int>> m; 
public:
    
    bool book(int start, int end) {
        
        for(auto itr : m)
        {
            if(itr.first < end && start < itr.second)
                return false;  
            }
       m.push_back({start, end});
       return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */