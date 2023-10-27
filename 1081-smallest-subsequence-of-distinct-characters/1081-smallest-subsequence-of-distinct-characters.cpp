class Solution {
public:
    string smallestSubsequence(string s) {
         int n = s.size();
        vector<int> last_index(26);
        vector<bool> taken(n, false);
        string ans;
        
        for(int i=0; i<n; i++)
        {
            char ch = s[i];
            last_index[ch - 'a'] = i;
        }
            
        for(int i=0; i<n; i++)
        {
            char ch = s[i];
            int ind = ch - 'a';
            if(taken[ind] == true)
                continue;
            
            while(ans.size() > 0 && ans.back() > ch && last_index[ans.back() - 'a'] > i)
            {
                taken[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(ch);
            taken[ch - 'a'] = true;            
        }
        return ans;
    }
};