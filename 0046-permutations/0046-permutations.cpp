class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int>& nums, int ind)
    {
        if(ind >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=ind; i<nums.size(); i++)
        {
            swap(nums[i], nums[ind]);
            solve(ans, nums, ind+1);
            swap(nums[i], nums[ind]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(ans, nums, 0);
        return ans;
        
    }
};