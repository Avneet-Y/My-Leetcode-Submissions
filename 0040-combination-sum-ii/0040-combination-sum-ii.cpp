class Solution {
public:
    void solve(int ind, vector<int> &ds, vector<vector<int>> &ans, vector<int>& candidates, int target)
    {
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=ind; i<candidates.size(); i++)
        {
            if(i != ind && candidates[i] == candidates[i-1])
                continue;
            if(candidates[i] > target)
                break;
            ds.push_back(candidates[i]);
            solve(i+1, ds, ans, candidates, target-candidates[i]);
            ds.pop_back();
        }   
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        int index = 0;
        solve(index, ds, ans, candidates, target);
        return ans;
    }
};