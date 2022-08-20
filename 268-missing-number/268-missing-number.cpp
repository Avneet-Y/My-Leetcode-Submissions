class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // long sum = (n*(n+1))/2;
        // for(int i=0; i<n ;i++)
        // {
        //     sum -= nums[i];
        // }
        // return sum;
        
        int xorele = n;    
        for(int i=0; i<n; i++)
        {
            xorele = xorele ^ i;
            xorele = xorele ^ nums[i];
        }
            return xorele;
        
        
    }
};