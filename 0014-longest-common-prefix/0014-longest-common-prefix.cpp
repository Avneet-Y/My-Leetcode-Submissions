class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int s0 = strs[0].size();
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<s0; j++)
            {
                if(strs[0][j] != strs[i][j])
                {
                    s0 = j;
                    break;
                }
            }
        }
        return strs[0].substr(0, s0);
        
//Another app
//         string ans = "";
//         int n = strs.size();
//         sort(strs.begin(), strs.end());
//         string s0 = strs[0];
//         string s2 = strs[n-1];
//         int s = min(s0.size(), s2.size());
        
//         for(int i=0; i<s; i++)
//         {
//             if(s0[i] != s2[i])
//             {
//                 return ans;
//             }
//             ans += s0[i];
//         }
//         return ans;
    }
};