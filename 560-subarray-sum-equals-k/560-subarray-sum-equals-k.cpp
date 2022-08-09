class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0 ;

         unordered_map<int, int> mp;
         int pre_sum = 0;
         mp[pre_sum] = 1;
         for(int i=0 ;i<n; i++)
         {
             pre_sum += nums[i];
             if(mp.find(pre_sum - k) != mp.end())
             {
                count += mp[pre_sum - k];   
             }
             mp[pre_sum]++;
        }
        return count;
    }
};


