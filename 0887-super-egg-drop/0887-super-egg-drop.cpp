class Solution {
public:
    int dp[101][10001];
    int solve(int e, int f)      //e,k = eggs, f,n = floor
    {
        if(dp[e][f] != -1)
            return dp[e][f];
        
        if(f == 0 || f == 1)
            return f;
        
        if(e == 1)
            return f;
        
        int mini = INT_MAX; 
        int low = 1, high = f;
          while(low <= high) 
          {
              int mid = low + (high - low)/2;
              
              int lowvar = solve(e-1, mid-1);
              int highvar = solve(e, f-mid);
              
              int tempans = max(lowvar, highvar) + 1;
              mini = min(mini, tempans);
              
              if(lowvar > highvar) 
                  high = mid-1;
              else 
                  low=mid+1;
          }
        return dp[e][f] = mini;
    }
    
    
    int superEggDrop(int k, int n) {   //e,k = eggs, f,n = floor
        
        int ans;
        memset(dp, -1, sizeof(dp));
        ans = solve(k, n);
        return ans;
    }
};