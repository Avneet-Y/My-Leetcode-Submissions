class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        unordered_map<char, int> mp;
        string ans = "";
        int len = INT_MAX;
        int start = 0;
        
        for(auto it : t)
            mp[it]++;
        int count = mp.size();
        
        int i=0, j=0;
        while(j < n1)
        {
           mp[s[j]]--;
            if(mp[s[j]] == 0)
                count--;
            
            if(count == 0)
            {
                while(count == 0)
                {
                    if(len > j - i + 1)
                    {
                        len = j - i + 1; 
                        start = i;
                    }                 
                    mp[s[i]]++;
                    if(mp[s[i]] > 0)
                        count++;
                    i++;
                }
            }
            j++;
        }
        if(len != INT_MAX) 
            ans = s.substr(start, len);
        
        return ans;
    }
};