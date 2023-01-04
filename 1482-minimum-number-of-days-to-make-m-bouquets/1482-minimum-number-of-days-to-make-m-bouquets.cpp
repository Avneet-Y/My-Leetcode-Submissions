class Solution {
public:
    
    bool isvalid(vector<int>& bloomDay, int days, int m, int k)
    {
        int count = 0, result = 0;
        for(int i=0; i<bloomDay.size(); i++)
        {
            if(bloomDay[i] <= days)
            {
                count++; //count represents consective flowers
            }
            else
            {
                count = 0;
            }
            if(count == k)
            {
                count = 0; //reset the window
                result++;
            }
        }
        if(result >= m)
            return true;
        return false;
    }
    
    int solve(vector<int>& bloomDay, int m, int k) 
    {
        int res = -1;
        int start = 1, end = *max_element(bloomDay.begin(), bloomDay.end());
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(isvalid(bloomDay, mid, m, k) == true)
            {
                res = mid; 
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return res; 
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(), ans;
        ans = solve(bloomDay, m, k);
        return ans;
    }
};