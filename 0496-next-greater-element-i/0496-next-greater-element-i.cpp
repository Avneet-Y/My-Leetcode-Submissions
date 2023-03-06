class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        vector<int> ans;
        stack<int> st;
        unordered_map<int, int> mp;
        
        for(int i = n2-1; i >= 0; i--)
        {
            int ele = nums2[i];
            while(!st.empty() && st.top() <= ele)
                st.pop();
            int res = 0;
            if(st.size() == 0)
                res = -1;
            else
                res = st.top();
            mp.insert({ele, res});
            st.push(ele);
        }
        for(auto it : nums1)
        {
            ans.push_back(mp[it]);
        }
        return ans;
    }
};