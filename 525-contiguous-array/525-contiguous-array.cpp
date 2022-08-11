class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int sum = 0;
        int count = 0;
        
        for(int i=0 ; i<n; i++)
        {
            if(nums[i]==0)
                nums[i] = -1;
        }
        for(int i=0 ;i<n ;i++)
        {
            sum += nums[i];
            if(sum == 0)
            {
                count = i+1;
            }
            if(mp.find(sum) != mp.end())
            {
                count = max(count , i - mp[sum]);
            }
            else
                mp.insert({sum, i});
        }
    return count;
    }
};