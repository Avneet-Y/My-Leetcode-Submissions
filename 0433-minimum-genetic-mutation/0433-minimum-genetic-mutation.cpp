class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> st(bank.begin(), bank.end());
        queue<string> q;
        q.push(start);
        int count = 0;
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                string s = q.front();
                if (s == end)
                    return count;

                q.pop();
                st.erase(s);
                for (int i = 0; i < 8; i++)
                {
                    string temp = s;
                    temp[i] = 'A';
                    if (st.find(temp) != st.end())
                        q.push(temp);
                    
                    temp[i] = 'C';
                    if (st.find(temp) != st.end())
                        q.push(temp);
                    
                    temp[i] = 'G';
                    if (st.find(temp) != st.end())
                        q.push(temp);
                    
                    temp[i] = 'T';
                    if (st.find(temp) != st.end())
                        q.push(temp);
                }
            }
            count++;
        }
        return -1;
    }
};