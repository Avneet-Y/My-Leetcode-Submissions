class Solution {
public:
    void solve(int n, int k, vector<vector<int>> &ans, vector<int> &temp, int ind)
    {
        if(temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        for(int i = ind; i <= n; i++)
        {
            temp.push_back(i);
            solve(n, k, ans, temp, i+1);
            temp.pop_back();
        }
    }     

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(n, k, ans, temp, 1);
        return ans;
    }
};