class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long max_upto_now = INT_MIN;    
        long new_product = 1; 
        
        for(int i=0; i<n; i++)
        {
            new_product *= nums[i];
            if(max_upto_now < new_product)
            {
                max_upto_now = new_product;
            }
            if(new_product == 0)
                new_product = 1;
        }
        
        long new_product_from_last = 1; 
        for(int i=n-1; i>=0; i--)
        {
            new_product_from_last *= nums[i];
            if(max_upto_now < new_product_from_last)
            {
                max_upto_now = new_product_from_last;
            }
            if(new_product_from_last == 0)
                new_product_from_last = 1;
        }
        return max_upto_now; 
    }
};