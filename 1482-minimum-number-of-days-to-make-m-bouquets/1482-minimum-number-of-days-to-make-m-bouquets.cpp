class Solution {
public:
    bool isvalid(vector<int>& bloomDay, int m, int k, int midday)
    {
        int count = 0;
        int result = 0;
        int n = bloomDay.size();
        for(int i=0; i<n; i++)
        {
            if(bloomDay[i] <= midday)
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
    
    int binary(vector<int>& bloomDay, int m, int k)
    {
        int start = 1;
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(isvalid(bloomDay, m, k, mid) == true)
            {
                ans = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
        return ans;
        
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans = -1;
        ans = binary(bloomDay, m , k);
        return ans;
        
    }
};