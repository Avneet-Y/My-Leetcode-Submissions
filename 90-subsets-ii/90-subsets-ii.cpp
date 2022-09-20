/* 
class Solution {
public:
    void helper(int ind, vector<int> &nums, vector<int> &ds,vector<vector<int>>&ans)
    {
        
            ans.push_back(ds);
            for(int i = ind;i<nums.size();i++)
            {
                if(i!=ind && nums[i]==nums[i-1])
                    continue;
                ds.push_back(nums[i]);
                helper(i+1, nums, ds, ans);
                ds.pop_back();
            }  
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        helper(0,nums,ds,ans);
        return ans;
        
    }
};
*/
class Solution {
public:
    void helper(int ind, vector<int> &nums, vector<int> ds, set<vector<int>> &temp)
    {
        
        if( ind >= nums.size())
        {
            temp.insert(ds);
            return;
        }
            
        helper(ind + 1, nums, ds, temp);
        ds.push_back(nums[ind]);
        helper(ind + 1, nums, ds, temp);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       
        vector<int> ds;
        set<vector<int>> temp;
        sort(nums.begin(), nums.end()); 
        helper(0, nums, ds, temp);
        
        vector<vector<int>> ans;
        
        for(auto it : temp)
        {
           ans.push_back(it);
        }
        return ans;
        
    }
};