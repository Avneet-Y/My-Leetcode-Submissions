class SmallestInfiniteSet {
    
private:
    priority_queue<int, vector<int>, greater<int>> minh;
    unordered_set<int> st;
    int mini;

public:
    SmallestInfiniteSet() {
        mini = 1;
    }
    
    int popSmallest() {
        if(!minh.empty()) 
        {
            int small = minh.top();
            minh.pop();
            st.erase(small);
            return small;
        }
        mini += 1;
        return mini - 1;        
    }
    
    void addBack(int num) {
        if (mini > num && st.find(num) == st.end()) 
        {
            minh.push(num);
            st.insert(num);
        }   
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */