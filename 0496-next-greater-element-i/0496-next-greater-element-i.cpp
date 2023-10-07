class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> ans;
        stack<int> st;
        map<int, int> mp;
        
        for(int i=n-1; i>=0; i--)
        {
            while(st.size() > 0 && st.top() <= nums2[i])
            {
                st.pop();
            }
            if(st.size() == 0)
            {
                mp[nums2[i]] = -1;
            }
            else if(st.size() > 0 && st.top() > nums2[i])
            {
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        for(auto i : nums1)
        {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};