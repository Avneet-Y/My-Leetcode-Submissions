//Similar to aggressive cows

class Solution {
public:
    
    bool isvalid(vector<int> &position, int n, int m, int mid)
    {
        int force = 1, last = position[0];
        for(int i=1; i<n; i++)
        {
            if(position[i] - last >= mid)
            {
                last = position[i];
                force++;
            }
        }
        if(force >= m)
            return true;
        return false;
    }
    
    int solve(vector<int> &position, int n, int m)
    {
        
        int start = 1;
        int end = position[n-1];
        int res = 1;
        while(start <= end)
        {
            double mid = start + (end-start)/2;
            if(isvalid(position, n, m, mid) == true)
            {
                res = mid;
                start = mid+1;
            }
            else
                end = mid-1;
        }
        return res;
    }
    
    int maxDistance(vector<int>& position, int m) {
         
        int n = position.size(), ans;
        sort(position.begin(), position.end());
        ans = solve(position, n, m);
        return ans;
    }
};