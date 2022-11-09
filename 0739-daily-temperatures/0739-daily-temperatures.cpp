class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        vector<int> ans;
        int n = temperatures.size();
        for(int i = n-1; i >= 0; i--)
        {
            if(st.size() == 0)
            {
                ans.push_back(0);
            }
            else if(st.size() > 0 && st.top().first > temperatures[i])
            {
                ans.push_back(st.top().second - i);
            }
            else if(st.size() > 0 && st.top().first <= temperatures[i])
            {
                while(st.size() > 0 && st.top().first <= temperatures[i])
                {
                    st.pop();
                }
                if(st.size() == 0)
                {
                    ans.push_back(0);
                }
                else
                {
                    ans.push_back(st.top().second-i);
                }
            }
            st.push({temperatures[i],i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};