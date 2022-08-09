class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
      
        unordered_set<int> s;
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            s.insert(nums1[i]);
        }
        for(int j=0; j<m; j++)
        {
            if(s.find(nums2[j]) != s.end())
            {
                ans.push_back((nums2[j]));
                s.erase(nums2[j]);
            }
        }
        return ans;
        
    }
};