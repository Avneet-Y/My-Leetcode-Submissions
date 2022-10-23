class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        // map<int, int> mp;
        // for(auto i : nums)
        //     mp[i]++;
        // for(auto it = mp.begin(); it!= mp.end(); it++)
        // {
        //     if(it->second > 1)
        //         ans.push_back(it->first);
        // }
        // for(int i = 1; i <= nums.size(); i++)
        // {
        //     if(mp.find(i) == mp.end())
        //     {
        //         ans.push_back(i);
        //     }
        // }
        // return ans;  
        
        // Using xor
        
        int n = nums.size();
        set<int> s(nums.begin(), nums.end());
        int xorele = 0;
        for (auto i : s)
        {
            xorele ^= i;
        }
        int repeat = xorele;
		
        for (int i = 0; i < n; i++)
        {
            repeat ^= nums[i];
        }
        
		for (int i = 1; i <= n; i++)
        {
            xorele ^= i;
        }
        int missing = xorele;
        ans.push_back(repeat);
        ans.push_back(missing);
        return ans;
    }
};