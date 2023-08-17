class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;
        vector<int> ans;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
            st.insert(nums[i]);
        
        for(auto x : st)
            ans.push_back(x);

        if(ans.size() == 1)
            return ans[0];
  
        if(ans.size() == 2)
        {
            sort(ans.begin(), ans.end());
            return ans[1];
        }

        if(ans.size() >= 3)
            return ans[ans.size()-3];
        
        return ans[ans.size()];
    }
};