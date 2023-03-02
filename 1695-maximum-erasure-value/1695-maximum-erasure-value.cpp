class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        unordered_map<int, int> mp;
        long sum = 0;
        long maxi = INT_MIN;
        while(j < n)
        {
            mp[nums[j]]++;
            sum += nums[j];
            if(mp.size() == j-i+1)
            {
                maxi = max(maxi, sum);
                j++;
            }
            else if(mp.size() < j-i+1)
            {
                while(mp.size() < j-i+1)
                {
                    mp[nums[i]]--;
                    sum -= nums[i];
                    if(mp[nums[i]] == 0)
                        mp.erase(nums[i]);
                    i++;
                }
                j++;
            }
        }
        return maxi;   
    }
};