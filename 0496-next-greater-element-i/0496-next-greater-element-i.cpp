class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        vector<int> ans;
        stack<int> st;
        unordered_map<int, int> mp;
        
        for(int i = n2-1; i >= 0; i--)
        {
            while(st.size() > 0 && st.top() < nums2[i])
                st.pop();
            if(st.size() == 0)
                mp[nums2[i]] = -1;
            else
            {
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
            
        }
        for(auto it : nums1)
            ans.push_back(mp[it]);
        return ans;
    }
};