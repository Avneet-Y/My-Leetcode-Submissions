class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> ans(nums.size());
	    for (int i = 0, j = 0, k = 1; i < nums.size(); i++) 
        {
		    if (nums[i] % 2 == 0) 
            {
			    ans[j] = nums[i];
			    j += 2;
		    }
		    else 
            {
			    ans[k] = nums[i];
			    k += 2;
		    }
	    }
	return ans;
    }
};