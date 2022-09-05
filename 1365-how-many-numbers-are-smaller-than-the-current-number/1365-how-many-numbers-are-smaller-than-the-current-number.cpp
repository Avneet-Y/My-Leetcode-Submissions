class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // vector<int> ans;
        // for(int i=0; i<nums.size(); i++)
        // {
        //     int count=0;
        //     for(int j=0; j<nums.size(); j++)
        //     {
        //         if(nums[i]>nums[j])
        //             count++;     
        //     }
        //     ans.push_back(count);
        // }
        // return ans;
        map<int,int> mp;    
        int n = nums.size();
        vector<int> temp = nums;
        
        sort(temp.begin(),temp.end());
        for(int i=n-1; i>=0; i--)
            mp[temp[i]] = i;
        
        for(int i=0; i<n; i++)
            nums[i] = mp[nums[i]];
        
        return nums;
    
    }
};