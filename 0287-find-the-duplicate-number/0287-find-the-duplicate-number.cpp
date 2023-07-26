class Solution {
public:
    int findDuplicate(vector<int>& nums) {
         int n = nums.size();
        // unordered_map<int, int> mp;
        // for(auto i : nums)
        //     mp[i]++;
        // for(auto it = mp.begin(); it != mp.end(); it++)
        // {
        //     if(it->second > 1)
        //         return it->first;
        // }
        // return 0;
        
        //Using BS
        
        int low = 1;
        int high = n-1;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            int ct = 0;
            for(int i=0; i<n; i++)
            {
                if(nums[i] <= mid)
                {
                    ct++;
                }
            }
            if(ct <= mid)
            {
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return low;
        
    }
};