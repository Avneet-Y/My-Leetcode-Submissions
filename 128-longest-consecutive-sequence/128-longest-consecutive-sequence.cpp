/* 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int count = 1, ans = 1;
        if (n == 0) 
        {
            return 0;
        }
        sort(nums.begin(),nums.end());

        for (int i = 1; i < n; i++) {
           // if (nums[i] != nums[i-1]) {
                if (nums[i] == nums[i-1]+1) 
                {
                    count++;
                }
                else {
                    ans = max(ans, count);
                    count = 1;
                }
           // }
        }
        ans = max(ans, count);
        return ans;
    }
};
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
        }
        for(int i=0; i<n; i++)
        {
            if(mp.find(nums[i]-1) == mp.end())
            {
                int curr = 1;
                while(mp.find(nums[i] + curr) != mp.end())
                    curr++;
                count = max(count, curr);
        }
        }
         return count;
    }
};


