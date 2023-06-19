class Solution {
public:
    void solve(vector<int> nums, set<vector<int>> &temp, vector<int> output, int index)
    {
        if(index >= nums.size())
        {
            temp.insert(output);
            return;
        }
        
        //exclude
        solve(nums, temp, output, index+1);
        
        //include, but before include add
        int element = nums[index];
        output.push_back(element);
        
        solve(nums, temp, output, index+1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        set<vector<int>> temp;
        vector<int> output;
        sort(nums.begin(), nums.end());
        solve(nums, temp, output, 0);
        
        vector<vector<int>> ans;
        for(auto it : temp)
            ans.push_back(it);
        return ans;
    }
};