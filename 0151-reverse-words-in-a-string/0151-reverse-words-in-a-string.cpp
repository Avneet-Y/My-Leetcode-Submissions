class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        string temp = "";
        stack<string> st;
        int i = 0;
        for(int i=0; i<n; i++)
        {
            string temp = "";
            if(s[i] == ' ')
                continue;
            while(s[i] != ' ' and i < n)
            {
                temp += s[i];
                i++;
            }
            st.push(temp);
        }
        while(st.size() > 0)
        {
            ans += st.top();
            st.pop();
            if(st.size() > 0)
            {
                ans += ' ';
            }
        }
        return ans;
    }
};