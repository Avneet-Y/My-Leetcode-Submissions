class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int i)
    {
        if(i >= nums.size())
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(ans, temp, nums, i+1);
        temp.pop_back();
        solve(ans, temp, nums, i+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, temp, nums, 0);
        return ans;
    }
};