class Solution {
public:
    
    bool isvalid(vector<int>& weights, int days, int maxi, int n)
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
    
    int search(vector<int>& weights, int days, int n)
    {
        int sum = 0;
        int maxi = INT_MIN;
        int res = -1;
        for(int i=0; i<n; i++)
        {
            sum += weights[i];
            maxi = max(weights[i], maxi);
        }
        int start = maxi;
        int end = sum;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(isvalid(weights, days, mid, n) == true)
            {
                res = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
        return res;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int ans = search(weights, days, n);
        return ans;
    }
};