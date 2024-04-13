class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int product = 1;
        
        for(int i = 0; i < n; i++)
        {
            ans.push_back(product);  //1,1,2,6
            product *= nums[i];     
        }
        product = 1;
        for(int i = n-1; i >= 0; i--)
        {
            ans[i] *= product;  //24,12,8,6
            product *= nums[i]; //24,12,4,1
        }
        return ans;
    }
};