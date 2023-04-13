class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n1 = pushed.size();
        int n2 = popped.size();
        stack<int> st;
        int j = 0;
        for(int i=0; i<n1; i++)
        {
            st.push(pushed[i]);
            while(st.size() > 0 && j < n2 && popped[j] == st.top() )
            {
                j++;
                st.pop();
            }
        }
        if(st.size() == 0)
            return true;
        return false;
    }
};