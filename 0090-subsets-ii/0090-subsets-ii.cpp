class Solution {
public:
    void solve(set<vector<int>> &st, vector<int> &temp, vector<int>& nums, int i)
    {
        if(i >= nums.size())
        {
            st.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(st, temp, nums, i+1);
        temp.pop_back();
        solve(st, temp, nums, i+1);   
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        solve(st, temp, nums, 0);
        for(auto it : st)
            ans.push_back(it);
        return ans;
        
    }
};