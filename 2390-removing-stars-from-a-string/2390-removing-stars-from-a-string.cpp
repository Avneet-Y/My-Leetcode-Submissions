class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        stack<char> st;
        string ans = "";
        for(int i=0; i<n; i++)
        {
            if(st.size() > 0 && s[i] == '*')
                st.pop();
            if(s[i] != '*')
                st.push(s[i]);
        }
        while(st.size() > 0)
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};