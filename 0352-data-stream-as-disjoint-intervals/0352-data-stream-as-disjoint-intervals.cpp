class SummaryRanges {
public:
    vector<bool> arr;
    int mx = -1;
    SummaryRanges() 
    {
        arr = vector<bool>(10001, false);
    }
    
    void addNum(int value) 
    {
        arr[value] = true;
        mx = max(value, mx);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(int i = 0; i <= mx; i++)
        {
            int j = i;
            while(j <= mx && arr[j])
            {
                j++;
            }
            if(arr[i])
                ans.push_back(vector<int>{i,j-1});
            i = j;
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */