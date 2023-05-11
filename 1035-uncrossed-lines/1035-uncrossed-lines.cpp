class Solution {
public:
    int dp[501][501];
    int lcs(vector<int>& nums1, vector<int>& nums2, int n1, int n2)
    {
        for(int i=0; i<n1+1; i++)
        {
            for(int j=0; j<n2+1; j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        for(int i=1; i<n1+1; i++)
        {
            for(int j=1; j<n2+1; j++)
            {
                if(nums1[i-1] == nums2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n1][n2];
        
        
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int ans = lcs(nums1, nums2, n1, n2);
        return ans;
    }
};