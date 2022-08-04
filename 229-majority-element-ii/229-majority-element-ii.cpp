class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            m[nums[i]]++;
        }

        vector<int> ans;
        int ele;
        for(auto i : m)
         {
            if(i.second > n / 3)
            {
                ele = i.first;
                ans.push_back(ele);
            }
        }
        return ans;
    }
};