class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> output, int index)
    {
        if(index >= nums.size())
        {
            bool isPresent = find(ans.begin(), ans.end(), output) != ans.end();
            if(isPresent == false)
            {
                ans.push_back(output);
            }
            return;
        }
        
        //exclude
        solve(nums, ans, output, index+1);
        
        //include
        int ele = nums[index];
        output.push_back(ele);
        solve(nums, ans, output, index+1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int> output;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(nums, ans, output, 0);
        return ans;
    }
};