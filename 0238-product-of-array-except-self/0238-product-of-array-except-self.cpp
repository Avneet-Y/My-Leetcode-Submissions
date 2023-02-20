class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int product = 1;
        
        vector<int> ans(n);
        int left[n];
        int right[n];
        
        left[0] = 1;
        right[n-1] = 1;
        
        for(int i=1; i<n; i++)
        {
            left[i] = nums[i-1] * left[i-1];
        }
        for(int j=n-2; j>=0; j--)
        {
            right[j] = nums[j+1] * right[j+1];
        }
        
        for(int k=0; k<n; k++)
        {
            ans[k] = left[k] * right[k];
        }
       
        return ans; 
    }
};