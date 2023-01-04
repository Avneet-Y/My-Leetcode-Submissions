//In Page Allocation Problem the condition is that page should be allocated in a continuous //manner so for this question we will check for every possible permutation.

class Solution {
public:
    bool isvalid(vector<int>& cookies, int n, int k, int mid)
    {
        int sum = 0, children = 1;
        for(int i=0; i<n; i++)
        {
            sum += cookies[i];
            if(sum > mid)
            {
                children++;
                sum = cookies[i];
            }
            if(children > k)
            {
                return false;
            }
        }
        return true;
    }
    
    int solve(vector<int>& cookies, int n, int k)
    {
        int res = -1, maxi = INT_MIN;
        long long sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += cookies[i];
            maxi = max(maxi, cookies[i]);
        }
        int start = maxi;
        int end = sum;
        
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(isvalid(cookies, n, k, mid) == true)
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
    
    int distributeCookies(vector<int>& cookies, int k) {
        
        int n = cookies.size();
        int ans = INT_MAX;
        sort(cookies.begin(), cookies.end());  //sort first
        do
        {
            ans = min(ans, solve(cookies, n, k));
        }while(next_permutation(cookies.begin(), cookies.end()));
        return ans;
        
    }
};