class Solution {
public:
    void solve(vector<int> nums, vector<vector<int>> &ans, int index)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int j = index; j<nums.size(); j++)
        {
            if(j != index && nums[j] == nums[index])
                continue;
            swap(nums[index], nums[j]);
            solve(nums, ans, index+1);
            //swap(nums[j], nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        sort(nums.begin(), nums.end());
        solve(nums, ans, index);
        return ans;
    }
};