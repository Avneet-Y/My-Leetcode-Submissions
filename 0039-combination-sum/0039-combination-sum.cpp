class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, vector<int>& candidates, int target, int i)
    {
        if(i >= candidates.size())
        {
            if(target == 0)
            {
                ans.push_back(temp);
            }
            return;
        }
        if(target >= candidates[i])
        {
            temp.push_back(candidates[i]);
            solve(ans, temp, candidates, target-candidates[i], i);
            temp.pop_back();
        }
        solve(ans, temp, candidates, target, i+1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, temp, candidates, target, 0);
        return ans;
        
        
    }
};