class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &ds, vector<int>& candidates, int target, int ind)
    {
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }
        for(int i = ind; i < candidates.size(); i++)
        {
            if(i != ind && candidates[i] == candidates[i-1])
                continue;
            if(candidates[i] > target)
                break;
            ds.push_back(candidates[i]);
            solve(ans, ds, candidates, target-candidates[i], i+1);
            ds.pop_back();
        }    
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        solve(ans, ds, candidates, target, 0);
        return ans;
    }
};