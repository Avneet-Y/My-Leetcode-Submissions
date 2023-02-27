class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        long long ans = 0; 
        unordered_map<int,int> mp;
        int i=0, j=0;
        int n = nums.size();
        
        while(j < n)
        {
            if(mp.find(nums[j]) != mp.end())
            {
                int idx = mp[nums[j]];
                while(i <= idx)
                {
                    sum -= nums[i];
                    mp.erase(nums[i]);
                    i++;
                }
            }
            sum += nums[j];
            mp[nums[j]] = j;            
            if(j-i+1 == k)
            {
                ans = max(ans,sum);
                sum -= nums[i];
                mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};