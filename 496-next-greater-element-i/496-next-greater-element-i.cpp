class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        map<int,int> mp; 
        stack<int> st;
        int n = nums2.size();
        vector<int> ans;
    
        for(int i=n-1; i>=0; i--)
        {
      
            while(!st.empty() && st.top() < nums2[i])
            {
                st.pop();
            }

            if(st.empty())
            {
                mp[nums2[i]] = -1;
            }
      
            else
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