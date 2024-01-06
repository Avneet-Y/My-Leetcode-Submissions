class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        sort(strs.begin(), strs.end());
        string s0 = strs[0];
        string s2 = strs[n-1];
        int s = min(s0.size(), s2.size());
        
        for(int i=0; i<s; i++)
        {
            if(s0[i] != s2[i])
            {
                return ans;
            }
            ans += s0[i];
        }
        return ans;
        
    }
};