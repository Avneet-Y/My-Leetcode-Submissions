//similar to minimum allocation of pages among k students
//sum shoul be minimized so that both arrays don't get much load

class Solution {
public:
    
    bool isvalid(vector<int>& nums, int n, int k, int mid)
    {
        int sum = 0, way = 1;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            if(sum > mid)
            {
                way++;
                sum = nums[i];
            }
            if(way > k)
            {
                return false;
            }
        }
        return true;
    }
    
    int solve(vector<int>& nums, int n, int k)
    {
        int res = -1, maxi = INT_MIN;
        long long sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            maxi = max(maxi, nums[i]);
        }
        int start = maxi;
        int end = sum;
        
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(isvalid(nums, n, k, mid) == true)
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
    
    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size(), ans;
        ans = solve(nums, n, k);
        return ans;
        
    }
};