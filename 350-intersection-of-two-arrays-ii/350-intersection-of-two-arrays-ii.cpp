class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto i : nums1)
        {
            mp[i]++;
        }
        //if val from 2nd vector is present in map then
        //put it in output vector
        //also decrease the count
        for(auto i : nums2)
        {
            if(mp[i] > 0)
            {
                ans.push_back(i);
                mp[i]--;
            }
        }
        return ans;
    }
};
