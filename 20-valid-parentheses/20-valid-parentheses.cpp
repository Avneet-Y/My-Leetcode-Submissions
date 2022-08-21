class Solution {
public:
    bool isMatching(char a, char b)
    {
        return ( a=='{' && b=='}' || a=='(' && b==')' || a=='[' && b==']');
    }
    
    bool isValid(string s) {
        int n = s.size();
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='[' || s[i]=='{' || s[i]=='(')
                st.push(s[i]);
            else
            {
                if(st.empty()==true)
                    return false;
                else if(isMatching(st.top(), s[i]) == false)
                    return false;
                else
                    st.pop();
            }
        }
        return (st.empty()==true);
    }
};