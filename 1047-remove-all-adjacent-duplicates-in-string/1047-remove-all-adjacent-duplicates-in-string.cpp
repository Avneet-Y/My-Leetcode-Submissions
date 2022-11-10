class Solution {
public:
    string removeDuplicates(string s) {
        
        int n = s.size();
        string ans = "";
        stack<char> st;
        for(int i=0; i<s.size(); i++)
        {
            if(st.size() > 0)
            {
                if(st.top() == s[i])
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
    
        while(st.size() > 0)
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};