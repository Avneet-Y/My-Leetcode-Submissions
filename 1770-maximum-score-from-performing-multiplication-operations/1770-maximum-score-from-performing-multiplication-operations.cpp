class Solution {
public:
    
    vector<vector<int>> dp;
    int recurs(vector<int>& n, vector<int>& mul,int i,int k)
    {
        
        if(k >= mul.size())
        {
            return 0;
        }
           
        if(dp[i][k]!=INT_MAX)
        {
            return  dp[i][k];
        }
        
        int j=n.size()-(k-i)-1;
        int a= max( recurs(n,mul,i+1,k+1)+(n[i]*mul[k]),recurs(n,mul,i,k+1)+(n[j]*mul[k]));
        return dp[i][k]=a;
        
    }
    
    int maximumScore(vector<int>& nums, vector<int>& mul)
    {
        dp.resize(mul.size()+1, vector<int> (mul.size()+1,INT_MAX));
        return recurs(nums, mul, 0, 0);

    }
};