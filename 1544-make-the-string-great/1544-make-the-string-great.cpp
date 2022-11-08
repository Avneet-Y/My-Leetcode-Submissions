class Solution {
public:
    string makeGood(string s) {
        // int start = 0;
        // while(start != s.size())
        // {
        //     start = s.size();
        //     for(int i = 0; i < s.size(); i++)
        //     {
        //       if(s[i] == s[i+1] or s[i+1] == s[i])
        //         s.erase(i, 2);
        //     }
        // }
        // return s;
        
        stack<char> st;
        for(int i=0; i < s.size(); i++)
        {
            if(st.size() == 0)
            {
                st.push(s[i]);
                continue;
            }
            if(abs(st.top() - s[i]) == 32)
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
         }
        
        string ans;
        while(st.size() > 0)
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};