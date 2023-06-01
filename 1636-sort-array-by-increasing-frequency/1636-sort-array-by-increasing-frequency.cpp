class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto it: nums)
            mp[it]++;
        sort(nums.begin(), nums.end(), [&](int a, int b)
             {
                 return mp[a] != mp[b] ? mp[a] < mp[b] : a>b;
                 
             });
        return nums;
        
    }
};