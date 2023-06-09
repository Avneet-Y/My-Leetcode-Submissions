class Solution {
public:
    bool isvalid(vector<int>& weights, int n, int days, int mx)
    {
        int tempdays = 1;
        int tempsum = 0;
        for(int i=0; i<n; i++)
        {
            tempsum += weights[i];
            if(tempsum > mx)
            {
                tempdays++;
                tempsum = weights[i];
            }
            if(tempdays > days)
                return false;
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        
        int sum = accumulate(weights.begin(), weights.end(), 0);
        int maxi = *max_element(weights.begin(), weights.end());
        
        int start = maxi; 
        int end = sum;
        int ans = -1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(isvalid(weights, n, days, mid) == true)
            {
                ans = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
        return ans; 
    }
};