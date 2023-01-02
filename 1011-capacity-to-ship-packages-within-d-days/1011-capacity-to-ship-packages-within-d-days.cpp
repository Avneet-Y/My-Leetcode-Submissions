//similar to allocate minimum number of pages

class Solution {
public:
    
    bool isvalid(vector<int>& weights, int n, int days, int maxi)
    {
        int tempdays = 1;
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += weights[i];
            if(sum > maxi)
            {
                tempdays++;
                sum = weights[i];
            }
            if(tempdays > days)
                return false;
        }
        return true;
    }
    
    int solve(vector<int>& weights, int n, int days)
    {
        int sum = 0, res = -1;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++)
        {
            sum += weights[i];
            maxi = max(maxi, weights[i]);
        }
        int start = maxi;
        int end = sum;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(isvalid(weights, n, days, mid) == true)
            {
                res = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return res;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int ans = solve(weights, n, days);
        return ans;
    }
};