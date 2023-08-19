class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int> ans;
        int alice = 0;
        int bob = 0;
        for(auto it : aliceSizes)
        {
            alice += it;
        }
        for(auto it: bobSizes)
        {
            bob += it;
        }
        
        int diff = (bob - alice)/2;
        unordered_set<int> st(bobSizes.begin(), bobSizes.end());
        
        for(auto i : aliceSizes)
        {
              if(st.find(i + diff) != st.end())
              {
                  ans.push_back(i);
                  ans.push_back(i + diff);
                  break;
              }
        }
        return ans;
    }
};