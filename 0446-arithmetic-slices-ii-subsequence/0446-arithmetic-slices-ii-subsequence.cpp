class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<unordered_map< long , int> > mp (n);
		  
            for(int i = n-2 ; i>=0 ; i--)
            {   
			  for(int j= i+1 ; j<n ; j++)
              {
                    mp[i][(long)nums[j] - nums[i]]++;
              }
            }
					
            for(int i = n-3 ; i>=0 ; i--)
            {
                for(int j = i+1 ; j<n-1 ; j++)
                {
                    mp[i][(long)nums[j]-nums[i]] +=  mp[j][(long)nums[j]-nums[i]]; 
                    ans += mp[j][(long)nums[j]-nums[i]];
                }
            }
            return ans;
        
        
    }
};