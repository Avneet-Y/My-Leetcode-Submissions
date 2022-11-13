class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<string> st;
        string temp = "";
        for(int i = 0; i<n; i++)
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
        string ans = "";
        while(st.size() > 0)
        {   
            string temp1 = st.top();
            st.pop();
            ans += temp1;
            if(st.size() > 0)
                ans += " ";
        }
        return ans;
    }
};