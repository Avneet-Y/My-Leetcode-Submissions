// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//       int n1 = 0, n2 = 0;
//         for(int i = 0; i<nums.size()-1; i++)
//         {
//             for(int j = i+1; j<nums.size(); j++) 
//             {
//                 if(nums[i]+nums[j] == target)
//                 {
//                     n1 = i;
//                     n2 = j;
//                 }
//             }
//         }
//         return {n1,n2};
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        unordered_map<int, int> mp;
       
        for(int i=0; i<n; i++)
        {
            if(mp.find(target - nums[i]) != mp.end())
                return {mp[target-nums[i]], i};
            
            mp[nums[i]] = i;
            
        }
        return {};
    }
};