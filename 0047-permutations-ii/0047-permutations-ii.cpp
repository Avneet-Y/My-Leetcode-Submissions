class Solution {
public:
    void solve(set<vector<int>> &temp, vector<int>& nums, int ind)
    {
        if(ind >= nums.size())
        {
            temp.insert(nums);
            return;
        }
        for(int i=ind; i<nums.size(); i++)
        {
            swap(nums[i], nums[ind]);
            solve(temp, nums, ind+1);
            swap(nums[i], nums[ind]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> temp;
        sort(nums.begin(), nums.end());
        solve(temp, nums, 0);
        for(auto it : temp)
            ans.push_back(it);
        return ans;
        
        
    }
};