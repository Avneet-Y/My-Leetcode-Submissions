class Solution {
public:
    int maxi = 0;
    bool is_unique(string &str)
    {
        int n = str.size();
        vector<int> mp(26, 0);
        for(int i = 0; i < n; i++)
        {
            mp[str[i] - 'a']++;
            if(mp[str[i] - 'a'] > 1)   
                return false;
        }
        return true;
    }

    void solve(vector<string>& arr, int i, int n, string current)
    {
        if(is_unique(current) == false)
            return;
        if(i == n)
        {
            if(current.size() > maxi)
            {
                int size = current.size();   
                maxi = max(maxi, size);
            }
            return;
        }
        solve(arr, i + 1, n, current + arr[i]);
        solve(arr, i + 1, n, current);
    }
    
    int maxLength(vector<string>& arr) {
        
        int n = arr.size();
        solve(arr, 0, n, "");
        return maxi;
        
    }
};