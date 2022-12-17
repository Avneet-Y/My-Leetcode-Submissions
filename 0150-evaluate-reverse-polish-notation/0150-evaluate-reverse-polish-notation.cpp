//#define long long ll;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<long long> st;
        for(int i=0; i<n; i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i]== "/")
            {
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();
                if(tokens[i] == "+")
                {
                    st.push(a+b);
                }
                else if(tokens[i] == "-")
                {
                    st.push(b-a);

                }
                else if(tokens[i] == "/")
                {
                    st.push(b/a);
                }
                else
                {
                    st.push(a*b);
                }
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();   
    }
};