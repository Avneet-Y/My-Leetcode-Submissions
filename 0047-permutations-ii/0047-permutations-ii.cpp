class Solution {
public:
    void solve(vector<int>& nums, set<vector<int>> &temp, int index)
    {
        if(index >= nums.size())
        {
            temp.insert(nums);
            return;
        }
        for(int j = index; j<nums.size(); j++)
        {
            swap(nums[j], nums[index]);
            solve(nums, temp, index+1);
            swap(nums[j], nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> temp; 
        int index = 0;
        solve(nums, temp, index);
        for(auto it : temp)
            ans.push_back(it);
        return ans;
    }
};